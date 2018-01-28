// Extract XY or XYZ coordinates from multiple NapData objects
class NapVector {
  
  float x, y;
  float numBits = 2048;
  boolean firstBitSign = true;
  
  NapVector(ArrayList<NapData> n) {
    numBits = pow(2, (n.size() * 3) - int(firstBitSign));
    x = getCoordFromBytes(n, "x");
    y = getCoordFromBytes(n, "y");
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
   
  float getCoordFromBytes(ArrayList<NapData> n, String axis) {
    String returns = "";
    for (int i=0; i<n.size(); i++) {
      returns += getSingleByteVal(n.get(i), axis);
    }
    
    int sign = 1;
    if (firstBitSign) {
      sign = getSign(returns.charAt(0));
      String newReturns = "";
      for (int i=1; i<returns.length(); i++) {
        newReturns += returns.charAt(i);
      }
      returns = newReturns;
    }
    
    float finalReturns = 0.0;
    if (axis.equals("x")) {
      finalReturns = (unbinary(returns) / numBits) * sign;
    } else if (axis.equals("y")) {
      finalReturns = ((numBits - unbinary(returns)) / numBits) * sign;
    }

    String debug="";
    for (int i=n.size()-1; i>=0; i--) {
      debug += n.get(i).binary + " ";
    }
    debug += "-> " + axis + ": " + returns + " " + finalReturns;
    println(debug);
    
    return finalReturns;
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