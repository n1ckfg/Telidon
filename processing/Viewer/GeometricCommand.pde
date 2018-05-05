/**
* naplps.GeometricCommand
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.awt.Point;

class GeometricCommand extends Command {
	Point p1;
	boolean p1IsRelative;
	boolean set;
	
	GeometricCommand(Context ct, byte op, Point p, boolean rel, boolean doSet) {
		super(ct, op);
		p1 = new Point(p.x, p.y);
		p1IsRelative = rel;
		set = doSet;
	}
	
	GeometricCommand(Context ct, byte op, Point p) {
		this(ct, op, p, true, false);
	}
	
	void addPoint(Point p) {
		// do nothing here
	}
		
}
	
