/**
* naplps.PointCommand
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.awt.Point;
import java.awt.Graphics;

class PointCommand extends GeometricCommand
{

	boolean drawPoint = false;
	
	PointCommand(Context ct, byte op, Point p,
				boolean isRel, boolean doSet, boolean draw)
	{
		super(ct, op, p, isRel, doSet);
		drawPoint = draw;
	}
	
	void execute(Graphics gr)
	{
		if (p1IsRelative) {
			ctx.moveCurrentPt(p1);
		}
		else {
			ctx.setCurrentPt(p1);
      }
      if (drawPoint) {
      	if (ctx.bigPel)
      		gr.fillRect(ctx.cX, ctx.cY,
      			ctx.pelSize.x, ctx.pelSize.y);
      	else
      		gr.drawLine(ctx.cX, ctx.cY, ctx.cX, ctx.cY);
      }
   }
}

	
