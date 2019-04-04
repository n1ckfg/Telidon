/**
* naplps.LineCommand
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.awt.*;

class LineCommand extends GeometricCommand {
  
	Point p2;
	boolean p2IsRelative;
	
   LineCommand(Context ct, byte op, Point p, boolean rel, boolean doSet) {
   	super(ct, op, p, rel, doSet);
   	p2 = p1;
   	if (doSet) p1IsRelative = false;
   	p2IsRelative = rel;
   }
   
    void addPoint(Point p, boolean rel) {
		if (!p1IsRelative) {
			p2 = new Point(p.x, p.y);
			p2IsRelative = rel;
		}
	}
	
void execute(Graphics gr) {
	  	if (set) {
        ctx.setCurrentPt(p1);
      }
      
  		if (!p2IsRelative) {
      	if (ctx.bigPel) {
      		  doThickLine(gr, p2, true);
      	} else {
        		gr.drawLine(ctx.cX, ctx.cY, p2.x, ctx.screen-p2.y);
        }
        ctx.setCurrentPt(p2);
      } else {
     		if (ctx.bigPel) {
      	   doThickLine(gr, p2, false);
      	} else {
       	 	gr.drawLine(ctx.cX, ctx.cY, ctx.cX+p2.x, ctx.cY-p2.y);
        }
      	ctx.moveCurrentPt(p2);
      }
  }
  
  private void doThickLine(Graphics gr, Point pt, boolean abs)
  {
  		int nx = ctx.cX;
  		int ny = ctx.cY;
  		int dx = ctx.pelSize.x - 1;
  		if (dx < 1) dx = 0;
  		int dy = ctx.pelSize.y - 1;
  		if (dy < 1) dy = 0;
 // println("thickline: Pelsize: "+pelSize+" dx, dy"+dx+","+dy);
 		if (dy == 1 && dx == 1) {
 		if (abs) {
 			gr.drawLine(nx, ny, pt.x, ctx.screen-pt.y);
 			gr.drawLine(nx+dx, ny, pt.x+dx, ctx.screen-pt.y);
 			gr.drawLine(nx+dx, ny+dy, pt.x+dx, ctx.screen-(pt.y+dy));
 			gr.drawLine(nx, ny+dy, pt.x, ctx.screen-(pt.y+dy));
 		}
 		else {
  			gr.drawLine(nx, ny, nx+pt.x, ny-pt.y);
  			nx += dx;
  			gr.drawLine(nx, ny, nx+pt.x, ny-pt.y);
  			ny += dy;
  			gr.drawLine(nx, ny, nx+pt.x, ny-pt.y);
  			nx -= dx;
  			gr.drawLine(nx, ny, nx+pt.x, ny-pt.y);
  		}
  		}
  		
  		if (dx > 1 || dy > 1) {
  			int xv[] = new int[6];
  			int yv[] = new int[6];
  			int px = pt.x;
  			int py = pt.y;
  			nx = ctx.cX;
  			ny = ctx.cY;
  			
  			if (abs) {
  				py = ctx.screen - py;
  			}
  			else {
  				px = ctx.cX + px;
  				py = ctx.cY - py;
  			}
  			if (px < nx) {
  				nx = px; ny = py;
  				px = ctx.cX; py = ctx.cY;
  			}
  			xv[0] = nx; yv[0] = ny;
  			xv[1] = nx; yv[1] = ny-dy;
  			if (py < ny) {
  				xv[2] = px; yv[2] = py-dy;
  				xv[3] = px+dx; yv[3] = py-dy;
  				xv[4] = px+dx; yv[4] = py;
  				xv[5] = nx+dx; yv[5] = ny;
  			}
  			else {
  				xv[2] = nx+dx; yv[2] = ny-dy;
  				xv[3] = px+dx; yv[3] = py-dy;
  				xv[4] = px+dx; yv[4] = py;
  				xv[5] = px; yv[5] = py;
  			}
  			Polygon pgon = new Polygon(xv, yv, 6);
  			gr.fillPolygon(pgon);
  		}
  				
  	}
  	
}
