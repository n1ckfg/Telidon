"use strict";

var nap;

function preload() {
	loadStrings("./images/boom.nap", function(response) {
		nap = new NapDraw(response, 640, 640);
	});
}

function setup() {
	createCanvas(640, 640);
	console.log(nap);
}

function draw() {
	background(255,0,0);
	nap.draw();
}

