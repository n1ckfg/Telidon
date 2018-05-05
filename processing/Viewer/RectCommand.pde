/**
* naplps.RectCommand
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU Public License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/

package naplps;

import java.awt.*;

class RectCommand extends GeometricCommand
{
	Point p2;
	Point op1; // original p1
	boolean fill;
	
	RectCommand(Context ct, byte op, Point p, boolean doSet, boolean filled)
   {
   	super(ct, op, p, !doSet, doSet);
   	p2 = p1;
   	fill = filled;
   }
   
	void addPoint(Point p)
	{
		if (set) {
			p2 = new Point(p.x, p.y);
			
		}
	}
	
	public void execute(Graphics gr)
	{
	System.out.println("RectCommand.execute() - "+p1+p2);
	  	if (set) {
        ctx.setCurrentPt(p1);
      }
      
      if (ctx.bigPel) {		// need to add precomp as below
  			int nx = ctx.cX;
  			int ny = ctx.cY;
  			int dx = ctx.pelSize.x - 1;
  			if (dx < 1) dx = 0;
  			int dy = ctx.pelSize.y - 1;
  			if (dy < 1) dy = 0;
        	gr.drawRect(nx, ny, p2.x, -p2.y);
 			gr.drawRect(nx+dx, ny, p2.x, -p2.y);
 			gr.drawRect(nx+dx, ny-dy, p2.x, -p2.y);
 			gr.drawRect(nx, ny-dy, p2.x, -p2.y);
 		}

			// the java.awt functions don't seem to like -ve width or height,
			// so precompensate here
			
			int x1, y1, x2, y2;
			
			if (p2.x < 0) {
				x1 = ctx.cX + p2.x;
				x2 = p2.x * -1;
			}
			else {
				x1 = ctx.cX;
				x2 = p2.x;
			}
			if (p2.y < 0) {
				y1 = ctx.cY - p2.y;	
				y2 = p2.y * -1;
			}
			else {
				y1 = ctx.cY;
				y2 = p2.y;
			}

  		if (fill) {
      gr.fillRect(x1, y1-y2, x2, y2);

        if (ctx.highlight) {
           	gr.setColor(Color.black);
           	gr.drawRect(x1, y1-y2, x2, y2);
           	gr.setColor(ctx.fgColor);
        }
      }
      else {
        gr.drawRect(x1, y1-y2, x2, y2);
      }
      ctx.cX += p2.x;
  }
  
}