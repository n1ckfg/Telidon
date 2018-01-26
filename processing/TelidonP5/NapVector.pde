class NapVector {
  
  int xInt, yInt;
  float x, y;
  float numBits = 512;
  
  NapVector(ArrayList<NapData> n) {
    xInt = getCoordFromBytes(n, "x");
    yInt = getCoordFromBytes(n, "y");
    
    x = (float) xInt / numBits;
    y = (float) yInt / numBits;
  }
  
  String getSingleByteVal(NapData n, String axis, boolean isHead) {
    if (isHead) {
      if (axis.equals("x")) {
        return "" + n.binary.charAt(4) + n.binary.charAt(5);
      } else if (axis.equals("y")) {
        return "" + n.binary.charAt(2) + n.binary.charAt(3);
      } else {
        return "" + 0;
      }
    } else {
      if (axis.equals("x")) {
        return "" + n.binary.charAt(4) + n.binary.charAt(5) + n.binary.charAt(6);
      } else if (axis.equals("y")) {
        return "" + n.binary.charAt(1) + n.binary.charAt(2) + n.binary.charAt(3);
      } else {
        return "" + 0;
      }
    }
  }
   
  int getCoordFromBytes(ArrayList<NapData> n, String axis) {
    String returns = "";
    for (int i=n.size()-1; i>0; i--) {
      returns += getSingleByteVal(n.get(i), axis, i==0);
    }
    return unbinary(returns);
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