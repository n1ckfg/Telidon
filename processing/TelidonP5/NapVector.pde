// Extract XY or XYZ coordinates from multiple NapData objects
class NapVector {
  
  int xInt, yInt;
  float x, y;
  float numBits = 2048;
  boolean reverse = true;
  
  NapVector(ArrayList<NapData> n) {
    numBits = pow(2, (n.size() * 3) - 1);
    xInt = getCoordFromBytes(n, "x", reverse);
    yInt = getCoordFromBytes(n, "y", reverse);
    
    x = (float) xInt / numBits;
    y = (float) yInt / numBits;
    println("x: " + x + ", y: " + y + " | " + "x*w: " + (x * 320) + ", y*h: " + (y * 240));
  }
  
  String getSingleByteVal(NapData n, String axis) {
    String returns = "";
    if (axis.equals("x")) {
      returns = "" + n.binary.charAt(3) + n.binary.charAt(4) + n.binary.charAt(5);
    } else if (axis.equals("y")) {
      returns = "" + n.binary.charAt(0) + n.binary.charAt(1) + n.binary.charAt(2);
    }
    return returns;
  }
  
  int getSign(char c) {
    if (c == '1') {
      return 1;
    } else {
      return -1;
    }
  }
   
  int getCoordFromBytes(ArrayList<NapData> n, String axis, boolean reverse) {
    String returns = "";
    if (reverse) {
      for (int i=n.size()-1; i>=0; i--) {
        returns += getSingleByteVal(n.get(i), axis);
      }
    } else {
      for (int i=0; i<n.size(); i++) {
        returns += getSingleByteVal(n.get(i), axis);
      }
    }
    
    int sign = getSign(returns.charAt(0));
    String newReturns = "";
    for (int i=1; i<returns.length(); i++) {
      newReturns += returns.charAt(i);
    }
    return unbinary(newReturns);
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