/**
* naplps.Context
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU Public License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/

package naplps;

import java.awt.Point;
import java.awt.Color;

/**
* Context stores the NAPLPS graphic context
* information.  
*/

class Context extends Object
{
	// instance vars
		
	protected int cX = 0;
	protected int cY = 0;
	protected boolean is3D = false;
	protected int singleValLength = 1;
	protected int multiValLength = 3;
	protected int screen = 512;
	protected int colorMode = 0;
	protected int colorMapIndex = 0;
	protected Color colorMap[];
	protected Point pelSize;
	protected boolean bigPel = false;  // true if pel bigger than 1x1
	protected Color fgColor = Color.white;
	protected Color bgColor = Color.black;
	protected boolean highlight = false;
	protected int lineTexture = 0;
	protected int texturePattern = 0;
	protected Point maskSize;
	
	public Context()
	{
		super();
	}
	
	public void init()//DataInputStream in)
	{
		// inp = in;
		pelSize = new Point(0, 0);
		maskSize = new Point(0, 0);
		bigPel = false;
		initColorMap();
	}
	
	/**
	* Initialize a standard NAPLPS colormap
	*/
	public void initColorMap()
	{
		colorMap = new Color[16];
		for (int i = 0; i <= 7; i++)		// grayscale
			colorMap[i] = new Color(i*32, i*32, i*32);

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
	
	public void setCurrentPt(Point p)
	{
		cX = p.x;
		cY = screen - p.y;
	}
	
	public void moveCurrentPt(Point d)
	{
		cX += d.x;
		cY -= d.y;
	}

		
}
