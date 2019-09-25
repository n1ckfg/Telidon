/**
* naplps.Show
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.io.*;
import java.awt.*;

/**
* Show - this is the meat of the NAPLPS decoder.
* It reads the input stream, decodes it, and invokes the
* geometry etc. primitives as needed.
*/

class Show {
  
  byte SI = 017;
  byte SO = 016;

  byte RESET = 040;
  byte DOMAIN = 041;
  byte TEXT = 042;
  byte TEXTURE = 043;
  byte PSET_A = 044;
  byte PSET_R = 045;
  byte POINTA = 046;
  byte POINTR = 047;
  byte LINE_A = 050;
  byte LINE_R = 051;
  byte SETLNA = 052;
  byte SETLNR = 053;
  byte ARC_LN = 054;
  byte ARC_FL = 055;
  byte ARCSTL = 056;
  byte ARCSTF = 057;
  byte RECT_L = 060;
  byte RECT_F = 061;
  byte RECSTL = 062;
  byte RECSTF = 063;
  byte POLY_L = 064;
  byte POLY_F = 065;
  byte PLYSTL = 066;
  byte PLYSTF = 067;
  byte FIELD  = 070;
  byte INCRPT = 071;
  byte INCRLN = 072;
  byte INCRPY = 073;
  byte SETCLR = 074;
  byte WAIT = 075;
  byte SELCLR = 076;
  byte BLINK  = 077;
 
	boolean isPdi(byte c) {
		return ((RESET <= c && c <= BLINK));
	}
	
	boolean isCntrl(byte c) {
		return (c < RESET);
	}
	
	// instance vars
	
	DataInputStream inp;
	boolean putBack = false;
	byte putBackByte;
	
	Context ctx;
	Point nextPt;
	Color nextClr;
	boolean stepMode = false;
	boolean escape8 = false;
	
	// constructor takes a data input
	Show()
	{
		ctx = new Context();
	}
	
	Show(DataInputStream in) 
	{
		this();
		init(in);
	}
	void init(DataInputStream in)
	{
		inp = in;
		nextPt = new Point(0, 0);
		ctx.init();
	}
		
	byte getByte() throws IOException
	{
		if (putBack) {
			putBack = false;
			return putBackByte;
		}
		else {
			byte c = inp.readByte();
			if ((c & 0200) != 0) {
				if (escape8) {
					return (byte) (c & 0177);
				}
				else {
					putBack = true;
					putBackByte = (byte)(c & 0177);
					escape8 = true;
					return SO;
				}
			}
			else {
				if (escape8) {
					putBack = true;
					putBackByte = c;
					escape8 = false;
					return SI;
				}
				else {
					return c;
				}
			}
		}
	}
	
	void unGetByte(byte c)
	{
		putBackByte = c;
		putBack = true;
	}
	
	boolean setDomain()
	{
		try {
			byte c = getByte();
			ctx.is3D = ((c & 040) != 0);
			ctx.singleValLength = 1 + (c & 003);
			ctx.multiValLength = 1 + ((c & 034) >> 2);
		   getPoint();	  // pel size
		   ctx.pelSize.x = nextPt.x;
		   ctx.pelSize.y = nextPt.y;
		   ctx.bigPel = (ctx.pelSize.x > 1 || ctx.pelSize.y > 1);
  println("pelSize = "+ctx.pelSize);
		   return true;
		}
		catch (IOException e) {
			return false;
		}
	}
	
/**
* NAPLPS mixes X,Y coordinate data in each successive byte,
* so we need to disentangle this into separate X and Y values.
* Don't mess with this without thinking carefully about what
* you're doing.   Diagramming out the bits and bytes helps.
*/
	boolean getPoint()  /* disassemble coords from Naplps input */
	{
   byte c;
   int x = 0;
   int y = 0;
   int max = (1 << (3*ctx.multiValLength)) - 1;
	try {
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		return false;
   	}
  		x = (c & 070) >> 3; y = c & 07;
		for (int i = 1; i < ctx.multiValLength; i++ ) {
   		c = getByte();
   		if (c < 64) {
    			unGetByte(c);
    			return false;
   		}
   		x <<= 3; y<<=3;
		   x |= ((c & 070)>>3); y |= (c & 07);
		}   
   // check sign bit
   if (x > (max/2)) x = x-(max+1);
   if (y > (max/2)) y = y-(max+1);
   println("Got point: ("+x+","+y+")");
   nextPt.x = ctx.screen*x/(max/2); nextPt.y = ctx.screen*y/(max/2);
   println("Converted nextpt: "+nextPt);
   return true;
   }
   catch (IOException e) {
   	return false;
   }
	}

/*
* NAPLPS also mixes up the RGB color info into each byte.
* The above caveat about messing with coordinates also applies
* here.
*/

boolean getColor()
	{
	byte c;
	int r = 0, g = 0, b = 0;
	int r2 = 0, g2 = 0, b2 = 0;
   int shift = 8 - (2*ctx.multiValLength);
   nextClr = Color.yellow; // default
	try {
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		return false;
   	}
   	g = c & 040; r = c & 020; b = c & 010;
   	c <<= 2;
   	g |= c & 020; r |= c & 010; b |= c & 004;
   	g >>=4; r >>=3; b >>=2;
   	for (int i = 1; i < ctx.multiValLength; i++ ) {
   		c = getByte();
   		if (c < 64) {
    			unGetByte(c);
    			return false;
   		}
   		g2 = c & 040; r2 = c & 020; b2 = c & 010;
   		c <<= 2;
   		g2 |= c & 020; r2 |= c & 010; b2 |= c & 004;
   		g2 >>= 4; r2 >>= 3; b2 >>= 2;
   		g <<= 2; r <<= 2; b <<= 2;
   		g |= g2; r |= r2; b |= b2;
   	}
   int fill = 0;//(2 << shift) - 1;
   r <<= shift; g <<= shift; b <<= shift;
   nextClr = new Color(r+fill, g+fill, b+fill);
   return true;
   }
   catch (IOException e) {
      return false;
   }
 }
 
 void selectColor()
 {
 	byte c;
	try {
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		ctx.colorMode = 0;
    		return;
   	}
   println("wanted cmap index: "+ (c & 077) + "(shifted: "+ ((c & 074)>>2) + ")");
   	ctx.colorMapIndex = (c & 074) >> 2;
   	ctx.colorMode = 1;
   	nextClr = ctx.colorMap[ctx.colorMapIndex];
   	//ignore mode 2 for now
   }
   catch (IOException e) {
   	ctx.colorMode = 0;
   	return;
   }
 }
   
   	
 
 void doWait()
 {
   byte c;
   int delayMillis;
	try {
   	c = getByte();
   	if (c != 0134) {
			return;
   	}
   	c = getByte();
   	while (c > 64) {
   		delayMillis = 100 * (c & 077);
   		try {
   			Thread.sleep(delayMillis);
   		}
   		catch (InterruptedException e) {
   		}
   		c = getByte();
   	}
   	unGetByte(c);
   }
   catch (IOException e){
   }
  }
   
	void doReset(PGraphics gr)
	{
  		byte c;
  		try {
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		return;
   	}
   	if ((c & 001) != 0) { // reset domain
   		ctx.singleValLength = 1;
   		ctx.multiValLength = 3;
   		ctx.is3D = false;
   	}
   	int colormode = ((c & 005) >> 1);
   	switch (colormode) {
   		case 0:
   			break;
   		case 1:
   			ctx.colorMode = 0;
   			break;
   		case 2:
   			ctx.colorMode = 1;
   			break;
   		case 3:
   			ctx.colorMode = 1;
   			gr.setColor(Color.white);
   			ctx.fgColor = Color.white;
   			break;
   	}
   	int screenstuff = ((c & 070) >> 3);
   	Color save = gr.getColor();
   	switch (screenstuff) {
   		case 0:
   			break;
   		case 1:
   		case 7:
   			gr.clearRect(0, 0, ctx.screen, ctx.screen);
   			break;
   		case 2:
   		case 5:
   		case 6:
   			gr.fillRect(0, 0, ctx.screen, ctx.screen);
   			if (screenstuff != 6)
   				break;		// case 6 drops through to 3
   		case 3:
   			gr.setColor(Color.black);
   			gr.drawRect(0, 0, ctx.screen, ctx.screen);
   			gr.setColor(save);
   			ctx.fgColor = save;
   			break;
   		case 4:
   			gr.drawRect(0, 0, ctx.screen, ctx.screen);
   			break;
		}
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		return;
   	}
   	if ((c & 001) != 0) {		// reset text
   		ctx.cX = ctx.cY = 0;
   	}
   	if ((c & 010) != 0) {		// reset texture
   		ctx.highlight = false;
   		ctx.lineTexture = 0;
   		ctx.texturePattern = 0;
   	}
   	// for now ignore the rest
   }
   catch (IOException e) {
   }
  }
 
 void doTexture()
 {
 	byte c;
  	try {
   	c = getByte();
   	if (c < 64) {
    		unGetByte(c);
    		return;
   	}
   	ctx.lineTexture = c & 003;
   	ctx.highlight = ((c & 004) != 0);
   	ctx.texturePattern = ((c & 070) >> 3);
   	if (getPoint()) {
   		ctx.maskSize.x = nextPt.x;
   		ctx.maskSize.y = nextPt.y;
   	}
   }
   catch (IOException e) {
   }
 }


void doArc(boolean set, PGraphics gr, boolean fill)
{
	Point pt1, pt2, pt3;
	pt1 = new Point(ctx.cX,ctx.cY);
	pt2 = new Point(0,0);
	pt3 = new Point(0,0);
	if (set) {	// first is new setpoint
		if (!getPoint()) return;
		pt1.x = nextPt.x;
		pt1.y = ctx.screen - nextPt.y;
	}
	// get point 2
	if (!getPoint()) return;	// need at least 2 points
	pt2.x = pt1.x + nextPt.x; 	// relative;
	pt2.y = pt1.y - nextPt.y;

	// get point 3, if there is one
	if (!getPoint()) {			// only two, do a circle
		doCircle(gr, pt1, pt2, fill);
		ctx.cX = pt1.x;
		ctx.cY = pt1.y;
	}
	else {							// 3 pts, do arc
		pt3.x = pt2.x + nextPt.x;
		pt3.y = pt2.y - nextPt.y;
		// NB - some data has 3rd point for circle - see if 3rd is
		// same as the first.
		if (pt1.x == pt3.x && pt1.y == pt3.y)
			doCircle(gr, pt1, pt2, fill);
		else
			doArc3pt(gr, pt1, pt2, pt3, fill);
		ctx.cX = pt3.x;
		ctx.cY = pt3.y;
		
		// and gobble any remaining points, we ignore
		while (getPoint());
	}
}
		
		
void doCircle(PGraphics gr, Point a, Point b, boolean fill)
{
	//Points a & b define a diameter, center is midway
	int x, y, diam, cx, cy;
	
	cx = (a.x + b.x)/2;
	cy = (a.y + b.y)/2;
	
	diam = (int) Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	x = cx - (diam/2);
	y = cy - (diam/2);
	
	if (fill) {
		gr.fillOval(x, y, diam, diam);
		if (ctx.highlight) {
			gr.setColor(Color.black);
			gr.drawOval(x, y, diam, diam);
			if (!ctx.bigPel) gr.setColor(ctx.fgColor); //otherwise do it below
		}
	}
	else
		gr.drawOval(x, y, diam, diam);
	
	// following will occur in fgColor unless highlight & fill, in
	// which case black (set above)
	
	if (ctx.bigPel) {
  		int dx = ctx.pelSize.x - 1;
  		if (dx < 1) dx = 0;
  		int dy = ctx.pelSize.y - 1;
  		if (dy < 1) dy = 0;
  		gr.drawOval(x+dx, y, diam, diam);
  		gr.drawOval(x+dx, y+dy, diam, diam);
  		gr.drawOval(x, y+dy, diam, diam);
  		if (ctx.highlight) gr.setColor(ctx.fgColor);
  	}

}

void doArc3pt(PGraphics gr, Point a, Point b, Point c, boolean fill) 
{
Point p = new Point(0,0);
double A, B, C, D, E, F, G;
int r;

//println("doArc3pt: "+a+b+c);
	A = b.x - a.x;
        B = b.y - a.y;
        C = c.x - a.x;
        D = c.y - a.y;
    
        E = A*(a.x + b.x) + B*(a.y + b.y);
        F = C*(a.x + c.x) + D*(a.y + c.y);
    
        G = 2.0*(A*(c.y - b.y)-B*(c.x - b.x));
    
        p.x = (int)((D*E - B*F) / G);
        p.y = (int)((A*F - C*E) / G);
 
//printf("Center is : (%d, %d)\n", p.x, p.y);

	r = (int) Math.sqrt((double)(a.x-p.x)*(a.x-p.x) + (a.y-p.y)*(a.y-p.y));

//printf("Radius is : %d\n", r);

/* now for calculating gr.drawArc parms:
	which are bounding box corner, width,height, start angle, end angle
*/
	{
	int width, height;
	Point box = new Point(0,0);
	double SA, EA; int sa, ea;
	int area, s;
/* use area to determine direction: -ve = clockwise, +ve = ccw */

	area = (((a.x*b.y)-(a.y*b.x))
		+((b.x*c.y)-(b.y*c.x))
		+((c.x*a.y)-(c.y*a.x))
		)/2;

	width = height = 2 * r;
	box.x = p.x - r;
	box.y = p.y - r;

	SA = Math.atan2((double)(a.y-p.y), (double)(a.x-p.x));
	EA = Math.atan2((double)(c.y-p.y), (double)(c.x-p.x));

/* the following isn't quite right yet - magnitude OK but
  sign and phase may be off */

	sa = (int) (180.0 * SA / 3.141592654);
	ea = (int) (180.0 * EA / 3.141592654);


	/* but I do care which 'side' the middle point is on */
	/* so I know whether to specify long way or short way */
	/* around the circle */

	s = ((a.y-b.y)*(c.x-a.x)-(a.x-b.x)*(c.y-a.y));

	/* try if side (or area) -ve (same sign both, always) */
	/* and start angle -ve, or side and sa both +ve, then */
	/* fix end angle */

	ea = ea - sa;

	if (s < 0 && sa < 0)
		ea = ea-360;
	else if (s >= 0 && sa >=0)
		ea = ea + 360;

	if (ea < -360) ea += 360;   // why does this happen?
	else if (ea > 360) ea -= 360;
	
	// for now, we just do unfilled arc - built in fillArc does a pie wedge,
	// NAPLPS defines just the chord
	gr.drawArc(box.x, box.y, width, height, -sa, -ea);
	if (ctx.bigPel) {
  		int dx = ctx.pelSize.x - 1;
  		if (dx < 1) dx = 0;
  		int dy = ctx.pelSize.y - 1;
  		if (dy < 1) dy = 0;
  		gr.drawArc(box.x+dx, box.y, width, height, -sa, -ea);
  		gr.drawArc(box.x+dx, box.y+dy, width, height, -sa, -ea);
  		gr.drawArc(box.x, box.y+dy, width, height, -sa, -ea);
  	}

/* TODO: fix up the following to do a proper filled section
* (chord) of circle. 
*/
  	if (fill) {	// fudge the fill with a triangle
		int px[] = new int[3]; int py[] = new int[3];
		px[0] = a.x; py[0] = a.y;
		px[1] = b.x; py[1] = b.y;
		px[2] = c.x; py[2] = c.y;
		gr.fillPolygon(px, py, 3);
	}
//println("drawArc parms: ("+box+", "+width+", "+height+", "+sa+", "+ea);
	}
}
  
  void setStep(boolean b)
  {
  	stepMode = b;
  	println("stepMode = "+stepMode);
  }
   
  void step(PGraphics gr)
  {
  	stepMode = true;
  	println("stepping..");
  	disassemble(gr);
  }
  
  void doPoint(byte c, PGraphics gr, boolean isRel, boolean doSet, boolean draw)
  {
  		PointCommand cmd;
  		
  		while (getPoint()) {
  			cmd = new PointCommand(ctx, c, nextPt, isRel, doSet, draw);
  			cmd.execute(gr);
  		}
  }
  		
  
  void doLine(byte c, boolean rel, PGraphics gr, boolean set)
  {
      LineCommand cmd;
      
      while (getPoint()) {
      	cmd = new LineCommand(ctx, c, nextPt, rel, set);
      	if (set) {
	  			getPoint();
  				cmd.addPoint(nextPt, rel);
      	}
      	cmd.execute(gr);
      }
  }
  
  void doRectangle(byte c, boolean set, PGraphics gr, boolean fill)
	{	
		RectCommand cmd;

		
		while (getPoint()) {
			cmd = new RectCommand(ctx, c, nextPt, set, fill);
         if (set) {
         	getPoint();
           cmd.addPoint(nextPt);
         }
			cmd.execute(gr);
		}
	}
	
  	void doPolygon(byte c, boolean set, PGraphics gr, boolean fill)
  	{
     int sx = 0; int sy = 0;
     
  	  if (set) {
  	  		getPoint();
        	sx = nextPt.x;
        	sy = ctx.screen-nextPt.y;
     }
	  PolygonCommand cmd = new PolygonCommand(ctx, c, new Point(sx,sy), set, fill);
     while (getPoint()) {
			cmd.addPoint(nextPt);
     }
		cmd.execute(gr);
  }
  	
  byte c;
  boolean textMode = true;
  void disassemble(PGraphics gr)
 {
   GeometricCommand cmd;
   try {
   out: while (true)
   {
    c=getByte();
    if (isCntrl(c)) {
      if (c == 016) /* SO */ {
         println("<SO>");
         textMode = false;
         }
      else if (c == 017) /* SI */ {
         println("<SI>");
         textMode = true;
         }
      else
         println("  ??: "+c);
      }
    else 
      if (textMode) {
         //System.out.print((char)c);
         gr.drawString(String.valueOf((char)c), ctx.cX, ctx.cY);
         ctx.cX += 10;
      }
      else
      if (isPdi(c)) 
         switch (c) {
        case RESET: println("RESET");
        		doReset(gr);
            break;
        case DOMAIN: println("DOMAIN");
        		setDomain();
            break;
        case TEXT : println("TEXT");
            break;
        case TEXTURE: println("TEXTURE");
        		doTexture();
            break;
        case PSET_A: println("PSET_A");
            while (getPoint()) {
            	cmd = new PointCommand(ctx,c, nextPt, false, true, false);
            	cmd.execute(gr);
            }
            break;
        case PSET_R: println("PSET_R");
            while (getPoint()) {
            	cmd = new PointCommand(ctx,c, nextPt, true, true, false);
            	cmd.execute(gr);
            }
            break;
        case POINTA: println("POINTA");
            while (getPoint()) {
            	cmd = new PointCommand(ctx,c, nextPt, false, true, true);
            	cmd.execute(gr);
            }
            break;
        case POINTR: println("POINTR");
            while (getPoint()) {
            	cmd = new PointCommand(ctx,c, nextPt, true, true, true);
            	cmd.execute(gr);
            }
            break;
        case LINE_A: println("LINE_A");
				doLine(c, false, gr, false);
            break;
        case LINE_R: println("LINE_R");
				doLine(c, true, gr, false);
            break;
        case SETLNA: println("SETLNA");
				doLine(c, false, gr, true);
            break;
        case SETLNR: println("SETLNR");
				doLine(c, true, gr, true);
            break;
            
        // arcs 
        case ARC_LN: println("ARC_LN");
        		doArc(false, gr, false);
            break;
        case ARC_FL: println("ARC_FL");
        		doArc(false, gr, true);
            break;
        case ARCSTL: println("ARCSTL");
        		doArc(true, gr, false);
	          break;
        case ARCSTF: println("ARCSTF");
        		doArc(true, gr, true);
            break;
        case RECT_L: println("RECT_L");
        		doRectangle(c, false, gr, false);
            break;
        case RECT_F: println("RECT_F");
        		doRectangle(c, false, gr, true);
            break;
        case RECSTL: println("RECSTL");
        		doRectangle(c, true, gr, false);
            break;
        case RECSTF: println("RECSTF");
        		doRectangle(c, true, gr, true);
            break;
        case POLY_L: println("POLY_L");
				doPolygon(c, false, gr, false);
            break;
        case POLY_F: println("POLY_F");
				doPolygon(c, false, gr, true);
            break;
        case PLYSTL: println("PLYSTL");
				doPolygon(c, true, gr, false);
            break;
        case PLYSTF: println("PLYSTF");
				doPolygon(c, true, gr, true);
            break;
        case FIELD: println("FIELD");
            break;
        case INCRPT: println("INCRPT");
            break;
        case INCRLN: println("INCRLN");
            break;
        case INCRPY: println("INCRPY");
            break;
        case SETCLR: println("SETCLR");
            getColor();
           	gr.setColor(nextClr);
           ctx.fgColor = nextClr;
            if (ctx.colorMode != 0) {
            	ctx.colorMap[ctx.colorMapIndex] = nextClr;
           println("set colormap["+ctx.colorMapIndex+"] to "+nextClr);
            }            	
            break;
        case WAIT : println("WAIT");
        		 doWait();
            break;
        case SELCLR: println("SELCLR");
        		selectColor();
        		gr.setColor(nextClr);
        		ctx.fgColor = nextClr;
            break;
        case BLINK: println("BLINK");
            break;
        default:
            System.err.println("Can't happen!");
        }
     else {
        println(" ??: "+c);
     }
     if (stepMode) { println("break"); break out;}
     }//end while

    }
    catch (IOException e) {
    }
   }
   
   // mainline for testing
   
   /*
   static void main(String args[])
   {
      java.awt.Frame frame = new java.awt.Frame("PDI");
      frame.resize(512, 512); 
      frame.setBackground(Color.black);
      frame.show();
      PGraphics gr = frame.getGraphics();
      FileDialog fd;
      try {
   	 fd = new FileDialog(frame, "NAPLPS");
   	 fd.show();
   	 String fname = fd.getFile();
   	DataInputStream dis = new DataInputStream(new FileInputStream(fname));
   	Show pdi = new Show(dis);
   	pdi.ctx.screen = 512;
   	gr.setColor(Color.white);// for now
   	pdi.disassemble(gr);
   	}
   	catch (Exception e) {
   		println("IO exception");
   	}
   }
   */
   
}
