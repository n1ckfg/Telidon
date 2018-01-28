// Extract XY or XYZ coordinates from multiple NapData objects
class NapVector {
  
  int xInt, yInt;
  float x, y;
  float numBits = 2048;
  boolean firstBitSign = true;
  
  NapVector(ArrayList<NapData> n) {
    numBits = pow(2, (n.size() * 3) - int(firstBitSign));
    xInt = getCoordFromBytes(n, "x");
    yInt = getCoordFromBytes(n, "y");
    
    x = (float) xInt / numBits;
    y = 1.0 - ((float) yInt / numBits);
  }
  
  String binaryConv(NapData n, int loc) {
    String returns = "";
    for (int i=loc; i<loc+3; i++) {
      returns += n.binary.charAt(i);
    }
    return returns;
  }
  
  String getSingleByteVal(NapData n, String axis) {
    String returns = "";
    if (axis.equals("x")) {
        returns = "" + binaryConv(n, 1);
    } else if (axis.equals("y")) {
        returns = "" + binaryConv(n, 4);
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
   
  int getCoordFromBytes(ArrayList<NapData> n, String axis) {
    String returns = "";
    for (int i=n.size()-1; i>=0; i--) {
      returns += getSingleByteVal(n.get(i), axis);
    }
    
    String newReturns = "";
    for (int i=0; i<returns.length()-1; i++) {
      newReturns += returns.charAt(i);
    }
    
    if (firstBitSign) returns = newReturns;
    
    String debug="";
    for (int i=n.size()-1; i>=0; i--) {
      debug += n.get(i).binary + " ";
    }
    debug += " -> " + axis + ": " + returns + " " + unbinary(returns);
    println(debug);
    
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