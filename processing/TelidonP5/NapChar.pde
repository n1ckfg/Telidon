class NapChar {
  
  char c;
  String binary;
  String rbinary;
  int ascii;
  String hex;
  
  NapChar(char _c) {
    c = _c;
    ascii = getAscii();
    binary = getBinary();
    rbinary = getRBinary();
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
  
  String getRBinary() {
      return new StringBuffer(binary).reverse().toString();
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
      case("0E"):
        returns = "Shift-Out"; // graphics mode
        break;
      case("0F"):
        returns = "Shift-In"; // text mode
        break;
      case("18"):
        returns = "CANCEL";
        break;
      case("1B"):
        returns = "ESC";
        break;
      case("1F"):
        returns = "NSR"; // Non-Selective Reset
        break;
      case("20"):
        returns = "RESET";
        break;
      case("21"):
        returns = "DOMAIN";
        break;
      case("22"):
        returns = "TEXT";
        break;
      case("23"):
        returns = "TEXTURE";
        break;
      case("24"):
        returns = "POINT SET ABS";
        break;
      case("25"):
        returns = "POINT SET REL";
        break;
      case("3E"):
        returns = "SELECT COLOR";
        break;
      case("37"):
        returns = "SET & POLY FILLED";
        break;
      default:
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