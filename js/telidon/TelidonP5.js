"use strict";

// TelidonP5 - a p5.js renderer for the NAPLPS command array that naplps.js
// produces.  It stands in for renderer.js: the same command array goes in and
// the same picture comes out, but every mark is made with a p5 drawing call
// rather than against a bare Canvas 2D context, so NAPLPS artwork can share a
// canvas with a sketch's own drawing.
//
// The target handed to render() is a p5 sketch instance or a p5.Graphics; both
// answer the same drawing calls, which is what lets a programmable fill mask be
// rendered into an offscreen tile by the same code that draws the display.
//
// Two things NAPLPS needs have no p5 equivalent: clipping, which hatched fills,
// pattern fills and DRCS glyphs are contained by, and line dashes, which the
// line textures are drawn with.  Those two reach through to drawingContext;
// nothing else here does, and neither of them paints - they only constrain
// where and how p5 then paints.  p5's push()/pop() save and restore that
// context, so a clip lifts with the rest of the state.
(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define([], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory();
  } else {
    root.TelidonP5 = factory();
  }
}(typeof self !== 'undefined' ? self : this, function () {
  'use strict';

  // Fill pattern codes from the TEXTURE PDI.
  var FILL_SOLID = 0;
  var FILL_VERTICAL = 1;
  var FILL_HORIZONTAL = 2;
  var FILL_CROSS = 3;
  // 4-7 are the programmable masks A-D.  With no DEF TEXTURE they draw nothing
  // in color modes 0 and 1, and the background color in mode 2.

  // ─── Geometry ──────────────────────────────────────────────────────

  // Maps unit-screen coordinates onto the canvas.  By default X and Y share a
  // scale so the 4:3 aspect ratio is preserved whatever the canvas size, and the
  // unit origin sits at the bottom-left corner.  DRCS glyphs and pattern tiles
  // reuse the renderer with a viewport that maps the unit screen onto a
  // character field or a tile instead.
  function Viewport(width, height, opts) {
    opts = opts || {};
    this.width = width;
    this.height = height;
    this.sx = opts.sx === undefined ? width : opts.sx;
    this.sy = opts.sy === undefined ? width : opts.sy;
    this.originX = opts.originX === undefined ? 0 : opts.originX;
    this.originY = opts.originY === undefined ? height : opts.originY;
    // Pel sizes and line widths are lengths, not positions, so they scale by the
    // average of the two axes when the viewport is not square.
    this.scale = (this.sx + this.sy) / 2;
  }
  Viewport.prototype.x = function (x) { return this.originX + x * this.sx; };
  Viewport.prototype.y = function (y) { return this.originY - y * this.sy; };
  Viewport.prototype.len = function (v) { return v * this.scale; };

  // A DRCS glyph or pattern mask is drawn in unit-screen coordinates into a
  // notional bitmap that has the aspect ratio of its target, with the larger of
  // the two dimensions counting as one full unit.  This returns the extent of
  // the unit square that the target covers.
  function programExtent(w, h) {
    if (w >= h) return { w: 1, h: h / (w || 1) };
    return { w: w / (h || 1), h: 1 };
  }

  function clamp(v, lo, hi) { return v < lo ? lo : (v > hi ? hi : v); }

  // ─── Color ─────────────────────────────────────────────────────────

  var WHITE = { r: 1, g: 1, b: 1 };
  var BLACK = { r: 0, g: 0, b: 0 };

  // Colors arrive as fractions; p5 is driven in RGB 255, which render() sets.
  function chan(v) { return Math.max(0, Math.min(255, Math.round(v * 255))); }
  function setFill(pg, c) { pg.fill(chan(c.r), chan(c.g), chan(c.b)); }
  function setStroke(pg, c) { pg.stroke(chan(c.r), chan(c.g), chan(c.b)); }
  function colorKey(c) { return chan(c.r) + ',' + chan(c.g) + ',' + chan(c.b); }

  // ─── Renderer State ────────────────────────────────────────────────

  function createState() {
    return {
      // In color mode 0 the drawing color is given directly; in modes 1 and 2 it
      // is a palette entry.  A terminal holds indices in its framebuffer and
      // colors in the palette, so an entry rewritten after a shape was drawn
      // recolors that shape - see displayPaletteFor.
      direct: { r: 1, g: 1, b: 1 },
      palette: [],        // the palette as the stream has built it so far
      displayPalette: null, // the palette the frame is displayed through
      fgIndex: 0,
      bgIndex: 0,
      colorMode: 0,
      pel: { w: 0, h: 0 },
      texture: { fill: FILL_SOLID, outline: false, line: 0 },
      mask: null,    // active programmable fill mask, if one is defined
      nested: false, // true while drawing a DRCS glyph or a pattern tile
      blinks: [],     // active palette-animation processes
      clock: 0,       // seconds of WAIT elapsed so far
      blinkClock: 0,  // wall-clock seconds, used for palette animation
      point: { x: 0, y: 0 }
    };
  }

  // The state a stored definition - a DRCS glyph or a pattern tile - is drawn
  // in.  It inherits the colors of the environment that invoked it, but gets
  // its own copies of the palettes so that a definition which sets its own
  // entries does not write them back into the caller's.
  function nestedState(state) {
    var nested = createState();
    nested.nested = true;
    nested.palette = state.palette.slice();
    nested.displayPalette = state.displayPalette ? state.displayPalette.slice() : null;
    nested.direct = state.direct;
    nested.fgIndex = state.fgIndex;
    nested.bgIndex = state.bgIndex;
    nested.colorMode = state.colorMode;
    nested.blinks = state.blinks;
    nested.clock = state.clock;
    nested.blinkClock = state.blinkClock;
    return nested;
  }

  // Current drawing color, resolved through the palette when in a palette mode.
  function fg(state) {
    if (state.colorMode === 0) return state.direct;
    return paletteEntry(state, state.fgIndex, WHITE);
  }

  // Current background color, used for character fields, outlines of filled
  // objects and the gaps in pattern fills.
  function bg(state) {
    if (state.colorMode === 0) return BLACK;
    return paletteEntry(state, state.bgIndex, BLACK);
  }

  // Look up a palette entry, following any blink processes that are in their ON
  // phase.  They are applied in definition order, so a later process sees the
  // substitution an earlier one made - which the spec calls out explicitly.
  function paletteEntry(state, index, fallback) {
    for (var i = 0; i < state.blinks.length; i++) {
      var b = state.blinks[i];
      if (b.from === index && blinkIsOn(b, state.blinkClock)) index = b.to;
    }
    var palette = state.displayPalette || state.palette;
    return palette[index] || fallback;
  }

  // The phase a blink process is in.  Blink runs on wall-clock time, which is
  // not the same as the WAIT clock: a still image with no WAIT commands still
  // has its palette animated.
  function blinkIsOn(b, time) {
    var period = b.on + b.off;
    if (period <= 0) return false;
    var phase = (time - b.start) % period;
    if (phase < 0) phase += period;
    return phase < b.on;
  }

  // The logical pel is the brush used by every drawing operation.  It is at
  // least one unit in each direction and is rounded up, never down.
  function pelPixels(state, vp) {
    return {
      w: Math.max(1, Math.ceil(Math.abs(state.pel.w) * vp.scale)),
      h: Math.max(1, Math.ceil(Math.abs(state.pel.h) * vp.scale))
    };
  }

  // Width of the swept region when a w x h rectangular brush is dragged along a
  // line, measured perpendicular to the direction of travel.  A horizontal line
  // is as thick as the pel is high, a vertical one as thick as it is wide.
  function strokeWidthFor(pel, dx, dy) {
    var len = Math.sqrt(dx * dx + dy * dy);
    if (len === 0) return Math.max(pel.w, pel.h);
    return pel.w * Math.abs(dy / len) + pel.h * Math.abs(dx / len);
  }

  // Dash pattern for the current line texture.  A dot is one logical pel and a
  // dash three, with one pel of gap.  A zero pel dimension leaves lines in that
  // orientation solid, which is why the default pel size draws everything solid.
  function dashPattern(state, pel, dx, dy) {
    if (!state.texture.line) return null;
    var horizontal = Math.abs(dx) >= Math.abs(dy);
    if (horizontal && state.pel.w === 0) return null;
    if (!horizontal && state.pel.h === 0) return null;
    var unit = horizontal ? pel.w : pel.h;
    switch (state.texture.line) {
      case 1: return [unit, unit];                     // dotted
      case 2: return [unit * 3, unit];                 // dashed
      case 3: return [unit * 3, unit, unit, unit];     // dot-dash
      default: return null;
    }
  }

  // ─── p5 Helpers ────────────────────────────────────────────────────

  // Trace a polygon with p5's shape API.  p5 keeps no path object between
  // calls, so a shape that is filled and then outlined is traced twice.
  function shape(pg, pts, close) {
    pg.beginShape();
    for (var i = 0; i < pts.length; i++) pg.vertex(pts[i].x, pts[i].y);
    pg.endShape(close ? pg.CLOSE : undefined);
  }

  // Clip to a polygon.  p5 has no clipping call, so this is the one place the
  // raw context is touched; pair it with pg.push()/pg.pop(), which save and
  // restore that context, and the clip lifts with them.
  function clipTo(pg, pts) {
    var ctx = pg.drawingContext;
    ctx.beginPath();
    ctx.moveTo(pts[0].x, pts[0].y);
    for (var i = 1; i < pts.length; i++) ctx.lineTo(pts[i].x, pts[i].y);
    ctx.closePath();
    ctx.clip();
  }

  // Line dashes have no p5 equivalent either, and are set per segment.
  function setDash(pg, dash) {
    if (pg.drawingContext.setLineDash) pg.drawingContext.setLineDash(dash || []);
  }

  function fillRect(pg, x, y, w, h) {
    if (w <= 0 || h <= 0) return;
    pg.rect(x, y, w, h);
  }

  function boundsOf(points) {
    var x0 = Infinity, y0 = Infinity, x1 = -Infinity, y1 = -Infinity;
    for (var i = 0; i < points.length; i++) {
      if (points[i].x < x0) x0 = points[i].x;
      if (points[i].x > x1) x1 = points[i].x;
      if (points[i].y < y0) y0 = points[i].y;
      if (points[i].y > y1) y1 = points[i].y;
    }
    return { x0: x0, y0: y0, x1: x1, y1: y1 };
  }

  function cornersOf(b) {
    return [
      { x: b.x0, y: b.y0 }, { x: b.x1, y: b.y0 },
      { x: b.x1, y: b.y1 }, { x: b.x0, y: b.y1 }
    ];
  }

  // ─── Painting ──────────────────────────────────────────────────────

  // Fill a shape according to the active fill pattern.  The outline arrives as
  // points rather than as a path, since p5 has nothing to hand a path to.
  function paintFilled(pg, state, vp, pts) {
    var bounds = boundsOf(pts);
    var pel = pelPixels(state, vp);
    var fill = state.texture.fill;
    var bw = bounds.x1 - bounds.x0;
    var bh = bounds.y1 - bounds.y0;

    if (fill === FILL_SOLID) {
      pg.noStroke();
      setFill(pg, fg(state));
      shape(pg, pts, true);
      return;
    }

    if (fill === FILL_VERTICAL || fill === FILL_HORIZONTAL || fill === FILL_CROSS) {
      pg.push();
      clipTo(pg, pts);
      pg.noStroke();
      pg.rectMode(pg.CORNER);
      // In mode 2 the gaps between the hatching show the background color.
      if (state.colorMode === 2) {
        setFill(pg, bg(state));
        fillRect(pg, bounds.x0, bounds.y0, bw, bh);
      }
      setFill(pg, fg(state));
      // Hatching is one pel wide, one pel apart, and registered to the screen
      // origin so that adjacent objects line up.
      if (fill === FILL_VERTICAL || fill === FILL_CROSS) {
        var stepX = pel.w * 2;
        for (var x = Math.floor(bounds.x0 / stepX) * stepX; x <= bounds.x1; x += stepX) {
          fillRect(pg, x, bounds.y0, pel.w, bh);
        }
      }
      if (fill === FILL_HORIZONTAL || fill === FILL_CROSS) {
        var stepY = pel.h * 2;
        for (var y = Math.floor(bounds.y0 / stepY) * stepY; y <= bounds.y1; y += stepY) {
          fillRect(pg, bounds.x0, y, bw, pel.h);
        }
      }
      pg.pop();
      return;
    }

    if (state.mask && state.mask.maskProgram.length) {
      // Programmable mask: stamp a prepared sheet of tiles across the object,
      // anchored to the screen origin so neighbouring objects keep registration.
      var sheet = maskSheet(pg, state, vp);
      if (sheet) {
        pg.push();
        clipTo(pg, pts);
        pg.noStroke();
        pg.imageMode(pg.CORNER);
        if (state.colorMode === 2) {
          pg.rectMode(pg.CORNER);
          setFill(pg, bg(state));
          fillRect(pg, bounds.x0, bounds.y0, bw, bh);
        }
        for (var sy = Math.floor(bounds.y0 / sheet.height) * sheet.height; sy < bounds.y1; sy += sheet.height) {
          for (var sx = Math.floor(bounds.x0 / sheet.width) * sheet.width; sx < bounds.x1; sx += sheet.width) {
            pg.image(sheet, sx, sy, sheet.width, sheet.height);
          }
        }
        pg.pop();
      }
      return;
    }

    // Undefined programmable mask: background only in mode 2, nothing otherwise.
    if (state.colorMode === 2) {
      pg.noStroke();
      setFill(pg, bg(state));
      shape(pg, pts, true);
    }
  }

  // How large a prepared sheet of mask tiles should be, in pixels.  p5 has no
  // repeating-pattern fill, so a mask is stamped with image(); repeating the
  // tile into a sheet first, once, keeps the number of stamps per fill small
  // even when the tile itself is only a few pixels across.
  var SHEET_TARGET = 128;

  // Build (and cache on the TEXTURE command) a sheet of the current
  // programmable fill mask.  The mask is itself a NAPLPS program, drawn into a
  // tile of the mask size and then repeated.
  function maskSheet(pg, state, vp) {
    var mask = state.mask;
    var tw = Math.max(1, Math.round(Math.abs(mask.maskW) * vp.scale));
    var th = Math.max(1, Math.round(Math.abs(mask.maskH) * vp.scale));
    var key = tw + 'x' + th + ':' + colorKey(fg(state));
    if (mask.p5Key === key) return mask.p5Sheet;

    // p5.Graphics come from the sketch, not from an offscreen buffer that may
    // itself be one, so a nested render still allocates against the sketch.
    var root = pg._pInst || pg;
    if (typeof root.createGraphics !== 'function') return null;

    var tile = root.createGraphics(tw, th);
    tile.pixelDensity(1);

    // The mask program draws in unit-screen coordinates; the larger side of the
    // tile counts as one full unit.
    var extent = programExtent(tw, th);
    var tileVp = new Viewport(tw, th, {
      sx: tw / extent.w, sy: th / extent.h, originX: 0, originY: th
    });

    var tileState = nestedState(state);
    tile.push();
    tile.colorMode(tile.RGB, 255);
    tile.angleMode(tile.RADIANS);
    tile.strokeCap(tile.SQUARE);
    tile.strokeJoin(tile.MITER);
    for (var i = 0; i < mask.maskProgram.length; i++) {
      drawCommand(tile, tileState, tileVp, mask.maskProgram[i]);
    }
    tile.pop();

    var nx = Math.max(1, Math.ceil(SHEET_TARGET / tw));
    var ny = Math.max(1, Math.ceil(SHEET_TARGET / th));
    var sheet = root.createGraphics(tw * nx, th * ny);
    sheet.pixelDensity(1);
    sheet.imageMode(sheet.CORNER);
    for (var cy = 0; cy < ny; cy++) {
      for (var cx = 0; cx < nx; cx++) sheet.image(tile, cx * tw, cy * th, tw, th);
    }
    tile.remove();

    if (mask.p5Sheet) mask.p5Sheet.remove();
    mask.p5Key = key;
    mask.p5Sheet = sheet;
    return sheet;
  }

  // Outline a filled object.  The outline is always solid regardless of the line
  // texture, and is drawn in black in color modes 0 and 1, the background color
  // in mode 2.  A filled arc is outlined along its curve only, never across the
  // chord, so it comes through here as an open path.
  function outlineFilled(pg, state, vp, pts, close) {
    if (!state.texture.outline) return;
    var pel = pelPixels(state, vp);
    setDash(pg, null);
    pg.noFill();
    pg.strokeWeight(Math.max(pel.w, pel.h));
    setStroke(pg, state.colorMode === 2 ? bg(state) : BLACK);
    shape(pg, pts, close);
  }

  // ─── Arcs ──────────────────────────────────────────────────────────

  // Circle through three points.  Returns null when they are collinear.
  function circumcircle(a, b, c) {
    var d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    if (Math.abs(d) < 1e-9) return null;
    var a2 = a.x * a.x + a.y * a.y;
    var b2 = b.x * b.x + b.y * b.y;
    var c2 = c.x * c.x + c.y * c.y;
    var ux = (a2 * (b.y - c.y) + b2 * (c.y - a.y) + c2 * (a.y - b.y)) / d;
    var uy = (a2 * (c.x - b.x) + b2 * (a.x - c.x) + c2 * (b.x - a.x)) / d;
    return { x: ux, y: uy, r: Math.hypot(a.x - ux, a.y - uy) };
  }

  // Sample the arc that starts at `a`, passes through `b` and ends at `c`.
  function arcPoints(a, b, c, steps) {
    var circle = circumcircle(a, b, c);
    if (!circle) return [a, c]; // collinear: the spec says draw a straight line

    var start = Math.atan2(a.y - circle.y, a.x - circle.x);
    var mid = Math.atan2(b.y - circle.y, b.x - circle.x);
    var end = Math.atan2(c.y - circle.y, c.x - circle.x);

    // Choose the sweep direction that actually passes through the intermediate
    // point, rather than the one that takes the short way round.
    var ccw = normalize(mid - start) < normalize(end - start);
    var sweep = ccw ? normalize(end - start) : -normalize(start - end);

    var out = [];
    steps = steps || 64;
    for (var i = 0; i <= steps; i++) {
      var t = start + sweep * (i / steps);
      out.push({ x: circle.x + circle.r * Math.cos(t), y: circle.y + circle.r * Math.sin(t) });
    }
    return out;
  }

  // Wrap an angle difference into [0, 2pi).
  function normalize(a) {
    var t = a % (Math.PI * 2);
    return t < 0 ? t + Math.PI * 2 : t;
  }

  // A Catmull-Rom spline through every point, used when an arc carries more
  // than three points.
  function splinePoints(pts, stepsPerSegment) {
    var out = [pts[0]];
    var steps = stepsPerSegment || 16;
    for (var i = 0; i < pts.length - 1; i++) {
      var p0 = pts[i > 0 ? i - 1 : 0];
      var p1 = pts[i];
      var p2 = pts[i + 1];
      var p3 = pts[i + 2 < pts.length ? i + 2 : pts.length - 1];
      for (var s = 1; s <= steps; s++) {
        var t = s / steps, t2 = t * t, t3 = t2 * t;
        out.push({
          x: 0.5 * ((2 * p1.x) + (-p0.x + p2.x) * t +
            (2 * p0.x - 5 * p1.x + 4 * p2.x - p3.x) * t2 +
            (-p0.x + 3 * p1.x - 3 * p2.x + p3.x) * t3),
          y: 0.5 * ((2 * p1.y) + (-p0.y + p2.y) * t +
            (2 * p0.y - 5 * p1.y + 4 * p2.y - p3.y) * t2 +
            (-p0.y + 3 * p1.y - 3 * p2.y + p3.y) * t3)
        });
      }
    }
    return out;
  }

  // ─── Text ──────────────────────────────────────────────────────────

  var ROTATIONS = [0, Math.PI / 2, Math.PI, Math.PI * 3 / 2];

  // Glyphs are drawn to fill the character field.  0.8 of the field height puts
  // a typical font's ascender at the top of the cell and its baseline on the
  // cell's bottom edge, which is how the reference images sit.
  var GLYPH_HEIGHT_RATIO = 0.8;

  // Fraction of the advance a glyph fills, leaving a small intercharacter gap.
  var GLYPH_FILL_RATIO = 0.92;

  // Set up a transform whose origin is the lower-left corner of the character
  // field, with the field rotated and mirrored as the TEXT PDI asks.  Inside the
  // transform the field spans x in [0, w] and y in [-h, 0] (canvas Y is down).
  // The caller brackets this with pg.push()/pg.pop().
  function enterCharField(pg, vp, cmd) {
    var w = vp.len(Math.abs(cmd.charWidth));
    var h = vp.len(Math.abs(cmd.charHeight));
    pg.translate(vp.x(cmd.x), vp.y(cmd.y));
    // The field rotates about its origin.  Canvas Y points down, so a positive
    // NAPLPS rotation is a negative canvas rotation.
    pg.rotate(-ROTATIONS[cmd.rotation || 0]);
    // Negative field dimensions mirror the character about the field's axes.
    if (cmd.charWidth < 0 || cmd.charHeight < 0) {
      pg.scale(cmd.charWidth < 0 ? -1 : 1, cmd.charHeight < 0 ? -1 : 1);
    }
    return { w: w, h: h };
  }

  // In color mode 2 the whole character field is painted with the background.
  function paintCharBackground(pg, state, cmd, field) {
    if (state.colorMode !== 2 || cmd.bgR === undefined) return;
    pg.noStroke();
    pg.rectMode(pg.CORNER);
    setFill(pg, { r: cmd.bgR, g: cmd.bgG, b: cmd.bgB });
    fillRect(pg, 0, -field.h, field.w, field.h);
  }

  function drawText(pg, state, vp, cmd) {
    pg.push();
    var field = enterCharField(pg, vp, cmd);
    paintCharBackground(pg, state, cmd, field);

    var size = field.h * GLYPH_HEIGHT_RATIO;
    if (size > 0) {
      pg.textFont('monospace');
      pg.textSize(size);
      pg.textAlign(pg.LEFT, pg.BASELINE);
      pg.noStroke();
      setFill(pg, fg(state));

      // NAPLPS scales characters to the character field, so a glyph is stretched
      // to fill the space the cursor is about to move through.  Under
      // proportional spacing that space is narrower than the field and varies
      // per character, which is what gives proportional text its shape.
      var target = vp.len(Math.abs(cmd.advance === undefined ? cmd.charWidth : cmd.advance));
      var natural = pg.textWidth(cmd.char);
      if (natural > 0 && target > 0) {
        pg.scale(clamp(target * GLYPH_FILL_RATIO / natural, 0.2, 4), 1);
      }
      pg.text(cmd.char, 0, 0);
    }
    pg.pop();
  }

  // Mosaic cells, as bit masks within the character code.  The spec numbers the
  // bits from 1 at the least significant end and lays the cells out as
  //   1 2
  //   3 4
  //   5 7
  // with bit 6 being the fixed set bit that puts the code in the graphic range.
  var MOSAIC_CELLS = [
    { mask: 0x01, col: 0, row: 0 },
    { mask: 0x02, col: 1, row: 0 },
    { mask: 0x04, col: 0, row: 1 },
    { mask: 0x08, col: 1, row: 1 },
    { mask: 0x10, col: 0, row: 2 },
    { mask: 0x40, col: 1, row: 2 }
  ];

  function drawMosaic(pg, state, vp, cmd) {
    pg.push();
    var field = enterCharField(pg, vp, cmd);
    paintCharBackground(pg, state, cmd, field);

    // Contiguous mode: the field divides into six equal rectangles.
    var cw = field.w / 2;
    var ch = field.h / 3;
    pg.noStroke();
    pg.rectMode(pg.CORNER);
    setFill(pg, fg(state));
    for (var i = 0; i < MOSAIC_CELLS.length; i++) {
      var cell = MOSAIC_CELLS[i];
      if (cmd.code & cell.mask) {
        // Row 0 is the top of the field, which is -h in canvas coordinates.
        fillRect(pg, cell.col * cw, -field.h + cell.row * ch, cw, ch);
      }
    }
    pg.pop();
  }

  // A DRCS character is a stored NAPLPS program rather than a glyph.  It is
  // drawn in unit-screen coordinates into a notional bitmap with the aspect
  // ratio of the character field, then scaled to fill that field.  Rendering the
  // program directly, rather than through a bitmap, keeps it resolution
  // independent - which the spec itself recommends.
  function drawDrcs(pg, state, vp, cmd) {
    pg.push();
    var field = enterCharField(pg, vp, cmd);
    paintCharBackground(pg, state, cmd, field);

    if (cmd.program && cmd.program.length && field.w > 0 && field.h > 0) {
      // Inside enterCharField the field's lower-left corner is the origin and
      // the field extends right and up (negative Y on canvas).
      var extent = programExtent(field.w, field.h);
      var glyphVp = new Viewport(field.w, field.h, {
        sx: field.w / extent.w, sy: field.h / extent.h, originX: 0, originY: 0
      });

      pg.push();
      clipTo(pg, cornersOf({ x0: 0, y0: -field.h, x1: field.w, y1: 0 }));
      var glyphState = nestedState(state);
      for (var i = 0; i < cmd.program.length; i++) {
        drawCommand(pg, glyphState, glyphVp, cmd.program[i]);
      }
      pg.pop();
    }
    pg.pop();
  }

  // ─── Primitives ────────────────────────────────────────────────────

  // The logical pel is not centred on the drawing point; the point sits at the
  // corner picked out by the signs of the pel dimensions, so spanning
  // x..x+w and y..y+h in unit space places it correctly for any sign.
  function drawPoint(pg, state, vp, cmd) {
    var pel = pelPixels(state, vp);
    var x = vp.x(cmd.x);
    var y = vp.y(cmd.y);
    pg.noStroke();
    pg.rectMode(pg.CORNER);
    setFill(pg, fg(state));
    fillRect(pg,
      state.pel.w < 0 ? x - pel.w : x,
      state.pel.h < 0 ? y : y - pel.h,
      pel.w, pel.h);
  }

  function drawLine(pg, state, vp, cmd) {
    strokeSegment(pg, state, vp, vp.x(cmd.x1), vp.y(cmd.y1), vp.x(cmd.x2), vp.y(cmd.y2));
  }

  // Segments go through beginShape() rather than line(): p5's line() nudges an
  // odd-width stroke half a pixel to make it crisp, which would leave every
  // outline half a pixel off the filled shape it bounds.
  function strokeSegment(pg, state, vp, x1, y1, x2, y2) {
    var pel = pelPixels(state, vp);
    var dx = x2 - x1, dy = y2 - y1;
    pg.noFill();
    setStroke(pg, fg(state));
    pg.strokeWeight(strokeWidthFor(pel, dx, dy));
    setDash(pg, dashPattern(state, pel, dx, dy));
    shape(pg, [{ x: x1, y: y1 }, { x: x2, y: y2 }], false);
    setDash(pg, null);
  }

  // Stroke an unfilled outline.  Each segment is stroked on its own so that the
  // pel-shaped brush gives horizontal and vertical runs their own thickness.
  function strokeOutline(pg, state, vp, pts, close) {
    var n = close ? pts.length : pts.length - 1;
    for (var i = 0; i < n; i++) {
      var a = pts[i];
      var b = pts[(i + 1) % pts.length];
      strokeSegment(pg, state, vp, a.x, a.y, b.x, b.y);
    }
  }

  function drawRect(pg, state, vp, cmd) {
    // Width and height are signed displacements from the drawing point.
    var x0 = vp.x(Math.min(cmd.x, cmd.x + cmd.w));
    var x1 = vp.x(Math.max(cmd.x, cmd.x + cmd.w));
    // Canvas Y is inverted, so the larger unit Y gives the smaller pixel Y.
    var y0 = vp.y(Math.max(cmd.y, cmd.y + cmd.h));
    var y1 = vp.y(Math.min(cmd.y, cmd.y + cmd.h));
    var pts = cornersOf({ x0: x0, y0: y0, x1: x1, y1: y1 });

    if (cmd.filled) {
      paintFilled(pg, state, vp, pts);
      outlineFilled(pg, state, vp, pts, true);
    } else {
      strokeOutline(pg, state, vp, pts, true);
    }
  }

  function drawPolygon(pg, state, vp, cmd) {
    if (!cmd.points || cmd.points.length < 2) return;
    var pts = cmd.points.map(function (p) { return { x: vp.x(p.x), y: vp.y(p.y) }; });

    if (cmd.filled) {
      paintFilled(pg, state, vp, pts);
      outlineFilled(pg, state, vp, pts, true);
    } else {
      strokeOutline(pg, state, vp, pts, true);
    }
  }

  function drawArc(pg, state, vp, cmd) {
    if (!cmd.points || cmd.points.length < 2) return;
    var pts = cmd.points.map(function (p) { return { x: vp.x(p.x), y: vp.y(p.y) }; });
    var curve;

    if (pts.length === 2) {
      // Start and end coincide: the second point gives the diameter of a circle.
      var a = pts[0], b = pts[1];
      var cx = (a.x + b.x) / 2, cy = (a.y + b.y) / 2;
      var r = Math.hypot(b.x - a.x, b.y - a.y) / 2;
      curve = [];
      for (var i = 0; i <= 96; i++) {
        var t = (i / 96) * Math.PI * 2;
        curve.push({ x: cx + r * Math.cos(t), y: cy + r * Math.sin(t) });
      }
    } else if (pts.length === 3) {
      curve = arcPoints(pts[0], pts[1], pts[2]);
    } else {
      curve = splinePoints(pts);
    }

    if (cmd.filled) {
      // The area between the arc and the chord joining its endpoints is filled,
      // but when it is outlined only the curved part is drawn - never the chord.
      paintFilled(pg, state, vp, curve);
      outlineFilled(pg, state, vp, curve, false);
    } else {
      strokeOutline(pg, state, vp, curve, false);
    }
  }

  function drawIncLine(pg, state, vp, cmd) {
    if (!cmd.segments) return;
    for (var i = 0; i < cmd.segments.length; i++) {
      var s = cmd.segments[i];
      strokeSegment(pg, state, vp, vp.x(s.x1), vp.y(s.y1), vp.x(s.x2), vp.y(s.y2));
    }
  }

  // A bitmap laid down one logical pel at a time.  In color mode 0 each pixel
  // carries its own RGB value; in the palette modes it carries an index, so
  // rewriting the palette recolors the image.
  function drawIncPoint(pg, state, vp, cmd) {
    var w = Math.max(1, Math.ceil(Math.abs(cmd.pelW) * vp.scale));
    var h = Math.max(1, Math.ceil(Math.abs(cmd.pelH) * vp.scale));

    // A bitmap is a long run of same-sized rectangles, so the p5 modes are set
    // once and the fill only re-sent when the color actually changes.
    pg.noStroke();
    pg.rectMode(pg.CORNER);
    var last = null;
    for (var i = 0; i < cmd.pixels.length; i++) {
      var p = cmd.pixels[i];
      var color = p.color || paletteEntry(state, p.index, BLACK);
      var key = colorKey(color);
      if (key !== last) {
        setFill(pg, color);
        last = key;
      }
      // As everywhere else, the drawing point sits at the corner of the pel
      // picked out by the signs of its dimensions.
      fillRect(pg,
        cmd.pelW < 0 ? vp.x(p.x) - w : vp.x(p.x),
        cmd.pelH < 0 ? vp.y(p.y) : vp.y(p.y) - h,
        w, h);
    }
  }

  // ─── Commands ──────────────────────────────────────────────────────

  function drawCommand(pg, state, vp, cmd) {
    switch (cmd.type) {
      // ── Environment ──
      case 'reset':
        // A border-only reset leaves the screen contents alone, and a reset
        // inside a DRCS glyph or pattern tile must not repaint the display.
        if (cmd.screen && !state.nested) {
          pg.push();
          pg.noStroke();
          pg.rectMode(pg.CORNER);
          setFill(pg, { r: cmd.r, g: cmd.g, b: cmd.b });
          fillRect(pg, 0, 0, vp.width, vp.height);
          pg.pop();
        }
        break;

      case 'palette':
        state.palette = cmd.colors.map(function (c) { return { r: c.r, g: c.g, b: c.b }; });
        break;

      case 'setPalette':
        // Rewriting an entry changes everything currently drawn in it, which is
        // why the frame is painted through the palette as it stands at the end
        // of the frame rather than this running one.  Inside a stored
        // definition there is no "end of the frame" to wait for - the tile or
        // glyph is rasterised in one go - so the write takes effect here.
        state.palette[cmd.index] = { r: cmd.r, g: cmd.g, b: cmd.b };
        if (state.nested && state.displayPalette) {
          state.displayPalette[cmd.index] = { r: cmd.r, g: cmd.g, b: cmd.b };
        }
        break;

      case 'setColor':
        if (!cmd.transparent) state.direct = { r: cmd.r, g: cmd.g, b: cmd.b };
        break;

      case 'selectColor':
        if (cmd.mode !== undefined) state.colorMode = cmd.mode;
        if (cmd.index !== undefined) state.fgIndex = cmd.index;
        if (cmd.bgIndex !== undefined) state.bgIndex = cmd.bgIndex;
        break;

      case 'blink':
        registerBlink(state, cmd);
        break;

      case 'blinkReset':
        state.blinks = [];
        break;

      case 'texture':
        state.texture = { fill: cmd.fill, outline: cmd.outline, line: cmd.line };
        // The tile sheet is cached on the command, which outlives each selection
        // of this texture and is reused across repeated renders.
        state.mask = cmd.maskProgram ? cmd : null;
        break;

      case 'pelSize':
        state.pel = { w: cmd.w, h: cmd.h };
        break;

      // ── Primitives ──
      case 'point':
        state.point = { x: cmd.x, y: cmd.y };
        if (cmd.draw) drawPoint(pg, state, vp, cmd);
        break;

      case 'line':
        drawLine(pg, state, vp, cmd);
        break;

      case 'rect':
        drawRect(pg, state, vp, cmd);
        break;

      case 'polygon':
        drawPolygon(pg, state, vp, cmd);
        break;

      case 'arc':
        drawArc(pg, state, vp, cmd);
        break;

      case 'incLine':
        drawIncLine(pg, state, vp, cmd);
        break;

      case 'incPoint':
        drawIncPoint(pg, state, vp, cmd);
        break;

      // ── Characters ──
      case 'text':
        drawText(pg, state, vp, cmd);
        break;

      case 'mosaic':
        drawMosaic(pg, state, vp, cmd);
        break;

      case 'drcs':
        drawDrcs(pg, state, vp, cmd);
        break;

      // field, domain, wait, bell, nsr: no direct visual effect here.
    }
  }

  // Start or stop a palette-animation process.  A start delay is measured from
  // the ON interval of the most recently defined process, and is ignored when
  // none is running.
  function registerBlink(state, cmd) {
    var existing = -1;
    for (var i = 0; i < state.blinks.length; i++) {
      if (state.blinks[i].from === cmd.from &&
        (cmd.to === undefined || state.blinks[i].to === cmd.to)) {
        existing = i;
        break;
      }
    }

    // A zero interval, or a BLINK with no operands, terminates instead.
    if (cmd.stop) {
      if (cmd.to === undefined) {
        state.blinks = state.blinks.filter(function (b) { return b.from !== cmd.from; });
      } else if (existing >= 0) {
        state.blinks.splice(existing, 1);
      }
      return;
    }

    var last = state.blinks[state.blinks.length - 1];
    var start = last ? last.start + (cmd.delay || 0) : state.clock;
    var proc = { from: cmd.from, to: cmd.to, on: cmd.on, off: cmd.off, start: start };

    // There can only be one process for a given pair of colors.
    if (existing >= 0) state.blinks[existing] = proc;
    else state.blinks.push(proc);
  }

  // ─── Timeline ──────────────────────────────────────────────────────

  // Walk the commands that belong to the frame being drawn, stopping at the
  // command limit and at the point where the WAIT clock passes `time`.  The
  // drawing pass and the palette pre-pass have to agree on exactly where a
  // frame ends, so they share this.  `clock` is the WAIT time each command
  // arrives at, which is the time before any WAIT that follows it.
  function eachCommandInFrame(commands, limit, time, fn) {
    var clock = 0;
    for (var i = 0; i < limit && i < commands.length; i++) {
      var cmd = commands[i];
      if (cmd.type === 'wait') {
        clock += cmd.seconds || 0;
        // Everything after this point belongs to a later moment in the image.
        if (clock > time) return clock;
        continue;
      }
      fn(cmd, clock);
    }
    return clock;
  }

  // The palette the frame is displayed through: the one the stream has built by
  // the end of the frame, not the one in force when each shape was drawn.
  //
  // A terminal's framebuffer stores palette indices, so rewriting an entry
  // recolors every pixel already drawn in it.  Images animate on that: they
  // draw a shape once and then sweep its entry, which is how canada1.nap turns
  // its maple leaf from green to red without redrawing it.  Resolving at draw
  // time instead freezes each shape at whatever color its entry happened to
  // hold at the moment it was painted, and the animation is lost.
  //
  // Only the commands inside the frame count, so scrubbing through a timed
  // image sees the palette as it stood at that moment.  A RESET that rebuilds
  // the palette also clears the screen, so nothing drawn under the old palette
  // survives to be miscolored by the new one.
  function displayPaletteFor(commands, limit, time) {
    var palette = [];
    eachCommandInFrame(commands, limit, time, function (cmd) {
      if (cmd.type === 'palette') {
        palette = cmd.colors.map(function (c) { return { r: c.r, g: c.g, b: c.b }; });
      } else if (cmd.type === 'setPalette') {
        palette[cmd.index] = { r: cmd.r, g: cmd.g, b: cmd.b };
      }
    });
    return palette;
  }

  // Total running time of an image, in seconds.  Zero for a still image.
  function duration(commands) {
    var total = 0;
    for (var i = 0; i < commands.length; i++) {
      if (commands[i].type === 'wait') total += commands[i].seconds || 0;
    }
    return total;
  }

  // Whether an image animates its palette, which keeps moving even when the
  // image has no WAIT commands and so no duration of its own.
  function hasBlink(commands) {
    for (var i = 0; i < commands.length; i++) {
      if (commands[i].type === 'blink' && !commands[i].stop) return true;
    }
    return false;
  }

  // ─── Main Entry Point ──────────────────────────────────────────────

  // Draw a command array with p5.
  //
  //   pg                 a p5 sketch instance or a p5.Graphics to draw into.
  //   options.time       seconds into the image to draw up to.  WAIT commands
  //                      advance this clock, so an animated image can be played
  //                      by rendering repeatedly with an increasing time.
  //                      Defaults to Infinity, which draws the whole image.
  //   options.blinkTime  wall-clock seconds used to phase palette animation.
  //                      Defaults to options.time, which is right for a timed
  //                      image; pass it separately for a still image whose only
  //                      motion is BLINK.
  //   options.limit      stop after this many commands (useful for debugging).
  function render(pg, commands, options) {
    options = options || {};
    commands = commands || [];
    var width = options.width || pg.width;
    var height = options.height || pg.height;
    var vp = new Viewport(width, height);
    var state = createState();
    var limit = options.limit === undefined ? commands.length : options.limit;
    var time = options.time === undefined ? Infinity : options.time;
    var blinkTime = options.blinkTime;

    state.displayPalette = displayPaletteFor(commands, limit, time);

    // Everything below draws in absolute pixels with p5 in its default modes,
    // whatever the sketch had set; push()/pop() hands them back afterwards.
    pg.push();
    pg.colorMode(pg.RGB, 255);
    pg.angleMode(pg.RADIANS);
    pg.rectMode(pg.CORNER);
    pg.imageMode(pg.CORNER);
    pg.strokeCap(pg.SQUARE);
    pg.strokeJoin(pg.MITER);
    pg.background(options.background === undefined ? 0 : options.background);

    eachCommandInFrame(commands, limit, time, function (cmd, clock) {
      state.clock = clock;
      state.blinkClock = blinkTime === undefined ? clock : blinkTime;
      drawCommand(pg, state, vp, cmd);
    });

    pg.pop();
    return state;
  }

  return {
    render: render,
    duration: duration,
    hasBlink: hasBlink,
    Viewport: Viewport,
    version: '1.0.0'
  };
}));
