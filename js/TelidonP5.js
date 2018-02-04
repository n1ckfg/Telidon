"use strict";

// 5. Drawing class--this is where it all comes together.
// p5.js-specific drawing code is separated here.
class NapDraw {
	    
    constructor(_filePath, _w, _h) { // string
        this.w = _w;
        this.h = _h;
        this.decoder = new NapDecoder(_filePath); 
        this.drawCmds = []; // NapDrawCmd[]
        this.counter = 0;
        
        for (var i=0; i<this.decoder.cmds.length; i++) {
            var cmd = this.decoder.cmds[i]; // NapCmd
            if (cmd.opcode.id === "SET & POLY FILLED") {
                this.drawCmds.push(new NapDrawCmd(cmd, this.w, this.h));
                for (var j=0; j<cmd.points.length; j++) {
                    console.log(j + ". " + cmd.points[j]);
                }
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
        this.w = _w;
        this.h = _h;
        this.cmd = _cmd; // NapCmd
        this.tex = createGraphics(this.w, this.h); // PGraphics
        this.tex.scale(1/pixelDensity());
        this.scanPos = this.h; // float
        this.scanDelta = 5; // float
        this.moveScanline = false;
    }
    
    update() {
        if (this.moveScanline) {
            this.scanPos -= this.scanDelta;
            if (this.scanPos <= 0) this.moveScanline = false;
        }
    }
    
    draw() {
        this.drawPoints(this.cmd.points, this.w, this.h);
        
        // TODO faster pixel drawing https://p5js.org/reference/#/p5/pixels
        if (this.moveScanline) {
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
        }
        
        image(this.tex, 0, 0);
    }
    
    run() {
        this.update();
        this.draw();
    }
    
    drawPoints(points, w, h) { // PVector, w, h
        this.tex.noFill();
        this.tex.stroke(255,255,0);
        this.tex.strokeWeight(2);
        this.tex.beginShape();
        for (var i=0; i<this.cmd.points.length; i++) {
            var p = this.cmd.points[i]; // PVector
            this.tex.vertex(p.x * w, p.y * h);
        }
        this.tex.endShape(CLOSE);
        
        this.tex.strokeWeight(8);
        for (var i=0; i<this.cmd.points.length; i++) {
            if (i===0) {
                this.tex.stroke(0, 255, 255);
            } else if (i===1) {
                this.tex.stroke(255, 0, 0);
            } else {
                this.tex.stroke(127);
            }
            var p = this.cmd.points[i]; // PVector
            this.tex.point(p.x * w, p.y * h);

            //tex.textFont(font, fontSize);
            //tex.fill(0);
            //tex.text(i, (p.x * w) + 2, (p.y * h) + 2);
            //tex.fill(255);
            //tex.text(i, p.x * w, p.y * h);
        }
    }
    
}