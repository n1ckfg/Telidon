"use strict";

var filePath = "nap/boom.nap";
var nap;

function setup() {
	createCanvas(640, 460);
	nap = new NapChar('c');
	console.log(nap.ascii);
}

function draw() {
	background(255,0,0);
}