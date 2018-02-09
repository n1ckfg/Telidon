"use strict";

// 5. Drawing class--this is where it all comes together.
// p5.js-specific drawing code is separated here.
class NapDraw {
	    
    constructor(_filePath, _w, _h) { // string
        this.decoder = new NapDecoder(_filePath); 
        this.drawCmds = []; // NapDrawCmd[]
        this.counter = 0;
        
        for (var i=0; i<this.decoder.cmds.length; i++) {
            var cmd = this.decoder.cmds[i]; // NapCmd
            if (cmd.opcode.id === "SET & POLY FILLED") {
                this.drawCmds.push(new NapDrawCmd(cmd, _w, _h));
                //for (var j=0; j<cmd.points.length; j++) {
                    //console.log(j + ". " + cmd.points[j]);
                //}
            }
        }
    }

    draw() {
        background(0);
        for (var i=0; i<this.drawCmds.length; i++) {
            var drawCmd = this.drawCmds[i];
            if (!drawCmd.moveScanline) this.counter++;
            if (i === this.counter || !drawCmd.moveScanline) {
                drawCmd.run();
            }
        }        
    }

}

class NapDrawCmd {
   
    constructor(_cmd, _w, _h) { // NapCmd
        this.cmd = _cmd; // NapCmd
        this.tex = createGraphics(_w, _h); // PGraphics
        this.tex.scale(1/pixelDensity());
        this.scanPos = _h; // float
        this.scanDelta = 5; // float
        this.moveScanline = false;
        this.labelPoints = true;
    }
    
    update() {
        if (this.moveScanline) {
            this.scanPos -= this.scanDelta;
            if (this.scanPos <= 0) this.moveScanline = false;
        }
    }
    
    draw() {
        this.drawPoints(this.cmd.points, this.tex.width, this.tex.height);
        
        // TODO faster pixel drawing https://p5js.org/reference/#/p5/pixels
        if (this.moveScanline) {
            /*
            this.tex.loadPixels();
            for (var x=0; x < this.tex.width; x++) {
                for (var y=0; y < this.tex.height; y++) {
                    var loc = 4 * (x + y*this.tex.width);
                    if (y <= this.scanPos) {
                        this.tex.pixels[loc] = 0;
                        this.tex.pixels[loc + 1] = 0;
                        this.tex.pixels[loc + 2] = 0;
                        this.tex.pixels[loc + 3] = 0;
                    }
                }
            }
            this.tex.updatePixels();
            */
            image(this.tex.get(0, this.scanPos, this.tex.width, this.tex.height), 0, this.scanPos);
        } else {        
            image(this.tex, 0, 0);
        }
    }
    
    run() {
        this.update();
        this.draw();
    }
    
    drawPoints(points, w, h) { // PVector, w, h
        this.tex.noFill();
        this.tex.stroke(0,255,50,5);
        this.tex.strokeWeight(2);
        this.tex.beginShape();
        for (var i=0; i<points.length; i++) {
            var p = points[i]; // PVector
            this.tex.vertex(p.x * w, p.y * h);
        }
        this.tex.endShape(CLOSE);
        
        if (this.labelPoints) {
        	this.tex.strokeWeight(4);
	        for (var i=0; i<points.length; i++) {
                this.tex.stroke(50, 255, 50, 5);

	            var p = points[i]; // PVector
	            this.tex.point(p.x * w, p.y * h);

	            //tex.textFont(font, fontSize);
	            //tex.fill(0);
	            //tex.text(i, (p.x * w) + 2, (p.y * h) + 2);
	            //tex.fill(255);
	            //tex.text(i, p.x * w, p.y * h);
	        }
    	}
    }
    
}