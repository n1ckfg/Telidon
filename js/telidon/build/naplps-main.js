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

function unbinaryToFloat(binaryString) {
    let bytes = unbinary(binaryString);
    var sign = (bytes & 0x80000000) ? -1 : 1;
    var exponent = ((bytes >> 23) & 0xFF) - 127;
    var significand = (bytes & ~(-1 << 23));

    if (exponent == 128) 
        return sign * ((significand) ? Number.NaN : Number.POSITIVE_INFINITY);

    if (exponent == -127) {
        if (significand == 0) return sign * 0.0;
        exponent = -126;
        significand /= (1 << 22);
    } else significand = (significand | (1 << 23)) / (1 << 23);

    return sign * significand * Math.pow(2, exponent);
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

function remap(value, min1, max1, min2, max2) {
    let range1 = max1 - min1;
    let range2 = max2 - min2;
    let valueScaled = (value - min1) / range1;
    return min2 + (valueScaled * range2);
}

function getDistance(v1, v2) {
    if (v1.z !== undefined && v2.z !== undefined) {
        return Math.sqrt((v1.x - v2.x)**2 + (v1.y - v2.y)**2 + (v1.z - v2.z)**2);
    } else {
        return Math.sqrt((v1.x - v2.x)**2 + (v1.y - v2.y)**2);
    }
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

function doEncode(input) {
    input = input.charAt(input.length-2) + input.charAt(input.length-1);
    let returns = "";
    for (let i = 0; i < input.length; i += 2) {
        returns += String.fromCharCode(parseInt(input.substr(i, 2), 16));
    }
    return returns;
}

function floatToBinary(input) {
    let buffer = new ArrayBuffer(4);
    let intView = new Int32Array(buffer);
    let floatView = new Float32Array(buffer);

    floatView[0] = input;
    return intView[0].toString(2); // bits of the 32 bit float
}

function intToBinary(input) {
    let buffer = new ArrayBuffer(4);
    let intView = new Int32Array(buffer);
    let floatView = new Float32Array(buffer);

    intView[0] = parseInt(input);
    return intView[0].toString(2); // bits of the 32 bit float
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

    add(input) {
        this.x += input.x;
        this.y += input.y;
        return new Vector2(this.x, this.y);
    }

    sub(input) {
        this.x -= input.x;
        this.y -= input.y;
        return new Vector2(this.x, this.y);
    }

    mul(input) {
        this.x *= input.x;
        this.y *= input.y;
        return new Vector2(this.x, this.y);
    }

    div(input) {
        this.x /= input.x;
        this.y /= input.y;
        return new Vector2(this.x, this.y);
    }

}

class Vector3 {

    constructor(_x, _y, _z) {
        this.x = _x;
        this.y = _y;
        this.z = _z;
    }

    add(input) {
        this.x += input.x;
        this.y += input.y;
        this.z += input.z;
        return new Vector3(this.x, this.y, this.z);
    }

    sub(input) {
        this.x -= input.x;
        this.y -= input.y;
        this.z -= input.z;
        return new Vector3(this.x, this.y, this.z);
    }

    mul(input) {
        this.x *= input.x;
        this.y *= input.y;
        this.z *= input.z;
        return new Vector3(this.x, this.y, this.z);
    }

    div(input) {
        this.x /= input.x;
        this.y /= input.y;
        this.z /= input.z;
        return new Vector3(this.x, this.y, this.z);
    }

}

const naplps_black = new Vector3(0, 0, 0);
const naplps_gray1 = new Vector3(32, 32, 32);
const naplps_gray2 = new Vector3(64, 64, 64);
const naplps_gray3 = new Vector3(96, 96, 96);
const naplps_gray4 = new Vector3(128, 128, 128);
const naplps_gray5 = new Vector3(160, 160, 160);
const naplps_gray6 = new Vector3(192, 192, 192);
const naplps_gray7 = new Vector3(224, 224, 224);
const naplps_blue = new Vector3(0, 0, 255); // index 60
const naplps_blue_magenta = new Vector3(5*36, 0, 7*36);
const naplps_pinkish_red = new Vector3(7*36, 0, 4*36);
const naplps_orange_red = new Vector3(7*36, 2*36, 0);
const naplps_yellow = new Vector3(255, 255, 0);
const naplps_yellow_green = new Vector3(2*36, 7*36, 0);
const naplps_greenish = new Vector3(0, 7*36, 4*36);
const naplps_bluegreen = new Vector3(0, 5*36, 7*36);  
const naplps_white = new Vector3(255, 255, 255); // not part of the default palette
const naplps_defaultColorMap = [ naplps_black, naplps_gray1, naplps_gray2, naplps_gray3, naplps_gray4, naplps_gray5, naplps_gray6, naplps_gray7, naplps_blue, naplps_blue_magenta, naplps_pinkish_red, naplps_orange_red, naplps_yellow, naplps_yellow_green, naplps_greenish, naplps_bluegreen ]; 
const naplps_defaultColorIndices1 = [ "40", "44", "49", "4D", "52", "56", "5B", "5F", "60", "64", "68", "6C", "70", "74", "78", "7C"];
const naplps_defaultColorIndices2 = [ "40", "60", "40", "60", "50", "70", "50", "70", "40", "40", "40", "40", "40", "40", "40", "40"];

