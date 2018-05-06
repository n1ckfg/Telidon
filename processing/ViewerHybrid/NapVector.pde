// 2. Multi-byte data classes
//
// 2.1. Some NapData objects need to be combined for decoding. 
// XY and XYZ position are handled by the NapVector class.
class NapVector {
  
  float x, y;
  float bitVals = 512;
  int bitsPerByte = 3; // TODO set programatically from header info based on XY / XYZ
  boolean firstBitSign = true; // Should be true for all header options
  
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
  
  float getSign(char c) {
    if (c == '1') {
      return -1.0;
    } else {
      return 1.0;
    }
  }
   
  float getCoordFromBytes(ArrayList<NapData> n, String axis) {
    String returns = "";
    for (int i=0; i<n.size(); i++) {
      returns += getSingleByteVal(n.get(i), axis);
    }
    
    float sign = 1;
    if (firstBitSign) {
      sign = getSign(returns.charAt(0));
      returns = removeCharAt(returns, 0);
    }
    
    float finalReturns = 0;
    
    if (axis.equals("x")) {
      finalReturns = (unbinary(returns) / bitVals) * sign;
    } else if (axis.equals("y")) {
      finalReturns = ((bitVals - unbinary(returns)) / bitVals) * sign;
    }

    return finalReturns;
  }
  
}

String removeCharAt(String s, int index) {
  String returns = "";
  for (int i=0; i<s.length(); i++) {
    if (i != index) returns += s.charAt(i);
  }
  return returns;
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