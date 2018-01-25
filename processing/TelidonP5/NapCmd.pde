class NapCmd {
  
  String cmdRaw;
  int index;
  NapOpcode opcode;
  ArrayList<NapData> data;
  ArrayList<PVector> points;

  NapCmd(String _cmd, int _index) {
    cmdRaw = _cmd;
    index = _index;
    data = new ArrayList<NapData>();
    points = new ArrayList<PVector>();
    
    opcode = new NapOpcode(cmdRaw.charAt(0));
    if (cmdRaw.length() > 1) {
      for (int i=1; i<cmdRaw.length(); i++) {
        data.add(new NapData(cmdRaw.charAt(i)));
      }
    }
  }
  
  void run() {
  }
  
  void printCmd(String mode) {
    println(formatCmd(mode));
  }
  
  String formatCmd(String mode) {
    String returns = "(" + index + "). ";
    switch(mode) {
      case("char"):
        returns += opcode.c;
        break;
      case("binary"):
        returns += opcode.binary;
        break;
      case("ascii"):
        returns += opcode.ascii;
        break;
      case("hex"):
        returns += opcode.hex;
        break;
    }
    if (data.size() > 0) {
      returns += ", ";
      for (int i=0; i<data.size(); i++) {
        switch(mode) {
          case("char"):
            returns += "" + data.get(i).c;
            break;
          case("binary"):
            returns += "" + data.get(i).binary;
            break;
          case("ascii"):
            returns += "" + data.get(i).ascii;
            break;
          case("hex"):
            returns += "" + data.get(i).hex;
            break;
        }
        if (i < data.size() - 1) returns += ", ";
      }
    }
    return returns;
  }
  
  void getPoints8() {
    for (int i=0; i<data.size()-2; i+=2) {
      //float x = 1.0 - data.get(i).f;
      //float y = 1.0 - data.get(i+1).f;
      //points.add(new PVector(x, y));
    }
  }
  
  void getPoints16() {
    for (int i=0; i<data.size(); i+=4) {
      NapCoord napCoord = new NapCoord(data.get(i).c, data.get(i+1).c, data.get(i+2).c, data.get(i+3).c);
      points.add(new PVector(napCoord.x, napCoord.y));
    }
  }
  
}