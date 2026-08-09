# Telidon Architecture

The Telidon repository is a collection of tools and libraries centered around decoding and rendering **NAPLPS** (North American Presentation Layer Protocol Syntax) vector graphics files, primarily for modern web browsers. 

## High-Level Overview

The core components of the repository consist of an encoder/decoder library, a rendering wrapper built on top of [p5.js](https://p5js.org/), and a web-based demonstration that ties them together.

### 1. `naplps.js` (The Core Engine)
Located in `js/telidon/naplps.js`, this is the heart of the project. It acts as the parser for NAPLPS drawing instructions. 
- It reads the binary stream of a `.nap` file and translates the Picture Description Instructions (PDIs).
- It decodes coordinates (which are based on a Unit Screen as binary fractions), color mappings, and primitive drawing instructions (Lines, Arcs, Polygons, Points, etc.) defined in the NAPLPS standard.

### 2. `TelidonP5.js` (The Renderer)
Located in `js/telidon/TelidonP5.js`, this script acts as a bridge between the parsed NAPLPS commands and the `p5.js` rendering context.
- It instantiates a `NapDecoder` to process a file.
- It contains classes like `TelidonDraw` and `TelidonDrawCmd` that iterate over the decoded commands (`NapDrawCmd`).
- It implements progressive drawing (drawing the image command by command over time), emulating the slow rendering speed of historical Telidon terminals.

### 3. The Web Demonstration
The root `index.html` and the accompanying `css/main.css` form a web application for demonstrating the library's capabilities.
- It imports `p5.js`, `gif.js`, `naplps.js`, and `TelidonP5.js`.
- It loads various sample `.nap` images (located in `images/`) and renders them dynamically onto an HTML5 canvas.
- It provides interactivity, allowing users to drag and drop NAPLPS files or click on sample thumbnails to render them.

### 4. Tools and Prototypes
The `tools/` directory contains an array of miscellaneous tests, prototypes, and experimental viewers in several programming languages:
- **Java / Processing**: A prototype viewer reading NAPLPS (e.g., `TelidonP5` in Processing).
- **Python / Ruby**: Various scripts and experimental implementations.
- **Rosetta Stone**: Located in `tools/rosetta_stone/`, this serves as a tutorial that breaks down a simple NAPLPS image instruction by instruction.

### 5. The NAPLPS Standard (`docs/NAP.txt`)
The implementation is based on the NAPLPS specification (ANSI X3.110-1983 / CSA T500-1983). The reference spec details the OSI Presentation Layer protocol which:
- Divides instructions into C-sets (Control codes) and G-sets (Graphic sets including ASCII, PDIs, Mosaics, and Macros).
- Implements Cartesian coordinates based on a logical unit screen `(0,0)` to `(1,1)` with an aspect ratio of 4:3.
- Relies on PDI primitives like `RESET`, `DOMAIN`, `TEXT`, `LINE`, `ARC`, `POLYGON`, and color palettes.

## Data Flow
1. A `.nap` file is fetched or uploaded via the browser.
2. `naplps.js` ingests the file's byte stream and sequentially decodes the shift codes, G-sets, and PDIs.
3. Decoded primitive commands are stored in an array within `TelidonDraw`.
4. The `p5.js` draw loop in `index.html` repeatedly calls `TelidonDraw.draw()`.
5. `TelidonP5.js` evaluates time-based progression and issues rendering commands to the `p5.js` canvas.
