class NapCmd {
  
  String cmdRaw;
  int index;
  NapOpcode opcode;
  ArrayList<NapData> data;
  ArrayList<PVector> points;
  int pointBytes = 4; // TODO set programatically from header info

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
    
    switch(opcode.id) {
      case("SET & POLY FILLED"): 
        getPoints();
        break;
      default:
        break;
    }
  }
   
  void printCmd(String mode) {
    println(formatCmd(mode));
  }
  
  String formatCmd(String mode) {
    String returns = "(" + index + ") " + opcode.id;
    if (data.size() > 0) returns += ": ";
    if (opcode.id.equals("")) {
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
        default:
          break;
      }
    }
    if (data.size() > 0) {
      if (opcode.id.equals("")) returns += ", ";
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
          default:
            break;
        }
        if (i < data.size() - 1) returns += ", ";
      }
    }
    return returns;
  }
  
  void getPoints() {
    for (int i=0; i<data.size(); i+=pointBytes) {
      ArrayList<NapData> n = new ArrayList<NapData>();
      for (int j=0; j<pointBytes; j++) { 
        n.add(data.get(i + j));
      }
      NapVector napV = new NapVector(n);
      points.add(new PVector(napV.x, napV.y));
    }
  }
  
  void getDomain() {
    for (int i=0; i<data.size(); i++) {
      //
    }
  }
  
}