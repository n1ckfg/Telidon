// https://forum.processing.org/two/discussion/14390/fill-algorithm 

import java.util.ArrayDeque;
 
PImage img;
ArrayDeque<Point> q = new ArrayDeque<Point>();
 
public void setup() {
  size(400, 400, P2D);
  img = makeImage();
}
 
public void draw() {
  background(255);
  image(img, 0, 0);
}
 
public void mouseClicked() {
  // Flood fill with random colour
  int c = (int)(random(1, 0xFFFFFF)) | 0xFF000000;
  floodFill(img, mouseX, mouseY, c);
}
 
void floodFill(PImage picture, int orgX, int orgY, int newColor) {
  int pw = picture.width;
  int ph = picture.height;
  if (orgX < 0 || orgX >= pw || orgY < 0 || orgY >= ph)
    return;
  picture.loadPixels();
  int [] pxl = picture.pixels;
  int orgColor = pxl[orgX + orgY * pw];
  // Stop if the color is not being changed.
  if (newColor == orgColor)
    return;
  // Proceed with flood fill
  Point p = new Point(orgX, orgY);
  q.add(p);
  int west, east;
  while (!q.isEmpty () ) { //&& q.size() < 500) {
    p = q.removeFirst();
    if (isToFill(p.x, p.y, pxl, pw, ph, orgColor)) {
      west = east = p.x;
      while (isToFill(--west, p.y, pxl, pw, ph, orgColor));
      while (isToFill(++east, p.y, pxl, pw, ph, orgColor));
      for (int x = west + 1; x < east; x++) {
        pxl[x + p.y * pw] = newColor;
        if (isToFill(x, p.y - 1, pxl, pw, ph, orgColor))
          q.add(new Point(x, p.y - 1));
        if (isToFill(x, p.y + 1, pxl, pw, ph, orgColor))
          q.add(new Point(x, p.y + 1));
      }
    }
  }
  picture.updatePixels();
}
 
// Returns true if the specified pixel requires filling
boolean isToFill(int px, int py, int[] pxl, int pw, int ph, int orgColor) {
  if (px < 0 || px >= pw || py < 0 || py >= ph)
    return false;
  return pxl[px + py * pw] == orgColor;
}
 
// Make a simple image to test the flood fill function
PImage makeImage() {
  PGraphics pg = createGraphics(width, height, P2D);
  pg.noSmooth();
  pg.beginDraw();
  pg.background(255);
  pg.fill(255, 200, 200);
  pg.noStroke();
  pg.ellipse(width/2, height/3, 0.4f*width, 0.4f*height);
  pg.ellipse(width/3, height/1.8f, 0.4f*width, 0.4f*height);
  pg.ellipse(2*width/3, height/1.8f, 0.4f*width, 0.4f*height);
  pg.fill(255, 255, 200);
  pg.ellipse(width/2, height/2, 0.2f*width, 0.2f*height);
  pg.endDraw();
  return pg.get();
}
 
// Could use java.awt.Point instead
class Point {
  int x, y;
 
  public Point(int x, int y) {
    this.x = x;
    this.y = y;
  }
 
  public String toString() {
    return "[" + x + ", " + y + "]";
  }
}