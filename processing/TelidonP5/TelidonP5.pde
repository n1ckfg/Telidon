/*
http://www.fileformat.info/format/naplps/egff.htm
https://www.leadtools.com/help/leadtools/v19/main/api/napfmt.html
http://fileformats.archiveteam.org/wiki/NAPLPS
http://www.martinreddy.net/gfx/2d/NAP.txt


"NAPLPS defines line, box, circle, arc, polyline, polygon, spline, bitmaps, and fonts, both in 
palette and 24-bit color...as a stream of 7-bit or 8-bit ASCII characters. The coordinate model 
is right-handed Cartesian, meaning that X and Y coordinates increase toward the upper-right of 
the screen. A NAPLPS code sequence begins with the characters ESC 25 41 [27 25 41] and ends with the 
sequence ESC 25 40 [27 25 40]. NAPLPS code sequences are designed with an eye toward avoiding standard 
terminal escape sequences such as those provided by VT100 and ANSI. NAPLPS files are basically 
segments of the NAPLPS data stream redirected to a file. Properly formatted, NAPLPS data files 
are not unlike uuencoded binary files."
*/

String filePath = "nap/image.003.nap";
byte bytes[];
String[] stringsRaw;
String[] stringsNumeric;
String[] stringsAscii;
int byteSize = 7;

void setup() {
  size(640, 480);
  bytes = loadBytes(filePath);
  stringsRaw = loadStrings(filePath);
  
  stringsNumeric = splitByChar(decodeNBits(readNBits(new String(bytes), byteSize), byteSize), "?!#");
  stringsAscii = splitByNum(new String(bytes), byteSize);
  //println(stringsNumeric);
  //println(stringsAscii);
  
  printBytesFromStringArray(stringsAscii);
  
}

void draw() {
  background(0);
  // TODO shape methods here
}

void printBytesFromStringArray(String[] input) {
  for (int i=0; i<input.length; i++) {
    int len = input[i].length();
    for (int j=0; j<len; j++) {
      print(byte(input[i].charAt(j)));
      if (j < len-1) {
        print(", ");
      } else {
        print("\n");
      }
    }
  }
}