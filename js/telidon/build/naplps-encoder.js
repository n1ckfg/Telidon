// + + +   E N C O D E R   + + +

class StrokeWrapper {

	constructor(_color,_points, _isFill) {
		this.color = _color;
		this.points = _points;
		this.isFill = _isFill;
	}

}

class NapEncoder {

	constructor(input) {
		this.cmds = this.parseCommands(input);
	}

	parseCommands(input) {
		let returns = [];

		for (let stroke of input) {
			for (let point of stroke.points) {
				//
			}
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
				point.x = this.remap(point.x, minVal, maxVal, 0, 1);
				point.y = this.remap(point.y, minVal, maxVal, 0, 1);
			}
		}

		return input;
	}

	remap(value, min1, max1, min2, max2) {
        let range1 = max1 - min1;
        let range2 = max2 - min2;
        let valueScaled = (value - min1) / range1;
        return min2 + (valueScaled * range2);
    }

	makeOpcode(input) {

	}

	makeNapData(input) {

	}

	makeNapDataArray(input) {
		
	}

}

