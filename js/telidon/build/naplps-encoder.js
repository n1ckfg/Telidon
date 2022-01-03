// + + +   E N C O D E R   + + +

class NapInputWrapper {

	constructor(_color, _points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
		this.colorIndex = 0;
		// Number of bytes per encoded value. This is hardcoded here, but
		// can be set in the NAPLPS domain command.
		this.dataLength = 4;
	}

}

class NapInputPalette {

	constructor() {
		this.colors = [];
		this.minDistance = 0.1;
		this.paletteString = "";
	}

	addColor(_color) {
		for (let i=0; i<this.colors.length; i++) {
			const dist = getDistance(_color, this.colors[i]);
			console.log("Color similarity is " + dist);
			if (dist < this.minDistance) {
				console.log("Reusing color " + i + ", palette length is " + this.colors.length);
				return i;
			}
		}

		this.colors.push(_color);
		const len = this.colors.length - 1;
    	console.log("Adding color " + (len + 1) + ", palette length is " + this.colors.length);
		return len;
	}

	makeNapColor(_color) {
		let returns = [];

		returns.push(doEncode("3C")); // SET COLOR
		for (let i=0; i<this.dataLength; i++) {
			// TODO
		}

		const binaryR = binary(_color.x);
		const binaryG = binary(_color.y);
		const binaryB = binary(_color.z);
		returns.push(doEncode(hex(binaryR)));
		returns.push(doEncode(hex(binaryG)));
		returns.push(doEncode(hex(binaryB)));

		return returns.join("");
	}

	encodePalette() {
		let returns = [];

		for (let color of this.colors) {
			console.log("Encoding color " + color.x + ", " + color.y + ", " + color.z);
			returns.push(this.makeNapColor(color));
		}

		return returns.join("");
	}

	generatePalette(_strokes) {
		for (let stroke of _strokes) {
			stroke.index = this.addColor(stroke.color);
		}

		this.paletteString = this.encodePalette();
		return this.paletteString;
	}

}

class NapEncoder {

	constructor(_strokes) {
		this.strokes = _strokes;
		this.palette = new NapInputPalette();

		this.cmds = this.generateCommands(this.strokes);

		this.napRaw = this.cmds.join("");
		console.log(this.napRaw);
	}

	generateCommands(_strokes) {
		let returns = [];

		returns.push(this.makeNapHeader());
		returns.push(this.palette.generatePalette(this.strokes));

		input = this.normalizeAllStrokes(_strokes);
		for (let stroke of input) {
			returns.push(this.makeNapStroke(stroke.isFill, stroke.colorIndex, stroke.points));
		}

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

	makeNapOpcode(_isFill) { // only poly line and fill are implemented
		let returns = [];

		if (_isFill) {
			//returns.push(doEncode("37")); // SET & POLY FILLED
			returns.push(doEncode("35")); // POLY FILLED
		} else {
			//returns.push(doEncode("36")); // SET & POLY OUTLINED
			returns.push(doEncode("34")); // POLY OUTLINED
		}

		return returns; //.join("");
	}

	makeNapColorIndex(_colorIndex) {
		let returns = [];

		returns.push(doEncode("3E")); // SELECT COLOR
		returns.push(makeNapInt(1));//_colorIndex));

		return returns.join("");

	}

	makeNapInt(input) {
		const encodedInput = doEncode(hex(binary(input)));
		console.log("encoding input " + input + " as " + encodedInput);
		return encodedInput;		
	}

	makeNapVector(input) {
		//
	}

	makeNapPoints(_points) {
		let returns = [];

		returns.push(doEncode("51"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("65"));
		returns.push(doEncode("48"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("71"));
		returns.push(doEncode("73"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("59"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("52"));
		returns.push(doEncode("6C"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("62"));
		returns.push(doEncode("45"));
		returns.push(doEncode("40"));
		returns.push(doEncode("41"));
		returns.push(doEncode("48"));
		returns.push(doEncode("67"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("4D"));
		returns.push(doEncode("4D"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("52"));
		returns.push(doEncode("75"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("57"));
		returns.push(doEncode("79"));
		returns.push(doEncode("40"));
		returns.push(doEncode("40"));
		returns.push(doEncode("4D"));
		returns.push(doEncode("58"));
		returns.push(doEncode("78"));
		returns.push(doEncode("78"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("4D"));
		returns.push(doEncode("78"));
		returns.push(doEncode("7A"));
		returns.push(doEncode("40"));
		returns.push(doEncode("4E"));
		returns.push(doEncode("78"));
		returns.push(doEncode("71"));
		returns.push(doEncode("6D"));
		returns.push(doEncode("58"));
		returns.push(doEncode("40"));
		returns.push(doEncode("50"));
		returns.push(doEncode("48"));
		returns.push(doEncode("50"));
		returns.push(doEncode("40"));
		returns.push(doEncode("68"));
		returns.push(doEncode("50"));
		returns.push(doEncode("50"));
		returns.push(doEncode("47"));
		returns.push(doEncode("45"));
		returns.push(doEncode("42"));
		returns.push(doEncode("77"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("49"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("47"));
		returns.push(doEncode("46"));
		returns.push(doEncode("4B"));
		returns.push(doEncode("74"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("71"));
		returns.push(doEncode("7A"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("43"));
		returns.push(doEncode("4E"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("4A"));
		returns.push(doEncode("5E"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("6A"));
		returns.push(doEncode("7E"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("77"));
		returns.push(doEncode("5E"));
		returns.push(doEncode("50"));
		returns.push(doEncode("78"));
		returns.push(doEncode("70"));
		returns.push(doEncode("73"));
		returns.push(doEncode("4B"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("55"));
		returns.push(doEncode("5C"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("7F"));
		returns.push(doEncode("5E"));
		returns.push(doEncode("4A"));
		returns.push(doEncode("78"));
		returns.push(doEncode("70"));
		returns.push(doEncode("49"));
		returns.push(doEncode("5E"));

		return returns.join("");	
	}

	makeNapStroke(_isFill, _colorIndex, _points) {
		let returns = [];

		returns.push(this.makeNapColorIndex(_colorIndex));
		returns.push(this.makeNapOpcode(_isFill));
		returns.push(this.makeNapPoints(_points));

		return returns.join("");	
	}
}

