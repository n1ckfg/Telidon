"use strict";

var telidon;
var dropZone;
var sW = 640;
var sH = 640;

var shark, skull, santa, beer, haunt, email;

function preload() {
	loadStrings("./images/shark.nap", function(response) {
		telidon = new TelidonDraw(response, sW, sH);
	});
}

function setup() {
	createCanvas(sW, sH);
	dropZone = document.getElementsByTagName("body")[0];
    dropZone.addEventListener('dragover', onDragOver);
    dropZone.addEventListener('drop', onDrop);

    shark = document.getElementById("shark").addEventListener("click", function() {
        loadNewTelidon("./images/shark.nap");
    });

    skull = document.getElementById("skull").addEventListener("click", function() {
        loadNewTelidon("./images/wast.nap");
    });

    santa = document.getElementById("santa").addEventListener("click", function() {
        loadNewTelidon("./images/santa.nap");
    });

    beer = document.getElementById("beer").addEventListener("click", function() {
        loadNewTelidon("./images/beer.nap");
    });

    haunt = document.getElementById("haunt").addEventListener("click", function() {
        loadNewTelidon("./images/haunt.nap");
    });

    email = document.getElementById("email").addEventListener("click", function() {
        loadNewTelidon("./images/email2.nap");
    });

	//console.log(telidon);
    //background(0);
    //blendMode(ADD);
}

function draw() {
	background(0);
	telidon.draw();
}

// Show the copy icon when dragging over.  Seems to only work for chrome.
function onDragOver(e) {
    e.stopPropagation();
    e.preventDefault();
    e.dataTransfer.dropEffect = 'copy';    
}

function onDrop(e) {
    e.stopPropagation();
    e.preventDefault();
    var files = e.dataTransfer.files; // Array of all files
    for (var i=0, file; file=files[i]; i++) {
        var reader = new FileReader();
        reader.onload = function(e2) {
        	//blendMode(NORMAL);
        	//background(0);
        	//blendMode(ADD);
            telidon = new TelidonDraw([e2.target.result], sW, sH);
        }
        reader.readAsText(file, 'UTF-8');
    }      
}


function loadNewTelidon(fileName) {
    loadStrings(fileName, function(response) {
    	//blendMode(NORMAL);
    	//background(0);
    	//blendMode(ADD);
        telidon = new TelidonDraw(response, sW, sH);
    });
}