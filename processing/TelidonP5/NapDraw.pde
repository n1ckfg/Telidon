// This is where it all comes together
// Processing drawing code is separated here

class NapDraw extends NapDecoder {
  
  PGraphics tex;
  int texWidth = 320;
  int texHeight = 320;
  ArrayList<NapCmd> drawCmds;
  
  NapDraw(String _filePath) {
    super(loadStrings(_filePath));
    tex = createGraphics(texWidth, texHeight, P2D);
    drawCmds = new ArrayList<NapCmd>();
    
    for(int i=0; i<cmds.size(); i++) {
      NapCmd cmd = cmds.get(i);
      if (cmd.opcode.id.equals("SET & POLY FILLED")) drawCmds.add(cmd);
    }
  }
  
  void draw() {
    tex.beginDraw();
    tex.background(0);
    //for (int i=0; i<drawCmds.size(); i++) {
      drawPoints(drawCmds.get(0).points, texWidth, texHeight);
    //}
    tex.endDraw();
    
    image(tex, 0, 0, width, height);
  }
  
  void drawPoints(ArrayList<PVector> points, int w, int h) {
    tex.noFill();
    tex.stroke(255,255,0);
    tex.strokeWeight(1);
    tex.beginShape();
    for (int i=0; i<points.size(); i++) {
      PVector p = points.get(i);
      tex.vertex(p.x * w, p.y * h);
    }
    tex.endShape(CLOSE);
    
    tex.strokeWeight(4);
    for (int i=0; i<points.size(); i++) {
      if (i==0) {
        tex.stroke(0, 255, 255);
      } else {
        tex.stroke(127);
      }
      PVector p = points.get(i);
      tex.point(p.x * w, p.y * h);
    }
  }

}