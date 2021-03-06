"use strict";

var c;
var posCounterX = 0;
var posCounterY = 0;

var sW = 640;
var sH = 480;

var defaultFont;

var preview;
var telidon = [];
var maxLength = 1;

function preload() {
	loadNewTelidon("../../../images/boom.nap");
}

function setup() {
	c = createCanvas(sW, sH);
	c.position(0, 29);

    preview = document.getElementById("preview");
    setPreview("boom");
}

function draw() {    
	background(0);

    translate(0,sH-sW);
	
    for (var i=0; i<telidon.length; i++) {
		telidon[i].draw();
	}
}

function loadNewTelidon(fileName) { 
    loadStrings(fileName, function(response) {
    	//blendMode(NORMAL);
    	//background(0);
    	//blendMode(ADD);
        telidon = [];
        var reader = new FileReader();
        reader.onload = function(e2) {
            telidon.push(new TelidonDraw([e2.target.result], sW, sW));
            //recording = true;
        }
        reader.readAsText(new Blob(response), 'UTF-8');
    });
}

function setPreview(name) {
    preview.style.backgroundImage = "url(../../../tools/rosetta_stone/cover/png/" + name + ".png)";
}