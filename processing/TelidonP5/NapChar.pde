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
  
  //float f;
  
  NapData(char _c) {
    super(_c);
    //f = getCoord(ascii);
  }
  
  /*
  float getCoord(int _i) {
    float returns = (float)_i / 127.0;
    return returns;
  }
  */
  
}

class NapCoord {
  
  byte[] xb = new byte[2];
  byte[] yb = new byte[2];
  int xRaw, yRaw;
  float x, y;
  
  NapCoord(char _x1, char _x2, char _y1, char _y2) {
    xb[0] = byte(_x1);
    xb[1] = byte(_x2);
    yb[0] = byte(_y1);
    yb[1] = byte(_y2);
    xRaw = asInt16(xb); 
    yRaw = asInt16(yb); 
    x = 1.0 - ((float) xRaw / 65536.0);
    y = ((float) yRaw / 65536.0) * 0.75;
    println(x, y);
  }
  
  int asInt32(byte[] bytes) {
    return (bytes[0] & 0xFF) | ((bytes[1] & 0xFF) << 8) | ((bytes[2] & 0xFF) << 16) | ((bytes[3] & 0xFF) << 24);
  }
 
  int asInt24(byte[] bytes) {
    return (bytes[0] & 0xFF) | ((bytes[1] & 0xFF) << 8) | ((bytes[2] & 0xFF) << 16);
  }
  
  int asInt16(byte[] bytes) {
    return (bytes[0] & 0xFF) | ((bytes[1] & 0xFF) << 8);
  }
  
  int asInt8(byte b) {
    return (int) b & 0xFF;
  }
  
}