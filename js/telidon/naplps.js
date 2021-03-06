"use strict";

/* 
+ + +          NAPLPS for JavaScript          + + + 
+ + +     (part of the TelidonP5 Project)     + + +
+ + +   Nick Fox-Gieg  https://fox-gieg.com   + + +

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
    let bit;
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
    let result = "";
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
    let i = binaryString.length - 1, mask = 1, result = 0;
    while (i >= 0) {
        let ch = binaryString[i--];
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
    let hex = Number(d).toString(16).toUpperCase();
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
    let value = parseIntAlt("0x" + hex, 16);

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
        let arr = [];
        for (let i = 0; i < hex.length; i++) {
            arr.push(unhexScalar(hex[i]));
        }
        return arr;
    }
    return unhexScalar(hex);
}

function parseIntAlt(val, radix) {
    if (val instanceof Array) {
        let ret = [];
        for (let i = 0; i < val.length; i++) {
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
        let number = parseIntAlt(val, radix || 10); // Default to decimal radix.
        return number & 0xFFFFFFFF;
    }
    if (val instanceof Char) {
        return val.code;
    }
}

function removeCharAt(s, index) { // string, int
  let returns = "";
  for (let i=0; i<s.length; i++) {
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



// + + +   D E C O D E R   + + +

// The original NAPLPS decoders assumed a global state for reading colors.
// In our decoder, we don't have to use a limited palette, so 
// once read, each RGB color is just stored in its drawing command.

let naplps_drawingCursor = new Vector2(0.0, 0.0);

let naplps_black = new Vector3(0, 0, 0);
let naplps_gray1 = new Vector3(32, 32, 32);
let naplps_gray2 = new Vector3(64, 64, 64);
let naplps_gray3 = new Vector3(96, 96, 96);
let naplps_gray4 = new Vector3(128, 128, 128);
let naplps_gray5 = new Vector3(160, 160, 160);
let naplps_gray6 = new Vector3(192, 192, 192);
let naplps_gray7 = new Vector3(224, 224, 224);
let naplps_blue = new Vector3(0, 0, 255);
let naplps_blue_magenta = new Vector3(5*36, 0, 7*36);
let naplps_pinkish_red = new Vector3(7*36, 0, 4*36);
let naplps_orange_red = new Vector3(7*36, 2*36, 0);
let naplps_yellow = new Vector3(255, 255, 0);
let naplps_yellow_green = new Vector3(2*36, 7*36, 0);
let naplps_greenish = new Vector3(0, 7*36, 4*36);
let naplps_bluegreen = new Vector3(0, 5*36, 7*36);  

// naplps_white is not part of the default palette
let naplps_white = new Vector3(255, 255, 255);

let naplps_defaultColorMap = [ naplps_black, naplps_gray1, naplps_gray2, naplps_gray3, naplps_gray4, naplps_gray5, naplps_gray6, naplps_gray7, naplps_blue, naplps_blue_magenta, naplps_pinkish_red, naplps_orange_red, naplps_yellow, naplps_yellow_green, naplps_greenish, naplps_bluegreen ]; 
let naplps_colorMap = [ naplps_black, naplps_gray1, naplps_gray2, naplps_gray3, naplps_gray4, naplps_gray5, naplps_gray6, naplps_gray7, naplps_blue, naplps_blue_magenta, naplps_pinkish_red, naplps_orange_red, naplps_yellow, naplps_yellow_green, naplps_greenish, naplps_bluegreen ]; 
let naplps_colorMode = 0;
let naplps_lastColor = naplps_white;
let naplps_lastIndex = 0;

let naplps_backgroundColor = naplps_black;
let naplps_drawBackground = true;
let naplps_singleValLength = 1;
let naplps_multiValLength = 3;
let naplps_minVal = 40; // 64
let naplps_is3D = false;

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
        let returns = "";
        let b = binary(this.ascii);
        for (let i=b.length-7; i<b.length; i++) {
            returns += b.charAt(i);
        }
        return returns;
    }
    
    getRBinary() { // reverse binary
        return this.binary.split("").reverse().join("");
    }
    
    getHex() {
        let returns = "";
        let h = hex(parseIntAlt(this.ascii));
        for (let i=h.length-2; i<h.length; i++) {
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
        let returns = "";
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
        let returns = parseFloat(this.ascii / 127.0);
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
        let returns = "";
        for (let i=loc; i<loc+this.bitsPerByte; i++) {
            returns += n.binary.charAt(i);
        }
        return returns;
    }
    
    getSingleByteVal(n, axis) { // NapData, string
        let returns = "";
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
        let returns = "";
        for (let i=0; i<n.length; i++) {
            returns += this.getSingleByteVal(n[i], axis);
        }
        
        let sign = 1;
        if (this.firstBitSign) {
            sign = this.getSign(returns.charAt(0));
            returns = removeCharAt(returns, 0);
        }
        
        let finalReturns = 0;
        
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


// 2.3. Text
class NapText extends NapDataArray {
    // TODO figure out text formatting

    constructor(n) { // NapData[]
        super(n);
        this.text = this.setTextFromBytes(n);
    }

    setTextFromBytes(n) {
        let returns = "";
        for (let i=0; i<n.length; i++) {
            returns += "" + n[i].c;
        }
        return returns;
    }

}


// 3. COMMAND: One decoded drawing command.
// Assembled from the opcode and data bytes.
class NapCmd {
    
    constructor(_cmd, _index) { // string, int
        this.pointBytes = naplps_multiValLength; // int
        this.singleBytes = naplps_singleValLength; // int
        //this.pointRelative = true; // bool, TODO set programatically from header info...if this is in header?
        this.cmdRaw = _cmd; // string
        this.index = _index; // int
        this.data = []; // NapData[]
        this.points = []; // PVector[]
        this.col = naplps_lastColor;
        this.text = "";

        this.opcode = new NapOpcode(this.cmdRaw.charAt(0)); // NapOpcode
        if (this.cmdRaw.length > 1) {
            for (let i=1; i<this.cmdRaw.length; i++) {
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
               	this.setColor(); 
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
        let returns = "(" + this.index + ") " + this.opcode.id;
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
            for (let i=0; i<this.data.length; i++) {
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
    setColor() {
        let r = 0, g = 0, b = 0;
        let r2 = 0, g2 = 0, b2 = 0;
        let colorValLength = this.data.length;
        let shift = 8 - (2 * colorValLength);
        naplps_lastColor = naplps_yellow; // default
        
        try {
            let c = this.data[0].ascii;
            if (c < naplps_minVal) {
                this.col = naplps_lastColor;
                return false;
            }
            g = c & parseInt('040', 8);
            r = c & parseInt('020', 8);
            b = c & parseInt('010', 8);
            c <<= 2;
            g |= c & parseInt('020', 8);
            r |= c & parseInt('010', 8);
            b |= c & parseInt('004', 8);
            g >>= 4;
            r >>= 3;
            b >>= 2;
            for (let i = 1; i < colorValLength; i++ ) {
                c = this.data[i].ascii;
                if (c < naplps_minVal) {
                    this.col = naplps_lastColor;
                    return false;
                }
                g2 = c & parseInt('040', 8);
                r2 = c & parseInt('020', 8);
                b2 = c & parseInt('010', 8);
                c <<= 2;
                g2 |= c & parseInt('020', 8);
                r2 |= c & parseInt('010', 8);
                b2 |= c & parseInt('004', 8);
                g2 >>= 4;
                r2 >>= 3;
                b2 >>= 2;
                g <<= 2;
                r <<= 2;
                b <<= 2;
                g |= g2;
                r |= r2;
                b |= b2;
            }
            let fill = 0; //(2 << shift) - 1;
            r <<= shift;
            g <<= shift;
            b <<= shift;

            naplps_lastColor = new Vector3(r+fill, g+fill, b+fill);

            if (naplps_colorMode !== 0) {
                naplps_colorMap[naplps_lastIndex] = naplps_lastColor;
                console.log("<palette write>\nindex: " + naplps_lastIndex + ", color: " + naplps_lastColor.x + " " + naplps_lastColor.y + " " + naplps_lastColor.z);
            } else {
                console.log("<palette read>\nindex: " + naplps_lastIndex + ", color: " + naplps_lastColor.x + " " + naplps_lastColor.y + " " + naplps_lastColor.z);
            }

            this.col = naplps_lastColor;
            return true;
        } catch (e) {
            this.col = naplps_lastColor;
            return false;
        }
    }

    selectColor() {
        try {
            let c = this.data[0].ascii;
            if (c < naplps_minVal) {
                naplps_colorMode = 0;
                return;
            }

            naplps_lastIndex = (c & parseInt('074', 8)) >> 2;
            naplps_colorMode = 1;
            naplps_lastColor = naplps_colorMap[naplps_lastIndex];
            console.log("<palette read>\nindex: " + naplps_lastIndex + ", color: " + naplps_lastColor.x + " " + naplps_lastColor.y + " " + naplps_lastColor.z);
            //ignore mode 2 for now
        
            this.col = naplps_lastColor;
            return true;
        } catch (e) {
            naplps_colorMode = 0;

            this.col = naplps_lastColor;
            return false;
        }
    }

    setPoints(_allPointsRelative, _set) {
        try {
            let nvList = []; // NapVector[];
            for (let i=0; i<this.data.length; i+=this.pointBytes) {
                let n = []; // NapData[]
                for (let j=0; j<this.pointBytes; j++) {
                    n.push(this.data[i + j]);
                }
                nvList.push(new NapVector(n));
            }
            
            for (let i=0; i<nvList.length; i++) {
                let nv = nvList[i];

                    if (!_allPointsRelative && i===0) {
                        this.points.push(new Vector2(nv.x, nv.y));
                    } else if (_allPointsRelative && i===0) {
						this.points.push(naplps_drawingCursor)
					} else {
                        let p = this.points[this.points.length-1];
                        
                        let x = 0;         
                        if (nv.x < 0) {
                            x = (abs(nv.x) + abs(p.x)) - 1.0;
                        } else {
                            x = nv.x + p.x;
                        }
                        
                        let y = 0;
                        if (nv.y < 0) {
                            y = abs(nv.y) + p.y;
                        } else {
                            y = (abs(nv.y) + abs(p.y)) - 1.0;
                        }
                        
                        this.points.push(new Vector2(x, y));
                    }
                }
        } catch (e) { 
            console.log("*Error* " + this.opcode.id + " contains no coordinates.")
        }

        if (_set) {
        	try {
        		let lastPoint = this.points[this.point.length-1];
        		naplps_drawingCursor = new Vector2(lastPoint.x, lastPoint.y);
        	} catch (e) { 
            	console.log("*Error* " + this.opcode.id + " tried to set cursor position but failed.")
        	}
        }
    }

    sendReset() {
        try {
            let c = this.data[0].ascii;
            if (c < naplps_minVal) {
                return;
            }
            if ((c & parseInt('001', 8)) != 0) { // reset domain
                naplps_singleValLength = 1;
                naplps_multiValLength = 3;
                naplps_is3D = false;
            }
            let colormodeVal = ((c & parseInt('005', 8)) >> 1);
            switch (colormodeVal) {
                case 0:
                    break;
                case 1:
                    naplps_colorMode = 0;
                    break;
                case 2:
                    naplps_colorMode = 1;
                    break;
                case 3:
                    naplps_colorMode = 1;
                    naplps_lastColor = naplps_white;
                    break;
            }
            let screenVal = ((c & parseInt('070', 8)) >> 3);
            //let saveColor = naplps_lastColor;
            switch (screenVal) {
                case 0:
                    break;
                case 1:
                case 7:
                    //gr.clearRect(0, 0, ctx.screen, ctx.screen);
                    break;
                case 2:
                case 5:
                case 6:
                    //gr.fillRect(0, 0, ctx.screen, ctx.screen);
                    if (screenstuff != 6)
                        break;      // case 6 drops through to 3
                case 3:
                    //gr.setColor(Color.naplps_black);
                    //gr.drawRect(0, 0, ctx.screen, ctx.screen);
                    //naplps_lastColor = saveColor;
                    break;
                case 4:
                    //gr.drawRect(0, 0, ctx.screen, ctx.screen);
                    break;
                }
            c = this.data[1].ascii;
            if (c < naplps_minVal) {
                return;
            }
            if ((c & parseInt('001', 8)) != 0) {       // reset text
                naplps_drawingCursor = new Vector2(0.0, 0.0);
            }
            if ((c & parseInt('010', 8)) != 0) {       // reset texture
                //ctx.highlight = false;
                //ctx.lineTexture = 0;
                //ctx.texturePattern = 0;
            }
            // for now ignore the rest
        } catch (e) { }
    }

    sendNsr() {
        naplps_colorMode = 0;
        for (let i=0; i<naplps_colorMap.length; i++) {
            naplps_colorMap[i] = naplps_defaultColorMap[i];
        }
        naplps_lastColor = new Vector3(255, 255, 255);
    }

    setText() {
        let nt = new NapText(this.data);
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
    	let domainByte = this.data[0].getBinary();
    	let domainPointBytes = domainByte[2] + domainByte[3] + domainByte[4];
    	let domainSingleBytes = domainByte[5] + domainByte[6];
    	
    	// TODO find out why this fails in some cases
    	switch (domainPointBytes) {
   			case("000"):
   				naplps_multiValLength = 1;
   				break;   
		    case("001"):
		    	naplps_multiValLength = 2;
		    	break;
		    case("010"):
		    	naplps_multiValLength = 3;
		    	break;
		    case("011"):
		    	naplps_multiValLength = 4;
		    	break;
		    case("100"):
		    	naplps_multiValLength = 5;
		    	break;
		    case("101"):
		    	naplps_multiValLength = 6;
		    	break;
		    case("110"):
		    	naplps_multiValLength = 7;
		    	break;
		    case("111"):
		    	naplps_multiValLength = 8;
		    	break;
	    	default:
	    		naplps_multiValLength = 3;
	    		break;
    	}

    	switch (domainSingleBytes) {
		    case("00"):
		        naplps_singleValLength = 1;
		        break;
		    case("01"):
		        naplps_singleValLength = 2;
		        break;
		    case("10"):
		        naplps_singleValLength = 3;
		        break;
		    case("11"):
		        naplps_singleValLength = 4;
		        break;
		    default:
		    	naplps_singleValLength = 1;
		    	break;
    	}

    	//this.pointBytes = 1 + (domainByte & '\x1C' >> 2);
    	//this.singleBytes = 1 + (domainByte & '\x3c');
    	console.log("DOMAIN SETTINGS: " + naplps_multiValLength + " bytes per coordinate.");


    }
    
}


// 4. DECODER: Contains all the decoded drawing commands.
// Decodes the format only; drawing happens in TelidonDraw
class NapDecoder {
    
    constructor(input) { // string[]
        this.napRaw = input[0]; // string
        this.cmds = this.parseCommands(this.napRaw); // NapCmd[]
        this.version = this.detectVersion();
        console.log("* * * * * * * * * * *\n" + "Telidon " + this.version + " file containing " + this.cmds.length + " commands.\n" + "* * * * * * * * * * *\n");
    }
    
    detectVersion() {
    	let input = this.cmds[0].opcode.hex;
    	if (input == "0E") { // TODO find additional cases
    		return 699;
    	} else {
    		return 709;
    	}
    }

    isOpcode(c) { // char or string
        let b = binary(c);
        return b[b.length-7] === '0';
    }

    parseCommands(input) {
    	let returns = [];

	    let counter = 0; // int
        let tempCmd = "";

        for (let i=0; i<input.length; i++) {
            let c = input[i]; // char or string
            if (this.isOpcode(new Char(c))) {
                if (tempCmd === "") {
                    tempCmd += c;
                } else {
                    if (tempCmd.length >= 1) {
                        let nextNapCmd = new NapCmd(tempCmd, counter);
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

        for (let i=0; i<returns.length; i++) {
            returns[i].printCmd("hex");
        }    

        return returns;
    }
   
}

// + + +   E N C O D E R   + + +

class StrokeWrapper {

	constructor(_color,_points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
	}

}

class NapEncoder {

	constructor(input) {
		this.cmds = this.parseCommands(input);
		this.napRaw = this.cmds.join("");
		console.log(napRaw);
	}

	parseCommands(input) {
		let returns = [];

		input = this.normalizeAllStrokes(input);

		for (let stroke of input) {
			let cmd = this.makeNapOpcode(stroke.isFill);
			cmd += this.makeNapColor(stroke.color);
			
			for (let point of stroke.points) {
				cmd += this.makeNapVector(point);
			}

			returns.push(cmd);
		}

		return returns;
	}

	normalizeAllStrokes(input) {
		let minX = 0;
		let maxX = 0;
		let minY = 0;
		let maxY = 0;
		let minVal = 0;
		let maxVal = 0;
		
		for (let stroke of input) {
			for (let point of stroke.points) {
				if (point.x < minX) {
					minX = point.x;
				} else if (point.x > maxX) {
					maxX = point.x;
				}
				if (point.y < minY) {
					minY = point.y;
				} else if (point.y > maxY) {
					maxY = point.y;
				}
			}
		}

		if (Math.abs(maxX - minX) > Math.abs(maxY - minY)) {
			maxVal = maxX;
			minVal = minX;
		} else {
			maxVal = maxY;
			minVal = minY;
		}

		for (let stroke of input) {
			for (let point of stroke.points) {
				point.x = this.remap(point.x, minVal, maxVal, 0, 1);
				point.y = this.remap(point.y, minVal, maxVal, 0, 1);
			}
		}

		return input;
	}

	remap(value, min1, max1, min2, max2) {
        let range1 = max1 - min1;
        let range2 = max2 - min2;
        let valueScaled = (value - min1) / range1;
        return min2 + (valueScaled * range2);
    }

	makeNapOpcode(_isFill) { // only poly line and fill are implemented
		if (_isFill) {
			return "A";
		} else {
			return "B";
		}
	}

	makeNapColor(_color) {
		return "C";
	}

	makeNapVector(input) {
		return "D";		
	}

}

