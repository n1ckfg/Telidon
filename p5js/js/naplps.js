"use strict";

class NapDecoder {
	//
}

class NapCmd {
	//
}

class NapVector {
	//
}

class NapChar {
    
    constructor(_c) {
        this.c = _c; // char
        this.ascii = this.getAscii(); // int
        this.binary = this.getBinary(); // string
        //this.rbinary = getRBinary(); // string
        this.hex = this.getHex(); // string
    }
    
    getAscii() {
        return int(this.c);
    }
    
    getBinary() {
        var returns = "";
        var b = binary(this.c);
        for (var i=b.length()-7; i<b.length(); i++) {
            returns += b.charAt(i);
        }
        return returns;
    }
    
    //getRBinary() { // reverse binary
            //return new StringBuffer(binary).reverse().toString();
    //}
    
    getHex() {
        var returns = "";
        var h = hex(this.c);
        for (var i=h.length()-2; i<h.length(); i++) {
            returns += h.charAt(i);
        }        
        return returns;
    }

}

class NapOpcode {
	//
}

class NapData {
	//
}