/**
* naplps.Context
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.awt.Point;
import java.awt.Color;

/**
* Context stores the NAPLPS graphic context
* information.  
*/

class Context extends Object {
	// instance vars
		
	int cX = 0;
	int cY = 0;
	boolean is3D = false;
	int singleValLength = 1;
	int multiValLength = 3;
	int screen = 512;
	int colorMode = 0;
	int colorMapIndex = 0;
	Color colorMap[];
	Point pelSize;
	boolean bigPel = false;  // true if pel bigger than 1x1
	Color fgColor = Color.white;
	Color bgColor = Color.black;
	boolean highlight = false;
	int lineTexture = 0;
	int texturePattern = 0;
	Point maskSize;
		
  Context() {
    super();
  }
  
	void init() { //DataInputStream in)
		// inp = in;
		pelSize = new Point(0, 0);
		maskSize = new Point(0, 0);
		bigPel = false;
		initColorMap();
	}
	
	/**
	* Initialize a standard NAPLPS colormap
	*/
	void initColorMap() {
		colorMap = new Color[16];
		for (int i = 0; i <= 7; i++) {		// grayscale
			colorMap[i] = new Color(i*32, i*32, i*32);
    }

		// following aren't all exact (some are), but close
		colorMap[8] = Color.blue;
		colorMap[9] = new Color (5*36, 0, 7*36); //blue magenta
		colorMap[10] = new Color(7*36, 0, 4*36); //pinkish red
		colorMap[11] = new Color(7*36, 2*36, 0); //orange red
		colorMap[12] = Color.yellow;
		colorMap[13] = new Color(2*36, 7*36, 0); //yellow green
		colorMap[14] = new Color(0, 7*36, 4*36); //greenish
		colorMap[15] = new Color(0, 5*36, 7*36); //bluegreen;
	}
	
	void setCurrentPt(Point p) {
		cX = p.x;
		cY = screen - p.y;
	}
	
	void moveCurrentPt(Point d) {
		cX += d.x;
		cY -= d.y;
	}
	
}
