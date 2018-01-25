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
    if (cmd.opcode.id.equals("SET & POLY FILLED")) drawCmds.add(cmd);
  }
  
  println("Found " + drawCmds.size() + " polygons.");
  
  for (int i=0; i<drawCmds.size(); i++) {
    drawCmds.get(i).getPoints();
    println(drawCmds.get(i).points.size());
  }
  
  // first point of first shape is (0.146, 0.4018) from SVG
  println(drawCmds.get(0).points.get(0));
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