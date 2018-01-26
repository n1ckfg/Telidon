class NapVector {
  
  int xInt, yInt;
  float x, y;
  float numBits = 2048;
  
  NapVector(NapData n4, NapData n3, NapData n2, NapData n1) {
    xInt = getX(n1, n2, n3, n4);
    yInt = getY(n1, n2, n3, n4);
    
    x = (float) xInt / numBits;
    y = (float) yInt / numBits;
  }
  
  String getVal(NapData n, String axis, boolean isHead) {
    if (isHead) {
      if (axis.equals("x")) {
        return "" + n.binary.charAt(4) + n.binary.charAt(5);
      } else {
        return "" + n.binary.charAt(2) + n.binary.charAt(3);
      }
    } else {
      if (axis.equals("x")) {
        return "" + n.binary.charAt(4) + n.binary.charAt(5) + n.binary.charAt(6);
      } else {
        return "" + n.binary.charAt(1) + n.binary.charAt(2) + n.binary.charAt(3);
      }
    }
  }
  
  int getX(NapData n1, NapData n2, NapData n3, NapData n4) {
    String b = getVal(n1, "x", true) + getVal(n2, "x", false) + getVal(n3, "x", false) + getVal(n4, "x", false);
    return unbinary(b);
  }
  
  int getY(NapData n1, NapData n2, NapData n3, NapData n4) {
    String b = getVal(n1, "y", true) + getVal(n2, "y", false) + getVal(n3, "y", false) + getVal(n4, "y", false);
    return unbinary(b);
  }
  
}

/*
           X     Y               X   Y   Z
     8 7|6 5 4|3 2 1|       8 7|6 5|4 3|2 1|
    -----------------      -----------------
    |?|1|S| | |S| | |      |?|1|S| |S| |S| |
    -----------------      -----------------
    |?|1| | | | | | |      |?|1| | | | | | |
    -----------------      -----------------
        . . .                  . . .
    -----------------      -----------------
    |?|1| | | | | | |      |?|1| | | | | | |
    -----------------      -----------------
*/