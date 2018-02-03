"use strict";

// 5. Drawing class--this is where it all comes together.
// p5.js-specific drawing code is separated here.
class NapDraw extends NapDecoder {
	    
    constructor(_filePath) { // string
        super(loadStrings(_filePath));
        this.drawCmds = []; // NapCmd[]
        
        for(var i=0; i<this.cmds.length; i++) {
            var cmd = this.cmds[i]; // NapCmd
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