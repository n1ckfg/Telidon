// Extract XY or XYZ coordinates from multiple NapData objects
class NapVector {
  
  float x, y;
  float bitVals = 512;
  int bitsPerByte = 3;
  boolean firstBitSign = true;
  
  NapVector(ArrayList<NapData> n) {
    bitVals = pow(2, (n.size() * bitsPerByte) - int(firstBitSign));
    x = getCoordFromBytes(n, "x");
    y = getCoordFromBytes(n, "y");
  }
  
  String binaryConv(NapData n, int loc) {
    String returns = "";
    for (int i=loc; i<loc+bitsPerByte; i++) {
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
      returns = ""+newReturns;
    }
    
    float finalReturns = 0.0;
    if (axis.equals("x")) {
      finalReturns = (unbinary(returns) / bitVals) * sign;
    } else if (axis.equals("y")) {
      finalReturns = ((bitVals - unbinary(returns)) / bitVals) * sign;
    }

    String debug="";
    for (int i=0; i<n.size(); i++) {
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