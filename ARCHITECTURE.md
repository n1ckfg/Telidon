# Telidon Architecture

The Telidon repository is a collection of tools and libraries centered around decoding and rendering **NAPLPS** (North American Presentation Layer Protocol Syntax) vector graphics files, primarily for modern web browsers. 

## High-Level Overview

The core components of the repository consist of an encoder/decoder library, a rendering wrapper built on top of [p5.js](https://p5js.org/), and a web-based demonstration that ties them together.

The two libraries meet at a **command array**: a plain array of JavaScript objects, each carrying a `type` and the operands that go with it. That array is the only thing they share. `naplps.js` knows the byte format and nothing about drawing; `TelidonP5.js` knows how to draw and nothing about the byte format. Either can be used on its own.

### 1. `naplps.js` (The Core Engine)
Located in `js/telidon/naplps.js`, this is the heart of the project. It is a UMD module that publishes itself as `NAPLPS` in a browser, and it uses no p5.js-specific code.

- `NAPLPS.decode(data)` reads the byte stream of a `.nap` file and translates the Picture Description Instructions (PDIs), returning `{ commands, state }`. `data` may be a `Uint8Array`, an `ArrayBuffer`, a byte array, or a string of character codes.
- `NAPLPS.encode(commands)` serialises a command array back into a NAPLPS byte stream as a `Uint8Array`. This is what turns imported SVG into `.nap`.
- It decodes coordinates (which are based on a Unit Screen as binary fractions), color mappings, and primitive drawing instructions (Lines, Arcs, Polygons, Points, etc.) defined in the NAPLPS standard.
- Also exported: `buildDefaultPalette`, `decodeCoordinate` / `encodeCoordinate`, `decodeColor` / `encodeColor`, and `PDI_NAMES`, which maps an opcode to its mnemonic and is useful when tracing a stream by hand.

The command types a decode can produce:

| Group | Types |
| --- | --- |
| Environment | `reset`, `domain`, `pelSize`, `texture`, `field`, `nsr` |
| Color | `palette`, `setPalette`, `setColor`, `selectColor`, `blink`, `blinkReset` |
| Geometry | `point`, `line`, `rect`, `polygon`, `arc`, `incLine`, `incPoint` |
| Characters | `text`, `mosaic`, `drcs` |
| Timing and misc | `wait`, `bell` |

`palette` is synthetic: the decoder emits the starting palette up front so that a renderer can resolve palette indices without reimplementing the default-palette algorithm.

Stored definitions are resolved at decode time rather than left as references. A macro is expanded inline, so it never appears in the command array at all; a DRCS glyph's program is attached to each `drcs` command as `program`, and a programmable fill mask's program is attached to the `texture` command that selects it as `maskProgram`.

#### Encoder notes

`encode()` is not a byte-for-byte inverse of `decode()`. It restates the picture, not the stream that carried it, so a round trip preserves what is drawn but not always how it was compressed:

- **Macros** have already been expanded by the decoder, so a re-encoded file draws the same picture without them.
- **DRCS characters** keep their character code, but the stored program that defines the glyph is not written back out, so a re-encoded file has nothing left to draw them with.
- **Programmable fill masks** are dropped the same way: the TEXTURE PDI that selects a mask survives, its definition does not.
- **Incremental lines** are re-emitted as ordinary line segments. The scribble encoding only pays off when the steps are uniform, which a command array cannot promise.

Otherwise the encoder tracks enough of the environment — operand sizes, which G-set is invoked, where the drawing point and the text cursor sit — to avoid re-sending state that has not changed.

> `js/telidon/build/` holds the sources of a **previous** implementation, and `build.command` concatenates them over `../naplps.js`. Running it will overwrite the current library.

### 2. `TelidonP5.js` (The Renderer)
Located in `js/telidon/TelidonP5.js`, this script draws a decoded command array with `p5.js`. It publishes itself as `TelidonP5`.

- `TelidonP5.render(pg, commands, options)` draws the array. `pg` is a p5 sketch instance or a `p5.Graphics`; both answer the same drawing calls, which is what lets a programmable fill mask be rendered into an offscreen tile by the same code that draws the display.
- `options.limit` stops after that many commands, `options.time` stops where the WAIT clock passes that many seconds, and `options.blinkTime` phases palette animation against the wall clock. `width`, `height` and `background` override the defaults taken from the target.
- `TelidonP5.duration(commands)` totals the WAIT commands, and `TelidonP5.hasBlink(commands)` reports whether the palette animates. Together they say whether an image is still or moving.
- `TelidonP5.Viewport` maps unit-screen coordinates onto the canvas. X and Y share a scale so the 4:3 aspect ratio is preserved whatever the canvas size, and the unit origin sits at the bottom-left corner — so a 640x480 canvas holds the visible band, y in [0, 0.75], exactly.

Every mark is made with a p5 drawing call rather than against a bare Canvas 2D context, so NAPLPS artwork can share a canvas with a sketch's own drawing. Two things NAPLPS needs have no p5 equivalent and reach through to `drawingContext`: clipping, which hatched fills, pattern fills and DRCS glyphs are contained by, and line dashes, which the line textures are drawn with. Neither of them paints — they only constrain where and how p5 then paints — and `push()`/`pop()` save and restore that context, so a clip lifts with the rest of the state.

`render()` draws a whole array in one call and clears its target first, so it is not itself progressive. Drawing an image command by command, the way a historical Telidon terminal did, is the caller's job: re-render with a growing `limit`, and advance `time` alongside it so that an animated image holds each of its frames.

### 3. The Web Demonstration
The root `index.html` and the accompanying `css/main.css` form a web application for demonstrating the library's capabilities.
- It imports `p5.js` (with `p5.dom` and `p5.svg`), `gif.js`, `naplps.js`, and `TelidonP5.js`.
- It loads various sample `.nap` images (located in `images/`) and renders them dynamically onto an HTML5 canvas.
- It provides interactivity, allowing users to drag and drop NAPLPS files or click on sample thumbnails to render them, and records what it draws as an animated GIF.
- A local `NapPlayer` class owns the playback loop. It decodes once, renders into an offscreen `p5.Graphics`, and walks the command array on a clock that charges each ordinary command a fixed slice of time and each `wait` the whole pause it asks for. Once a still image is finished it stops re-rendering and blits the buffer it already has.
- `.nap` files are read as bytes rather than as text, since a NAPLPS stream is not UTF-8 and several of the sample images carry bytes that a text decode would eat.
- Dropping an SVG runs the reverse path: its polygons, polylines and paths become a command array, `NAPLPS.encode` serialises it, and the resulting `.nap` is both downloaded and played back. NAPLPS can only use a fill color or a stroke color in one path, not both, and its outlined polygons always close, so an open polyline picks up a closing edge.

Minified builds of both libraries sit beside them as `naplps.min.js` and `TelidonP5.min.js`, exporting the same globals.

### 4. Tools and Prototypes
The `tools/` directory contains an array of miscellaneous tests, prototypes, and experimental viewers in several programming languages:
- **Java / Processing**: A prototype viewer reading NAPLPS (e.g., `TelidonP5` in Processing).
- **Python / Ruby**: Various scripts and experimental implementations.
- **Rosetta Stone**: Located in `tools/rosetta_stone/`, this serves as a tutorial that breaks down a simple NAPLPS image instruction by instruction. Its `cover/png/` images are the reference renderings the sample files should match.

### 5. The NAPLPS Standard (`docs/NAP.txt`)
The implementation is based on the NAPLPS specification (ANSI X3.110-1983 / CSA T500-1983). The reference spec details the OSI Presentation Layer protocol which:
- Divides instructions into C-sets (Control codes) and G-sets (Graphic sets including ASCII, PDIs, Mosaics, and Macros).
- Implements Cartesian coordinates based on a logical unit screen `(0,0)` to `(1,1)` with an aspect ratio of 4:3, so only y in `[0, 0.75]` is visible.
- Relies on PDI primitives like `RESET`, `DOMAIN`, `TEXT`, `LINE`, `ARC`, `POLYGON`, and color palettes.

## Data Flow
1. A `.nap` file is fetched or uploaded via the browser, as bytes.
2. `NAPLPS.decode()` ingests the byte stream and sequentially decodes the shift codes, G-sets, and PDIs into a command array.
3. `index.html` holds that array in a `NapPlayer`, along with an offscreen `p5.Graphics` to draw it into.
4. The `p5.js` draw loop advances the player's clock, which decides how far down the array playback has reached.
5. `TelidonP5.render()` redraws the buffer up to that point, and the buffer is blitted onto the visible canvas.
