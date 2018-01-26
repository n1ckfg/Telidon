// Processing drawing code is separated here

class NapDraw {
  
  PGraphics tex;
  int texWidth = 320;
  int texHeight = 320;
  
  Naplps nap;
  ArrayList<NapCmd> drawCmds;
  
  NapDraw(String _filePath) {
    tex = createGraphics(texWidth, texHeight, P2D);
    nap = new Naplps(loadStrings(_filePath));
    drawCmds = new ArrayList<NapCmd>();
    
    for(int i=0; i<nap.cmds.size(); i++) {
      NapCmd cmd = nap.cmds.get(i);
      cmd.printCmd("hex");
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
    tex.stroke(0,255,0);
    tex.strokeWeight(1);
    tex.beginShape();
    for (int i=0; i<points.size(); i++) {
      PVector p = points.get(i);
      tex.vertex(p.x * w, p.y * h);
    }
    tex.endShape(CLOSE);
    
    tex.strokeWeight(4);
    for (int i=0; i<points.size(); i++) {
      if (i==0) tex.stroke(255,0,0);
      if (i==1) tex.stroke(0,0,255);
      if (i>1) tex.stroke(127);
      PVector p = points.get(i);
      tex.point(p.x * w, p.y * h);
    }
  }

}