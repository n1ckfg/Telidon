// NAPLPS (North American Presentation Level Protocol Syntax) Decoder/Encoder
// Pure JavaScript implementation - UMD module
(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define([], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory();
  } else {
    root.NAPLPS = factory();
  }
}(typeof self !== 'undefined' ? self : this, function () {
  'use strict';

  // ─── Environment Constants ─────────────────────────────────────────
  // The unit screen is 1.0 wide with a 4:3 aspect ratio, so only y in
  // [0, 0.75] is visible.  Y increases upward from the bottom-left origin.
  var UNIT_SCREEN_HEIGHT = 0.75;

  var PALETTE_SIZE = 16;
  // Nominal white is palette entry 011...1 - the middle of the palette - and
  // nominal black is entry 0.  See "There are two special colors" in the spec.
  var NOMINAL_WHITE = PALETTE_SIZE / 2 - 1;
  // Bits needed to name a palette entry.
  var PALETTE_BITS = Math.round(Math.log(PALETTE_SIZE) / Math.LN2);

  // Default character field: 1/40 of the unit screen wide, 5/128 high, i.e. a
  // 40x25 character grid of which 19 rows are visible.
  var DEFAULT_CHAR_WIDTH = 1 / 40;
  var DEFAULT_CHAR_HEIGHT = 5 / 128;
  // Y of the bottom edge of the top row of text.
  var TOP_ROW_Y = UNIT_SCREEN_HEIGHT - DEFAULT_CHAR_HEIGHT;

  function cloneTextState(t) {
    return {
      charWidth: t.charWidth, charHeight: t.charHeight,
      rotation: t.rotation, path: t.path,
      spacing: t.spacing, rowSpacing: t.rowSpacing,
      cursorStyle: t.cursorStyle, cursorLink: t.cursorLink
    };
  }

  // Restore a snapshotted environment into a fresh decoder state.
  function applyEnv(state, env) {
    state.g0 = env.g0; state.g1 = env.g1; state.g2 = env.g2; state.g3 = env.g3;
    state.glSet = env.glSet; state.grSet = env.grSet;
    state.domain = { multiBytes: env.domain.multiBytes, singleBytes: env.domain.singleBytes, dimensions: env.domain.dimensions };
    state.textState = cloneTextState(env.textState);
    state.texture = { fill: env.texture.fill, outline: env.texture.outline, line: env.texture.line };
    state.maskSize = { w: env.maskSize.w, h: env.maskSize.h };
    state.pelSize = { w: env.pelSize.w, h: env.pelSize.h };
    state.colorMode = env.colorMode;
    state.paletteIndex = env.paletteIndex;
    state.palette = env.palette.map(function (c) { return { r: c.r, g: c.g, b: c.b }; });
    state.drawingColor = { r: env.drawingColor.r, g: env.drawingColor.g, b: env.drawingColor.b };
    state.bgColor = { r: env.bgColor.r, g: env.bgColor.g, b: env.bgColor.b };
    state.drawingPoint = { x: 0, y: 0 };
  }

  function defaultTextState() {
    return {
      charWidth: DEFAULT_CHAR_WIDTH,
      charHeight: DEFAULT_CHAR_HEIGHT,
      rotation: 0,   // 0=0deg, 1=90deg, 2=180deg, 3=270deg
      path: 0,       // 0=right, 1=left, 2=up, 3=down
      spacing: 0,    // 0=1x, 1=1.25x, 2=1.5x, 3=proportional
      rowSpacing: 0, // 0=1x, 1=1.25x, 2=1.5x, 3=2x
      cursorStyle: 0,
      cursorLink: 0
    };
  }

  // Intercharacter and interrow spacing multipliers, indexed by the 2-bit code.
  var CHAR_SPACING = [1, 1.25, 1.5, 1];   // index 3 is handled separately
  var PROPORTIONAL = 3;
  var ROW_SPACING = [1, 1.25, 1.5, 2];

  // Macros may invoke other macros; cap the nesting to stop a self-referential
  // definition from looping forever.
  var MAX_MACRO_DEPTH = 8;

  // The fixed-format byte that must follow a WAIT PDI (binary 1011100).
  var WAIT_MARKER = 0x5C;

  // ─── Default Palette ───────────────────────────────────────────────
  function buildDefaultPalette(numEntries) {
    var palette = [];
    var half = numEntries / 2;
    // First half: greyscale
    for (var i = 0; i < half; i++) {
      var grey = i / (half - 1);
      palette.push({ r: grey, g: grey, b: grey });
    }
    // Second half: hues around the color wheel
    // Blue at 0°, Red at 120°, Green at 240°
    for (var i = 0; i < half; i++) {
      var angle = (i / half) * 360;
      // Convert angle to RGB where Blue=0°, Red=120°, Green=240°
      var r = 0, g = 0, b = 0;
      // Determine which sector
      if (angle < 60) {
        // Blue to Magenta (Blue + Red increasing)
        b = 1; r = angle / 60; g = 0;
      } else if (angle < 120) {
        // Magenta to Red (Red full, Blue decreasing)
        r = 1; b = 1 - (angle - 60) / 60; g = 0;
      } else if (angle < 180) {
        // Red to Yellow (Red full, Green increasing)
        r = 1; g = (angle - 120) / 60; b = 0;
      } else if (angle < 240) {
        // Yellow to Green (Green full, Red decreasing)
        g = 1; r = 1 - (angle - 180) / 60; b = 0;
      } else if (angle < 300) {
        // Green to Cyan (Green full, Blue increasing)
        g = 1; b = (angle - 240) / 60; r = 0;
      } else {
        // Cyan to Blue (Blue full, Green decreasing)
        b = 1; g = 1 - (angle - 300) / 60; r = 0;
      }
      palette.push({ r: r, g: g, b: b });
    }
    return palette;
  }

  // ─── Coordinate and Value Parsing ──────────────────────────────────

  // Check if a byte is a data byte (0x40-0x7F)
  function isDataByte(b) {
    return b >= 0x40 && b <= 0x7F;
  }

  // Collect consecutive data bytes from the stream starting at pos
  function collectDataBytes(data, pos) {
    var bytes = [];
    while (pos < data.length && isDataByte(data[pos])) {
      bytes.push(data[pos]);
      pos++;
    }
    return { bytes: bytes, nextPos: pos };
  }

  // Decode a multi-value XY coordinate from data bytes
  // For 2D coordinates with N bytes per operand:
  //   Each byte contributes 6 data bits (bits 5-0, with bit 6 always 1, bit 7 unused)
  //   The bits are interleaved: bits 5,4,3 = X component, bits 2,1,0 = Y component
  //   First byte: bit 5 = X sign, bits 4,3 = X MSBs; bit 2 = Y sign, bits 1,0 = Y MSBs
  //   Subsequent bytes: bits 5,4,3 = next 3 X bits; bits 2,1,0 = next 3 Y bits
  function decodeCoordinate(dataBytes, numBytesPerOperand) {
    var n = Math.min(dataBytes.length, numBytesPerOperand);
    if (n === 0) return { x: 0, y: 0 };

    // Extract the 6 data bits from each byte
    var xBits = [];
    var yBits = [];
    for (var i = 0; i < n; i++) {
      var b = dataBytes[i] & 0x3F; // strip bits 7,6
      xBits.push((b >> 5) & 1, (b >> 4) & 1, (b >> 3) & 1);
      yBits.push((b >> 2) & 1, (b >> 1) & 1, b & 1);
    }

    // Pad to expected length if fewer bytes received
    while (xBits.length < numBytesPerOperand * 3) {
      xBits.push(0);
      yBits.push(0);
    }

    // The bits form a two's-complement signed integer, most significant first,
    // scaled so that the full positive range is one unit screen.  With the
    // default 3-byte operand that is 9 bits: -1.0 .. +0.998.
    var totalBits = numBytesPerOperand * 3;
    return {
      x: bitsToSignedFraction(xBits, totalBits),
      y: bitsToSignedFraction(yBits, totalBits)
    };
  }

  // Interpret bits[0..totalBits-1] (MSB first) as a two's-complement integer and
  // scale it to a fraction of the unit screen.
  function bitsToSignedFraction(bits, totalBits) {
    var val = 0;
    for (var i = 0; i < totalBits; i++) {
      val = val * 2 + (bits[i] || 0);
    }
    var half = Math.pow(2, totalBits - 1);
    if (val >= half) val -= half * 2; // negative in two's complement
    return val / half;
  }

  // Add a relative displacement to the current drawing point.  Coordinates are
  // in unit-screen space with Y increasing upward, so this is a plain vector add.
  function accumulateCoordinate(current, move) {
    return { x: current.x + move.x, y: current.y + move.y };
  }

  // Split data bytes into operands of the given size
  function splitOperands(dataBytes, bytesPerOperand) {
    var operands = [];
    for (var i = 0; i + bytesPerOperand <= dataBytes.length; i += bytesPerOperand) {
      operands.push(dataBytes.slice(i, i + bytesPerOperand));
    }
    // Handle trailing partial operand (pad with 0x40)
    var remainder = dataBytes.length % bytesPerOperand;
    if (remainder > 0) {
      var partial = dataBytes.slice(dataBytes.length - remainder);
      while (partial.length < bytesPerOperand) partial.push(0x40);
      operands.push(partial);
    }
    return operands;
  }

  // Decode color from multi-value operand (GRB interleaved)
  // Bits 5,2 = Green, bits 4,1 = Red, bits 3,0 = Blue per byte
  function decodeColor(dataBytes) {
    var gBits = [];
    var rBits = [];
    var bBits = [];
    for (var i = 0; i < dataBytes.length; i++) {
      var d = dataBytes[i] & 0x3F;
      gBits.push((d >> 5) & 1, (d >> 2) & 1);
      rBits.push((d >> 4) & 1, (d >> 1) & 1);
      bBits.push((d >> 3) & 1, d & 1);
    }

    function bitsToFraction(bits) {
      var val = 0;
      for (var i = 0; i < bits.length; i++) {
        val += bits[i] * Math.pow(2, -(i + 1));
      }
      return val;
    }

    return {
      r: bitsToFraction(rBits),
      g: bitsToFraction(gBits),
      b: bitsToFraction(bBits)
    };
  }

  // Decode a single-value unsigned operand from data bytes
  function decodeSingleValue(dataBytes, numBytes) {
    var n = Math.min(dataBytes.length, numBytes);
    var val = 0;
    var totalBits = numBytes * 6;
    for (var i = 0; i < n; i++) {
      var d = dataBytes[i] & 0x3F;
      val = (val << 6) | d;
    }
    // Left-shift if we got fewer bytes than expected
    val <<= (numBytes - n) * 6;
    return val;
  }

  // ─── Proportional Text Spacing ─────────────────────────────────────
  // In proportional mode the cursor advance depends on the character rather than
  // the full character field.  The spec classifies every graphic character into
  // one of ten width classes and gives an algorithm that keeps the visible gap
  // between characters constant across font sizes and display resolutions.
  //
  // Both tables are indexed [low nibble][high nibble - 2], matching the layout
  // printed in the standard.  Undefined cells fall back to the widest class.
  var WIDEST_CLASS = 9;

  var ASCII_WIDTH_CLASS = [
    [9, 5, 9, 5, 1, 5], [0, 1, 5, 6, 5, 5], [4, 5, 5, 5, 5, 5], [6, 5, 5, 5, 5, 5],
    [9, 5, 5, 9, 5, 2], [9, 5, 5, 5, 5, 5], [9, 5, 5, 9, 5, 9], [0, 5, 8, 9, 5, 9],
    [1, 5, 5, 9, 5, 9], [1, 5, 2, 9, 0, 5], [9, 0, 5, 9, 4, 5], [9, 3, 5, 4, 5, 5],
    [3, 5, 5, 9, 0, 0], [5, 8, 9, 4, 9, 5], [0, 5, 5, 2, 5, 9], [9, 8, 9, 9, 5]
  ];

  var SUPP_WIDTH_CLASS = [
    [9, 4, 9, 5, 6, 9], [0, 9, 2, 1, 9, 9], [9, 4, 2, 9, 6, 6], [5, 4, 2, 9, 5, 5],
    [9, 7, 9, 9, 9, 6], [9, 6, 5, 6, 9, 0], [9, 9, 5, 9, 9, 4], [6, 0, 0, 9, 5, 4],
    [9, 9, 4, 9, 9, 7], [1, 1, 9, 9, 9, 9], [6, 6, 1, 9, 9, 9], [8, 8, 7, 9, 5, 6],
    [9, 9, 9, 9, 5, 4], [7, 9, 4, 9, 9, 2], [9, 9, 8, 9, 6, 5], [7, 8, 2, 9, 9]
  ];

  // Cursor displacement in 256ths, indexed [field width in 256ths - 6][class].
  // Rows 6 to 11 are used directly; row 12 gives the unit spacing that the
  // scaling algorithm uses for wider character fields.
  var PROPORTIONAL_DISPLACEMENT = [
    [2, 3, 4, 3, 4, 5, 6, 4, 5, 6],   //  6/256
    [3, 4, 5, 4, 5, 6, 7, 5, 6, 7],   //  7/256
    [2, 3, 4, 4, 5, 6, 7, 6, 7, 8],   //  8/256
    [3, 4, 5, 5, 6, 7, 8, 7, 8, 9],   //  9/256
    [4, 5, 6, 6, 7, 8, 9, 8, 9, 10],  // 10/256
    [3, 4, 6, 6, 7, 8, 10, 8, 10, 11],// 11/256
    [6, 5, 4, 4, 3, 2, 1, 2, 1, 0]    // 12/256 and above: unit spacing
  ];
  var UNIT_SPACING_ROW = 6;

  function widthClassOf(code, setName) {
    var table = (setName === 'SUPP') ? SUPP_WIDTH_CLASS : ASCII_WIDTH_CLASS;
    var column = (code >> 4) - 2;
    var row = code & 0x0F;
    if (column < 0 || column > 5 || row > 15) return WIDEST_CLASS;
    var cls = table[row][column];
    return cls === undefined ? WIDEST_CLASS : cls;
  }

  // Cursor displacement for one character, as a fraction of the unit screen.
  function proportionalAdvance(fieldWidth, code, setName) {
    var cls = widthClassOf(code, setName);
    var n = Math.floor(fieldWidth * 256);

    if (n < 12) {
      // Below 12/256 the displacement is read straight out of the table.
      var row = Math.max(6, n) - 6;
      return PROPORTIONAL_DISPLACEMENT[row][cls] / 256;
    }

    // Wider fields scale the unit spacing.  The odd-looking subtract/or/subtract
    // is from the standard: it forces the widest class onto an odd width.
    var fixed = Math.floor(fieldWidth * 65536);
    var scaled = Math.floor(fixed * 11 / 13);
    scaled = (((scaled - 256) | 256) - 256);
    var f = Math.floor(scaled / 256);

    var unit = PROPORTIONAL_DISPLACEMENT[UNIT_SPACING_ROW][cls];
    var reduction = Math.floor(unit * f / 6 + 0.5);
    return Math.max(0, n - reduction) / 256;
  }

  // ─── G-Set Designation ─────────────────────────────────────────────
  // Final byte of an ESC designation sequence -> which character set it names.
  var G_SET_DESIGNATORS = {
    0x42: 'ASCII',  // 94-char
    0x7C: 'SUPP',   // 94-char
    0x57: 'PDI',    // 96-char
    0x7D: 'MOSAIC', // 96-char
    0x7A: 'MACRO',  // 96-char, also spelled 20 7A
    0x7B: 'DRCS'    // 96-char, also spelled 20 7B
  };

  // Intermediate byte of an ESC designation sequence -> which G-set it targets.
  var ESC_TO_GSET = {
    0x28: 'g0', 0x29: 'g1', 0x2A: 'g2', 0x2B: 'g3',
    0x2D: 'g1', 0x2E: 'g2', 0x2F: 'g3'
  };

  // ─── PDI Opcode Names ─────────────────────────────────────────────
  var PDI_NAMES = {
    0x20: 'RESET',
    0x21: 'DOMAIN',
    0x22: 'TEXT',
    0x23: 'TEXTURE',
    0x24: 'POINT_SET_ABS',
    0x25: 'POINT_SET_REL',
    0x26: 'POINT_ABS',
    0x27: 'POINT_REL',
    0x28: 'LINE_ABS',
    0x29: 'LINE_REL',
    0x2A: 'SET_LINE_ABS',
    0x2B: 'SET_LINE_REL',
    0x2C: 'ARC_OUTLINED',
    0x2D: 'ARC_FILLED',
    0x2E: 'SET_ARC_OUTLINED',
    0x2F: 'SET_ARC_FILLED',
    0x30: 'RECT_OUTLINED',
    0x31: 'RECT_FILLED',
    0x32: 'SET_RECT_OUTLINED',
    0x33: 'SET_RECT_FILLED',
    0x34: 'POLY_OUTLINED',
    0x35: 'POLY_FILLED',
    0x36: 'SET_POLY_OUTLINED',
    0x37: 'SET_POLY_FILLED',
    0x38: 'FIELD',
    0x39: 'INC_POINT',
    0x3A: 'INC_LINE',
    0x3B: 'INC_POLY_FILLED',
    0x3C: 'SET_COLOR',
    0x3D: 'WAIT',
    0x3E: 'SELECT_COLOR',
    0x3F: 'BLINK'
  };

  // ─── Decoder ──────────────────────────────────────────────────────

  function createDefaultState() {
    return {
      drawingPoint: { x: 0, y: TOP_ROW_Y },
      // The text cursor normally moves with the drawing point, but FIELD parts
      // them: the drawing point goes to the field's origin while text starts at
      // its top edge.  syncedDrawing records where they last agreed.
      textCursor: { x: 0, y: TOP_ROW_Y },
      syncedDrawing: { x: 0, y: TOP_ROW_Y },
      colorMode: 0,
      drawingColor: { r: 1, g: 1, b: 1 }, // nominal white
      bgColor: { r: 0, g: 0, b: 0 },      // nominal black
      palette: buildDefaultPalette(PALETTE_SIZE),
      paletteIndex: NOMINAL_WHITE,
      domain: {
        multiBytes: 3,
        singleBytes: 1,
        dimensions: 2
      },
      pelSize: { w: 0, h: 0 },
      // The active field: where text flows.  Defaults to the whole unit screen.
      field: { left: 0, right: 1, bottom: 0, top: UNIT_SCREEN_HEIGHT },
      autoWrapped: false, // an automatic wrap just happened; swallow a CR LF
      texture: {
        fill: 0,       // 0=solid, 1=vertical, 2=horizontal, 3=cross, 4-7=mask A-D
        outline: false,
        line: 0        // 0=solid, 1=dotted, 2=dashed, 3=dot-dash
      },
      maskSize: { w: DEFAULT_CHAR_WIDTH, h: DEFAULT_CHAR_HEIGHT },
      textState: defaultTextState(),
      glSet: 'G0',     // which G-set is invoked into GL
      grSet: 'G1',     // which G-set is invoked into GR (8-bit mode)
      macros: {},
      drcs: {},          // character code -> stored NAPLPS program
      textureMasks: {},  // 0-3 (masks A-D) -> stored NAPLPS program
      drcsCache: {},     // decoded form of the above, built on first use
      maskCache: {},
      drcsEnv: {},       // environment each definition was received in
      maskEnv: {},
      pendingDef: null,  // definition block currently being captured
      macroDepth: 0,
      // G-set assignments
      g0: 'ASCII',
      g1: 'PDI',
      g2: 'SUPP',
      g3: 'MOSAIC',
      // Single-shift flag
      singleShift: null
    };
  }

  // Decode a NAPLPS byte stream into a command array.
  // `inherit` carries the macro, DRCS and pattern-mask tables into a nested
  // decode, so a stored definition can use the ones defined before it.
  function decode(inputData, inherit) {
    var data;
    if (inputData instanceof Uint8Array) {
      data = inputData;
    } else if (Array.isArray(inputData)) {
      data = inputData;
    } else if (typeof inputData === 'string') {
      data = [];
      for (var i = 0; i < inputData.length; i++) {
        data.push(inputData.charCodeAt(i) & 0xFF);
      }
    } else {
      data = new Uint8Array(inputData);
    }

    var state = createDefaultState();
    // Publish the starting palette so a renderer can resolve palette indices
    // without duplicating the default-palette algorithm.
    function pushPalette() {
      commands.push({ type: 'palette', colors: state.palette.map(function (c) {
        return { r: c.r, g: c.g, b: c.b };
      }) });
    }

    if (inherit) {
      state.macros = inherit.macros || state.macros;
      state.drcs = inherit.drcs || state.drcs;
      state.textureMasks = inherit.textureMasks || state.textureMasks;
      if (inherit.env) applyEnv(state, inherit.env);
    }
    var commands = [];
    var pos = 0;
    var naplpsMode = false;

    // Which character set currently occupies a G-set slot ('G0'..'G3').
    function gsetContents(slot) {
      switch (slot) {
        case 'G0': return state.g0;
        case 'G1': return state.g1;
        case 'G2': return state.g2;
        case 'G3': return state.g3;
        default: return state.g0;
      }
    }

    // On-screen size of the character field, after rotation.  Rotations of 90
    // and 270 degrees swap the field's width and height as seen on screen.
    function fieldExtent() {
      var t = state.textState;
      var upright = (t.rotation === 0 || t.rotation === 2);
      return {
        x: Math.abs(upright ? t.charWidth : t.charHeight),
        y: Math.abs(upright ? t.charHeight : t.charWidth)
      };
    }

    // The text cursor.  Cursor and drawing point move together by default, so a
    // drawing primitive that has repositioned the drawing point since the last
    // character pulls the cursor along with it.
    function cursor() {
      if (state.drawingPoint.x !== state.syncedDrawing.x ||
        state.drawingPoint.y !== state.syncedDrawing.y) {
        state.textCursor = { x: state.drawingPoint.x, y: state.drawingPoint.y };
        state.syncedDrawing = { x: state.drawingPoint.x, y: state.drawingPoint.y };
      }
      return state.textCursor;
    }

    // Push the text cursor back onto the drawing point.
    function commitCursor() {
      state.drawingPoint = { x: state.textCursor.x, y: state.textCursor.y };
      state.syncedDrawing = { x: state.textCursor.x, y: state.textCursor.y };
    }

    // Distance the cursor travels per character.  The spec measures this
    // parallel to the character path, using whichever field dimension lies
    // along the path once the field's rotation has been applied.
    //
    // `code` and `setName` are only needed for proportional spacing; without
    // them the fixed advance is returned, which is what <tab> and <backspace>
    // use since they always count as the widest class.
    function charAdvance(code, setName) {
      var t = state.textState;
      var extent = fieldExtent();
      var alongX = (t.path === 0 || t.path === 1);
      var along = alongX ? extent.x : extent.y;

      if (t.spacing !== PROPORTIONAL) return along * CHAR_SPACING[t.spacing];

      // Proportional spacing needs the field's width axis to run along the
      // path.  When it does not, the spec falls back to the full field height.
      var widthIsUpright = (t.rotation === 0 || t.rotation === 2);
      if (widthIsUpright !== alongX) return Math.abs(t.charHeight);

      // Mosaics are never proportionally spaced.
      if (code === undefined || setName === 'MOSAIC' || setName === 'DRCS') return along;

      return proportionalAdvance(Math.abs(t.charWidth), code, setName);
    }

    // Move the cursor one character along the character path.  If the next
    // character field would fall outside the active field, the spec calls for an
    // automatic carriage return and line feed.
    function advanceCursor(code, setName) {
      var d = charAdvance(code, setName);
      var c = cursor();
      switch (state.textState.path) {
        case 0: c.x += d; break; // right
        case 1: c.x -= d; break; // left
        case 2: c.y += d; break; // up
        case 3: c.y -= d; break; // down
      }

      if (fieldOverflows()) {
        carriageReturn();
        nextRow(1);
        // An explicit CR LF arriving right after an automatic wrap is dropped so
        // that the line only advances once.
        state.autoWrapped = true;
      } else {
        state.autoWrapped = false;
      }
      commitCursor();
    }

    // Whether the character field at the cursor sticks out of the active field.
    function fieldOverflows() {
      var e = fieldExtent();
      var p = state.textCursor;
      var f = state.field;
      // Compare with a small tolerance so a field that divides exactly into
      // character cells does not wrap one character early.
      var slack = 1e-9;
      switch (state.textState.path) {
        case 0: return p.x + e.x > f.right + slack;
        case 1: return p.x - e.x < f.left - slack;
        case 2: return p.y + e.y > f.top + slack;
        default: return p.y - e.y < f.bottom - slack;
      }
    }

    // Return the cursor to the start of the current row.
    function carriageReturn() {
      var c = cursor();
      if (state.textState.path === 0 || state.textState.path === 1) {
        c.x = (state.textState.path === 0) ? state.field.left : state.field.right;
      } else {
        c.y = (state.textState.path === 2) ? state.field.bottom : state.field.top - fieldExtent().y;
      }
      commitCursor();
    }

    // Move the cursor one character backwards along the character path.
    function reverseCursor() {
      var d = charAdvance();
      var c = cursor();
      switch (state.textState.path) {
        case 0: c.x -= d; break;
        case 1: c.x += d; break;
        case 2: c.y -= d; break;
        case 3: c.y += d; break;
      }
      commitCursor();
    }

    // Send the cursor to the start of the first row of the active field, which
    // defaults to the whole display area.
    function homeCursor() {
      state.textCursor = { x: state.field.left, y: state.field.top - fieldExtent().y };
      commitCursor();
    }

    // Move the cursor to the next row, perpendicular to the character path.
    function nextRow(dir) {
      var t = state.textState;
      var extent = fieldExtent();
      var alongX = (t.path === 0 || t.path === 1);
      var d = (alongX ? extent.y : extent.x) * ROW_SPACING[t.rowSpacing];
      var c = cursor();
      if (alongX) c.y -= dir * d;
      else c.x += dir * d;
      commitCursor();
    }

    // Emit one character of a graphic set at the cursor, then advance.
    function emitGraphicChar(setName, code) {
      var t = state.textState;
      var c = cursor();
      var cmd = {
        x: c.x,
        y: c.y,
        charWidth: t.charWidth,
        charHeight: t.charHeight,
        rotation: t.rotation,
        path: t.path,
        spacing: t.spacing,
        rowSpacing: t.rowSpacing,
        // How far the cursor moves for this character.  A renderer needs it to
        // size the glyph, since under proportional spacing it is narrower than
        // the character field.
        advance: charAdvance(code, setName)
      };
      // In color mode 2 the character field background is painted too.
      if (state.colorMode === 2) {
        cmd.bgR = state.bgColor.r;
        cmd.bgG = state.bgColor.g;
        cmd.bgB = state.bgColor.b;
      }

      if (setName === 'MOSAIC') {
        cmd.type = 'mosaic';
        cmd.code = code === 0x5F ? 0x7F : code; // 5F is an alias for 7F
        commands.push(cmd);
      } else if (setName === 'DRCS') {
        cmd.type = 'drcs';
        cmd.code = code;
        // The stored program is decoded once and rendered scaled into the
        // character field, so DRCS glyphs stay resolution independent.
        if (state.drcs[code]) {
          cmd.program = decodeDefinition(state.drcs[code], state.drcsCache, code, state.drcsEnv[code]);
        }
        commands.push(cmd);
      } else if (code !== 0x7F) { // DEL is not a graphic
        cmd.type = 'text';
        cmd.char = String.fromCharCode(code);
        cmd.set = setName;
        commands.push(cmd);
      }
      advanceCursor(code, setName);
    }

    // ─── Definition Blocks (DEF MACRO / DEF DRCS / DEF TEXTURE) ───
    // Each of these captures a stream of NAPLPS bytes that is replayed later
    // rather than drawn now.  Any of them terminates a definition already open,
    // as does END.

    // Close whatever definition is open and file the bytes it collected.
    function closeDefinition() {
      var def = state.pendingDef;
      if (!def) return;
      state.pendingDef = null;

      if (def.kind === 'macro') {
        state.macros[def.id] = def.bytes;
      } else if (def.kind === 'drcs') {
        // A definition with no body resets that character back to <space>.
        if (def.bytes.length) {
          state.drcs[def.id] = def.bytes;
          state.drcsEnv[def.id] = def.env;
        } else {
          delete state.drcs[def.id];
        }
        state.drcsCache = {};
      } else if (def.kind === 'texture') {
        if (def.bytes.length) {
          state.textureMasks[def.id] = def.bytes;
          state.maskEnv[def.id] = def.env;
        } else {
          delete state.textureMasks[def.id];
        }
        state.maskCache = {};
      }
      // The unit screen goes back to the display and the drawing point to 0,0.
      if (def.kind !== 'macro') state.drawingPoint = { x: 0, y: 0 };
    }

    function openDefinition(kind, id) {
      closeDefinition();
      // The captured stream is replayed later, but the spec says it takes effect
      // in the terminal's current state, so remember the environment it was
      // received in - which G-sets are invoked above all, since a pattern built
      // from mosaics would otherwise replay as ASCII.
      state.pendingDef = { kind: kind, id: id, bytes: [], env: snapshotEnv() };
    }

    // The parts of the environment a stored definition needs to replay faithfully.
    function snapshotEnv() {
      return {
        g0: state.g0, g1: state.g1, g2: state.g2, g3: state.g3,
        glSet: state.glSet, grSet: state.grSet,
        domain: { multiBytes: state.domain.multiBytes, singleBytes: state.domain.singleBytes, dimensions: state.domain.dimensions },
        textState: cloneTextState(state.textState),
        texture: { fill: state.texture.fill, outline: state.texture.outline, line: state.texture.line },
        maskSize: { w: state.maskSize.w, h: state.maskSize.h },
        pelSize: { w: state.pelSize.w, h: state.pelSize.h },
        colorMode: state.colorMode,
        paletteIndex: state.paletteIndex,
        palette: state.palette.map(function (c) { return { r: c.r, g: c.g, b: c.b }; }),
        drawingColor: { r: state.drawingColor.r, g: state.drawingColor.g, b: state.drawingColor.b },
        bgColor: { r: state.bgColor.r, g: state.bgColor.g, b: state.bgColor.b }
      };
    }

    // Read the byte that names what a DEF sequence is defining.
    function nextByte() {
      return pos < data.length ? data[pos] : -1;
    }

    function handleC1(code) {
      switch (code) {
        case 0x80: // DEF MACRO
        case 0x81: // DEFP MACRO
        case 0x82: // DEFT MACRO
          var macroId = nextByte();
          if (macroId >= 0x20 && macroId <= 0x7F) {
            pos++;
            openDefinition('macro', macroId);
          } else {
            closeDefinition();
          }
          break;

        case 0x83: // DEF DRCS
          var drcsId = nextByte();
          if (drcsId >= 0x20 && drcsId <= 0x7F) {
            pos++;
          } else if (state.pendingDef && state.pendingDef.kind === 'drcs') {
            // Chained definitions omit the code: it steps on from the previous
            // one, wrapping 7F back round to 20.
            drcsId = state.pendingDef.id >= 0x7F ? 0x20 : state.pendingDef.id + 1;
          } else {
            closeDefinition();
            break;
          }
          openDefinition('drcs', drcsId);
          break;

        case 0x84: // DEF TEXTURE - 41 to 44 select mask A to D
          var mask = nextByte();
          if (mask >= 0x41 && mask <= 0x44) {
            pos++;
            openDefinition('texture', mask - 0x41);
          } else {
            closeDefinition();
          }
          break;

        case 0x85: // END
          closeDefinition();
          break;

        case 0x9F: // UNPROTECT - no visual effect here
          break;
      }
    }

    // Decode a stored definition into commands, caching the result.  DRCS
    // characters and pattern masks are stored as NAPLPS programs and rendered
    // when used, which keeps them scalable instead of baking them into a bitmap.
    function decodeDefinition(bytes, cache, key, env) {
      if (cache[key]) return cache[key];
      // Seed the cache first: a definition that refers to itself then resolves
      // to an empty program instead of recursing forever.
      cache[key] = [];
      cache[key] = decode(bytes, {
        macros: state.macros,
        drcs: state.drcs,
        textureMasks: state.textureMasks,
        env: env
      }).commands;
      return cache[key];
    }

    // Run a macro's byte string through the decoder.  Macros may invoke other
    // macros, so guard against a definition that calls itself.
    function expandMacro(code) {
      var body = state.macros[code];
      if (!body || state.macroDepth >= MAX_MACRO_DEPTH) return;
      state.macroDepth++;
      var saved = data, savedPos = pos;
      data = body;
      pos = 0;
      runDecodeLoop();
      data = saved;
      pos = savedPos;
      state.macroDepth--;
    }

    // Non-Selective Reset: return the whole environment to its default state.
    function resetToDefaults() {
      state.glSet = 'G0';
      state.grSet = 'G1';
      state.g0 = 'ASCII';
      state.g1 = 'PDI';
      state.g2 = 'SUPP';
      state.g3 = 'MOSAIC';
      state.domain = { multiBytes: 3, singleBytes: 1, dimensions: 2 };
      state.pelSize = { w: 0, h: 0 };
      state.field = { left: 0, right: 1, bottom: 0, top: UNIT_SCREEN_HEIGHT };
      state.autoWrapped = false;
      state.texture = { fill: 0, outline: false, line: 0 };
      state.maskSize = { w: DEFAULT_CHAR_WIDTH, h: DEFAULT_CHAR_HEIGHT };
      state.textState = defaultTextState();
      state.colorMode = 0;
      state.palette = buildDefaultPalette(PALETTE_SIZE);
      state.paletteIndex = NOMINAL_WHITE;
      state.drawingColor = { r: 1, g: 1, b: 1 };
      state.bgColor = { r: 0, g: 0, b: 0 };
      state.drawingPoint = { x: 0, y: TOP_ROW_Y };
      state.textCursor = { x: 0, y: TOP_ROW_Y };
      state.syncedDrawing = { x: 0, y: TOP_ROW_Y };
      state.macros = {};
      state.drcs = {};
      state.textureMasks = {};
      state.drcsCache = {};
      state.maskCache = {};
      state.drcsEnv = {};
      state.maskEnv = {};
      state.singleShift = null;
    }

    function handlePDI(opcode, pos) {
      var collected = collectDataBytes(data, pos);
      var dataBytes = collected.bytes;
      var nextPos = collected.nextPos;
      var mb = state.domain.multiBytes;
      var sb = state.domain.singleBytes;

      switch (opcode) {
        case 0x20: // RESET
          handleReset(dataBytes);
          break;

        case 0x21: // DOMAIN
          handleDomain(dataBytes);
          break;

        case 0x22: // TEXT
          handleText(dataBytes);
          break;

        case 0x23: // TEXTURE
          handleTexture(dataBytes);
          break;

        case 0x24: // POINT SET ABS
        case 0x25: // POINT SET REL
        case 0x26: // POINT ABS
        case 0x27: // POINT REL
          handlePoint(opcode, dataBytes, mb);
          break;

        case 0x28: // LINE ABS
        case 0x29: // LINE REL
        case 0x2A: // SET & LINE ABS
        case 0x2B: // SET & LINE REL
          handleLine(opcode, dataBytes, mb);
          break;

        case 0x2C: // ARC OUTLINED
        case 0x2D: // ARC FILLED
        case 0x2E: // SET & ARC OUTLINED
        case 0x2F: // SET & ARC FILLED
          handleArc(opcode, dataBytes, mb);
          break;

        case 0x30: // RECT OUTLINED
        case 0x31: // RECT FILLED
        case 0x32: // SET & RECT OUTLINED
        case 0x33: // SET & RECT FILLED
          handleRect(opcode, dataBytes, mb);
          break;

        case 0x34: // POLY OUTLINED
        case 0x35: // POLY FILLED
        case 0x36: // SET & POLY OUTLINED
        case 0x37: // SET & POLY FILLED
          handlePolygon(opcode, dataBytes, mb);
          break;

        case 0x38: // FIELD
          handleField(dataBytes, mb);
          break;

        case 0x39: // INC POINT
          handleIncPoint(dataBytes);
          break;

        case 0x3A: // INC LINE
          handleIncLine(dataBytes, mb);
          break;

        case 0x3B: // INC POLY FILLED
          handleIncPolyFilled(dataBytes, mb);
          break;

        case 0x3C: // SET COLOR
          handleSetColor(dataBytes, mb);
          break;

        case 0x3D: // WAIT
          handleWait(dataBytes);
          break;

        case 0x3E: // SELECT COLOR
          handleSelectColor(dataBytes, sb);
          break;

        case 0x3F: // BLINK
          handleBlink(dataBytes, sb);
          break;
      }

      return nextPos;
    }

    // RESET (20).  Two fixed-format bytes select which parts of the environment
    // are reset; the spec fixes the order as DOMAIN, COLOR, SCREEN, TEXT,
    // BLINK, FIELDS, TEXTURE, MACRO, DRCS.
    function handleReset(dataBytes) {
      var byte1 = dataBytes.length > 0 ? (dataBytes[0] & 0x3F) : 0;
      var byte2 = dataBytes.length > 1 ? (dataBytes[1] & 0x3F) : 0;

      // DOMAIN - bit 1 of the first byte
      if (byte1 & 0x01) {
        state.domain = { multiBytes: 3, singleBytes: 1, dimensions: 2 };
        state.pelSize = { w: 0, h: 0 };
        commands.push({ type: 'domain', multiBytes: 3, singleBytes: 1 });
        commands.push({ type: 'pelSize', w: 0, h: 0 });
      }

      // COLOR - bits 3 and 2 of the first byte
      switch ((byte1 >> 1) & 0x03) {
        case 0: // nothing
          break;
        case 1: // color mode 0, default palette, drawing color white
          state.palette = buildDefaultPalette(PALETTE_SIZE);
          state.colorMode = 0;
          state.drawingColor = { r: 1, g: 1, b: 1 };
          state.paletteIndex = NOMINAL_WHITE;
          pushPalette();
          commands.push({ type: 'selectColor', mode: 0 });
          break;
        case 2: // keep the mode (but mode 0 is treated as case 3)
          state.palette = buildDefaultPalette(PALETTE_SIZE);
          state.drawingColor = { r: 1, g: 1, b: 1 };
          state.paletteIndex = NOMINAL_WHITE;
          if (state.colorMode === 0) state.colorMode = 1;
          pushPalette();
          break;
        case 3: // color mode 1, default palette, drawing color white
          state.palette = buildDefaultPalette(PALETTE_SIZE);
          state.colorMode = 1;
          state.drawingColor = { r: 1, g: 1, b: 1 };
          state.paletteIndex = NOMINAL_WHITE;
          pushPalette();
          break;
      }

      // SCREEN - bits 6, 5 and 4 of the first byte.  Codes 3 and 4 touch only
      // the border, and must leave the screen contents alone.
      var black = { r: 0, g: 0, b: 0 };
      var draw = state.drawingColor;
      switch ((byte1 >> 3) & 0x07) {
        case 0: break;                                            // nothing
        case 1: pushScreenReset(black, null); break;              // screen -> black
        case 2: pushScreenReset(draw, null); break;               // screen -> drawing color
        case 3: pushScreenReset(null, black); break;              // border -> black
        case 4: pushScreenReset(null, draw); break;               // border -> drawing color
        case 5: pushScreenReset(draw, draw); break;               // both -> drawing color
        case 6: pushScreenReset(draw, black); break;              // screen -> drawing, border -> black
        case 7: pushScreenReset(black, black); break;             // both -> black
      }

      // TEXT - bit 1 of the second byte
      if (byte2 & 0x01) {
        state.textState = defaultTextState();
        homeCursor();
      }

      // BLINK - bit 2 of the second byte
      if ((byte2 >> 1) & 0x01) {
        commands.push({ type: 'blinkReset' });
      }

      // FIELDS - bit 3 of the second byte (no visual effect)

      // TEXTURE - bit 4 of the second byte.  Programmable masks are preserved.
      if ((byte2 >> 3) & 0x01) {
        state.texture = { fill: 0, outline: false, line: 0 };
        state.maskSize = { w: 1 / 40, h: 5 / 128 };
        commands.push({ type: 'texture', fill: 0, line: 0, outline: false });
      }

      // MACRO - bit 5 of the second byte
      if ((byte2 >> 4) & 0x01) {
        state.macros = {};
      }

      // DRCS - bit 6 of the second byte
      if ((byte2 >> 5) & 0x01) {
        state.drcs = {};
        state.drcsCache = {};
      }
    }

    // Emit a screen and/or border repaint.  Either may be null to leave it alone.
    function pushScreenReset(screen, border) {
      var cmd = { type: 'reset' };
      if (screen) {
        cmd.screen = 'color';
        cmd.r = screen.r; cmd.g = screen.g; cmd.b = screen.b;
      }
      if (border) {
        cmd.border = 'color';
        cmd.borderR = border.r; cmd.borderG = border.g; cmd.borderB = border.b;
      }
      commands.push(cmd);
    }

    function handleDomain(dataBytes) {
      if (dataBytes.length < 1) return;
      var ff = dataBytes[0] & 0x3F;

      var dims = (ff & 0x20) ? 3 : 2;
      var multiBytesCode = (ff >> 2) & 0x07;
      var multiBytes = multiBytesCode + 1;
      var singleBytesCode = ff & 0x03;
      var singleBytes = singleBytesCode + 1;

      state.domain.dimensions = dims;
      state.domain.multiBytes = multiBytes;
      state.domain.singleBytes = singleBytes;

      commands.push({ type: 'domain', multiBytes: multiBytes, singleBytes: singleBytes });

      // Remaining data bytes define pel size
      if (dataBytes.length > 1) {
        var pelData = dataBytes.slice(1);
        var coord = decodeCoordinate(pelData, multiBytes);
        // The sign is meaningful: it decides which corner of the logical pel
        // the drawing point sits at, so it must not be thrown away.
        state.pelSize = { w: coord.x, h: coord.y };
        commands.push({ type: 'pelSize', w: state.pelSize.w, h: state.pelSize.h });
      }
    }

    function handleText(dataBytes) {
      if (dataBytes.length < 1) return;
      var ff1 = dataBytes[0] & 0x3F;

      state.textState.spacing = (ff1 >> 4) & 0x03;
      state.textState.path = (ff1 >> 2) & 0x03;
      state.textState.rotation = ff1 & 0x03;

      if (dataBytes.length > 1) {
        var ff2 = dataBytes[1] & 0x3F;
        state.textState.cursorStyle = (ff2 >> 4) & 0x03;
        state.textState.cursorLink = (ff2 >> 2) & 0x03;
        state.textState.rowSpacing = ff2 & 0x03;
      }

      // Remaining bytes define character field size
      if (dataBytes.length > 2) {
        var charData = dataBytes.slice(2);
        var coord = decodeCoordinate(charData, state.domain.multiBytes);
        // A negative dimension mirrors the character about that axis, so the
        // sign is kept here too.
        if (coord.x !== 0) state.textState.charWidth = coord.x;
        if (coord.y !== 0) state.textState.charHeight = coord.y;
      }
    }

    // TEXTURE (23).  A fixed-format byte selects the fill pattern, whether
    // filled objects are outlined, and the line texture; an optional multi-value
    // operand gives the tile size used by the programmable masks.
    function handleTexture(dataBytes) {
      if (dataBytes.length < 1) return;
      var ff = dataBytes[0] & 0x3F;

      state.texture.fill = (ff >> 3) & 0x07;
      state.texture.outline = !!((ff >> 2) & 0x01);
      state.texture.line = ff & 0x03;

      // With no operand the mask size is left as it was.
      if (dataBytes.length > 1) {
        var size = decodeCoordinate(dataBytes.slice(1), state.domain.multiBytes);
        state.maskSize = { w: size.x, h: size.y };
      }

      var cmd = {
        type: 'texture',
        fill: state.texture.fill,
        outline: state.texture.outline,
        line: state.texture.line
      };
      // Fill patterns 4-7 are the programmable masks A-D.
      if (state.texture.fill >= 4) {
        var maskId = state.texture.fill - 4;
        if (state.textureMasks[maskId]) {
          cmd.maskProgram = decodeDefinition(state.textureMasks[maskId], state.maskCache, maskId, state.maskEnv[maskId]);
        }
        cmd.maskW = state.maskSize.w;
        cmd.maskH = state.maskSize.h;
      }
      commands.push(cmd);
    }

    function handlePoint(opcode, dataBytes, mb) {
      var isAbs = (opcode === 0x24 || opcode === 0x26);
      var isDraw = (opcode === 0x26 || opcode === 0x27);
      var operands = splitOperands(dataBytes, mb);

      for (var i = 0; i < operands.length; i++) {
        var coord = decodeCoordinate(operands[i], mb);
        var x, y;
        if (isAbs) {
          x = coord.x;
          y = coord.y;
        } else {
          var next = accumulateCoordinate(state.drawingPoint, coord);
          x = next.x;
          y = next.y;
        }
        state.drawingPoint = { x: x, y: y };
        if (isDraw) {
          commands.push({ type: 'point', x: x, y: y, draw: true });
        } else {
          commands.push({ type: 'point', x: x, y: y, draw: false });
        }
      }
    }

    function handleLine(opcode, dataBytes, mb) {
      var hasSet = (opcode === 0x2A || opcode === 0x2B);
      var isAbs = (opcode === 0x28 || opcode === 0x2A);
      var operands = splitOperands(dataBytes, mb);
      var idx = 0;

      if (hasSet && operands.length > 0) {
        var setCoord = decodeCoordinate(operands[0], mb);
        if (isAbs) {
          state.drawingPoint = { x: setCoord.x, y: setCoord.y };
        } else {
          state.drawingPoint = accumulateCoordinate(state.drawingPoint, setCoord);
        }
        commands.push({ type: 'point', x: state.drawingPoint.x, y: state.drawingPoint.y, draw: false });
        idx = 1;
      }

      for (var i = idx; i < operands.length; i++) {
        var coord = decodeCoordinate(operands[i], mb);
        var x1 = state.drawingPoint.x;
        var y1 = state.drawingPoint.y;
        var x2, y2;
        if (isAbs) {
          x2 = coord.x;
          y2 = coord.y;
        } else {
          var next = accumulateCoordinate(state.drawingPoint, coord);
          x2 = next.x;
          y2 = next.y;
        }
        commands.push({ type: 'line', x1: x1, y1: y1, x2: x2, y2: y2 });
        state.drawingPoint = { x: x2, y: y2 };
      }
    }

    // ARC (2C-2F).  An arc runs from the current drawing point through an
    // intermediate point to an end point.  With only an intermediate point the
    // end point is taken to equal the start and a circle is drawn, the
    // intermediate point giving the diameter.  More than three points describe
    // a curvilinear spline.
    function handleArc(opcode, dataBytes, mb) {
      var hasSet = (opcode === 0x2E || opcode === 0x2F);
      var isFilled = (opcode === 0x2D || opcode === 0x2F);
      var operands = splitOperands(dataBytes, mb);
      var idx = 0;

      if (hasSet && operands.length > 0) {
        var setCoord = decodeCoordinate(operands[0], mb);
        state.drawingPoint = { x: setCoord.x, y: setCoord.y };
        idx = 1;
      }

      var cx = state.drawingPoint.x;
      var cy = state.drawingPoint.y;
      var points = [{ x: cx, y: cy }];

      for (var i = idx; i < operands.length; i++) {
        var next = accumulateCoordinate({ x: cx, y: cy }, decodeCoordinate(operands[i], mb));
        cx = next.x;
        cy = next.y;
        points.push({ x: cx, y: cy });
      }

      if (points.length < 2) return;

      commands.push({ type: 'arc', points: points, filled: isFilled });

      // The drawing point ends at the end point; for a circle that is the start.
      state.drawingPoint = points.length === 2
        ? { x: points[0].x, y: points[0].y }
        : { x: cx, y: cy };
    }

    function handleRect(opcode, dataBytes, mb) {
      var hasSet = (opcode === 0x32 || opcode === 0x33);
      var isFilled = (opcode === 0x31 || opcode === 0x33);
      var operands = splitOperands(dataBytes, mb);
      var idx = 0;

      if (hasSet && operands.length > 0) {
        var setCoord = decodeCoordinate(operands[0], mb);
        state.drawingPoint = { x: setCoord.x, y: setCoord.y };
        commands.push({ type: 'point', x: state.drawingPoint.x, y: state.drawingPoint.y, draw: false });
        idx = 1;
      }

      for (var i = idx; i < operands.length; i++) {
        var coord = decodeCoordinate(operands[i], mb);
        var x = state.drawingPoint.x;
        var y = state.drawingPoint.y;
        var next = accumulateCoordinate(state.drawingPoint, coord);
        commands.push({
          type: 'rect',
          x: x, y: y,
          w: next.x - x, h: next.y - y,
          filled: isFilled
        });
        // After rect, drawing point moves by width only (for bar charts)
        state.drawingPoint.x = next.x;
      }
    }

    function handlePolygon(opcode, dataBytes, mb) {
      var hasSet = (opcode === 0x36 || opcode === 0x37);
      var isFilled = (opcode === 0x35 || opcode === 0x37);
      var operands = splitOperands(dataBytes, mb);
      var idx = 0;

      var startX = state.drawingPoint.x;
      var startY = state.drawingPoint.y;

      if (hasSet && operands.length > 0) {
        var setCoord = decodeCoordinate(operands[0], mb);
        startX = setCoord.x;
        startY = setCoord.y;
        state.drawingPoint = { x: startX, y: startY };
        idx = 1;
      }

      var points = [{ x: startX, y: startY }];
      var cx = startX, cy = startY;

      for (var i = idx; i < operands.length; i++) {
        var coord = decodeCoordinate(operands[i], mb);
        // Polygon uses displacements (relative)
        var next = accumulateCoordinate({ x: cx, y: cy }, coord);
        cx = next.x;
        cy = next.y;
        points.push({ x: cx, y: cy });
      }

      if (points.length > 1) {
        commands.push({
          type: 'polygon',
          points: points,
          filled: isFilled
        });
      }
      // Drawing point unchanged after polygon
    }

    // FIELD (38).  Defines the active field: the region text flows and scrolls
    // within, and that bitmap images are drawn into.  The first operand is an
    // absolute origin and the second the field's width and height, either of
    // which may be negative - as with the logical pel, the sign decides which
    // corner the origin sits in.
    function handleField(dataBytes, mb) {
      var operands = splitOperands(dataBytes, mb);
      var origin, size;

      if (operands.length === 0) {
        // No operands resets the field to the whole unit screen.
        origin = { x: 0, y: 0 };
        size = { x: 1, y: UNIT_SCREEN_HEIGHT };
      } else if (operands.length === 1) {
        // One operand gives the size; the drawing point is the origin.
        origin = { x: state.drawingPoint.x, y: state.drawingPoint.y };
        size = decodeCoordinate(operands[0], mb);
      } else {
        origin = decodeCoordinate(operands[0], mb);
        size = decodeCoordinate(operands[1], mb);
      }

      state.field = {
        left: Math.min(origin.x, origin.x + size.x),
        right: Math.max(origin.x, origin.x + size.x),
        bottom: Math.min(origin.y, origin.y + size.y),
        top: Math.max(origin.y, origin.y + size.y)
      };

      commands.push({
        type: 'field',
        x: origin.x, y: origin.y,
        w: size.x, h: size.y
      });

      // The drawing point moves to the field's origin, which is what the
      // bitmap PDIs draw from.  Text instead starts at the field's top edge; a
      // <linefeed> then steps down into the first character row.
      state.drawingPoint = { x: origin.x, y: origin.y };
      state.syncedDrawing = { x: origin.x, y: origin.y };
      state.textCursor = { x: state.field.left, y: state.field.top };
    }

    // INCREMENTAL POINT (39).  A bitmap: a fixed-format byte gives the number of
    // bits per pixel, and the rest is a bitstring of pixel values laid down one
    // logical pel at a time, left to right, wrapping within the active field.
    function handleIncPoint(dataBytes) {
      if (dataBytes.length < 1) return;
      var bitsPerPixel = dataBytes[0] & 0x3F;
      if (bitsPerPixel === 0 || bitsPerPixel > 48) return; // invalid: discard

      // A zero pel dimension becomes the smallest the current DOMAIN can express.
      var smallest = Math.pow(2, -(state.domain.multiBytes * 3 - 1));
      var pelW = state.pelSize.w || smallest;
      var pelH = state.pelSize.h || -smallest;

      var field = state.field;
      var start = { x: state.drawingPoint.x, y: state.drawingPoint.y };
      // The whole PDI is discarded if the first pel is not inside the field.
      if (start.x < field.left || start.x > field.right ||
        start.y < field.bottom || start.y > field.top) return;

      var bits = [];
      for (var i = 1; i < dataBytes.length; i++) {
        var d = dataBytes[i] & 0x3F;
        bits.push((d >> 5) & 1, (d >> 4) & 1, (d >> 3) & 1,
          (d >> 2) & 1, (d >> 1) & 1, d & 1);
      }

      var pixels = [];
      var x = start.x;
      var y = start.y;
      var bi = 0;

      while (bi + bitsPerPixel <= bits.length) {
        var value = bits.slice(bi, bi + bitsPerPixel);
        bi += bitsPerPixel;

        pixels.push({
          x: x,
          y: y,
          color: state.colorMode === 0
            ? colorFromBitstring(value)
            : null,
          index: state.colorMode === 0 ? null : bitsToInt(value)
        });

        x += pelW;
        // Overlapping the field boundary wraps to the opposite edge and steps a
        // row.  Any bits left in the current data byte are discarded first.
        var past = pelW >= 0 ? (x + pelW > field.right) : (x + pelW < field.left);
        if (past) {
          bi = Math.ceil(bi / 6) * 6;
          x = pelW >= 0 ? start.x : field.right;
          y += pelH;
          if (y > field.top || y < field.bottom) break; // no room to scroll
        }
      }

      if (pixels.length) {
        commands.push({
          type: 'incPoint',
          pelW: pelW,
          pelH: pelH,
          bitsPerPixel: bitsPerPixel,
          pixels: pixels
        });
      }

      // The drawing point returns to the field origin once the last pel is drawn.
      state.drawingPoint = { x: field.left, y: field.bottom };
    }

    // Interpret a bitstring as an unsigned integer, most significant bit first.
    function bitsToInt(bits) {
      var v = 0;
      for (var i = 0; i < bits.length; i++) v = v * 2 + bits[i];
      return v;
    }

    // In color mode 0 the bits of a pixel are packed GRBGRB..., so a packing
    // count that is not a multiple of three gives the primaries unequal
    // precision - which the spec explicitly allows.
    function colorFromBitstring(bits) {
      var channels = [[], [], []]; // G, R, B
      for (var i = 0; i < bits.length; i++) channels[i % 3].push(bits[i]);

      function fraction(b) {
        if (!b.length) return 0;
        var v = 0;
        for (var i = 0; i < b.length; i++) v += b[i] * Math.pow(2, -(i + 1));
        return v;
      }
      return { r: fraction(channels[1]), g: fraction(channels[0]), b: fraction(channels[2]) };
    }

    function handleIncLine(dataBytes, mb) {
      // Incremental line (scribble)
      if (dataBytes.length < mb) return;

      var stepBytes = dataBytes.slice(0, mb);
      var step = decodeCoordinate(stepBytes, mb);
      var dx = step.x;
      var dy = step.y;

      // Remaining bytes are bitstream of 2-bit opcodes
      var bitstream = [];
      for (var i = mb; i < dataBytes.length; i++) {
        var d = dataBytes[i] & 0x3F;
        bitstream.push((d >> 5) & 1, (d >> 4) & 1, (d >> 3) & 1,
          (d >> 2) & 1, (d >> 1) & 1, d & 1);
      }

      var drawFlag = true;
      var points = [{ x: state.drawingPoint.x, y: state.drawingPoint.y }];
      var cx = state.drawingPoint.x;
      var cy = state.drawingPoint.y;
      var segments = [];
      var bi = 0;

      while (bi + 1 < bitstream.length) {
        var op = (bitstream[bi] << 1) | bitstream[bi + 1];
        bi += 2;

        if (op === 0) {
          // Control opcode - next 2 bits
          if (bi + 1 >= bitstream.length) break;
          var subOp = (bitstream[bi] << 1) | bitstream[bi + 1];
          bi += 2;
          switch (subOp) {
            case 0: drawFlag = !drawFlag; break;
            case 1: dx = -dx; break;
            case 2: dy = -dy; break;
            case 3: dx = -dx; dy = -dy; break;
          }
        } else {
          var nx = cx, ny = cy;
          if (op === 1) { nx += dx; }
          else if (op === 2) { ny += dy; }
          else if (op === 3) { nx += dx; ny += dy; }

          if (drawFlag) {
            segments.push({ x1: cx, y1: cy, x2: nx, y2: ny });
          }
          cx = nx;
          cy = ny;
        }
      }

      if (segments.length > 0) {
        commands.push({ type: 'incLine', segments: segments });
      }
      state.drawingPoint = { x: cx, y: cy };
    }

    function handleIncPolyFilled(dataBytes, mb) {
      // Same as inc line but filled, draw flag always on
      if (dataBytes.length < mb) return;

      var stepBytes = dataBytes.slice(0, mb);
      var step = decodeCoordinate(stepBytes, mb);
      var dx = step.x;
      var dy = step.y;

      var bitstream = [];
      for (var i = mb; i < dataBytes.length; i++) {
        var d = dataBytes[i] & 0x3F;
        bitstream.push((d >> 5) & 1, (d >> 4) & 1, (d >> 3) & 1,
          (d >> 2) & 1, (d >> 1) & 1, d & 1);
      }

      var cx = state.drawingPoint.x;
      var cy = state.drawingPoint.y;
      var points = [{ x: cx, y: cy }];
      var bi = 0;

      while (bi + 1 < bitstream.length) {
        var op = (bitstream[bi] << 1) | bitstream[bi + 1];
        bi += 2;

        if (op === 0) {
          if (bi + 1 >= bitstream.length) break;
          var subOp = (bitstream[bi] << 1) | bitstream[bi + 1];
          bi += 2;
          switch (subOp) {
            case 0: break; // draw flag toggle ignored for filled
            case 1: dx = -dx; break;
            case 2: dy = -dy; break;
            case 3: dx = -dx; dy = -dy; break;
          }
        } else {
          if (op === 1) { cx += dx; }
          else if (op === 2) { cy += dy; }
          else if (op === 3) { cx += dx; cy += dy; }
          points.push({ x: cx, y: cy });
        }
      }

      if (points.length > 1) {
        commands.push({ type: 'polygon', points: points, filled: true });
      }
    }

    function handleSetColor(dataBytes, mb) {
      if (dataBytes.length === 0) {
        // Transparent color
        commands.push({ type: 'setColor', r: 0, g: 0, b: 0, transparent: true });
        return;
      }

      if (state.colorMode === 0) {
        // Direct RGB color - data is a multi-value GRB operand
        var operands = splitOperands(dataBytes, mb);
        for (var i = 0; i < operands.length; i++) {
          var color = decodeColor(operands[i]);
          state.drawingColor = color;

          // Find or assign a palette entry
          var foundIdx = -1;
          for (var j = 0; j < state.palette.length; j++) {
            var p = state.palette[j];
            if (Math.abs(p.r - color.r) < 0.01 &&
              Math.abs(p.g - color.g) < 0.01 &&
              Math.abs(p.b - color.b) < 0.01) {
              foundIdx = j;
              break;
            }
          }
          if (foundIdx >= 0) {
            state.paletteIndex = foundIdx;
          } else {
            // Assign to an unused entry
            if (state.paletteIndex < state.palette.length - 1) {
              state.paletteIndex++;
            }
            if (state.paletteIndex < state.palette.length) {
              state.palette[state.paletteIndex] = { r: color.r, g: color.g, b: color.b };
            }
          }

          commands.push({ type: 'setColor', r: color.r, g: color.g, b: color.b });
        }
      } else {
        // Mode 1 or 2: modify palette at current palette index
        var operands = splitOperands(dataBytes, mb);
        var palIdx = state.paletteIndex;
        for (var i = 0; i < operands.length; i++) {
          var color = decodeColor(operands[i]);
          if (palIdx < state.palette.length) {
            state.palette[palIdx] = { r: color.r, g: color.g, b: color.b };
          }
          commands.push({ type: 'setPalette', index: palIdx, r: color.r, g: color.g, b: color.b });
          // Increment palette index using the NAPLPS algorithm
          palIdx = incrementPaletteIndex(palIdx, state.palette.length);
        }
      }
    }

    function incrementPaletteIndex(idx, numEntries) {
      // NAPLPS palette increment: find the most significant zero bit,
      // set it to 1, and clear all bits to the left
      var bits = Math.ceil(Math.log2(numEntries)) || 4;
      for (var b = bits - 1; b >= 0; b--) {
        if (!(idx & (1 << b))) {
          idx |= (1 << b);
          // Clear all bits to the left
          for (var c = b + 1; c < bits; c++) {
            idx &= ~(1 << c);
          }
          return idx;
        }
      }
      return idx; // All ones - stop
    }

    // WAIT (3D).  A fixed-format byte of 1011100 confirms the command; the bytes
    // after it are wait intervals in tenths of a second which add together to
    // give the total pause.  Anything else after the PDI voids it.
    function handleWait(dataBytes) {
      if (dataBytes.length && (dataBytes[0] & 0x7F) !== WAIT_MARKER) return;
      var tenths = 0;
      for (var i = 1; i < dataBytes.length; i++) tenths += dataBytes[i] & 0x3F;
      commands.push({ type: 'wait', seconds: tenths / 10 });
    }

    function handleSelectColor(dataBytes, sb) {
      if (dataBytes.length === 0) {
        // Mode 0
        state.colorMode = 0;
        commands.push({ type: 'selectColor', mode: 0 });
        return;
      }

      var operands = splitOperands(dataBytes, sb);

      if (operands.length >= 2) {
        // Mode 2: fg + bg palette indices
        state.colorMode = 2;
        var fgIdx = decodeSingleValue(operands[0], sb);
        var bgIdx = decodeSingleValue(operands[1], sb);
        // Shift to get palette entry from MSBs
        var totalBits = sb * 6;
        var palBits = Math.ceil(Math.log2(state.palette.length)) || 4;
        fgIdx = fgIdx >> (totalBits - palBits);
        bgIdx = bgIdx >> (totalBits - palBits);

        if (fgIdx < state.palette.length) {
          state.paletteIndex = fgIdx;
          state.drawingColor = {
            r: state.palette[fgIdx].r,
            g: state.palette[fgIdx].g,
            b: state.palette[fgIdx].b
          };
        }
        if (bgIdx < state.palette.length) {
          state.bgColor = {
            r: state.palette[bgIdx].r,
            g: state.palette[bgIdx].g,
            b: state.palette[bgIdx].b
          };
        }
        commands.push({
          type: 'selectColor',
          mode: 2,
          index: fgIdx,
          bgIndex: bgIdx,
          r: state.drawingColor.r, g: state.drawingColor.g, b: state.drawingColor.b,
          bgR: state.bgColor.r, bgG: state.bgColor.g, bgB: state.bgColor.b
        });
      } else {
        // Mode 1: fg palette index only
        state.colorMode = 1;
        var fgIdx = decodeSingleValue(operands[0], sb);
        var totalBits = sb * 6;
        var palBits = Math.ceil(Math.log2(state.palette.length)) || 4;
        fgIdx = fgIdx >> (totalBits - palBits);

        if (fgIdx < state.palette.length) {
          state.paletteIndex = fgIdx;
          state.drawingColor = {
            r: state.palette[fgIdx].r,
            g: state.palette[fgIdx].g,
            b: state.palette[fgIdx].b
          };
        }
        commands.push({
          type: 'selectColor',
          mode: 1,
          index: fgIdx,
          r: state.drawingColor.r, g: state.drawingColor.g, b: state.drawingColor.b
        });
      }
    }

    // BLINK (3F).  Sets up palette animation: the blink-from entry (the current
    // drawing color) periodically takes on the contents of the blink-to entry.
    // A single value operand names the blink-to entry, then three fixed-format
    // bytes give the ON, OFF and START DELAY intervals in tenths of a second.
    function handleBlink(dataBytes, sb) {
      if (dataBytes.length === 0) {
        // No operands: stop every blink process driven by the drawing color.
        commands.push({ type: 'blink', stop: true, from: state.paletteIndex });
        return;
      }

      var from = state.paletteIndex;
      var pos = 0;
      while (pos + sb <= dataBytes.length) {
        var to = paletteIndexFromOperand(dataBytes.slice(pos, pos + sb), sb);
        pos += sb;

        var on = pos < dataBytes.length ? (dataBytes[pos++] & 0x3F) : 0;
        var off = pos < dataBytes.length ? (dataBytes[pos++] & 0x3F) : 0;
        var delay = pos < dataBytes.length ? (dataBytes[pos++] & 0x3F) : 0;

        commands.push({
          type: 'blink',
          from: from,
          to: to,
          // A zero ON or OFF interval terminates that blink process instead.
          stop: (on === 0 || off === 0),
          on: on / 10,
          off: off / 10,
          delay: delay / 10
        });

        // Trailing bytes start another blink implicitly, stepping the
        // blink-from entry with the same rule SET COLOR uses.
        if (pos >= dataBytes.length) break;
        from = incrementPaletteIndex(from, state.palette.length);
      }
    }

    // A single value operand names a palette entry in its most significant bits.
    function paletteIndexFromOperand(bytes, sb) {
      var total = sb * 6;
      var bits = Math.round(Math.log(state.palette.length) / Math.LN2) || 4;
      return decodeSingleValue(bytes, sb) >> (total - bits);
    }

    // ─── Main Decode Loop ─────────────────────────────────────────
    // Factored into a function so that macro expansion can re-enter it with a
    // different byte string (see expandMacro).
    function runDecodeLoop() {
    while (pos < data.length) {
      var b = data[pos];

      // Handle ESC sequences
      if (b === 0x1B) {
        pos++;
        if (pos >= data.length) break;
        var escByte = data[pos];

        // Check for NAPLPS init/term: ESC 25 41 / ESC 25 40
        if (escByte === 0x25) {
          pos++;
          if (pos < data.length) {
            if (data[pos] === 0x41) {
              naplpsMode = true;
              pos++;
            } else if (data[pos] === 0x40) {
              naplpsMode = false;
              pos++;
            } else {
              pos++;
            }
          }
          continue;
        }

        // C1 control codes in 7-bit mode: ESC 40-5F
        if (escByte >= 0x40 && escByte <= 0x5F) {
          pos++;
          handleC1(escByte + 0x40); // fold onto the 8-bit C1 range 80-9F
          continue;
        }

        // G-set designation: ESC 28-2B designates a 94-character set into
        // G0-G3, ESC 2D-2F a 96-character set into G1-G3.  29-2B are also
        // accepted for 96-character sets for backwards compatibility, so the
        // set is identified by the terminating byte rather than the intermediate.
        if (escByte >= 0x28 && escByte <= 0x2F) {
          pos++;
          var final = pos < data.length ? data[pos] : -1;
          // 20 is an extension prefix; 7A/7B are accepted bare as equivalents.
          if (final === 0x20 && pos + 1 < data.length) {
            pos++;
            final = data[pos];
          }
          var setName = G_SET_DESIGNATORS[final];
          if (setName) {
            var slot = ESC_TO_GSET[escByte];
            // ASCII cannot be designated anywhere but G0.
            if (slot && !(setName === 'ASCII' && slot !== 'g0')) {
              state[slot] = setName;
            }
          }
          pos++;
          continue;
        }

        // C0/C1 set designation (ESC 21 4B / ESC 22 46) - only two sets exist,
        // so there is nothing to track.
        if (escByte === 0x21 || escByte === 0x22) {
          pos++;
          if (pos < data.length) pos++;
          continue;
        }

        // GL locking shifts
        if (escByte === 0x6E) { state.glSet = 'G2'; pos++; continue; }
        if (escByte === 0x6F) { state.glSet = 'G3'; pos++; continue; }
        // GR locking shifts (8-bit mode).  6B/6C/6D are the legacy spellings.
        if (escByte === 0x7E || escByte === 0x6B) { state.grSet = 'G1'; pos++; continue; }
        if (escByte === 0x7D || escByte === 0x6C) { state.grSet = 'G2'; pos++; continue; }
        if (escByte === 0x7C || escByte === 0x6D) { state.grSet = 'G3'; pos++; continue; }

        // Unknown ESC sequence
        pos++;
        continue;
      }

      // While a DEF MACRO / DEF DRCS / DEF TEXTURE is open, bytes are captured
      // verbatim rather than executed.  ESC is handled above so that the C1
      // terminators are still recognised.
      if (state.pendingDef) {
        state.pendingDef.bytes.push(b);
        pos++;
        continue;
      }

      // C1 control codes in 8-bit mode
      if (b >= 0x80 && b <= 0x9F) {
        pos++;
        handleC1(b);
        continue;
      }

      // C0 control codes (00-1F)
      if (b < 0x20) {
        switch (b) {
          case 0x00: // NULL - ignore
          case 0x01: case 0x02: case 0x03: case 0x04:
          case 0x05: case 0x06: // Transmission control - ignore
          case 0x10: case 0x11: case 0x12: case 0x13:
          case 0x14: case 0x15: case 0x16: case 0x17: // Device control - ignore
            break;

          case 0x07: // BELL
            commands.push({ type: 'bell' });
            break;

          case 0x08: // BACKSPACE - one character against the path
            reverseCursor();
            break;

          case 0x09: // TAB - one character along the path
            advanceCursor();
            break;

          case 0x0A: // LINE FEED - next row
            if (state.autoWrapped) state.autoWrapped = false;
            else nextRow(1);
            break;

          case 0x0B: // VERTICAL TAB - previous row
            nextRow(-1);
            break;

          case 0x0C: // FORM FEED - clear the screen and home the cursor
            commands.push({ type: 'reset', screen: 'color', r: 0, g: 0, b: 0 });
            homeCursor();
            break;

          case 0x0D: // CARRIAGE RETURN - start of the current row
            if (!state.autoWrapped) carriageReturn();
            break;

          case 0x0E: // SHIFT OUT - invoke G1 into GL
            state.glSet = 'G1';
            break;

          case 0x0F: // SHIFT IN - invoke G0 into GL
            state.glSet = 'G0';
            break;

          case 0x18: // CANCEL
            break;

          case 0x19: // SS2 - single shift G2
            state.singleShift = 'G2';
            break;

          case 0x1A: // Service delimiter - ignore
            break;

          case 0x1C: // Cursor position
            pos++;
            if (pos + 1 < data.length) {
              var row = (data[pos] & 0x7F) - 32;
              var col = (data[pos + 1] & 0x7F) - 32;
              state.textCursor = {
                x: col * state.textState.charWidth,
                y: state.field.top - (row + 1) * fieldExtent().y
              };
              commitCursor();
              pos++;
            }
            break;

          case 0x1D: // SS3 - single shift G3
            state.singleShift = 'G3';
            break;

          case 0x1E: // HOME
            homeCursor();
            break;

          case 0x1F: // NSR - Non-Selective Reset
            resetToDefaults();
            commands.push({ type: 'nsr' });
            pushPalette();
            // Check for optional cursor position bytes
            if (pos + 2 < data.length && data[pos + 1] >= 0x40 && data[pos + 1] <= 0x7F
              && data[pos + 2] >= 0x40 && data[pos + 2] <= 0x7F) {
              var row = (data[pos + 1] & 0x3F);
              var col = (data[pos + 2] & 0x3F);
              state.textCursor = {
                x: col * state.textState.charWidth,
                y: state.field.top - (row + 1) * fieldExtent().y
              };
              commitCursor();
              pos += 2;
            }
            break;
        }
        pos++;
        continue;
      }

      // Resolve which G-set this byte should be interpreted through.  Bytes in
      // GL (20-7F) use the set invoked into GL; bytes in GR (A0-FF) use GR.
      var activeSet, code;
      if (b >= 0xA0) {
        activeSet = gsetContents(state.grSet);
        code = b & 0x7F;
      } else {
        activeSet = gsetContents(state.glSet);
        code = b;
        // A single shift borrows G2/G3 for exactly one character.
        if (state.singleShift) {
          activeSet = gsetContents(state.singleShift);
          state.singleShift = null;
        }
      }

      if (activeSet === 'PDI') {
        if (code >= 0x20 && code <= 0x3F) {
          pos++;
          pos = handlePDI(code, pos);
          continue;
        }
        // A data byte with no preceding opcode has nothing to apply to.
        pos++;
        continue;
      }

      if (activeSet === 'MACRO') {
        pos++;
        expandMacro(code);
        continue;
      }

      // ASCII, supplementary, mosaic and DRCS all render into the character field.
      if (code >= 0x20 && code <= 0x7F) {
        emitGraphicChar(activeSet, code);
      }
      pos++;
    }
  }

  pushPalette();
    runDecodeLoop();
    closeDefinition(); // file a definition left open by a truncated stream
    return { commands: commands, state: state };
  }

  // ─── Encoder (Basic) ──────────────────────────────────────────────

  // Inverse of decodeCoordinate: encode a signed unit-screen coordinate pair as
  // an interleaved multi-value operand.
  function encodeCoordinate(x, y, numBytes) {
    var totalBits = numBytes * 3;
    var xBits = signedFractionToBits(x, totalBits);
    var yBits = signedFractionToBits(y, totalBits);

    var bytes = [];
    for (var i = 0; i < numBytes; i++) {
      var j = i * 3;
      // Bit 6 is always set so the byte stays in the printable data range.
      bytes.push(0x40 |
        (xBits[j] << 5) | (xBits[j + 1] << 4) | (xBits[j + 2] << 3) |
        (yBits[j] << 2) | (yBits[j + 1] << 1) | yBits[j + 2]);
    }
    return bytes;
  }

  // An unsigned integer as a bit array, most significant bit first.
  function intToBits(value, count) {
    var bits = new Array(count);
    for (var i = count - 1; i >= 0; i--) {
      bits[i] = value & 1;
      value = Math.floor(value / 2);
    }
    return bits;
  }

  // Inverse of the decoder's colorFromBitstring: pack a colour into `count`
  // bits laid out GRBGRB..., so a count that is not a multiple of three gives
  // the primaries unequal precision.
  function colorToBitstring(color, count) {
    var lengths = [0, 0, 0];
    for (var i = 0; i < count; i++) lengths[i % 3]++;
    var channels = [
      fractionToBits(color.g, lengths[0]),
      fractionToBits(color.r, lengths[1]),
      fractionToBits(color.b, lengths[2])
    ];
    var taken = [0, 0, 0];
    var bits = [];
    for (var j = 0; j < count; j++) {
      var c = j % 3;
      bits.push(channels[c][taken[c]++]);
    }
    return bits;
  }

  // A fraction in [0, 1) as a binary fraction, most significant bit first.
  function fractionToBits(value, count) {
    var bits = [];
    var remainder = value;
    for (var i = 0; i < count; i++) {
      var threshold = Math.pow(2, -(i + 1));
      if (remainder >= threshold) { bits.push(1); remainder -= threshold; }
      else bits.push(0);
    }
    return bits;
  }

  // Represent a fraction in [-1, 1) as a two's-complement bit array, MSB first.
  function signedFractionToBits(value, totalBits) {
    var half = Math.pow(2, totalBits - 1);
    var n = Math.round(value * half);
    // Clamp to the representable range rather than letting it wrap around.
    if (n > half - 1) n = half - 1;
    if (n < -half) n = -half;
    if (n < 0) n += half * 2;

    var bits = new Array(totalBits);
    for (var i = totalBits - 1; i >= 0; i--) {
      bits[i] = n & 1;
      n = Math.floor(n / 2);
    }
    return bits;
  }

  function encodeColor(r, g, b, numBytes) {
    var bytes = [];
    // Convert r, g, b (0-1) to interleaved GRB bits
    var gBits = [], rBits = [], bBits = [];
    for (var i = 0; i < numBytes * 2; i++) {
      var threshold = Math.pow(2, -(i + 1));
      gBits.push(g >= threshold ? 1 : 0);
      if (g >= threshold) g -= threshold;
      rBits.push(r >= threshold ? 1 : 0);
      if (r >= threshold) r -= threshold;
      bBits.push(b >= threshold ? 1 : 0);
      if (b >= threshold) b -= threshold;
    }

    for (var i = 0; i < numBytes; i++) {
      var gi = i * 2, ri = i * 2, bi = i * 2;
      var byte = 0x40;
      byte |= (gBits[gi] << 5) | (rBits[ri] << 4) | (bBits[bi] << 3);
      byte |= (gBits[gi + 1] << 2) | (rBits[ri + 1] << 1) | bBits[bi + 1];
      bytes.push(byte);
    }
    return bytes;
  }

  // ─── Encoder ──────────────────────────────────────────────────────

  // Serialise a command array back into a NAPLPS byte stream.  The encoder
  // tracks enough of the environment (operand sizes, which G-set is invoked,
  // where the text cursor is) to avoid re-sending state that has not changed.
  function encode(commands) {
    var out = [];
    var mb = 3;          // multi-value operand size
    var sb = 1;          // single-value operand size
    var gl = null;       // which set is currently invoked into GL
    // The decoder starts with these, so a TEXT PDI is only needed when an image
    // actually departs from them.  Re-sending the defaults would round 1/40 and
    // 5/128 onto the operand grid and shift the whole character pitch.
    // qw/qh are the field dimensions the decoder will actually be using, which
    // is what the cursor advances by.
    var text = {
      w: DEFAULT_CHAR_WIDTH, h: DEFAULT_CHAR_HEIGHT, rotation: 0, path: 0,
      spacing: 0, rowSpacing: 0,
      qw: DEFAULT_CHAR_WIDTH, qh: DEFAULT_CHAR_HEIGHT
    };
    // The decoder keeps a drawing point and a text cursor that normally move
    // together but are parted by FIELD, and it wraps text against the active
    // field.  All three have to be modelled here or the positions this encoder
    // predicts drift from the ones the decoder will compute.
    var cursor = null;                // the decoder's drawing point
    var textCursor = null;            // the decoder's text cursor
    var syncedDraw = null;            // where the two last agreed
    var field = { left: 0, right: 1, bottom: 0, top: UNIT_SCREEN_HEIGHT };
    var paletteIndex = NOMINAL_WHITE; // the entry SELECT COLOR last chose
    var colorMode = 0;

    function emit(bytes) {
      for (var i = 0; i < bytes.length; i++) out.push(bytes[i]);
    }

    // Invoke a G-set into GL, if it is not already there.
    function useSet(name) {
      if (gl === name) return;
      if (name === 'PDI') out.push(0x0E);        // SO
      else if (name === 'ASCII') out.push(0x0F); // SI
      else if (name === 'MOSAIC') out.push(0x1B, 0x6F); // ESC 6F selects G3
      else if (name === 'DRCS') {
        // Designate DRCS into G2, then invoke G2 into GL.
        out.push(0x1B, 0x2E, 0x20, 0x7B);
        out.push(0x1B, 0x6E);
      }
      gl = name;
    }

    function pdi(opcode) {
      useSet('PDI');
      out.push(opcode);
    }

    function coord(x, y) {
      emit(encodeCoordinate(x, y, mb));
    }

    // Emit a displacement and advance the tracked cursor by the value the
    // decoder will actually read back.  Following the quantised position rather
    // than the ideal one keeps rounding error from accumulating along a run of
    // relative coordinates.
    function step(dx, dy) {
      var bytes = encodeCoordinate(dx, dy, mb);
      emit(bytes);
      var actual = decodeCoordinate(bytes, mb);
      cursor = { x: cursor.x + actual.x, y: cursor.y + actual.y };
    }

    // Single-value operands carry the value in their most significant bits.
    function single(value, bits) {
      var total = sb * 6;
      var v = (value << (total - bits)) >>> 0;
      var bytes = [];
      for (var i = sb - 1; i >= 0; i--) bytes.push(0x40 | ((v >> (i * 6)) & 0x3F));
      emit(bytes);
    }

    // The text cursor, following the drawing point if a primitive has moved it.
    function textAt() {
      if (cursor.x !== syncedDraw.x || cursor.y !== syncedDraw.y) {
        textCursor = { x: cursor.x, y: cursor.y };
        syncedDraw = { x: cursor.x, y: cursor.y };
      }
      return textCursor;
    }

    // Both cursors end up at the drawing point after any explicit move.
    function commit() {
      textCursor = { x: cursor.x, y: cursor.y };
      syncedDraw = { x: cursor.x, y: cursor.y };
    }

    // Move the drawing point, but only when it is not already there.  The move
    // is relative: an operand only spans [-1, 1), so a drawing point that has
    // walked off the unit screen cannot be restated in absolute form.
    function moveTo(x, y) {
      if (cursor && Math.abs(cursor.x - x) < 1e-9 && Math.abs(cursor.y - y) < 1e-9) {
        commit();
        return;
      }
      pdi(0x25); // POINT SET REL
      stepFar(x, y);
      commit();
    }

    // Put the text cursor somewhere.  POINT SET REL is relative to the drawing
    // point, and moving it drags the text cursor along, so nothing is emitted
    // when the text cursor is already in the right place.
    function moveTextTo(x, y) {
      var t = textAt();
      if (Math.abs(t.x - x) < 1e-9 && Math.abs(t.y - y) < 1e-9) return;
      pdi(0x25); // POINT SET REL
      stepFar(x, y);
      commit();
    }

    // Walk to a target that may be more than one operand away.  A multi-value
    // operand spans [-1, 1), so a longer move is emitted as repeated
    // displacements - POINT SET REL applies every operand it is given.
    function stepFar(x, y) {
      for (var guard = 0; guard < 64; guard++) {
        step(clampStep(x - cursor.x), clampStep(y - cursor.y));
        if (Math.abs(cursor.x - x) < 1e-9 && Math.abs(cursor.y - y) < 1e-9) return;
      }
    }

    // Largest displacement representable in one operand, less one quantum so
    // that rounding cannot push it over the top of the range.
    function clampStep(d) {
      var limit = 1 - Math.pow(2, -(mb * 3 - 1));
      return Math.max(-limit, Math.min(limit, d));
    }

    // Make a palette entry the current drawing color, if it is not already.
    function selectPaletteEntry(index) {
      if (index === undefined || paletteIndex === index) return;
      pdi(0x3E);
      single(index, PALETTE_BITS);
      paletteIndex = index;
      colorMode = 1;
    }

    // Blink intervals are tenths of a second in six bits: 0 to 6.3 seconds.
    function clampInterval(seconds) {
      return Math.max(0, Math.min(0x3F, Math.round((seconds || 0) * 10)));
    }

    // Re-send the TEXT PDI when any character attribute changes.
    function syncText(cmd) {
      var want = {
        w: cmd.charWidth, h: cmd.charHeight,
        rotation: cmd.rotation || 0, path: cmd.path || 0,
        spacing: cmd.spacing || 0, rowSpacing: cmd.rowSpacing || 0
      };
      if (text && text.w === want.w && text.h === want.h &&
        text.rotation === want.rotation && text.path === want.path &&
        text.spacing === want.spacing && text.rowSpacing === want.rowSpacing) return;
      pdi(0x22); // TEXT
      // First byte: bits 6-5 intercharacter spacing, 4-3 path, 2-1 rotation.
      out.push(0x40 | ((want.spacing & 0x03) << 4) |
        ((want.path & 0x03) << 2) | (want.rotation & 0x03));
      // Second byte: bits 2-1 interrow spacing.
      out.push(0x40 | (want.rowSpacing & 0x03));
      var bytes = encodeCoordinate(want.w, want.h, mb);
      emit(bytes);
      // The field size lands on the operand grid, and the cursor will advance by
      // the rounded value, so remember that rather than what we were asked for.
      var q = decodeCoordinate(bytes, mb);
      want.qw = q.x;
      want.qh = q.y;
      text = want;
    }

    // Advance the tracked cursor the way the decoder will after a character,
    // using the character field size the decoder actually holds.  This has to
    // include the automatic wrap at the edge of the active field, or the next
    // character's position would be predicted wrongly and no corrective move
    // emitted.  The re-decoded stream carries no FIELD PDI, so the field is the
    // whole unit screen.
    function advanceCursor(cmd) {
      var upright = ((cmd.rotation || 0) % 2) === 0;
      var ex = Math.abs(upright ? text.qw : text.qh);
      var ey = Math.abs(upright ? text.qh : text.qw);
      var path = cmd.path || 0;
      var advance = cmd.advance === undefined ? ex : Math.abs(cmd.advance);

      textCursor = { x: textCursor.x, y: textCursor.y };
      switch (path) {
        case 0: textCursor.x += advance; break;
        case 1: textCursor.x -= advance; break;
        case 2: textCursor.y += advance; break;
        case 3: textCursor.y -= advance; break;
      }
      cursor = { x: textCursor.x, y: textCursor.y };
      syncedDraw = { x: textCursor.x, y: textCursor.y };

      var slack = 1e-9;
      var overflow =
        path === 0 ? textCursor.x + ex > field.right + slack :
        path === 1 ? textCursor.x - ex < field.left - slack :
        path === 2 ? textCursor.y + ey > field.top + slack :
                     textCursor.y - ey < field.bottom - slack;
      if (!overflow) { commit(); return; }

      // Carriage return, then line feed.
      if (path === 0) textCursor = { x: field.left, y: textCursor.y - ey };
      else if (path === 1) textCursor = { x: field.right, y: textCursor.y - ey };
      else if (path === 2) textCursor = { x: textCursor.x + ex, y: field.bottom };
      else textCursor = { x: textCursor.x + ex, y: field.top - ey };
      cursor = { x: textCursor.x, y: textCursor.y };
      syncedDraw = { x: textCursor.x, y: textCursor.y };
    }

    out.push(0x1B, 0x25, 0x41); // ESC % A - enter NAPLPS mode
    out.push(0x1F, 0x40, 0x40); // NSR, cursor home
    cursor = { x: 0, y: TOP_ROW_Y };
    textCursor = { x: 0, y: TOP_ROW_Y };
    syncedDraw = { x: 0, y: TOP_ROW_Y };

    for (var i = 0; i < commands.length; i++) {
      var cmd = commands[i];
      switch (cmd.type) {
        case 'domain':
          mb = cmd.multiBytes || 3;
          sb = cmd.singleBytes || 1;
          pdi(0x21);
          out.push(0x40 | (((mb - 1) & 0x07) << 2) | ((sb - 1) & 0x03));
          break;

        case 'pelSize':
          // The pel size rides along with a DOMAIN PDI, so re-send the current
          // operand sizes and append it.
          pdi(0x21);
          out.push(0x40 | (((mb - 1) & 0x07) << 2) | ((sb - 1) & 0x03));
          coord(cmd.w, cmd.h);
          break;

        case 'reset':
          pdi(0x20);
          // Bits 6-4 select the screen action: 001 clears to black, 010 clears
          // to the drawing color.
          out.push(0x40 | (cmd.screen ? (isBlack(cmd) ? 0x08 : 0x10) : 0x00));
          out.push(0x40);
          break;

        case 'texture':
          pdi(0x23);
          out.push(0x40 | ((cmd.fill & 0x07) << 3) | (cmd.outline ? 0x04 : 0) | (cmd.line & 0x03));
          break;

        case 'setColor':
          pdi(0x3C);
          if (!cmd.transparent) emit(encodeColor(cmd.r, cmd.g, cmd.b, mb));
          break;

        case 'setPalette':
          pdi(0x3C);
          emit(encodeColor(cmd.r, cmd.g, cmd.b, mb));
          break;

        case 'selectColor':
          pdi(0x3E);
          if (cmd.index !== undefined) single(cmd.index, PALETTE_BITS);
          if (cmd.bgIndex !== undefined) single(cmd.bgIndex, PALETTE_BITS);
          if (cmd.mode !== undefined) colorMode = cmd.mode;
          if (cmd.index !== undefined) paletteIndex = cmd.index;
          break;

        case 'point':
          pdi(cmd.draw ? 0x27 : 0x25); // POINT REL / POINT SET REL
          step(cmd.x - cursor.x, cmd.y - cursor.y);
          break;

        case 'line':
          // Reaching the start point may need more than one operand, which only
          // POINT SET REL can express, so move first and then draw.
          moveTo(cmd.x1, cmd.y1);
          pdi(0x29); // LINE REL
          step(cmd.x2 - cursor.x, cmd.y2 - cursor.y);
          break;

        case 'rect':
          moveTo(cmd.x, cmd.y);
          pdi(cmd.filled ? 0x31 : 0x30); // RECT, drawn from the current point
          var size = encodeCoordinate(cmd.w, cmd.h, mb);
          emit(size);
          // After a rectangle the drawing point moves by its width only.
          cursor = { x: cursor.x + decodeCoordinate(size, mb).x, y: cursor.y };
          break;

        case 'polygon':
          if (!cmd.points || cmd.points.length < 2) break;
          // A polygon leaves the drawing point at the point it was set to.
          cursor = emitPointRun(cmd.filled ? 0x35 : 0x34, cmd.filled ? 0x37 : 0x36, cmd.points)[0];
          break;

        case 'arc':
          if (!cmd.points || cmd.points.length < 2) break;
          var drawn = emitPointRun(cmd.filled ? 0x2D : 0x2C, cmd.filled ? 0x2F : 0x2E, cmd.points);
          // An arc ends at its end point; a circle ends back at its start.
          cursor = drawn.length === 2 ? drawn[0] : drawn[drawn.length - 1];
          break;

        case 'incLine':
          // Re-emitted as ordinary line segments; the scribble encoding only
          // pays off when the steps are uniform, which we cannot assume here.
          for (var s = 0; s < (cmd.segments || []).length; s++) {
            var seg = cmd.segments[s];
            pdi(0x2A);
            coord(seg.x1, seg.y1);
            coord(seg.x2, seg.y2);
            cursor = { x: seg.x2, y: seg.y2 };
          }
          break;

        case 'text':
          syncText(cmd);
          moveTextTo(cmd.x, cmd.y);
          useSet('ASCII');
          out.push(cmd.char.charCodeAt(0) & 0x7F);
          advanceCursor(cmd);
          break;

        case 'mosaic':
          syncText(cmd);
          moveTextTo(cmd.x, cmd.y);
          useSet('MOSAIC');
          out.push(cmd.code & 0x7F);
          advanceCursor(cmd);
          break;

        case 'drcs':
          // The character is preserved; its stored definition is not re-emitted
          // (see the encoder notes in ARCHITECTURE.md).
          syncText(cmd);
          moveTo(cmd.x, cmd.y);
          useSet('DRCS');
          out.push(cmd.code & 0x7F);
          advanceCursor(cmd);
          break;

        case 'incPoint':
          encodeIncPoint(cmd);
          break;

        case 'wait':
          pdi(0x3D);
          out.push(0x40 | WAIT_MARKER); // fixed format byte required by WAIT
          // Intervals are tenths of a second, six bits each, and add together
          // to make up the total pause.
          var tenths = Math.round((cmd.seconds || 0) * 10);
          if (tenths === 0) {
            out.push(0x40);
          } else {
            while (tenths > 0) {
              var chunk = Math.min(tenths, 0x3F);
              out.push(0x40 | chunk);
              tenths -= chunk;
            }
          }
          break;

        case 'blink':
          // The blink-from entry is whatever the drawing color is, so it has to
          // be selected before the PDI rather than named inside it.
          selectPaletteEntry(cmd.from);
          pdi(0x3F);
          if (cmd.to !== undefined) {
            single(cmd.to, PALETTE_BITS);
            // A zero ON or OFF interval is itself the stop signal, so the
            // intervals go out as they are.
            out.push(0x40 | clampInterval(cmd.on));
            out.push(0x40 | clampInterval(cmd.off));
            out.push(0x40 | clampInterval(cmd.delay));
          }
          // With no operands at all, every process using this color stops.
          break;

        case 'blinkReset':
          // Bit 2 of the RESET PDI's second byte terminates all blink processes.
          pdi(0x20);
          out.push(0x40);
          out.push(0x40 | 0x02);
          break;

        case 'field':
          pdi(0x38);
          var fo = encodeCoordinate(cmd.x, cmd.y, mb);
          emit(fo);
          var fs = encodeCoordinate(cmd.w, cmd.h, mb);
          emit(fs);
          // Track the field as the decoder will read it back, since text wraps
          // against these bounds.
          var qo = decodeCoordinate(fo, mb);
          var qs = decodeCoordinate(fs, mb);
          field = {
            left: Math.min(qo.x, qo.x + qs.x), right: Math.max(qo.x, qo.x + qs.x),
            bottom: Math.min(qo.y, qo.y + qs.y), top: Math.max(qo.y, qo.y + qs.y)
          };
          // FIELD parts the two: the drawing point goes to the origin, the text
          // cursor to the field's top edge.
          cursor = { x: qo.x, y: qo.y };
          syncedDraw = { x: qo.x, y: qo.y };
          textCursor = { x: field.left, y: field.top };
          break;

        case 'bell':
          out.push(0x07);
          break;

        case 'nsr':
          out.push(0x1F, 0x40, 0x40);
          gl = 'ASCII';
          cursor = { x: 0, y: TOP_ROW_Y };
    textCursor = { x: 0, y: TOP_ROW_Y };
    syncedDraw = { x: 0, y: TOP_ROW_Y };
          break;
      }
    }

    // Re-emit a bitmap.  The decoder reads the scan geometry from the active
    // field and the logical pel, so both are restated before the PDI: the field
    // is sized to exactly the grid the pixels describe, with its origin at the
    // first pixel so the decoder starts the scan in the right corner.
    function encodeIncPoint(cmd) {
      var pixels = cmd.pixels || [];
      if (!pixels.length) return;

      // Columns run until x returns to where the first pixel started.
      var columns = 1;
      while (columns < pixels.length &&
        Math.abs(pixels[columns].x - pixels[0].x) > 1e-9) columns++;
      var rows = Math.ceil(pixels.length / columns);

      pdi(0x21); // DOMAIN, restating the operand sizes and the pel size
      out.push(0x40 | (((mb - 1) & 0x07) << 2) | ((sb - 1) & 0x03));
      coord(cmd.pelW, cmd.pelH);

      var wantField = {
        left: Math.min(pixels[0].x, pixels[0].x + columns * cmd.pelW),
        right: Math.max(pixels[0].x, pixels[0].x + columns * cmd.pelW),
        bottom: Math.min(pixels[0].y, pixels[0].y + rows * cmd.pelH),
        top: Math.max(pixels[0].y, pixels[0].y + rows * cmd.pelH)
      };

      // The field only has to drive the same scan, not match the grid exactly:
      // the row count is set by how many pixels there are, so a taller field is
      // still equivalent as long as the rows wrap in the same column and there
      // is room for them all.
      var pelW = Math.abs(cmd.pelW), pelH = Math.abs(cmd.pelH);
      var sameField =
        Math.abs(field.left - wantField.left) < 1e-9 &&
        Math.floor((field.right - field.left) / pelW + 1e-9) === columns &&
        field.bottom - 1e-9 <= wantField.bottom &&
        field.top + 1e-9 >= wantField.top;

      if (sameField) {
        // The field is already right; just put the drawing point at the corner
        // the scan starts from.
        moveTo(pixels[0].x, pixels[0].y);
      } else {
        pdi(0x38); // FIELD
        coord(pixels[0].x, pixels[0].y);
        coord(columns * cmd.pelW, rows * cmd.pelH);
        field = wantField;
      }
      cursor = { x: pixels[0].x, y: pixels[0].y };
      commit();

      // How the bitstring is read depends on the colour mode: direct RGB in
      // mode 0, palette indexes otherwise.  Make sure the decoder is in the
      // mode these pixels were captured in.
      var usesIndex = !pixels[0].color;
      if (usesIndex && colorMode === 0) {
        pdi(0x3E);
        single(paletteIndex, PALETTE_BITS);
        colorMode = 1;
      } else if (!usesIndex && colorMode !== 0) {
        pdi(0x3E); // no operands: colour mode 0
        colorMode = 0;
      }

      pdi(0x39); // INCREMENTAL POINT
      out.push(0x40 | (cmd.bitsPerPixel & 0x3F));

      var bits = [];
      for (var i = 0; i < pixels.length; i++) {
        var p = pixels[i];
        pushBits(bits, p.color
          ? colorToBitstring(p.color, cmd.bitsPerPixel)
          : intToBits(p.index || 0, cmd.bitsPerPixel));
        // The decoder discards the rest of the current byte when a row wraps,
        // so each row has to start on a byte boundary.
        if ((i + 1) % columns === 0) {
          while (bits.length % 6) bits.push(0);
        }
      }
      while (bits.length % 6) bits.push(0);
      for (var b = 0; b < bits.length; b += 6) {
        out.push(0x40 | (bits[b] << 5) | (bits[b + 1] << 4) | (bits[b + 2] << 3) |
          (bits[b + 3] << 2) | (bits[b + 4] << 1) | bits[b + 5]);
      }
    }

    function pushBits(target, bits) {
      for (var i = 0; i < bits.length; i++) target.push(bits[i]);
    }

    // Emit an ARC or POLYGON as a starting point followed by displacements.
    // The SET form carries an absolute start point, which only spans the unit
    // screen; a start point outside it is reached with a relative move first and
    // the plain opcode used instead.  Returns the quantised points so the caller
    // can leave the cursor exactly where the decoder will.
    function emitPointRun(plainOpcode, setOpcode, points) {
      var start = points[0];
      if (Math.abs(start.x) >= 1 || Math.abs(start.y) >= 1) {
        moveTo(start.x, start.y);
        pdi(plainOpcode);
      } else {
        pdi(setOpcode);
        var bytes = encodeCoordinate(start.x, start.y, mb);
        emit(bytes);
        cursor = decodeCoordinate(bytes, mb);
      }

      var actual = [{ x: cursor.x, y: cursor.y }];
      for (var k = 1; k < points.length; k++) {
        step(points[k].x - cursor.x, points[k].y - cursor.y);
        actual.push({ x: cursor.x, y: cursor.y });
      }
      return actual;
    }

    useSet('ASCII');
    out.push(0x1B, 0x25, 0x40); // ESC % @ - leave NAPLPS mode
    return new Uint8Array(out);
  }

  function isBlack(cmd) {
    return !cmd.r && !cmd.g && !cmd.b;
  }

  // ─── Public API ───────────────────────────────────────────────────

  return {
    decode: decode,
    encode: encode,
    buildDefaultPalette: buildDefaultPalette,
    decodeCoordinate: decodeCoordinate,
    encodeCoordinate: encodeCoordinate,
    decodeColor: decodeColor,
    encodeColor: encodeColor,
    PDI_NAMES: PDI_NAMES,
    version: '1.0.0'
  };
}));
