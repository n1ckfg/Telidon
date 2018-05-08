"use strict";

// NAPLPS JavaScript decoder
// Nick Fox-Gieg http://fox-gieg.com

// Uses no p5.js-specific code

var napDrawingCursor = new Vector2(0.0, 0.0);

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
        var h = hex(parseIntAlt(this.ascii));
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
                returns = "Shift-Out"; // graphics mode, we're here by default. Handled in step 2.
                break;
            case("0F"):
                returns = "Shift-In"; // text mode, data that follows is text. Hendled in step 2.
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
                returns = "TEXT"; // formats text, doesn't contain text itself
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
        // defaults for coordinate type.
        // TODO set programatically from domain info based on XY (3 bits) or XYZ (2 bits). 
        // However in almost all cases we can assume XY.
        this.bitsPerByte = 3; // int
        this.firstBitSign = true; // bool, should be true for all domain options?
        this.bitVals = this.getBitValsSigned(n);//pow(2, (n.length * this.bitsPerByte) - int(this.firstBitSign)); // float
    }
    
    getBitValsUnsigned(n) {
        return pow(2, (n.length * this.bitsPerByte));// - int(this.firstBitSign));
    }

    getBitValsSigned(n) {
        return pow(2, (n.length * this.bitsPerByte) - int(this.firstBitSign))
    }

    getSign(c) { // char or string
        if (c === '1') {
            return -1.0;
        } else {
            return 1.0;
        }
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

}

// 2.2. XY and XYZ position are handled by the NapVector class.
class NapVector extends NapDataArray {

    constructor(n) { // NapData[]
		super(n);
        this.x = this.getCoordFromBytes(n, "x"); // float
        this.y = this.getCoordFromBytes(n, "y"); // float
        //this.z = this.getCoordFromBytes(n, "z"); // float
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
            finalReturns = (unbinary(returns) / this.bitVals) * sign; // ? untested
        }

        return finalReturns;
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
            if (channel === "g") {
                returns += "" + n[i].binary.charAt(2);
                returns += "" + n[i].binary.charAt(5);
            } else if (channel === "r") {
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

        var maxVal = 255.0
        var finalReturns = maxVal * (unbinary(returns)/(2 * n.length));
        var finalReturnsInv = Math.abs(maxVal - finalReturns);
        var finalReturnsScaled = (finalReturnsInv / maxVal) * 255.0;

        //console.log(finalReturnsScaled);
        return finalReturnsScaled;
    }

}

// 2.4. Text
class NapText extends NapDataArray {
    // TODO figure out text formatting

    constructor(n) { // NapData[]
        super(n);
        this.text = this.getTextFromBytes(n);
    }

    getTextFromBytes(n) {
        var returns = "";
        for (var i=0; i<n.length; i++) {
            returns += "" + n[i].c;
        }
        return returns;
    }

}


// 3. COMMAND: One decoded drawing command.
// Assembled from the opcode and data bytes.
class NapCmd {
    
    constructor(_cmd, _index) { // string, int
        this.pointBytes = 4; // int
        this.singleBytes = 1; // int
        //this.pointRelative = true; // bool, TODO set programatically from header info...if this is in header?
        this.cmdRaw = _cmd; // string
        this.index = _index; // int
        this.data = []; // NapData[]
        this.points = []; // PVector[]
        this.col = new Vector3(0.5,0.5,0.5);
        this.text = "";

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
            case("Shift-Out"): // graphics mode, we're here by default
                // no effect?
                break;
            case("Shift-In"): // text mode, data that follows is text
                this.getText();
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
               	this.getDomain();
                break;
            case("TEXT"): // formats text, doesn't contain text itself
                // TODO
                break;
            case("TEXTURE"):
               	// TODO
                break;
            //~ ~ ~ POINTS ~ ~ ~
            case("POINT SET ABS"):
                this.getPoints(false, true); // relative, set cursor
                break;
            case("POINT SET REL"):
                this.getPoints(true, true);
                break;
            case("POINT ABS"):
                this.getPoints(false, false);
                break;
            case("POINT REL"):
                this.getPoints(true, false);
                break;
            //~ ~ ~ LINES ~ ~ ~
            case("LINE ABS"):
                this.getPoints(true, false); // TODO why is this broken?
                break;
            case("LINE REL"):
                this.getPoints(true, false);
                break;
            case("SET & LINE ABS"):
                this.getPoints(true, true); // TODO why is this broken?
                break;
            case("SET & LINE REL"):
                this.getPoints(true, true);
            	break;
            //~ ~ ~ ARCS ~ ~ ~
            case("ARC OUTLINED"):
                this.getPoints(true, false);
                break;
            case("ARC FILLED"):
                this.getPoints(true, false);
                break;
            case("SET & ARC OUTLINED"):
                this.getPoints(false, true);
                break;
            case("SET & ARC FILLED"):
                this.getPoints(false, true);
            	break;
            //~ ~ ~ RECTANGLES ~ ~ ~
            case("RECT OUTLINED"):
                this.getPoints(true, false);
                break;
            case("RECT FILLED"):
                this.getPoints(true, false);
                break;
            case("SET & RECT OUTLINED"):
                this.getPoints(false, true);
                break;
            case("SET & RECT FILLED"):
                this.getPoints(false, true);
            	break;
            //~ ~ ~ POLYGONS ~ ~ ~
            case("POLY OUTLINED"):
                this.getPoints(true, false);
                break;
            case("POLY FILLED"):
                this.getPoints(true, false);
                break;
            case("SET & POLY OUTLINED"): // relative points after first 
                this.getPoints(false, true);
                break;
            case("SET & POLY FILLED"): // relative points after first 
                this.getPoints(false, true);
                break;
            //~ ~ ~ INCREMENTALS ~ ~ ~
            case("FIELD"):
               	// TODO
                break;
            case("INCREMENTAL POINT"):
                this.getPoints(true, true);
                break;
            case("INCREMENTAL LINE"):
                this.getPoints(true, true);
                break;
            case("INCREMENTAL POLY FILLED"):
                this.getPoints(true, true);
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
    getPoints(_allPointsRelative, _set) {
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

                    if (!_allPointsRelative && i===0) {
                        this.points.push(new Vector2(nv.x, nv.y));
                    } else if (_allPointsRelative && i===0) {
						this.points.push(napDrawingCursor)
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
                }
        } catch (e) { 
            console.log("*** Error: " + this.opcode.id + " contains no coordinates. ***")
        }

        if (_set) {
        	try {
        		var lastPoint = this.points[this.point.length-1];
        		napDrawingCursor = new Vector2(lastPoint.x, lastPoint.y);
        	} catch (e) { 
            	console.log("*** Error: " + this.opcode.id + " tried to set cursor position but failed. ***")
        	}
        }
    }

    getColor() {
    	var nc = new NapColor(this.data);
    	// TODO distinguish between rgb and color map
    	this.col = new Vector3(nc.r, nc.g, nc.b);
    }

    getText() {
        var nt = new NapText(this.data);
        this.text += nt.text;
    }

    getDomain() {
    	/*
    	Only the first byte after the domain opcode (21) is relevant to us.
    	The rest of the bytes control “logical pel size”, which was a feature of vector monitors.

		In the domain byte, bits 6,5,4,3,2,1 contain the following information:
		* Bit 6 controls 2D vs. 3D coordinates:
		         0  XY (the default)
		         1  XYZ

		 * Bits 5, 4, 3 control the length of a multi-value operand:
		         0 0 0   1 byte
		         0 0 1   2 bytes
		         0 1 0   3 bytes (the default)
		         0 1 1   4 bytes
		         1 0 0   5 bytes
		         1 0 1   6 bytes
		         1 1 0   7 bytes
		         1 1 1   8 bytes

		* Bits 2, 1 control the length of a single value operand:
		         0 0    1 byte (the default)
		         0 1    2 bytes
		         1 0    3 bytes
		         1 1    4 bytes
		*/
    	if (this.data.length < 1) return;
    	var domainByte = this.data[0].getBinary();
    	var domainPointBytes = domainByte[2] + domainByte[3] + domainByte[4];
    	var domainSingleBytes = domainByte[5] + domainByte[6];
    	switch (domainPointBytes) {
   			case("000"):
   				this.pointBytes = 1;
   				break;   
		    case("001"):
		    	this.pointBytes = 2;
		    	break;
		    case("010"):
		    	this.pointBytes = 3;
		    	break;
		    case("011"):
		    	this.pointBytes = 4;
		    	break;
		    case("100"):
		    	this.pointBytes = 5;
		    	break;
		    case("101"):
		    	this.pointBytes = 6;
		    	break;
		    case("110"):
		    	this.pointBytes = 7;
		    	break;
		    case("111"):
		    	this.pointBytes = 8;
		    	break;
	    	default:
	    		this.pointBytes = 3;
	    		break;
    	}
    	switch (domainSingleBytes) {
		    case("00"):
		        this.singleBytes = 1;
		        break;
		    case("01"):
		        this.singleBytes = 2;
		        break;
		    case("10"):
		        this.singleBytes = 3;
		        break;
		    case("11"):
		        this.singleBytes = 4;
		        break;
		    default:
		    	this.singleBytes = 1;
		    	break;
    	}

    	//this.pointBytes = 1 + ((domainByte & '\x1C') >> 2);
    	//this.singleBytes = 1 + (domainByte & '\x3c');
    	console.log("DOMAIN SETTINGS: " + this.pointBytes + " bytes per coordinate.");


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
        this.colorMap = [];

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
                        var nextNapCmd = new NapCmd(tempCmd, this.counter);
                        this.cmds.push(nextNapCmd);
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

    defaultColorMap() {
		for (var i = 0; i <= 7; i++) {		// 1-8. grayscale
			this.colorMap.push(createColor(i*32, i*32, i*32));
    	}

		// following aren't all exact (some are), but close
		this.colorMap.push(createColor(0, 0, 255)); // 9. blue
		this.colorMap.push(createColor(5*36, 0, 7*36)); // 10. blue magenta
		this.colorMap.push(createColor(7*36, 0, 4*36)); // 11. pinkish red
		this.colorMap.push(createColor(7*36, 2*36, 0)); // 12. orange red
		this.colorMap.push(createColor(255, 255, 0)) // 13. yellow
		this.colorMap.push(createColor(2*36, 7*36, 0)); // 14. yellow green
		this.colorMap.push(createColor(0, 7*36, 4*36)); // 15. greenish
		this.colorMap.push(createColor(0, 5*36, 7*36)); // 16. bluegreen  	
    }
    
}