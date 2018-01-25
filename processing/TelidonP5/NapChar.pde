class NapChar {
  
  char c;
  String binary;
  int ascii;
  String hex;
  
  NapChar(char _c) {
    c = _c;
    binary = getBinary(c);
    ascii = int(c);
    hex = getHex(_c);
  }
  
  String getBinary(char _c) {
    String returns = "";
    String b = binary(_c);
    for (int i=b.length()-7; i<b.length(); i++) {
      returns += b.charAt(i);
    }
    return returns;
  }
  
  String getHex(char _c) {
    String returns = "";
    String h = hex(_c);
    for (int i=h.length()-2; i<h.length(); i++) {
      returns += h.charAt(i);
    }    
    return returns;
  }
  
}

class NapOpcode extends NapChar {
  
  String id = "";
  
  NapOpcode(char _c) {
    super(_c);
    id = getId(hex);
  }
  
  String getId(String s) {
    String returns = "";
    switch(s) {
      case("3E"):
         returns = "SELECT COLOR";
        break;
      case("37"):
        returns = "SET & POLY FILLED";
        break;
    }
    return returns;
  }
  
}

class NapData extends NapChar {
  
  float f;
  
  NapData(char _c) {
    super(_c);
    f = getNormFloat(ascii);
  }
  
  float getNormFloat(int _i) {
    float returns = (float)_i / 127.0;
    return returns;
  }
  
}

class NapVector {
  
  int xInt, yInt;
  float x, y;
  
  NapVector(NapData n1, NapData n2, NapData n3, NapData n4) {
    xInt = getX(n4, n3, n2, n1);
    yInt = getY(n4, n3, n2, n1);
    
    x = (float) xInt / 4096.0;
    y = (float) yInt / 4096.0;
  }
  
  String getSingleX(NapData n) {
    return "" + n.binary.charAt(4) + n.binary.charAt(5) + n.binary.charAt(6);
  }
  
  String getSingleY(NapData n) {
    return "" + n.binary.charAt(1) + n.binary.charAt(2) + n.binary.charAt(3);
  }
  
  int getX(NapData n1, NapData n2, NapData n3, NapData n4) {
    String b = getSingleX(n1) + getSingleX(n2) + getSingleX(n3) + getSingleX(n4);
    return unbinary(b);
  }
  
  int getY(NapData n1, NapData n2, NapData n3, NapData n4) {
    String b = getSingleY(n1) + getSingleY(n2) + getSingleY(n3) + getSingleY(n4);
    println(b);
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