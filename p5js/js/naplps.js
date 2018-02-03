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
class NapOpcode {
	//
}

// 1.3. The NapChars following an opcode contain the data that 
// the command will use.
class NapData {
	//
}


// 2. MULTI-BYTE data classes
//
// 2.1. Some NapData objects need to be combined for decoding. 
// XY and XYZ position are handled by the NapVector class.
class NapVector {
    
    NapVector(n) { // NapData[]
        this.bitsPerByte = 3; // int, TODO set programatically from header info based on XY / XYZ
        this.firstBitSign = true; // bool, should be true for all header options
        this.bitVals = pow(2, (n.size() * bitsPerByte) - int(firstBitSign)); // float
        this.x = this.getCoordFromBytes(n, "x"); // float
        this.y = this.getCoordFromBytes(n, "y"); // float
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
                returns = "" + this.binaryConv(n, 4);
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
     
    getCoordFromBytes(n, axis) { // NapData[], string
        var returns = "";
        for (var i=0; i<n.size(); i++) {
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
        }

        return finalReturns;
    }

}


// 3. COMMAND: One decoded drawing command.
// Assembled from the opcode and data bytes.
class NapCmd {
    
    // TODO draw each command to its own PGraphics buffer.
    constructor(_cmd, _index) { // string, int
        this.pointBytes = 4; // int, TODO set programatically from header info
        this.pointRelative = true;    // bool, TODO set programatically from header info
        this.cmdRaw = _cmd; // string
        this.index = _index; // int
        this.data = []; // NapData[]
        this.points = []; // PVector[]
        
        this.opcode = new NapOpcode(this.cmdRaw.charAt(0)); // NapOpcode
        if (this.cmdRaw.length > 1) {
            for (var i=1; i<this.cmdRaw.length; i++) {
                data.push(new NapData(this.cmdRaw.charAt(i)));
            }
        }
        
        // This is where we find out what kind of command it is
        // Which tells us how we handle the data
        switch(this.opcode.id) {
            case("SET & POLY FILLED"): // relative points after first 
                this.getPoints();
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
        var returns = "(" + index + ") " + this.opcode.id;
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
        var nvList = []; // NapVector[];
        for (var i=0; i<data.length; i+=pointBytes) {
            var n = []; // NapData[]
            for (var j=0; j<pointBytes; j++) {
                n.push(data[i + j]);
            }
            nvList.push(new NapVector(n));
        }
        
        for (var i=0; i<nvList.length; i++) {
            var nv = nvList[i];

            if (pointRelative) {
                if (i===0) {
                    points.push(new PVector(nv.x, nv.y));
                } else {
                    var p = points[points.length-1];
                    
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
                    
                    points.push(new PVector(x, y));
                }
            } else {
                points.push (new PVector(nv.x, nv.y));
            }
            // * * * * * 
        }
    }
    
    getDomain() {
        for (var i=0; i<data.length; i++) {
            // TODO parse header info, most importantly:
            // How many bytes per point
            // XY format (3 bits per axis per byte) or XYZ format (2 bits per axis per byte)
            // How many bytes per color
            // Color format?
        }
    }
    
}


// 4. DECODER: Contains all the decoded drawing commands.
// Decodes the format only; drawing happens in NapDraw
class NapDecoder {
    
    constructor(input) { // string[]
        this.napRaw = ""; // string
        this.cmds = []; // NapCmd[]
        this.counter = 0; // int
        this.debug = true; // bool

        for (var i=0; i<input.length; i++) {
            napRaw += input[i];
        }
        
        var tempCmd = "";
        for (var i=0; i<napRaw.length; i++) {
            var c = napRaw.charAt(i); // char or string
            if (isOpcode(c)) {
                if (tempCmd.equals("")) {
                    tempCmd += c;
                } else {
                    if (tempCmd.length >= 1) {
                        cmds.add(new NapCmd(tempCmd, counter));
                        counter++;
                    }
                    tempCmd = "";
                    tempCmd += c;
                }
            } else {
                tempCmd += c;
            }
        }
        
        if (debug) {
            for (var i=0; i<cmds.length; i++) {
                cmds[i].printCmd("hex");
            }
        }
    }
    
    isOpcode(c) { // char or string
        var b = binary(c);
        return b.charAt(b.length-7) === '0';
    }
    
}