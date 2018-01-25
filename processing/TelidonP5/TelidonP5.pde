String filePath = "nap/boom.nap";

PGraphics tex;
int texWidth = 320;
int texHeight = 240;

Naplps nap;
ArrayList<NapCmd> drawCmds;

void setup() {
  size(50, 50, P2D);
  surface.setSize(texWidth * 2, texWidth * 2);
  noSmooth();

  tex = createGraphics(texWidth, texHeight, P2D);
  nap = new Naplps(loadStrings(filePath));
  
  drawCmds = new ArrayList<NapCmd>();
  
  for(int i=0; i<nap.cmds.size(); i++) {
    NapCmd cmd = nap.cmds.get(i);
    if (cmd.opcode.hex.equals("37")) drawCmds.add(cmd);
  }
  
  println("Found " + drawCmds.size() + " polygons.");
  
  for (int i=0; i<drawCmds.size(); i++) {
    drawCmds.get(i).getPoints();
  }
}

void draw() {
  tex.beginDraw();
  tex.background(0);
  for (int i=0; i<drawCmds.size(); i++) {
    drawPoints(drawCmds.get(i).points, texWidth, texHeight);
  }
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
  tex.endShape();
  
  tex.stroke(255,0,0);
  tex.strokeWeight(4);
  for (int i=0; i<points.size(); i++) {
    PVector p = points.get(i);
    tex.point(p.x * w, p.y * h);
  }
}