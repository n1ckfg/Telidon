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