// + + +   E N C O D E R   + + +

class NapInputWrapper {

	constructor(_color, _points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
		this.colorIndex = 0;
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
			if (getDistance(_color, this.colors[i]) < this.minDistance) {
				return i;
			}
		}

		this.colors.push(_color);
		return this.colors.length - 1;
	}

	makeNapColor(_color) {
		let returns = [];

		returns.push(doEncode("3C")); // SET COLOR
		returns.push(doEncode("69"));
		returns.push(doEncode("44"));
		returns.push(doEncode("69"));
		returns.push(doEncode("44"));

		return returns.join("");
	}

	generatePalette(_strokes) {
		for (let stroke of _strokes) {
			stroke.index = this.addColor(stroke.color);
		}

		this.paletteString = this.encodePalette();
		return this.paletteString;
	}

	encodePalette() {
		let returns = [];

		for (let color of this.colors) {
			returns.push(this.makeNapColor(color));
		}

		return returns.join("");
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

		returns.push(this.palette.generatePalette(this.strokes));

		return returns.join("");
	}

	makeNapOpcode(_isFill) { // only poly line and fill are implemented
		let returns = [];

		if (_isFill) {
			returns.push(doEncode("37")); // SET & POLY FILLED
			returns.push(doEncode("35")); // POLY FILLED
		} else {
			returns.push(doEncode("36")); // SET & POLY OUTLINED
			returns.push(doEncode("34")); // POLY OUTLINED
		}

		return returns; //.join("");
	}

	makeNapColorIndex(_colorIndex) {
		let returns = [];

		returns.push(doEncode("3E")); // SELECT COLOR
		returns.push(doEncode("44"));
		returns.push(doEncode("60"));

		return returns.join("");
	}

	makeNapVector(input) {
		//
	}

	makeNapPoints(_points) {
		let returns = [];

		returns.push(doEncode("40"));
		returns.push(doEncode("63"));
		returns.push(doEncode("6F"));
		returns.push(doEncode("6D"));
		returns.push(doEncode("70"));
		returns.push(doEncode("75"));
		returns.push(doEncode("73"));
		returns.push(doEncode("65"));
		returns.push(doEncode("72"));
		returns.push(doEncode("76"));
		returns.push(doEncode("65"));

		return returns.join("");	
	}

	makeNapStroke(_isFill, _colorIndex, _points) {
		let returns = [];

		returns.push(this.makeNapOpcode(_isFill));
		returns.push(this.makeNapColorIndex(_colorIndex));
		returns.push(this.makeNapPoints(_points));

		return returns.join("");	
	}
}

