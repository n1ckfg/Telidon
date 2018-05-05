/**
* naplps.PolygonCommand
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.awt.*;

class PolygonCommand extends GeometricCommand
{
	Polygon pgon;
	boolean fill;

	PolygonCommand(Context ctx, byte op, Point p, boolean doSet, boolean filled)
	{
		super(ctx, op, p, !doSet, doSet);
		fill = filled;
		pgon = new Polygon();
		addPoint(p);
	}
	
	void addPoint(Point p)
	{
		pgon.addPoint(p.x, p.y);
	}
	
	void execute(Graphics gr)
	{
		Polygon abs = new Polygon();
		int xpts[] = pgon.xpoints;
		int ypts[] = pgon.ypoints;
		
		if (p1IsRelative) 
			abs.addPoint(ctx.cX+xpts[0], ctx.cY-ypts[0]);
		else
			abs.addPoint(xpts[0], ypts[0]);
			
		for (int i = 1; i < pgon.npoints; i++) {
			abs.addPoint(abs.xpoints[i-1]+xpts[i],
							  abs.ypoints[i-1]-ypts[i]);
		}
		
		abs.addPoint(abs.xpoints[0], abs.ypoints[0]);
		
      if (fill) {
     		gr.fillPolygon(abs);
     		if (ctx.highlight) {
        		gr.setColor(Color.black);
        		gr.drawPolygon(abs);
        		gr.setColor(ctx.fgColor);
     		}
     	}
  		else {
     		gr.drawPolygon(abs);
 		}
 		
 		if (set) {
     		ctx.cX = abs.xpoints[0];
     		ctx.cY = abs.ypoints[0];
     	}
	}
	/*
  	void doPolygon(boolean set, Graphics gr, boolean fill)
  	{
     int sx = ctx.cX; int sy = ctx.cY;
	  Polygon pgon = new Polygon();
		
  	  if (set) {
  	  		getPoint();
        	sx = ctx.cX = nextPt.x;
        	sy = ctx.cY = ctx.screen-nextPt.y;
     }
     
     pgon.addPoint(ctx.cX, ctx.cY);
     while (getPoint()) {
        	ctx.cX += nextPt.x;
        	ctx.cY -= nextPt.y;
       	pgon.addPoint(ctx.cX, ctx.cY);
     }
     pgon.addPoint(sx, sy);
     if (fill) {
     		gr.fillPolygon(pgon);
     		if (ctx.highlight) {
        		gr.setColor(Color.black);
        		gr.drawPolygon(pgon);
        		gr.setColor(ctx.fgColor);
     		}
     	}
     else {
     		gr.drawPolygon(pgon);
     }
     ctx.cX = sx; ctx.cY = sy;
  }
  */
}
