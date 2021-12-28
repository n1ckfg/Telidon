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
		this.cmds = this.parseCommands(_strokes);
		this.napRaw = this.cmds.join("");
		console.log(this.napRaw);
	}

	parseCommands(_strokes) {
		let returns = [];

		returns.push(this.makeNapHeader());
		input = this.normalizeAllStrokes(_strokes);
		for (let stroke of input) {
			returns.push(this.makeNapStroke(stroke.isFill, stroke.color, stroke.points));
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

	doEncode(input) {
		let returns = "";
		for (let i = 0; i < input.length; i += 2) {
			returns += String.fromCharCode(parseInt(input.substr(i, 2), 16));
		}
		console.log(returns);
		return returns;
	}

	makeNapHeader() {
		let returns = [];

		returns.push(this.doEncode("18")); // cancel

		returns.push(this.doEncode("1B")); // esc
		returns.push(this.doEncode("45"));

		returns.push(this.doEncode("1F")); // nsr 
		returns.push(this.doEncode("40"));
		returns.push(this.doEncode("40"));
		
		returns.push(this.doEncode("0E")); // shift-out (graphics mode)

		returns.push(this.doEncode("20")); // reset 
		returns.push(this.doEncode("7F"));
		returns.push(this.doEncode("4F"));

		returns.push(this.doEncode("21")); // domain
		returns.push(this.doEncode("4D"));
		returns.push(this.doEncode("40"));
		returns.push(this.doEncode("40"));
		returns.push(this.doEncode("40"));
		returns.push(this.doEncode("40"));

		return returns.join("");
	}

	makeNapOpcode(_isFill) { // only poly line and fill are implemented
		let returns = [];

		if (_isFill) {
			returns.push(this.doEncode("37")); // SET & POLY FILLED
		} else {
			returns.push(this.doEncode("36")); // SET & POLY OUTLINED
		}

		return returns; //.join("");
	}

	makeNapColor(_color) {
		let returns = [];
		returns.push(this.doEncode("3E")); // SELECT COLOR
		returns.push(this.doEncode("44"));
		returns.push(this.doEncode("60"));

		returns.push(this.doEncode("3C")); // SET COLOR
		returns.push(this.doEncode("69"));
		returns.push(this.doEncode("44"));
		returns.push(this.doEncode("69"));
		returns.push(this.doEncode("44"));

		return returns.join("");
	}

	makeNapVector(input) {
		//
	}

	makeNapPoints(_points) {
		let returns = [];

		returns.push(this.doEncode("40"));
		returns.push(this.doEncode("63"));
		returns.push(this.doEncode("6F"));
		returns.push(this.doEncode("6D"));
		returns.push(this.doEncode("70"));
		returns.push(this.doEncode("75"));
		returns.push(this.doEncode("73"));
		returns.push(this.doEncode("65"));
		returns.push(this.doEncode("72"));
		returns.push(this.doEncode("76"));
		returns.push(this.doEncode("65"));

		return returns.join("");	
	}

	makeNapStroke(_isFill, _color, _points) {
		let returns = [];

		returns.push(this.makeNapOpcode(_isFill));
		returns.push(this.makeNapColor(_color));
		returns.push(this.makeNapPoints(_points));

		return returns.join("");	
	}
}

