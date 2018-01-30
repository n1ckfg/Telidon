// This is where it all comes together
// Processing drawing code is separated here

class NapDraw extends NapDecoder {
  
  ArrayList<NapCmd> drawCmds;
  
  NapDraw(String _filePath) {
    super(loadStrings(_filePath));
    drawCmds = new ArrayList<NapCmd>();
    
    for(int i=0; i<cmds.size(); i++) {
      NapCmd cmd = cmds.get(i);
      if (cmd.opcode.id.equals("SET & POLY FILLED")) drawCmds.add(cmd);
    }
  }
  
  void draw() {
    background(0);
    //for (int i=0; i<drawCmds.size(); i++) 
      // ~ ~ ~ ~ ~ ~ ~ ~
      int whichShape = 0;
      int whichPoint = 8;
      // ~ ~ ~ ~ ~ ~ ~ ~
      println(drawCmds.get(whichShape).points.get(whichPoint));
      drawPoints(drawCmds.get(whichShape).points, width, height);
    //}    
  }
  
  void drawPoints(ArrayList<PVector> points, int w, int h) {
    noFill();
    stroke(255,255,0);
    strokeWeight(2);
    beginShape();
    for (int i=0; i<points.size(); i++) {
      PVector p = points.get(i);
      vertex(p.x * w, p.y * h);
    }
    endShape(CLOSE);
    
    strokeWeight(8);
    for (int i=0; i<points.size(); i++) {
      if (i==0) {
        stroke(0, 255, 255);
      } else if (i==1) {
        stroke(255, 0, 0);
      } else {
        stroke(127);
      }
      PVector p = points.get(i);
      point(p.x * w, p.y * h);
    }
  }

}