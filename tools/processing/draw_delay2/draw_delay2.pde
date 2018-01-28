PVector[] coords = new PVector[6];
boolean moveScanline = true;
Scanline scanline;
PGraphics tex;

void setup() {
  size(640, 480, P2D);
  tex = createGraphics(width, height, P2D);
  scanline = new Scanline();
  
  coords[0] = new PVector(width * 0.25, height * 0.25);
  coords[1] = new PVector(width * 0.75, height * 0.25);
  coords[2] = new PVector(width * 0.65, height * 0.5);
  coords[3] = new PVector(width * 0.75, height * 0.75);
  coords[4] = new PVector(width * 0.25, height * 0.75);
  coords[5] = new PVector(width * 0.35, height * 0.5);
}

void draw() {
  scanline.update();
  background(0);
  
  tex.beginDraw();
  tex.fill(255,0,0);
  tex.strokeWeight(4);
  tex.stroke(0,0,255);
  tex.beginShape();
  for (int i=0; i<coords.length; i++) {
    tex.vertex(coords[i].x, coords[i].y);
  }
  tex.endShape(CLOSE);
  tex.endDraw();
  
  tex.loadPixels();
  for (int x=0; x < tex.width; x++) {
    for (int y=0; y < tex.height; y++) {
      int loc = x + y*tex.width;
      if (y < scanline.yPos) tex.pixels[loc] = color(0);
    }
  }
  tex.updatePixels();
  image(tex, 0, 0);

  scanline.draw();
  strokeWeight(6);
  stroke(0,255,255);
  for (int i=0; i<coords.length; i++) {
    point(coords[i].x, coords[i].y);
  }
}

void keyPressed() {
  moveScanline = !moveScanline;
}

class Scanline {

  float yPos = height;
  float yDelta = 3;
  PVector p1, p2;
  
  Scanline() {
    p1 = new PVector(0,yPos);
    p2 = new PVector(width,yPos);
  }
  
  void update() {
    if (moveScanline) yPos -= yDelta;
    if (yPos < 0) yPos = height;
    p1.y = p2.y = yPos;
  } 
  
  void draw() {
    stroke(180 + random(255-180));
    strokeWeight(1);
    line(p1.x, p1.y, p2.x, p2.y);
  }
  
}