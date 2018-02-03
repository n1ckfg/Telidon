"use strict";

var nap;

function preload() {
	nap = new NapDecoder(loadStrings("./files/nap/boom.nap"));
}

function setup() {
	createCanvas(640, 640);
	console.log(nap);
}

function draw() {
	background(255,0,0);
}

