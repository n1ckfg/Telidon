ArrayList<PVector> shape1;
ArrayList<PVector> shape2;
ArrayList<PVector> shape3;

String shape1s = "1460,4018 2114,4380 2393,3369 2759,4097 4277,3276 4946,4507 5889,3276 6870,4570 7896,4062 8238,5874 9024,6304 8120,7192 7559,9038 6182,7900 4883,9419 3872,8003 2598,9155 2158,7754 913,7568 1792,6284 898,5322 2002,5259";
String shape2s = "3071,3081 3701,4111 4981,2978 5581,5932 6753,3100 7095,5669 8736,4258 7617,6807 8643,8433 7085,7925 6519,9526 5723,7607 4190,9736 4136,7192 1885,9214 2959,7349 1475,7163 2749,6382 1016,4848 2774,5000";
String shape3s = "2432,4336 3272,4897 3814,3022 4717,5024 5391,2510 5987,5459 7246,3828 7114,6128 8867,7100 7486,7573 7100,9404 5933,7129 5777,9590 4795,7568 3491,9126 3403,6728 1836,6606 2798,5957 1714,3872";

float svgWidth = 10000;
float svgHeight = 10000;

void setup() {
  size(640, 640, P2D);
  shape1 = parseSvgShape(shape1s);
  //shape2 = parseSvgShape(shape2s);
  //shape3 = parseSvgShape(shape3s);  
}

void draw() {
  background(0);
  drawSvgShape(shape1, color(255,255,0));
  //drawSvgShape(shape2, color(255,0,255));
  //drawSvgShape(shape3, color(255,0,0));
}

ArrayList<PVector> parseSvgShape(String s) {
  ArrayList<PVector> returns = new ArrayList<PVector>();
  String[] points = split(s, " ");
  for (int i=0; i<points.length; i++) {
    String[] p = split(points[i], ",");
    returns.add(new PVector(float(p[0]) / svgWidth, float(p[1]) / svgHeight));
  }
  
  printPoints(returns);

  return returns; 
}

void drawSvgShape(ArrayList<PVector> points, color c) {
  stroke(c);
  strokeWeight(2);
  noFill();
  beginShape();
  for (int i=0; i<points.size(); i++) {
    PVector p = points.get(i);
    vertex(p.x * width, p.y * height);
  }
  endShape(CLOSE);
  strokeWeight(8);
  for (int i=0; i<points.size(); i++) {
    if (i==0) {
      stroke(0,255,255);
    } else if (i==1) {
      stroke(255,0,0);
    } else {
      stroke(127);
    }
    PVector p = points.get(i);
    point(p.x * width, p.y * height);
  }
}

void printPoints(ArrayList<PVector> points) {
  for (int i=0; i<points.size(); i++) {
    println(i + ". " + points.get(i));
  }
}