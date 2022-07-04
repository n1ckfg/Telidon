"use strict";

// 5. Drawing class--this is where it all comes together.
// p5.js-specific drawing code is separated here.
class TelidonDraw {
	    
    constructor(_filePath, _w, _h) { // string
        this.decoder = new NapDecoder(_filePath); 
        this.drawCmds = []; // NapDrawCmd[]
        this.counter = 0;
        this.finished = false;

        for (let i=0; i<this.decoder.cmds.length; i++) {
            let cmd = this.decoder.cmds[i]; // NapCmd
            this.drawCmds.push(new TelidonDrawCmd(cmd, _w, _h));
        }
    }

    draw() {
        this.finished = true;
        
        if (this.decoder.version === 699) background(127);

        for (let i=0; i<this.drawCmds.length; i++) {
            let drawCmd = this.drawCmds[i];
            if (!drawCmd.moveScanline) this.counter++;
            if (i === this.counter || !drawCmd.moveScanline) {
                drawCmd.run();
            }

            if (!drawCmd.finished) this.finished = false;
        }        
    }

}

class TelidonDrawCmd {
   
    constructor(_cmd, _w, _h) { // NapCmd
        this.cmd = _cmd; // NapCmd
        this.w = _w;
        this.h = _h;
        //this.tex = createGraphics(w, h); // PGraphics
        //this.tex.scale(1/pixelDensity());
        this.scanPos = this.h; // float
        this.scanDelta = 5; // float
        this.moveScanline = false;
        this.progressiveDraw = true;
        this.labelPoints = false;
        this.col = color(0);
        this.thickness = 1;
        this.text = "";
        this.markTime = 0;
        this.progressiveDrawInterval = 66;
        this.extraLoopCounter = 0;

        this.points = [];
        this.pointsIndex = 0;

        if (!this.progressiveDraw) {
            for (let point of this.cmd.points) {
                if (point.x >= 0 && point.x <= 1 && point.y >= 0 && point.y <= 1) {
                    this.points.push(point);
                }
            }
        }
        this.finished = false;
    }
    
    update() {
        //if (this.moveScanline) {
            //this.scanPos -= this.scanDelta;
            //if (this.scanPos <= 0) this.moveScanline = false;
        //}
        if (millis() > this.markTime + this.progressiveDrawInterval) {
            if (this.progressiveDraw && this.points.length < this.cmd.points.length && this.pointsIndex < this.cmd.points.length) {
            	const point = this.cmd.points[this.pointsIndex];
                if (point.x >= 0 && point.x <= 1 && point.y >= 0 && point.y <= 1) {
                    this.points.push(point);
            	}
                this.pointsIndex++;

                this.markTime = millis();
            }
        }

        if (!this.finished && this.points.length === this.cmd.points.length) {
            if (this.extraLoopCounter < this.progressiveDrawInterval) {
                this.extraLoopCounter++;
            } else {
                this.finished = true;
            }
        }
    }
    
    draw() {
	    // *** IMPORTANT STEP 3 of 3 ***
        // This is where the decoded commands finally get drawn to the screen.
        switch(this.cmd.opcode.id) {
        	//~ ~ ~ ~ ~ CONTROL CODES ~ ~ ~ ~ ~
            case("Shift-Out"): // graphics mode, we're here by default
           		// no effect?
                break;
            case("Shift-In"): // text mode, data that follows is text
                this.drawText(this.cmd.text);               
                break;
            case("CANCEL"):
           		// no effect?
                break;
            case("ESC"):
           		// no effect?
                break;
            case("NSR"): // Non-Selective Reset
           		// no effect?
                break;
            //~ ~ ~ ~ ~ PDI (PICTURE DESCRIPTION INSTRUCTION) CODES ~ ~ ~ ~ ~
            //~ ~ ~ ENVIRONMENT, part 1 ~ ~ ~
            case("RESET"):
                // TODO
                break;
            case("DOMAIN"): // header information
            	// TODO
                break;
            case("TEXT"):
                // TODO               
                break;
            case("TEXTURE"):
				// TODO	            
                break;
            //~ ~ ~ POINTS ~ ~ ~
            case("POINT SET ABS"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("POINT SET REL"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("POINT ABS"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("POINT REL"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            //~ ~ ~ LINES ~ ~ ~
            case("LINE ABS"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("LINE REL"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("SET & LINE ABS"):
        		this.drawPoints(this.points, this.w, this.h);
                break;
            case("SET & LINE REL"):
        		this.drawPoints(this.points, this.w, this.h);
            	break;
            //~ ~ ~ ARCS ~ ~ ~
            case("ARC OUTLINED"):
        		this.drawArc(this.cmd.points, this.w, this.h, false);
                break;
            case("ARC FILLED"):
        		this.drawArc(this.cmd.points, this.w, this.h, true);
                break;
            case("SET & ARC OUTLINED"):
        		this.drawArc(this.cmd.points, this.w, this.h, false);
                break;
            case("SET & ARC FILLED"):
        		this.drawArc(this.cmd.points, this.w, this.h, true);
            	break;
            //~ ~ ~ RECTANGLES ~ ~ ~
            case("RECT OUTLINED"):
        		this.drawRect(this.cmd.points, this.w, this.h, false);
                break;
            case("RECT FILLED"):
        		this.drawRect(this.cmd.points, this.w, this.h, true);
                break;
            case("SET & RECT OUTLINED"):
        		this.drawRect(this.cmd.points, this.w, this.h, false);
                break;
            case("SET & RECT FILLED"):
        		this.drawRect(this.cmd.points, this.w, this.h, true);
            	break;
            //~ ~ ~ POLYGONS ~ ~ ~
            case("POLY OUTLINED"):
        		this.drawPoints(this.points, this.w, this.h, false);
                break;
            case("POLY FILLED"):
        		this.drawPoints(this.points, this.w, this.h, true);
                break;
            case("SET & POLY OUTLINED"): // relative points after first 
        		this.drawPoints(this.points, this.w, this.h, false);
                break;
            case("SET & POLY FILLED"): // relative points after first 
        		this.drawPoints(this.points, this.w, this.h, true);//this.tex.width, this.tex.height);
                //for (let j=0; j<cmd.points.length; j++) {
                    //console.log(j + ". " + cmd.points[j]);
                //}
                break;
            //~ ~ ~ INCREMENTALS ~ ~ ~
            case("FIELD"):
				// TODO	            
                break;
            case("INCREMENTAL POINT"):
				// TODO	            
                break;
            case("INCREMENTAL LINE"):
				// TODO	            
                break;
            case("INCREMENTAL POLY FILLED"):
				// TODO	            
                break;
            //~ ~ ~ ENVIRONMENT, part 2 ~ ~ ~ 
            case("SET COLOR"): // this picks a color
				this.setColor(this.cmd.col);  
                break;
            case("WAIT"):
				// TODO	            
                break;
            case("SELECT COLOR"): // this sets the color mode
				this.setColor(this.cmd.col);           
                break
            case("BLINK"):
				// TODO	            
                break;
            default:
                break;    
    	}
        
        // TODO faster pixel drawing https://p5js.org/reference/#/p5/pixels
        //if (this.moveScanline) {
            /*
            this.tex.loadPixels();
            for (let x=0; x < this.tex.width; x++) {
                for (let y=0; y < this.tex.height; y++) {
                    let loc = 4 * (x + y*this.tex.width);
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
            //image(this.tex.get(0, this.scanPos, this.tex.width, this.tex.height), 0, this.scanPos);
        //} else {        
            //image(this.tex, 0, 0);
        //}
    }
    
    run() {
        this.update();
        this.draw();
    }
 
    setBackground(v) {
        if (drawBackground) {
            background(color(v.x, v.y, v.z));
            drawBackground = false;
        }
    }

    setColor(v) {
    	this.col = color(v.x, v.y, v.z);
       	fill(this.col);
       	stroke(this.col);
      	strokeWeight(this.thickness); // TODO should this go somewhere else?
        //console.log("color: " + this.col);
    }

    drawText(_text) {
        //fill(255);
        //stroke(0);
        text(_text, width * 0.0625, height * 1.25); // TODO position
    }

    drawRect(points, w, h, isFill) { // PVector, w, h
        if (isFill) {
        	//noStroke();
        } else {
        	noFill();
        }
        if (points.length == 2) {
            let x1 = points[0].x * w;
            let y1 = points[0].y * h;
            let x2 = points[1].x * w;
            let y2 = points[1].y * h;
            rectMode(CORNER);
            rect(x1, y1, x2-x1, y2-y1);
        } else {
            this.drawPoints(points, w, h);
        }
    }

    drawArc(points, w, h, isFill) { // PVector, w, h
        if (isFill) {
        	//noStroke();
        } else {
        	noFill();
        }
	    if (points.length == 2) {
	    	let x1 = points[0].x * w;
	    	let y1 = points[0].y * h;
	   		let x2 = points[1].x * w;
	    	let y2 = points[1].y * h;
		    //let d = dist(x1, y1, x2, y2);
		    ellipseMode(CORNER);
		    ellipse(x1, y1, x2-x1, x2-x1);
		} else {
            for (let i=0; i<points.length-1; i++) {
                let x1 = points[i].x * w;
                let y1 = points[i].y * h;
                let x2 = points[i+1].x * w;
                let y2 = points[i+1].y * h;
                arc(x1, y1, x2-x1, y2-y1, i * (PI/points.length), (i+1) * (PI/points.length));
            }
        }
    }

    drawPoints(points, w, h, isFill) { // PVector, w, h
        if (isFill) {
        	//noStroke();
        } else {
        	noFill();
        }
        beginShape();
        for (let i=0; i<points.length; i++) {
            let p = points[i]; // PVector
            vertex(p.x * w, p.y * h);
            if (i === points.length-1) {
                vertex(points[0].x * w, points[0].y * h);
            }
        }

        endShape(CLOSE);
        
        if (this.labelPoints) {
            stroke(255, 63);
        	strokeWeight(this.thickness * 4);
	        for (let i=0; i<points.length; i++) {
	            let p = points[i]; // PVector
	            point(p.x * w, p.y * h);

	            //tex.textFont(font, fontSize);
	            //tex.fill(0);
	            //tex.text(i, (p.x * w) + 2, (p.y * h) + 2);
	            //tex.fill(255);
	            //tex.text(i, p.x * w, p.y * h);
	        }
    	}
    }
    
}