class Naplps {
  
  String napRaw;
  ArrayList<NapCmd> cmds;
  int counter = 0;
  
  Naplps(String[] input) {
    napRaw = "";
    cmds = new ArrayList<NapCmd>();

    for (int i=0; i<input.length; i++) {
      napRaw += input[i];
    }
    
    String tempCmd = "";
    for (int i=0; i<napRaw.length(); i++) {
      char c = napRaw.charAt(i);
      if (isOpcode(c)) {
        if (tempCmd.equals("")) {
          tempCmd += c;
        } else {
          if (tempCmd.length() >= 1) {
            cmds.add(new NapCmd(tempCmd, counter));
            counter++;
          }
          tempCmd = "";
          tempCmd += c;
        }
      } else {
        tempCmd += c;
      }
    }
    
    for (int i=0; i<cmds.size(); i++) {
      println(cmds.get(i).printCmd("hex"));
    }
  }
  
  void run() {
    for (int i=0; i<cmds.size(); i++) {
      cmds.get(i).run();
    }
  }
  
  boolean isOpcode(char c) {
    String b = binary(c);
    return b.charAt(b.length()-7) == '0';
  }
  
}

class NapCmd {
  
  String cmdRaw;
  int index;
  NapOpcode opcode;
  ArrayList<NapData> data;
  
  NapCmd(String _cmd, int _index) {
    cmdRaw = _cmd;
    index = _index;
    data = new ArrayList<NapData>();
    
    opcode = new NapOpcode(cmdRaw.charAt(0));
    if (cmdRaw.length() > 1) {
      for (int i=1; i<cmdRaw.length(); i++) {
        data.add(new NapData(cmdRaw.charAt(i)));
      }
    }
  }
  
  void run() {
  }
  
  String printCmd(String mode) {
    String returns = "(" + (index+1) + "). ";
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
  
}

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
  NapOpcode(char _c) {
    super(_c);
  }
}

class NapData extends NapChar {
  NapData(char _c) {
    super(_c);
  }
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 

/*
http://www.fileformat.info/format/naplps/egff.htm
https://www.leadtools.com/help/leadtools/v19/main/api/napfmt.html
http://fileformats.archiveteam.org/wiki/NAPLPS
http://www.martinreddy.net/gfx/2d/NAP.txt

// COORDINATES
(0,0) is lower left.
(1,1) is upper right.
Assumes a 4:3 aspect ratio and everything above 0.75 Y is clipped.

// CONTROL CODES
"NAPLPS defines line, box, circle, arc, polyline, polygon, spline, bitmaps, and fonts, both in 
palette and 24-bit color...as a stream of 7-bit or 8-bit ASCII characters. The coordinate model 
is right-handed Cartesian, meaning that X and Y coordinates increase toward the upper-right of 
the screen. A NAPLPS code sequence begins with the characters ESC 25 41 [27 25 41] and ends with the 
sequence ESC 25 40 [27 25 40]. NAPLPS code sequences are designed with an eye toward avoiding standard 
terminal escape sequences such as those provided by VT100 and ANSI. NAPLPS files are basically 
segments of the NAPLPS data stream redirected to a file. Properly formatted, NAPLPS data files 
are not unlike uuencoded binary files."

// John Durno:
It may seem odd now, but back in the 70s encoding vector graphics using the 128
characters of 7 bit ASCII was a very clever thing to do. ASCII was easy to
communicate over serial connections, transmitting binary was a lot harder … and
in fact binary files were often encoded as ASCII for transmission and then
decoded back to binary at the other end. Using a native ASCII encoding obviated
the need for that step, saving processing power, storage and bandwidth.

So my understanding is that every byte in a NAPLPS data stream has an ASCII
representation. And of course it’s a fairly easy step to translate ASCII back to
binary if you need to.

For example,  according to the spec* the 7th bit of (every?) NAPLPS byte is a
flag field indicating whether the byte is a command (an opcode) or data
associated with the previously received opcode. The flag is 0 for opcode byte, 1
for data byte. So if you receive an ‘@’ in the NAPLPS stream, your parser can
tell pretty quickly whether it’s an opcode or not, because it would know the
binary representation of ‘@’ in 7-bit ASCII is 1000000. The 7th bit is 1, so it
has to be data.

Another example, let’s say you receive a space character followed by an ‘x’. The
binary representations of those two characters are:

0100000

1111000

The first character is the ‘reset’ opcode, the second is the data byte that
specifies the nature of the reset (in this case, screen and border to black
[plus some other stuff that we won’t go into here]).


// Spec
This is the heart of NAPLPS, the graphical drawing
primitives. There are eight environment codes (RESET,
DOMAIN, TEXT, TEXTURE, SET COLOR, WAIT, SELECT COLOR and
BLINK) which set the graphics environment and 6 different
object types (POINT, LINE, ARC, RECTANGLE, POLYGON,
INCREMENTALS). 

*/