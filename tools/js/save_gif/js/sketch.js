var capture;
var recording = false;
var c;
var gif;

function setup() {
    c = createCanvas(320, 240);
    capture = createCapture(VIDEO);
    capture.size(320, 240);
    capture.hide();
    setupGif();
}

function draw() {
    background(255);
    image(capture, 0, 0, 320, 240);

    if (recording && frameCount % 3 == 0) {
        gif.addFrame(c.elt, {delay: 1, copy: true});
    }

}

function mousePressed() {
    recording = !recording;
    if (!recording) {
        gif.render();
    }
}

function setupGif() {
    gif = new GIF({
        workers: 2,
        workerScript: './js/libraries/gifjs/gif.worker.js', // https://github.com/jnordberg/gif.js/issues/59
        quality: 40
    });

    gif.on('finished', function(blob) {
        // https://developer.mozilla.org/en-US/docs/Web/API/HTMLMediaElement/srcObject
		var img = document.createElement('img');
		img.src = URL.createObjectURL(blob);
        
        document.body.appendChild(img);

        setupGif();
    });
}