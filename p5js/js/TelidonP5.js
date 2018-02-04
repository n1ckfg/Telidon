"use strict";

// 5. Drawing class--this is where it all comes together.
// p5.js-specific drawing code is separated here.
class NapDraw {
	    
    constructor(_filePath) { // string
        this.decoder = new NapDecoder(_filePath); 
        this.drawCmds = []; // NapCmd[]
        
        for (var i=0; i<this.decoder.cmds.length; i++) {
            var cmd = this.decoder.cmds[i]; // NapCmd
            if (cmd.opcode.id === "SET & POLY FILLED") {
                this.drawCmds.push(cmd);
                for (var j=0; j<cmd.points.length; j++) {
                    console.log(j + ". " + cmd.points[j]);
                }
            }
        }
    }

    draw() {
        background(0);
        for (var i=0; i<this.drawCmds.length; i++) {
            this.drawPoints(this.drawCmds[i].points, width, height);
        }        
    }
    
    drawPoints(points, w, h) { // PVector[], int, int
        noFill();
        stroke(255,255,0);
        strokeWeight(2);
        beginShape();
        for (var i=0; i<points.length; i++) {
            var p = points[i]; // PVector
            vertex(p.x * w, p.y * h);
        }
        endShape(CLOSE);
        
        strokeWeight(8);
        for (var i=0; i<points.length; i++) {
            if (i===0) {
                stroke(0, 255, 255);
            } else if (i===1) {
                stroke(255, 0, 0);
            } else {
                stroke(127);
            }
            var p = points[i]; // PVector
            point(p.x * w, p.y * h);

            //fill(255);
            //text(i, p.x * w, p.y * h);
        }
    }

}

/*
class NapDrawCmd {
   
    NapDrawCmd(NapCmd _cmd) {
        this.cmd = _cmd; // NapCmd
        this.tex = createGraphics(width, height, P2D); // PGraphics
        this.scanPos = height; // float
        this.scanDelta = 10; // float
        this.moveScanline = true;
    }
    
    update() {
        if (this.moveScanline) {
            this.scanPos -= this.scanDelta;
            if (this.scanPos < 0) this.moveScanline = false;
        }
    }
    
    draw() {
        this.tex.beginDraw();
        this.drawPoints(this.cmd.points, width, height);
        this.tex.endDraw();
        
        this.tex.loadPixels();
        for (var x=0; x < this.tex.width; x++) {
            for (var y=0; y < this.tex.height; y++) {
                var loc = x + y*this.tex.width;
                if (y < this.scanPos) this.tex.pixels[loc] = color(0,0);
            }
        }
        this.tex.updatePixels();
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
        for (var i=0; i<this.points.length; i++) {
            var p = this.points[i]; // PVector
            this.tex.vertex(p.x * w, p.y * h);
        }
        this.tex.endShape(CLOSE);
        
        this.tex.strokeWeight(8);
        for (var i=0; i<this.points.length; i++) {
            if (i===0) {
                this.tex.stroke(0, 255, 255);
            } else if (i===1) {
                this.tex.stroke(255, 0, 0);
            } else {
                this.tex.stroke(127);
            }
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
*/