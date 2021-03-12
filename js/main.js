"use strict";

let recording = true;
let c;
let gif;
let posCounterX = 0;
let posCounterY = 0;

let telidon = [];
let maxLength = 3;

let dropZone;
let sW = 640;
let sH = 480;

let defaultFont;

let preview, explanation, explanationbg;
let shark, skull, santa, beer, haunt, email, mouse;

let isMobile = false;


function preload() {
    isMobile = detectMobile();

    if (isMobile) loadNewTelidon("./images/shark.nap");
}

function setup() {
	c = createCanvas(sW, sH);
	c.position(0, 29);

    if (!isMobile) setupGif();

	dropZone = document.getElementsByTagName("body")[0];
    dropZone.addEventListener('dragover', onDragOver);
    dropZone.addEventListener('drop', onDrop);
    
    defaultFont = loadFont("./archives/fonts/Telidon-Bold/Telidon-Bold.ttf", function(font) {
        textFont(font);
        textSize(36);
        textAlign(LEFT);        
    });

    preview = document.getElementById("preview");
    setPreview("shark");
    
    explanation = document.getElementById("explanation");
    explanationbg = document.getElementById("explanation-bg");
    explanation.addEventListener("click", function() {
        explanation.style = "opacity: 0";
        explanationbg.style = "opacity: 0";
    });

    shark = document.getElementById("shark").addEventListener("click", function() {
        loadNewTelidon("./images/shark.nap");
        setPreview("shark");
    });

    skull = document.getElementById("skull").addEventListener("click", function() {
        loadNewTelidon("./images/wast.nap");
        setPreview("skull");
    });

    santa = document.getElementById("santa").addEventListener("click", function() {
        loadNewTelidon("./images/santa.nap");
        setPreview("santa");
    });

    beer = document.getElementById("beer").addEventListener("click", function() {
        loadNewTelidon("./images/beer.nap");
        setPreview("beer");
    });

    haunt = document.getElementById("haunt").addEventListener("click", function() {
        loadNewTelidon("./images/haunt.nap");
        setPreview("haunt");
    });

    email = document.getElementById("email").addEventListener("click", function() {
        loadNewTelidon("./images/email2.nap");
        setPreview("email");
    });

    mouse = document.getElementById("mouse").addEventListener("click", function() {
        loadNewTelidon("./images/tb1.nap");
        setPreview("mouse");
    });

	//console.log(telidon);
    //background(0);
    //blendMode(ADD);
}

function draw() {    
	background(0);
    if (telidon.length < 1) {
        fill(255);
        textAlign(CENTER);
        text("\\\\ DRAG ' n ' DROP //", width/2, height/2);
        textAlign(LEFT);
        return;
    }

    translate(0,sH-sW);
	
    for (let i=0; i<telidon.length; i++) {
		telidon[i].draw();
	}

    if (!isMobile && recording && frameCount % 2 == 0) {
        gif.addFrame(c.elt, {delay: 1, copy: true});
    }

    if (!isMobile && recording && telidon[telidon.length-1].finished) {
        recording = false;
        gif.render();
    }
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
    let files = e.dataTransfer.files; // Array of all files
    for (let i=0, file; file=files[i]; i++) {
        let reader = new FileReader();
        reader.onload = function(e2) {
        	//blendMode(NORMAL);
        	//background(0);
        	//blendMode(ADD);
            if (telidon.length >= maxLength) telidon.splice(0,1);
            telidon.push(new TelidonDraw([e2.target.result], sW, sW));
            recording = true;
            preview.style.backgroundImage = null;
        }
        reader.readAsText(file, 'UTF-8');
    }      
}


function loadNewTelidon(fileName) { 
    loadStrings(fileName, function(response) {
    	//blendMode(NORMAL);
    	//background(0);
    	//blendMode(ADD);
        telidon = [];
        let reader = new FileReader();
        reader.onload = function(e2) {
            telidon.push(new TelidonDraw([e2.target.result], sW, sW));
            recording = true;
        }
        reader.readAsText(new Blob(response), 'UTF-8');
    });
}

function setPreview(name) {
    preview.style.backgroundImage = "url(./tools/rosetta_stone/cover/png/" + name + ".png)";
}

function setupGif() {
    gif = new GIF({
        workers: 4,
        workerScript: './js/libraries/gifjs/gif.worker.js', // https://github.com/jnordberg/gif.js/issues/59
        quality: 40
    });

    gif.on('finished', function(blob) {
        // https://developer.mozilla.org/en-US/docs/Web/API/HTMLMediaElement/srcObject
        let img = document.createElement('img');
        img.src = URL.createObjectURL(blob);
        img.style = "width: " + sW/2 + "px; height: " + sH/2 + "px; position: absolute; left: " + posCounterX + "px; top: " + (posCounterY + sH + 29) + "px;";
        posCounterX += sW/2;
        if (posCounterX > 1.5 * sW) {
            posCounterX = 0;
            posCounterY += sH/2;
        }
        document.body.appendChild(img);

        setupGif();
    });
}

function detectMobile() {
    if (/Android|webOS|iPhone|iPad|iPod|BlackBerry|BB|PlayBook|IEMobile|Windows Phone|Kindle|Silk|Opera Mini/i.test(navigator.userAgent)) {
        return true;
    } else {
        return false;
    }
}