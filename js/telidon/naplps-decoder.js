"use strict";

/* 
NAPLPS JavaScript decoder (part of the TelidonP5 Project)
Nick Fox-Gieg https://fox-gieg.com

Note: Uses no p5.js-specific code

Binary utilities adapted from the methods in:
https://github.com/processing-js/processing-js
*/

/*
* binary()
* Converts a byte, char, int, or color to a String containing the equivalent binary
* notation. For example color(0, 102, 153, 255) will convert to the String
* "11111111000000000110011010011001".
*
* @param {byte|char|int|color} num                    byte, char, int, color: value to convert
* @param {int} numBits                                            number of digits to return
* @returns {String}
*/

function binary(num, numBits) {
    var bit;
    if (numBits > 0) {
        bit = numBits;
    } else if(num instanceof Char) {
        bit = 16;
        num |= 0; // making it int
    } else {
        // autodetect, skipping zeros
        bit = 32;
        while (bit > 1 && !((num >>> (bit - 1)) & 1)) {
            bit--;
        }
    }
    var result = "";
    while (bit > 0) {
        result += ((num >>> (--bit)) & 1) ? "1" : "0";
    }
    return result;
}

/*
* unbinary()
* Converts a String representation of a binary number to its equivalent integer value.
* For example, unbinary("00001000") will return 8.
*
* @param {String} binaryString String
* @returns {Int}
*/
function unbinary(binaryString) {
    var i = binaryString.length - 1, mask = 1, result = 0;
    while (i >= 0) {
        var ch = binaryString[i--];
        if (ch !== '0' && ch !== '1') {
            throw "the value passed into unbinary was not an 8 bit binary number";
        }
        if (ch === '1') {
            result += mask;
        }
        mask <<= 1;
    }
    return result;
}

function decimalToHex(d, padding) {
    //if there is no padding value added, default padding to 8 else go into while statement.
    padding = (padding === undefined || padding === null) ? padding = 8 : padding;
    if (d < 0) {
        d = 0xFFFFFFFF + d + 1;
    }
    var hex = Number(d).toString(16).toUpperCase();
    while (hex.length < padding) {
        hex = "0" + hex;
    }
    if (hex.length >= padding) {
        hex = hex.substring(hex.length - padding, hex.length);
    }
    return hex;
}

/*
* hex()
* Converts a byte, char, int, or color to a String containing the equivalent hexadecimal notation.
* For example color(0, 102, 153, 255) will convert to the String "FF006699".
*
* Note: since we cannot keep track of byte, int types by default the returned string is 8 chars long
* if no 2nd argument is passed.    closest compromise we can use to match java implementation Feb 5 2010
* also the char parser has issues with chars that are not digits or letters IE: !@#$%^&*
*
* @param {byte|char|int|Color} value     the value to turn into a hex string
* @param {int} digits                                 the number of digits to return
* @returns {String}
*/
function hex(value, len) {
    if (arguments.length === 1) {
        if (value instanceof Char) {
            len = 4;
        } else { // int or byte, indistinguishable at the moment, default to 8
            len = 8;
        }
    }
    return decimalToHex(value, len);
}

function unhexScalar(hex) {
    var value = parseIntAlt("0x" + hex, 16);

    // correct for int overflow java expectation
    if (value > 2147483647) {
        value -= 4294967296;
    }
    return value;
}

/*
* unhex()
* Converts a String representation of a hexadecimal number to its equivalent integer value.
*
* @param {String} hex     the hex string to convert to an int
* @returns {int}
*/
function unhex(hex) {
    if (hex instanceof Array) {
        var arr = [];
        for (var i = 0; i < hex.length; i++) {
            arr.push(unhexScalar(hex[i]));
        }
        return arr;
    }
    return unhexScalar(hex);
}

function parseIntAlt(val, radix) {
    if (val instanceof Array) {
        var ret = [];
        for (var i = 0; i < val.length; i++) {
            if (typeof val[i] === 'string' && !/^\s*[+\-]?\d+\s*$/.test(val[i])) {
                ret.push(0);
            } else {
                ret.push(intScalar(val[i], radix));
            }
        }
        return ret;
    }
    return intScalar(val, radix);
}

function intScalar(val, radix) {
    if (typeof val === 'number') {
        return val & 0xFFFFFFFF;
    }
    if (typeof val === 'boolean') {
        return val ? 1 : 0;
    }
    if (typeof val === 'string') {
        var number = parseIntAlt(val, radix || 10); // Default to decimal radix.
        return number & 0xFFFFFFFF;
    }
    if (val instanceof Char) {
        return val.code;
    }
}

function removeCharAt(s, index) { // string, int
  var returns = "";
  for (var i=0; i<s.length; i++) {
    if (i != index) returns += s.charAt(i);
  }
  return returns;
}

class Char {

    constructor(chr) {
        if (typeof chr === 'string' && chr.length === 1) {
            this.code = chr.charCodeAt(0);
        } else if (typeof chr === 'number') {
            this.code = chr;
        } else if (chr instanceof Char) {
            this.code = chr;
        } else {
            this.code = NaN;
        }
        return this.code;
    }

    toString() {
        return String.fromCharCode(this.code);
    }

    valueOf() {
        return this.code;
    }

}

class Vector2 {

    constructor(_x, _y) {
        this.x = _x;
        this.y = _y;
    }

}

class Vector3 {

    constructor(_x, _y, _z) {
        this.x = _x;
        this.y = _y;
        this.z = _z;
    }

}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

var napDrawingCursor = new Vector2(0.0, 0.0);

var black = new Vector3(0, 0, 0);
var gray1 = new Vector3(32, 32, 32);
var gray2 = new Vector3(64, 64, 64);
var gray3 = new Vector3(96, 96, 96);
var gray4 = new Vector3(128, 128, 128);
var gray5 = new Vector3(160, 160, 160);
var gray6 = new Vector3(192, 192, 192);
var gray7 = new Vector3(224, 224, 224);
var blue = new Vector3(0, 0, 255);
var blue_magenta = new Vector3(5*36, 0, 7*36);
var pinkish_red = new Vector3(7*36, 0, 4*36);
var orange_red = new Vector3(7*36, 2*36, 0);
var yellow = new Vector3(255, 255, 0);
var yellow_green = new Vector3(2*36, 7*36, 0);
var greenish = new Vector3(0, 7*36, 4*36);
var bluegreen = new Vector3(0, 5*36, 7*36);  

// white is not part of the default palette
var white = new Vector3(255, 255, 255);

var colorMap = [ black, gray1, gray2, gray3, gray4, gray5, gray6, gray7, blue, blue_magenta, pinkish_red, orange_red, yellow, yellow_green, greenish, bluegreen ]; 
var colorMode = 0;
var currentColor = white;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~


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
                returns = "Shift-In"; // text mode, data that follows is text. Handled in step 2.
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
                returns = "SET COLOR";
                break;
            case("3D"):
                returns = "WAIT";
                break;
            case("3E"):
                returns = "SELECT COLOR"; 
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


// 2.4. Text
class NapText extends NapDataArray {
    // TODO figure out text formatting

    constructor(n) { // NapData[]
        super(n);
        this.text = this.setTextFromBytes(n);
    }

    setTextFromBytes(n) {
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
        this.col = currentColor;
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
                this.setText();
                break;
            case("CANCEL"):
               	// no effect?
                break;
            case("ESC"):
               	// no effect?
                break;
            case("NSR"): // Non-Selective Reset
               	this.sendNsr();
                break;
            //~ ~ ~ ~ ~ PDI (PICTURE DESCRIPTION INSTRUCTION) CODES ~ ~ ~ ~ ~
            //~ ~ ~ ENVIRONMENT, part 1 ~ ~ ~
            case("RESET"):
               	this.sendReset();
                break;
            case("DOMAIN"): // header information
               	this.setDomain();
                break;
            case("TEXT"): // formats text, doesn't contain text itself
                // TODO
                break;
            case("TEXTURE"):
               	// TODO
                break;
            //~ ~ ~ POINTS ~ ~ ~
            case("POINT SET ABS"):
                this.setPoints(false, true); // relative, set cursor
                break;
            case("POINT SET REL"):
                this.setPoints(true, true);
                break;
            case("POINT ABS"):
                this.setPoints(false, false);
                break;
            case("POINT REL"):
                this.setPoints(true, false);
                break;
            //~ ~ ~ LINES ~ ~ ~
            case("LINE ABS"):
                this.setPoints(true, false); // TODO why is this broken?
                break;
            case("LINE REL"):
                this.setPoints(true, false);
                break;
            case("SET & LINE ABS"):
                this.setPoints(true, true); // TODO why is this broken?
                break;
            case("SET & LINE REL"):
                this.setPoints(true, true);
            	break;
            //~ ~ ~ ARCS ~ ~ ~
            case("ARC OUTLINED"):
                this.setPoints(true, false);
                break;
            case("ARC FILLED"):
                this.setPoints(true, false);
                break;
            case("SET & ARC OUTLINED"):
                this.setPoints(false, true);
                break;
            case("SET & ARC FILLED"):
                this.setPoints(false, true);
            	break;
            //~ ~ ~ RECTANGLES ~ ~ ~
            case("RECT OUTLINED"):
                this.setPoints(true, false);
                break;
            case("RECT FILLED"):
                this.setPoints(true, false);
                break;
            case("SET & RECT OUTLINED"):
                this.setPoints(false, true);
                break;
            case("SET & RECT FILLED"):
                this.setPoints(false, true);
            	break;
            //~ ~ ~ POLYGONS ~ ~ ~
            case("POLY OUTLINED"):
                this.setPoints(true, false);
                break;
            case("POLY FILLED"):
                this.setPoints(true, false);
                break;
            case("SET & POLY OUTLINED"): // relative points after first 
                this.setPoints(false, true);
                break;
            case("SET & POLY FILLED"): // relative points after first 
                this.setPoints(false, true);
                break;
            //~ ~ ~ INCREMENTALS ~ ~ ~
            case("FIELD"):
               	// TODO
                break;
            case("INCREMENTAL POINT"):
                this.setPoints(true, true);
                break;
            case("INCREMENTAL LINE"):
                this.setPoints(true, true);
                break;
            case("INCREMENTAL POLY FILLED"):
                this.setPoints(true, true);
                break;
            //~ ~ ~ ENVIRONMENT, part 2 ~ ~ ~ 
            case("SET COLOR"): 
               	this.setColor(); // rgb color
                break;
            case("WAIT"):
               	// TODO
                break;
            case("SELECT COLOR"): 
               	this.selectColor(); // palette color
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
    setPoints(_allPointsRelative, _set) {
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
                returns += n[i].binary.charAt(1).toString();
                returns += n[i].binary.charAt(2).toString();
            } else if (channel === "r") {
                returns += n[i].binary.charAt(3).toString();
                returns += n[i].binary.charAt(4).toString();
            } else if (channel === "b") {
                returns += n[i].binary.charAt(5).toString();
                returns += n[i].binary.charAt(6).toString();
            }
        }

        return parseInt(255 * (1.0 - (unbinary(returns) / this.bitVals)));
    }

    sendReset() {
        // TODO
    }

    sendNsr() {
        colorMode = 0;
        currentColor = new Vector3(255, 255, 255);
    }

    getPaletteIndexFromBytes(n) {
        var returns = "";

        returns += n[0].binary.charAt(1).toString();
        returns += n[0].binary.charAt(2).toString();
        returns += n[0].binary.charAt(3).toString();
        returns += n[0].binary.charAt(4).toString();
        returns += n[0].binary.charAt(5).toString();
        returns += n[0].binary.charAt(6).toString();

        return parseInt((returns & parseInt('074', 8))>>2);
    }

    setColor() {
        var r = this.getColorFromBytes(this.data, "r");
        var g = this.getColorFromBytes(this.data, "g");
        var b = this.getColorFromBytes(this.data, "b");
        currentColor = new Vector3(r, g, b);
        this.col = currentColor;
        console.log("Select color: " + currentColor.x + " " + currentColor.y + " " + currentColor.z);
    }

    selectColor() {
        var last = this.data.length - 1;
        var index = -1;
        if (this.data[last].ascii < 40) {
            colorMode = 0;
        } else {
            colorMode = 1;
            index = this.getPaletteIndexFromBytes(this.data); // int
            currentColor = colorMap[index];
        }
        this.col = currentColor;
        console.log("Select color: index " + index + ", " + currentColor.x + " " + currentColor.y + " " + currentColor.z);
    }

    setText() {
        var nt = new NapText(this.data);
        this.text += nt.text;
    }

    setDomain() {
    	/*
    	Only the first byte after the domain opcode (21) is used here.
    	The rest of the bytes control "logical pel size" (the ability to render images at a 
        different resolution than the display, in this case the browser canvas).
        Logical pel size is not implemented.

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
        this.napRaw = input[0]; // string
        this.cmds = this.parseCommands(this.napRaw); // NapCmd[]
    }
    
    isOpcode(c) { // char or string
        var b = binary(c);
        return b[b.length-7] === '0';
    }

    parseCommands(input) {
    	var returns = [];

	    var counter = 0; // int
        var tempCmd = "";

        for (var i=0; i<input.length; i++) {
            var c = input[i]; // char or string
            if (this.isOpcode(new Char(c))) {
                if (tempCmd === "") {
                    tempCmd += c;
                } else {
                    if (tempCmd.length >= 1) {
                        var nextNapCmd = new NapCmd(tempCmd, counter);
                        returns.push(nextNapCmd);
                        counter++;
                    }
                    tempCmd = "";
                    tempCmd += c;
                }
            } else {
                tempCmd += c;
            }
        }

        for (var i=0; i<returns.length; i++) {
            returns[i].printCmd("hex");
        }    

        return returns;
    }
   
}

