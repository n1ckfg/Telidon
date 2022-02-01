// + + +   E N C O D E R   + + +

class NapInputWrapper {

	constructor(_color, _points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
	}

}


class NapEncoder {

	constructor(_strokes) {
		//this.strokes = this.normalizeAllStrokes(_strokes);
		this.strokes = _strokes;
		console.log("Encoder input is " + this.strokes.length + " strokes.");

		// Number of bytes per encoded value. This is hardcoded here, but
		// can be set in the NAPLPS domain command.
		this.dataLength = 4;
        this.bitsPerByte = 3; 

		// We know that the hardcoded 4-byte domain has 2048 position values
		// (3 position bits per byte, minus the sign for the first bit)
		this.maxBitVals = 2048;
        this.firstBitSign = true; 

        this.lastColor = undefined;
		this.cmds = this.generateCommands();
		this.napRaw = this.cmds.join("");
		this.debug = false;

		console.log(this.napRaw);
	}

	generateCommands() {
		let returns = [];

		const headerString = this.makeNapHeader();
		console.log("Generating header: " + headerString);
		returns.push(headerString);

		for (let i=0; i<this.strokes.length; i++) {
			console.log("\n");
			console.log("* * * Begin encoding stroke " + (i+1) + " / " + this.strokes.length + " * * *");
			returns.push(this.makeNapStroke(this.strokes[i].isFill, this.strokes[i].color, this.strokes[i].points));
			console.log("* * * End encoding stroke " + (i+1) + " / " + this.strokes.length + " * * *");
			console.log("\n");
		}

		const footerString = this.makeNapFooter();
		console.log("Generating footer: " + footerString);
		returns.push(footerString);

		return returns;
	}

	makeNapHeader() {
		let returns = [];

		returns.push(doEncode("18")); // cancel

		returns.push(doEncode("1B")); // esc
		returns.push(doEncode("45"));

		returns.push(doEncode("1F")); // nsr 
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		
		returns.push(doEncode("0E")); // shift-out (graphics mode)

		returns.push(doEncode("20")); // reset 
		returns.push(doEncode("7F"));
		returns.push(doEncode("4F"));

		returns.push(doEncode("21")); // domain
		returns.push(doEncode("4D"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));

		return returns.join("");
	}

	makeNapFooter() {
		let returns = [];

		returns.push(doEncode("1B")); // esc
		returns.push(doEncode("45"));

		return returns.join("");
	}

	makeNapOpcode(_isFill) { // only poly line and fill are implemented
		let returns = [];

		/*
         * 28 LINE ABS
         * 29 LINE REL
         * 2A SET & LINE ABS
         * 2B SET & LINE REL
		 * 34 POLY OUTLINED
		 * 35 POLY FILLED
		 * 36 SET & POLY OUTLINED
		 * 37 SET & POLY FILLED
		 */

		if (!_isFill) {
			returns.push(doEncode("36")); // OUTLINED
		} else {
			returns.push(doEncode("37")); // FILLED
		}

		return returns;
	}

	// TODO set color can generate a custom 16-color palette

	makeNapSelectColor(_color) {
		let returns = [];

		returns.push(doEncode("3E")); // SELECT COLOR

		let index = 0;
		let dist = 999999;
		for (let i=0; i<naplps_defaultColorMap.length; i++) {
			let newDist = getDistance(_color, naplps_defaultColorMap[i]);
			if (newDist < dist) {
				index = i;
				dist = newDist;
			}
		}

		returns.push(doEncode(naplps_defaultColorIndices1[index])); 
		returns.push(doEncode(naplps_defaultColorIndices2[index])); 
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));

		return returns.join("");

	}

	/*
	makeNapInt(input) {
		const binaryInput = intToBinary(input);
		const hexInput = hex(input, 2);
		const encodedInput = doEncode(hexInput);
		console.log("Encoding int input: " + input + ", binary: " + binaryInput + ", hex: " + hexInput + ", encoded: " + encodedInput);
		console.log("Testing unbinary: " + unbinary(binaryInput));
		return encodedInput;		
	}
	*/

    getBitValsUnsigned(n) {
        return pow(2, (n.length * this.bitsPerByte));
    }

    getBitValsSigned(n) {
        return pow(2, (n.length * this.bitsPerByte) - int(this.firstBitSign))
    }

	makeNapVector2(input) {
		let returns = [];

		if (this.debug) console.log("Encoding vector input " + input.x + ", " + input.y + " ...");

		const intX = parseInt(Math.abs(input.x) * this.maxBitVals);
		const intY = parseInt(Math.abs(input.y) * this.maxBitVals);
		if (this.debug) console.log("Converting vector to int: " + intX + ", " + intY);

		let binX = binary(intX, 11); //intToBinary(intX);
		let binY = binary(intY, 11); //intToBinary(intY);
		if (this.debug) console.log("Converting int to binary: " + binX + ", " + binY);

		for (let i=0; i<this.dataLength; i++) {
			let vectorByte = "01";

			// first bit is the sign
			switch (i) {
				case 0:
					if (input.x > 0) {
						vectorByte += "0";
					} else {
						vectorByte += "1";
					}

					vectorByte += binX.charAt(0);
					vectorByte += binX.charAt(1);

					if (input.y > 0) {
						vectorByte += "0";
					} else {
						vectorByte += "1";
					}

					vectorByte += binY.charAt(0);
					vectorByte += binY.charAt(1);
					break;
				case 1:
					vectorByte += binX.charAt(2);
					vectorByte += binX.charAt(3);
					vectorByte += binX.charAt(4);

					vectorByte += binY.charAt(2);
					vectorByte += binY.charAt(3);
					vectorByte += binY.charAt(4);
					break;
				case 2:
					vectorByte += binX.charAt(5);
					vectorByte += binX.charAt(6);
					vectorByte += binX.charAt(7);

					vectorByte += binY.charAt(5);
					vectorByte += binY.charAt(6);
					vectorByte += binY.charAt(7);
					break;
				case 3:
					vectorByte += binX.charAt(8);
					vectorByte += binX.charAt(9);
					vectorByte += binX.charAt(10);

					vectorByte += binY.charAt(8);
					vectorByte += binY.charAt(9);
					vectorByte += binY.charAt(10);
					break;
			}

			const hexByte = hex(unbinary(vectorByte));
			const encodedByte = doEncode(hexByte);

			if (this.debug) console.log("Encoded byte " + i + ", binary: " + vectorByte + ", hex: " + hexByte + ", " + encodedByte)
			returns.push(encodedByte);
		}

		return returns.join("");
	}

	normalizeAllStrokes(input) {
		let minX = 0;
		let maxX = 0;
		let minY = 0;
		let maxY = 0;
		let minVal = 0;
		let maxVal = 0;
		
		for (let stroke of input) {
			for (let point of stroke.points) {
				if (point.x < minX) {
					minX = point.x;
				} else if (point.x > maxX) {
					maxX = point.x;
				}
				if (point.y < minY) {
					minY = point.y;
				} else if (point.y > maxY) {
					maxY = point.y;
				}
			}
		}

		if (Math.abs(maxX - minX) > Math.abs(maxY - minY)) {
			maxVal = maxX;
			minVal = minX;
		} else {
			maxVal = maxY;
			minVal = minY;
		}

		for (let stroke of input) {
			for (let point of stroke.points) {
				point.x = remap(point.x, minVal, maxVal, 0, 1);
				point.y = remap(point.y, minVal, maxVal, 0, 0.75);
			}
		}

		return input;
	}

	makeNapPoints(_points) {
		console.log("Encoding " + _points.length + " points to poly ...");
		let returns = [];
		
		let pointsToEncode = [];

        for (let i=0; i<_points.length; i++) {
        	console.log(_points[i].x + ", " + _points[i].y);
           	_points[i].y = 1.0 - _points[i].y;

            if (i === 0) {
            	pointsToEncode.push(_points[0]);
            } else {
            	let nv = _points[i];
            	let nvLast = _points[i-1];

                // ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
                let x = Math.abs(nv.x) - Math.abs(nvLast.x);
                if (nv.x < nvLast.x) x = Math.abs(x) - 1;
                
                let y = Math.abs(nv.y) - Math.abs(nvLast.y);
                if (nv.y < nvLast.y) y = Math.abs(y) - 1;               
                // ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 

                if (i === _points.length-1) {
	                console.log("\n");
                }

                let newPoint = new Vector2(x, y);
                pointsToEncode.push(newPoint);              
            }
        }

        for (let point of pointsToEncode) {
           	returns.push(this.makeNapVector2(point));
            console.log("Encoded point (" + point.x + ", " + point.y +").");
        }

		return returns.join("");	
	}

	makeNapStroke(_isFill, _color, _points) {
		let returns = [];

		if (this.lastColor === undefined || this.lastColor !== _color) {
			returns.push(this.makeNapSelectColor(_color));
			this.lastColor = _color;
		}
		returns.push(this.makeNapOpcode(_isFill));
		returns.push(this.makeNapPoints(_points));

		return returns.join("");	
	}
}

