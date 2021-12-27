// + + +   E N C O D E R   + + +

class StrokeWrapper {

	constructor(_color, _points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
	}

}

class NapEncoder {

	constructor(input) {
		this.cmds = this.parseCommands(input);
		this.napRaw = this.cmds.join("");
		console.log(this.napRaw);
	}

	parseCommands(input) {
		let returns = [];

		returns.push(this.makeNapHeader());

		input = this.normalizeAllStrokes(input);

		for (let stroke of input) {
			let cmd = [];
			cmd.push(this.makeNapOpcode(stroke.isFill));
			cmd.push(this.makeNapColor(stroke.color));
			
			for (let point of stroke.points) {
				cmd.push(this.makeNapVector(point));
			}

			let cmdString = cmd.join("");
			returns.push(cmdString);
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

		return returns.join("");
	}

	makeNapColor(_color) {
		let returns = [];

		returns.push(this.doEncode("3C")); // SET COLOR
		returns.push(this.doEncode("3E")); // SELECT COLOR

		return returns.join("");
	}

	makeNapVector(input) {
		let returns = [];

		returns.push(this.doEncode("5A")); 
		returns.push(this.doEncode("6F"));
		returns.push(this.doEncode("4C"));
		returns.push(this.doEncode("5A"));
		returns.push(this.doEncode("7F"));

		return returns.join("");	
	}

}

