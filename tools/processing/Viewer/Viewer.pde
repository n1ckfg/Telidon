/**
* naplps.Viewer
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
import java.net.*;

/**
* A NAPLPS viewer application.   There's some code here for
* setting up as a server for remote viewer apps, this is for
* testing in conjuction with conferencing/whiteboarding app
* (ie JCoSy).
*
* Use the File/Open dialog to select a NAPLPS PDI (Picture
* Description Instruction) file (extension .nap or .pdi) to
* view.   Most of the other stuff doesn't work yet.
*/

Show pdi;
boolean stepmode = false;
String filepath = "";
FileInputStream file;     
PGraphics canvas;	
     
void setup() { 
  size(516, 550, P2D);
  canvas = createGraphics(width, height, P2D);
  pdi = new Show();
  
  try {
    file = new FileInputStream(filepath);
  } catch (Exception e) {
    println("IO exception");
    exit();
  }
  
  DataInputStream dis = new DataInputStream(file);
  pdi.init(dis);
  pdi.setStep(stepmode);
  pdi.ctx.screen = 512;
}
  
void draw() {
  pdi.step(canvas);
}
