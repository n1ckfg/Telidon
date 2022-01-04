// + + +   E N C O D E R   + + +

class NapInputWrapper {

	constructor(_color, _points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
		this.colorIndex = 0;
	}

}


class NapEncoder {

	constructor(_strokes) {
		this.strokes = _strokes; //this.normalizeAllStrokes(_strokes);
		console.log("Encoder input is " + this.strokes.length + " strokes.");
		this.colors = [];
		this.minColorDistance = 0.1;

		// Number of bytes per encoded value. This is hardcoded here, but
		// can be set in the NAPLPS domain command.
		this.dataLength = 4;
        this.bitsPerByte = 3; 
        this.firstBitSign = true; 

		this.cmds = this.generateCommands(this.strokes);
		this.napRaw = this.cmds.join("");

		console.log(this.napRaw);
	}

	addPaletteColor(_color) {
		for (let i=0; i<this.colors.length; i++) {
			const dist = getDistance(_color, this.colors[i]);
			console.log("Color similarity is " + dist);
			if (dist < this.minColorDistance) {
				console.log("Reusing color " + i + ", palette length is " + this.colors.length);
				return i;
			}
		}

		this.colors.push(_color);
		const len = this.colors.length - 1;
    	console.log("Adding color " + (len + 1) + ", palette length is " + this.colors.length);
		return len;
	}

	generatePalette() {
		let returns = [];

		for (let i=0; i<this.strokes.length; i++) {
			this.strokes[i].colorIndex = this.addPaletteColor(this.strokes[i].color);
		}

		for (let color of this.colors) {
			console.log("Encoding color " + color.x + ", " + color.y + ", " + color.z);
			returns.push(this.makeNapSetColor(color));
		}

		return returns.join("");
	}

	generateCommands(_strokes) {
		let returns = [];

		const headerString = this.makeNapHeader();
		console.log("Generating header: " + headerString);
		returns.push(headerString);

		//const paletteString = this.generatePalette(this.strokes);
		//console.log("Generating palette: " + paletteString);
		//returns.push(paletteString);

		for (let i=0; i<this.strokes.length; i++) {
			console.log("\n");
			console.log("* * * Begin encoding stroke " + (i+1) + " / " + this.strokes.length + " * * *");
			returns.push(this.makeNapStroke(this.strokes[i].isFill, this.strokes[i].colorIndex, this.strokes[i].points));
			console.log("* * * End encoding stroke " + (i+1) + " / " + this.strokes.length + " * * *");
			console.log("\n");
		}

		const footerString = this.makeNapFooter();
		console.log("Generating footer: " + footerString);
		returns.push(footerString);

		return returns;
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
				point.y = remap(point.y, minVal, maxVal, 0, 1);
			}
		}

		return input;
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
		 * 34 POLY OUTLINED
		 * 35 POLY FILLED
		 * 36 SET & POLY OUTLINED
		 * 37 SET & POLY FILLED
		 */

		if (_isFill) {
			returns.push(doEncode("37")); // FILLED
		} else {
			returns.push(doEncode("36")); // OUTLINED
		}

		return returns;
	}

	makeNapSetColor(_color) {
		let returns = [];

		returns.push(doEncode("3C")); // SET COLOR
		for (let i=0; i<this.dataLength; i++) {
			// TODO
		}

		/*
		const binaryR = binary(_color.x);
		const binaryG = binary(_color.y);
		const binaryB = binary(_color.z);
		returns.push(doEncode(hex(binaryR)));
		returns.push(doEncode(hex(binaryG)));
		returns.push(doEncode(hex(binaryB)));
		*/
		returns.push(doEncode("44"));
		returns.push(doEncode("74"));
		returns.push(doEncode("44"));
		returns.push(doEncode("46"));
		
		return returns.join("");
	}

	makeNapSelectColor(_colorIndex) {
		let returns = [];

		returns.push(doEncode("3E")); // SELECT COLOR
		returns.push(this.makeNapInt(_colorIndex));

		return returns.join("");

	}

	makeNapInt(input) {
		const binaryInput = intToBinary(input);
		const hexInput = hex(input, 2);
		const encodedInput = doEncode(hexInput);
		console.log("Encoding int input: " + input + ", binary: " + binaryInput + ", hex: " + hexInput + ", encoded: " + encodedInput);
		console.log("Testing unbinary: " + unbinary(binaryInput));
		return encodedInput;		
	}

    getBitValsUnsigned(n) {
        return pow(2, (n.length * this.bitsPerByte));
    }

    getBitValsSigned(n) {
        return pow(2, (n.length * this.bitsPerByte) - int(this.firstBitSign))
    }

	makeNapVector2(input) {
		let returns = [];

		console.log("Encoding vector input " + input + " ...");

		// We know that the hardcoded 4-byte domain has 2048 position values
		// (3 position bits per byte, minus the sign for the first bit)
		const maxBitVals = 2048;
		const intX = parseInt(Math.abs(input.x) * maxBitVals);
		const intY = parseInt(Math.abs(input.y) * maxBitVals);
		console.log("Converting vector to int: " + intX + ", " + intY);

		const binX = intToBinary(intX);
		const binY = intToBinary(intY);
		console.log("Converting int to binary: " + binX + ", " + binY);

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

			while (vectorByte.length < 8) vectorByte += "0";

			const hexByte = hex(unbinary(vectorByte));
			const encodedByte = doEncode(hexByte);

			console.log("Encoded byte " + i + ", binary: " + vectorByte + ", hex: " + hexByte + ", " + encodedByte)
			returns.push(encodedByte);
		}

		return returns.join("");
	}

	makeNapPoints(_points) {
		console.log("Encoding " + _points.length + " points ...");
		let returns = [];
		
		const firstPoint = _points[0];

		for (let i=0; i<_points.length; i++) {
			// first point is absolute position, rest are relative to first point
			if (i === 0) {
				returns.push(this.makeNapVector2(firstPoint));
			} else {
				returns.push(this.makeNapVector2(_points[i].sub(firstPoint)));
			}
		}

		return returns.join("");	
	}

	makeNapStroke(_isFill, _colorIndex, _points) {
		let returns = [];

		//returns.push(this.makeNapSelectColor(_colorIndex));
		returns.push(this.makeNapOpcode(_isFill));
		returns.push(this.makeNapPoints(_points));

		return returns.join("");	
	}
}

