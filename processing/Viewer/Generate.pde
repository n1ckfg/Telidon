/**
* naplps.Generate
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.io.*;

/**
* Ouput NAPLPS codes as requested.
*/

class Generate {
  
	Context ctx;
	DataOutputStream outp;
		
	// constructor takes a data input
	private Generate() {
		ctx = new Context();
	}
	
	Generate(DataOutputStream out) {
		this();
		init(out);
	}

	void init(DataOutputStream out) {
		outp = out;
		ctx.init();
	}
/**
* Convert a float representing fraction of a unit
* screen to an int less than 512.
*/

int coord(float x) {
	if (x < 1.0 && x > -1.0) {
		return (int) (511 * x);
	} else {
		return 511;
	}
}

void putByte(byte ch) throws IOException {
	if (outp != null) {
		outp.writeByte(ch);
	} else {
		throw new IOException("Output stream is null");
	}
}

void putAPoint(int x, int y) throws IOException { /* put abs point */
  System.out.println("putAPoint( "+x+", "+y+")");
  y = 256-y;		// naplps coordinate system is inverted
  putRAPoint(x, y);
}
   
void putRAPoint(int x, int y) throws IOException {
  int c;
  byte ch;
  System.out.println("putRAPoint( "+x+", "+y+")");
   c = (y & 0700) ; c >>= 3;
   c |= (x & 0700) ; c >>= 3;
   ch = (byte) (c | 0100);
   putByte(ch);
   c = (y & 070) ; c >>=3;
   c |= (x & 070);
   ch = (byte) (c | 0100);
   putByte(ch);
   c = (x & 07) ; c <<= 3;
   c |= (y & 07);
   ch = (byte) (c | 0100);
   putByte(ch);
}

void putRPoint(int x, int y) throws IOException { /* put rel point */
  System.out.println("putRPoint( "+x+", "+y+")");
  if (x < 0) x += 512;
  if (y < 0) y += 512;
  putRAPoint(x,y);
}

void setGraph() throws IOException { /* start graphics mode */
   putByte(Show.SO);
}

void endGraph() throws IOException { /* end graphics mode */
   putByte(Show.SI);
}

void point(boolean abs, boolean vis, int x, int y) throws IOException { /* set or mark point */
   if (abs) {
      if (vis) {
         putByte(Show.POINTA);
      } else {
         putByte(Show.PSET_A);
      }
      putAPoint(x,y);
   } else {
      if (vis) {
         putByte(Show.POINTR);
      } else {
         putByte(Show.PSET_R);
      }
      putRPoint(x,y);
   }
}

void line(boolean abs, int x, int y) throws IOException { /* draw a line */
   if (abs) {
      putByte(Show.LINE_A);
      putAPoint(x,y);
   } else {
      putByte(Show.LINE_R);
      putRPoint(x,y);
   }
}

void setLine(boolean abs, int x1, int y1, int x2, int y2) throws IOException { /* set and line */
   if (abs) {
     putByte(Show.SETLNA);
   } else {
     putByte(Show.SETLNR);
   }
   putAPoint(x1,y1);
   if (abs) {
     putAPoint(x2,y2);
   } else {
     putRPoint(x2,y2);
   }
}

void rectangle(boolean fill, int x1, int y1, int x2, int  y2) throws IOException {
	putByte((fill) ? Show.RECSTF : Show.RECSTL);
	putAPoint(x1,y1);
	putRPoint(x2-x1, y1-y2);
}

void circleCenter(boolean fill, int xc, int yc, int x2, int y2) throws IOException {
	int x1, y1;
	x1 = xc - (x2 - xc);
	y1 = yc - (y2 - yc);
	putByte((fill) ? Show.ARCSTF : Show.ARCSTL);
	putAPoint(x1,y1);
	putRPoint(x2-x1, y1-y2);
}

void setColor(java.awt.Color c) throws IOException {
	int r, g, b;
	byte ch = 0;
	r = c.getRed();
	g = c.getGreen();
	b = c.getBlue();
	putByte(Show.SETCLR);
	ch = 0100;
	ch |= (((g>>2) & 040) | ((r>>3) & 020) | ((b>>4) & 010));
	ch |= (((g>>4) & 004) | ((r>>5) & 002) | ((b>>6) & 001));
	putByte(ch);
	ch = 0100;
	ch |= ((g & 040) | ((r>>1) & 020) | ((b>>2) & 010));
	ch |= (((g >>2) & 004) | ((r>>3) & 002) | ((b>>4) & 001));
	putByte(ch);
	ch = 0100;
	ch |= (((g<<2) & 040) | ((r<<1) & 020) | (b & 010));
	ch |= ((g & 004) | ((r>>1) & 002) | ((b>>2) & 001));
	putByte(ch);
}
	
}
