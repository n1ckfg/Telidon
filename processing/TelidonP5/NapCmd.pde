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
  
  void getPoints() {
    for (int i=0; i<data.size(); i+=4) {
      NapVector napV = new NapVector(data.get(i), data.get(i+1), data.get(i+2), data.get(i+3));
      points.add(new PVector(napV.x, napV.y));
    }
  }
  
}