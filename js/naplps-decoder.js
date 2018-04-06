"use strict";

// NAPLPS JavaScript decoder
// Nick Fox-Gieg http://fox-gieg.com

// Uses no p5.js-specific code

// 1. SINGLE-BYTE data classes
// 
// 1.1. The NapChar class is the smallest component of a NAPLPS file. 
// It just contains a few methods for decoding one byte.
class NapChar {
    
    constructor(_c) {
        this.c = _c; // char or string
        this.ascii = this.getAscii(); // int
        this.binary = this.getBinary(); // string
        this.rbinary = this.getRBinary(); // string
        this.hex = this.getHex(); // string
    }
    
    getAscii() {
        return new Char(this.c);
    }
    
    getBinary() {
        var returns = "";
        var b = binary(this.ascii);
        for (var i=b.length-7; i<b.length; i++) {
            returns += b.charAt(i);
        }
        return returns;
    }
    
    getRBinary() { // reverse binary
        return this.binary.split("").reverse().join("");
    }
    
    getHex() {
        var returns = "";
        var h = hex(parseInt(this.ascii));
        for (var i=h.length-2; i<h.length; i++) {
            returns += h.charAt(i);
        }        
        return returns;
    }

}

// 1.2. Some NapChars contain opcodes, or drawing commands.
// The NapOpcode class decodes the command.
class NapOpcode extends NapChar {
	        
    constructor(_c) { // char or string
        super(_c);
        this.id = this.getId();
    }
    
    // *** IMPORTANT STEP 1 of 3 ***
    // This is the first step, where we match the hex code to a command.
    // The second step happens later on in this decoder.
    getId() { 
        var returns = "";
        switch(this.hex) {
        	//~ ~ ~ ~ ~ CONTROL CODES ~ ~ ~ ~ ~
            case("0E"):
                returns = "Shift-Out"; // graphics mode
                break;
            case("0F"):
                returns = "Shift-In"; // text mode
                break;
            case("18"):
                returns = "CANCEL";
                break;
            case("1B"):
                returns = "ESC";
                break;
            case("1F"):
                returns = "NSR"; // Non-Selective Reset
                break;
            //~ ~ ~ ~ ~ PDI (PICTURE DESCRIPTION INSTRUCTION) CODES ~ ~ ~ ~ ~
            //~ ~ ~ ENVIRONMENT, part 1 ~ ~ ~
            case("20"):
                returns = "RESET";
                break;
            case("21"):
                returns = "DOMAIN"; // header information
                break;
            case("22"):
                returns = "TEXT";
                break;
            case("23"):
                returns = "TEXTURE";
                break;
            //~ ~ ~ POINTS ~ ~ ~
            case("24"):
                returns = "POINT SET ABS";
                break;
            case("25"):
                returns = "POINT SET REL";
                break;
            case("26"):
                returns = "POINT ABS";
                break;
            case("27"):
                returns = "POINT REL";
                break;
            //~ ~ ~ LINES ~ ~ ~
            case("28"):
                returns = "LINE ABS";
                break;
            case("29"):
                returns = "LINE REL";
                break;
            case("2A"):
                returns = "SET & LINE ABS";
                break;
            case("2B"):
            	returns = "SET & LINE REL";
            	break;
            //~ ~ ~ ARCS ~ ~ ~
            case("2C"):
                returns = "ARC OUTLINED";
                break;
            case("2D"):
                returns = "ARC FILLED";
                break;
            case("2E"):
                returns = "SET & ARC OUTLINED";
                break;
            case("2F"):
            	returns = "SET & ARC FILLED";
            	break;
            //~ ~ ~ RECTANGLES ~ ~ ~
            case("30"):
                returns = "RECT OUTLINED";
                break;
            case("31"):
                returns = "RECT FILLED";
                break;
            case("32"):
                returns = "SET & RECT OUTLINED";
                break;
            case("33"):
            	returns = "SET & RECT FILLED";
            	break;
            //~ ~ ~ POLYGONS ~ ~ ~
            case("34"):
                returns = "POLY OUTLINED";
                break;
            case("35"):
                returns = "POLY FILLED";
                break;
            case("36"):
                returns = "SET & POLY OUTLINED";
                break;
            case("37"):
                returns = "SET & POLY FILLED";
                break;
            //~ ~ ~ INCREMENTALS ~ ~ ~
            case("38"):
                returns = "FIELD";
                break;
            case("39"):
                returns = "INCREMENTAL POINT";
                break;
            case("3A"):
                returns = "INCREMENTAL LINE";
                break;
            case("3B"):
                returns = "INCREMENTAL POLY FILLED";
                break;
            //~ ~ ~ ENVIRONMENT, part 2 ~ ~ ~ 
            case("3C"):
                returns = "SET COLOR"; // this picks a color
                break;
            case("3D"):
                returns = "WAIT";
                break;
            case("3E"):
                returns = "SELECT COLOR"; // this sets the color mode
                break
            case("3F"):
                returns = "BLINK";
                break;
            default:
                break;
        }
        return returns;
    }
    
}

// 1.3. The NapChars following an opcode contain the data that 
// the command will use.
class NapData extends NapChar {
    
    constructor(_c) { // char or string
        super(_c);
        this.f = this.getNormFloat(); // float
    }
    
    getNormFloat() {
        var returns = parseFloat(this.ascii / 127.0);
        return returns;
    }

}


// 2. MULTI-BYTE data classes
//
// 2.1. NapDataArray objects need to combine multiple NapData pieces for decoding. 
class NapDataArray {
    
    constructor(n) { // NapData[]
        this.bitsPerByte = 3; // int, TODO set programatically from header info based on XY / XYZ
        this.firstBitSign = true; // bool, should be true for all header options
        this.bitVals = pow(2, (n.length * this.bitsPerByte) - int(this.firstBitSign)); // float
    }
    
    binaryConv(n, loc) { // NapData, int
        var returns = "";
        for (var i=loc; i<loc+this.bitsPerByte; i++) {
            returns += n.binary.charAt(i);
        }
        return returns;
    }
    
    getSingleByteVal(n, axis) { // NapData, string
        var returns = "";
        if (axis === "x") {
            returns = "" + this.binaryConv(n, 1);
        } else if (axis === "y") {
            returns = "" + this.binaryConv(n, this.bitsPerByte + 1);//4);
        } else if (axis === "z") {
            returns = "" + this.binaryConv(n, (2 * this.bitsPerByte) + 1); // ? untested
        }
        return returns;
    }
    
    getSign(c) { // char or string
        if (c === '1') {
            return -1.0;
        } else {
            return 1.0;
        }
    }

/*
           X     Y               X   Y   Z
     8 7|6 5 4|3 2 1|       8 7|6 5|4 3|2 1|
    -----------------      -----------------
    |?|1|S| | |S| | |      |?|1|S| |S| |S| |
    -----------------      -----------------
    |?|1| | | | | | |      |?|1| | | | | | |
    -----------------      -----------------
        . . .                  . . .
    -----------------      -----------------
    |?|1| | | | | | |      |?|1| | | | | | |
    -----------------      -----------------
*/
     
    getCoordFromBytes(n, axis) { // NapData[], string
        var returns = "";
        for (var i=0; i<n.length; i++) {
            returns += this.getSingleByteVal(n[i], axis);
        }
        
        var sign = 1;
        if (this.firstBitSign) {
            sign = this.getSign(returns.charAt(0));
            returns = removeCharAt(returns, 0);
        }
        
        var finalReturns = 0;
        
        if (axis === "x") {
            finalReturns = (unbinary(returns) / this.bitVals) * sign;
        } else if (axis === "y") {
            finalReturns = ((this.bitVals - unbinary(returns)) / this.bitVals) * sign;
        } else if (axis === "z") {
            //finalReturns = (unbinary(returns) / this.bitVals) * sign; // ? untested
        }

        return finalReturns;
    }

/*
         G R B G R B
     8 7|6 5 4|3 2 1|
    -----------------
    |?|1| | | | | | |
    -----------------
    |?|1| | | | | | |
    -----------------
        . . .
    -----------------
    |?|1| | | | | | |
    -----------------
*/
    getColorFromBytes(n, channel) {  // NapData[], string
    	var returns = "";
    	for (var i=0; i<n.length; i++) {
    		if (channel === "r") {
            	returns += "" + n[i].binary.charAt(2);
            	returns += "" + n[i].binary.charAt(5);
    		} else if (channel === "g") {
               	returns += "" + n[i].binary.charAt(3);
            	returns += "" + n[i].binary.charAt(6);
    		} else if (channel === "b") {
            	returns += "" + n[i].binary.charAt(4);
            	returns += "" + n[i].binary.charAt(7);
    		}
    	}

    	returns = returns.split("");
    	returns = returns.reverse();
    	returns = returns.join("");

    	var finalReturns = Math.abs(255.0 - (255.0 * (unbinary(returns) / (2.0 * n.length))));
    	return finalReturns;
    }

}

// 2.2. XY and XYZ position are handled by the NapVector class.
class NapVector extends NapDataArray {

    constructor(n) { // NapData[]
		super(n);
        this.x = this.getCoordFromBytes(n, "x"); // float
        this.y = this.getCoordFromBytes(n, "y"); // float
        //this.z = this.getCoordFromBytes(n, "z"); // float
    }

}

// 2.3. RGB color
class NapColor extends NapDataArray {

	constructor(n) { // NapData[]
		super(n);
		// TODO find out if this needs a new method
		this.r = this.getColorFromBytes(n, "r"); // float
        this.g = this.getColorFromBytes(n, "g"); // float
        this.b = this.getColorFromBytes(n, "b"); // float

       	if (this.r < 0 || this.r > 255 || this.g < 0 || this.g > 255 || this.b < 0 || this.b > 255) {
    		this.r = 0;
    		this.g = 0;
    		this.b = 0;
        	//console.log("color: not RGB data? (" + this.r + ", " + this.g + ", " + this.b + ")");
    	} else {
	        //console.log("color: " + this.r + ", " + this.g + ", " + this.b);
    	}
	}

}


// 3. COMMAND: One decoded drawing command.
// Assembled from the opcode and data bytes.
class NapCmd {
    
    constructor(_cmd, _index) { // string, int
        this.pointBytes = 4; // int, TODO set programatically from header info
        this.pointRelative = true;    // bool, TODO set programatically from header info
        this.cmdRaw = _cmd; // string
        this.index = _index; // int
        this.data = []; // NapData[]
        this.points = []; // PVector[]
        this.col = new Vector3(0.5,0.5,0.5);

        this.opcode = new NapOpcode(this.cmdRaw.charAt(0)); // NapOpcode
        if (this.cmdRaw.length > 1) {
            for (var i=1; i<this.cmdRaw.length; i++) {
                this.data.push(new NapData(this.cmdRaw.charAt(i)));
            }
        }
        
        // *** IMPORTANT STEP 2 of 3 ***
        // The second step is where we find out what kind of command it is,
        // which tells us how we handle the data.
        // The third and final step is done separately, in the drawing code.
        switch(this.opcode.id) {
        	//~ ~ ~ ~ ~ CONTROL CODES ~ ~ ~ ~ ~
            case("Shift-Out"): // graphics mode
               	// no effect?
                break;
            case("Shift-In"): // text mode
               	// no effect?
                break;
            case("CANCEL"):
               	// no effect?
                break;
            case("ESC"):
               	// no effect?
                break;
            case("NSR"): // Non-Selective Reset
               	// no effect?
                break;
            //~ ~ ~ ~ ~ PDI (PICTURE DESCRIPTION INSTRUCTION) CODES ~ ~ ~ ~ ~
            //~ ~ ~ ENVIRONMENT, part 1 ~ ~ ~
            case("RESET"):
               	// no effect?
                break;
            case("DOMAIN"): // header information
               	// TODO
                break;
            case("TEXT"):
                // TODO
                break;
            case("TEXTURE"):
               	// TODO
                break;
            //~ ~ ~ POINTS ~ ~ ~
            case("POINT SET ABS"):
                this.getPoints();
                break;
            case("POINT SET REL"):
                this.getPoints();
                break;
            case("POINT ABS"):
                this.getPoints();
                break;
            case("POINT REL"):
                this.getPoints();
                break;
            //~ ~ ~ LINES ~ ~ ~
            case("LINE ABS"):
                this.getPoints();
                break;
            case("LINE REL"):
                this.getPoints();
                break;
            case("SET & LINE ABS"):
                this.getPoints();
                break;
            case("SET & LINE REL"):
                this.getPoints();
            	break;
            //~ ~ ~ ARCS ~ ~ ~
            case("ARC OUTLINED"):
                this.getPoints();
                break;
            case("ARC FILLED"):
                this.getPoints();
                break;
            case("SET & ARC OUTLINED"):
                this.getPoints();
                break;
            case("SET & ARC FILLED"):
                this.getPoints();
            	break;
            //~ ~ ~ RECTANGLES ~ ~ ~
            case("RECT OUTLINED"):
                this.getPoints();
                break;
            case("RECT FILLED"):
                this.getPoints();
                break;
            case("SET & RECT OUTLINED"):
                this.getPoints();
                break;
            case("SET & RECT FILLED"):
                this.getPoints();
            	break;
            //~ ~ ~ POLYGONS ~ ~ ~
            case("POLY OUTLINED"):
                this.getPoints();
                break;
            case("POLY FILLED"):
                this.getPoints();
                break;
            case("SET & POLY OUTLINED"): // relative points after first 
                this.getPoints();
                break;
            case("SET & POLY FILLED"): // relative points after first 
                this.getPoints();
                break;
            //~ ~ ~ INCREMENTALS ~ ~ ~
            case("FIELD"):
               	// TODO
                break;
            case("INCREMENTAL POINT"):
                this.getPoints();
                break;
            case("INCREMENTAL LINE"):
                this.getPoints();
                break;
            case("INCREMENTAL POLY FILLED"):
                this.getPoints();
                break;
            //~ ~ ~ ENVIRONMENT, part 2 ~ ~ ~ 
            case("SET COLOR"): // this picks a color
               	this.getColor();
                break;
            case("WAIT"):
               	// TODO
                break;
            case("SELECT COLOR"): // this sets the color mode
               	this.getColor();
                break
            case("BLINK"):
            	// TODO
                break;
            default:
                break;        	
        }
    }
     
    printCmd(mode) {
        console.log(this.formatCmd(mode));
    }
    
    // This prints out the command contents in various formats
    // Helpful for debugging
    formatCmd(mode) {
        var returns = "(" + this.index + ") " + this.opcode.id;
        if (this.data.length > 0) returns += ": ";
        if (this.opcode.id === "") {
            switch(mode) {
                case("char"):
                    returns += this.opcode.c;
                    break;
                case("binary"):
                    returns += this.opcode.binary;
                    break;
                 case("rbinary"):
                    returns += this.opcode.rbinary;
                    break;    
                case("ascii"):
                    returns += this.opcode.ascii;
                    break;
                case("hex"):
                    returns += this.opcode.hex;
                    break;
                default:
                    break;
            }
        }
        if (this.data.length > 0) {
            if (this.opcode.id === "") returns += ", ";
            for (var i=0; i<this.data.length; i++) {
                switch(mode) {
                    case("char"):
                        returns += "" + this.data[i].c;
                        break;
                    case("binary"):
                        returns += "" + this.data[i].binary;
                        break;
                    case("rbinary"):
                        returns += "" + this.data[i].rbinary;
                        break;
                    case("ascii"):
                        returns += "" + this.data[i].ascii;
                        break;
                    case("hex"):
                        returns += "" + this.data[i].hex;
                        break;
                    default:
                        break;
                }
                if (i < this.data.length - 1) returns += ", ";
            }
        }
        return returns;
    }
    
    // ~ ~ ~ Parsing methods begin here ~ ~ ~
    getPoints() {
        try {
            var nvList = []; // NapVector[];
            for (var i=0; i<this.data.length; i+=this.pointBytes) {
                var n = []; // NapData[]
                for (var j=0; j<this.pointBytes; j++) {
                    n.push(this.data[i + j]);
                }
                nvList.push(new NapVector(n));
            }
            
            for (var i=0; i<nvList.length; i++) {
                var nv = nvList[i];

                if (this.pointRelative) {
                    if (i===0) {
                        this.points.push(new Vector2(nv.x, nv.y));
                    } else {
                        var p = this.points[this.points.length-1];
                        
                        var x = 0;         
                        if (nv.x < 0) {
                            x = (abs(nv.x) + abs(p.x)) - 1.0;
                        } else {
                            x = nv.x + p.x;
                        }
                        
                        var y = 0;
                        if (nv.y < 0) {
                            y = abs(nv.y) + p.y;
                        } else {
                            y = (abs(nv.y) + abs(p.y)) - 1.0;
                        }
                        
                        this.points.push(new Vector2(x, y));
                    }
                } else {
                    this.points.push (new Vector2(nv.x, nv.y));
                }
                // * * * * * 
            }
        } catch (e) { 
            console.log("*** Error: " + this.opcode.id + " contains no coordinates. ***")
        }
    }

    getColor() {
    	var nc = new NapColor(this.data);

    	this.col = new Vector3(nc.r, nc.g, nc.b);
    }

    getDomain() {
        for (var i=0; i<this.data.length; i++) {
            // TODO header info, most importantly:
            // How many bytes per point
            // XY format (3 bits per axis per byte) or XYZ format (2 bits per axis per byte)
            // How many bytes per color
            // Color format?
        }
    }
    
}


// 4. DECODER: Contains all the decoded drawing commands.
// Decodes the format only; drawing happens in TelidonDraw
class NapDecoder {
    
    constructor(input) { // string[]
        this.napRaw = input[0];//""; // string
        this.cmds = []; // NapCmd[]
        this.counter = 0; // int
        this.debug = true; // bool

        //for (var i=0; i<input.length; i++) {
            //this.napRaw += input[i];
        //}

        var tempCmd = "";
        for (var i=0; i<this.napRaw.length; i++) {
            var c = this.napRaw[i]; // char or string
            if (this.isOpcode(new Char(c))) {
                if (tempCmd === "") {
                    tempCmd += c;
                } else {
                    if (tempCmd.length >= 1) {
                        this.cmds.push(new NapCmd(tempCmd, this.counter));
                        this.counter++;
                    }
                    tempCmd = "";
                    tempCmd += c;
                }
            } else {
                tempCmd += c;
            }
        }
        
        if (this.debug) {
            for (var i=0; i<this.cmds.length; i++) {
                this.cmds[i].printCmd("hex");
            }
        }
    }
    
    isOpcode(c) { // char or string
        var b = binary(c);
        return b[b.length-7] === '0';
    }
    
}