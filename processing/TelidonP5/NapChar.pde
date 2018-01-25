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
  
  NapChar x1, x2, y1, y2;
  int xInt, yInt;
  float x, y;
  
  NapVector(char _x1, char _x2, char _y1, char _y2) {
    x1 = new NapChar(_x1);
    x2 = new NapChar(_x2);
    y1 = new NapChar(_y1);
    y2 = new NapChar(_y2);
      
    xInt = getDoubleX(x2, x1);
    yInt = getDoubleY(y2, y1);
    
    x = (float) xInt / 63.0;
    y = (float) yInt / 63.0;
  }
  
  String getSingleX(NapChar n) {
    //return "" + n.binary.charAt(4) + n.binary.charAt(5) + n.binary.charAt(6);
    return "" + n.binary.charAt(6) + n.binary.charAt(5) + n.binary.charAt(4);
  }
  
  String getSingleY(NapChar n) {
    //return "" + n.binary.charAt(1) + n.binary.charAt(2) + n.binary.charAt(3);
    return "" + n.binary.charAt(3) + n.binary.charAt(2) + n.binary.charAt(1);
  }
  
  int getDoubleX(NapChar n1, NapChar n2) {
    return unbinary(getSingleX(n1) + getSingleX(n2));
  }
  
  int getDoubleY(NapChar n1, NapChar n2) {
    return unbinary(getSingleY(n1) + getSingleY(n2));
  }
  
}