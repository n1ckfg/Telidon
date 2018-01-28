NapPointF[] nF = new NapPointF[4];
NapPointB[] nB = new NapPointB[4];
NapPointB3[] nB3 = new NapPointB3[4];

void setup() {
  size(640,480);
  /*
  nF[0] = new NapPointF(0.25, 0.25);
  nF[1] = new NapPointF(0.75, 0.25);
  nF[2] = new NapPointF(0.75, 0.75);
  nF[3] = new NapPointF(0.25, 0.75);
  */
  /*
  nB[0] = new NapPointB("00000000000000000000000010100000", "00000000000000000000000001111000");
  nB[1] = new NapPointB("00000000000000000000000111100000", "00000000000000000000000001111000");
  nB[2] = new NapPointB("00000000000000000000000111100000", "00000000000000000000000101101000");
  nB[3] = new NapPointB("00000000000000000000000010100000", "00000000000000000000000101101000");
  */
  nB3[0] = new NapPointB3("010100000", "001111000");
  nB3[1] = new NapPointB3("111100000", "001111000");
  nB3[2] = new NapPointB3("111100000", "101101000");
  nB3[3] = new NapPointB3("010100000", "101101000");  
}

void draw() {
  background(0);
  stroke(255,255,0);
  strokeWeight(2);
  noFill();
  beginShape();
  /*
  for (int i=0; i<nF.length; i++) {
    vertex(nF[i].x, nF[i].y);
  }
  */
  for (int i=0; i<nB3.length; i++) {
    vertex(nB3[i].x, nB3[i].y);
  }  
  endShape(CLOSE);
}

class NapPointB3 {
  int x, y;
  String xB1, xB2, xB3, xB4, xB5, xB6, xB7, xB8, xB9; 
  String yB1, yB2, yB3, yB4, yB5, yB6, yB7, yB8, yB9;
  
  NapPointB3(String _x, String _y) {
    xB1 = "" + _x.charAt(0);
    xB2 = "" + _x.charAt(1);
    xB3 = "" + _x.charAt(2);
    xB4 = "" + _x.charAt(3);
    xB5 = "" + _x.charAt(4);
    xB6 = "" + _x.charAt(5);
    xB7 = "" + _x.charAt(6);
    xB8 = "" + _x.charAt(7);
    xB9 = "" + _x.charAt(8);
    
    yB1 = "" + _y.charAt(0);
    yB2 = "" + _y.charAt(1);
    yB3 = "" + _y.charAt(2);
    yB4 = "" + _y.charAt(3);
    yB5 = "" + _y.charAt(4);
    yB6 = "" + _y.charAt(5);
    yB7 = "" + _y.charAt(6);
    yB8 = "" + _y.charAt(7);
    yB9 = "" + _y.charAt(8);
    
    x = unbinary(xB1 + xB2 + xB3 + xB4 + xB5 + xB6 + xB7 + xB8 + xB9);
    y = unbinary(yB1 + yB2 + yB3 + yB4 + yB5 + yB6 + yB7 + yB8 + yB9);
    println(x + " " + y);
  }
}

class NapPointB {
  int x, y;
  String xB, yB;
  
  NapPointB(String _x, String _y) {
    xB = _x;
    yB = _y;
    x = unbinary(xB);
    y = unbinary(yB);
    println(x + " " + y);
  }
}

class NapPointF {
  int x, y;
  String xB, yB;
  
  NapPointF(float _x, float _y) {
    x = int(_x * width);
    y = int(_y * height);
    xB = binary(x);
    yB = binary(y);
    println(xB + " " + yB);
  }
}