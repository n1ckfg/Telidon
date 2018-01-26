class NapChar {
  
  char c;
  String binary;
  int ascii;
  String hex;
  
  NapChar(char _c) {
    c = _c;
    ascii = getAscii();
    binary = getBinary();
    hex = getHex();
  }
  
  int getAscii() {
    return int(c);
  }
  
  String getBinary() {
    String returns = "";
    String b = binary(c);
    for (int i=b.length()-7; i<b.length(); i++) {
      returns += b.charAt(i);
    }
    return returns;
  }
  
  String getHex() {
    String returns = "";
    String h = hex(c);
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
    id = getId();
  }
  
  String getId() {
    String returns = "";
    switch(hex) {
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
    f = getNormFloat();
  }
  
  float getNormFloat() {
    float returns = (float) ascii / 127.0;
    return returns;
  }
  
}