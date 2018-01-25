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
  
  tex.stroke(255,0,0);
  tex.strokeWeight(4);
  for (int i=0; i<points.size(); i++) {
    PVector p = points.get(i);
    tex.point(p.x * w, p.y * h);
  }
}