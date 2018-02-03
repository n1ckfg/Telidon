"use strict";

var filePath = "nap/boom.nap";
var nap;

function main() {
	nap = new NapChar("C");
	console.log(nap.c + " " + nap.ascii + " " + nap.binary + " "  + nap.rbinary + " " + nap.hex);
}

window.onload = main;