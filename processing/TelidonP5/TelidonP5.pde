String filePath = "nap/boom.nap";

PGraphics tex;
int texWidth = 320;
int texHeight = 320;

Naplps nap;
ArrayList<NapCmd> drawCmds;

void setup() {
  size(50, 50, P2D);
  surface.setSize(texWidth * 2, texHeight * 2);
  noSmooth();

  tex = createGraphics(texWidth, texHeight, P2D);
  nap = new Naplps(loadStrings(filePath));
  
  drawCmds = new ArrayList<NapCmd>();
  
  for(int i=0; i<nap.cmds.size(); i++) {
    NapCmd cmd = nap.cmds.get(i);
    if (cmd.opcode.id.equals("SET & POLY FILLED")) drawCmds.add(cmd);
  }
  
  for (int i=0; i<drawCmds.size(); i++) {
    drawCmds.get(i).getPoints();
  }
  
  // first point of first shape is (0.146, 0.4018) from SVG

  for (int i=0; i<drawCmds.get(0).points.size(); i++) {
    println(drawCmds.get(0).points.get(i));
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