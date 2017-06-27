/*
http://www.fileformat.info/format/naplps/egff.htm
https://www.leadtools.com/help/leadtools/v19/main/api/napfmt.html
http://fileformats.archiveteam.org/wiki/NAPLPS
http://www.martinreddy.net/gfx/2d/NAP.txt
http://ascii.cl/control-characters.htm
https://stackoverflow.com/questions/36519977/how-to-convert-string-into-a-7-bit-binary
http://www.dcode.fr/ascii-code

"NAPLPS defines line, box, circle, arc, polyline, polygon, spline, bitmaps, and fonts, both in 
palette and 24-bit color...as a stream of 7-bit or 8-bit ASCII characters. The coordinate model 
is right-handed Cartesian, meaning that X and Y coordinates increase toward the upper-right of 
the screen. A NAPLPS code sequence begins with the characters ESC 25 41 [27 25 41] and ends with the 
sequence ESC 25 40 [27 25 40]. NAPLPS code sequences are designed with an eye toward avoiding standard 
terminal escape sequences such as those provided by VT100 and ANSI. NAPLPS files are basically 
segments of the NAPLPS data stream redirected to a file. Properly formatted, NAPLPS data files 
are not unlike uuencoded binary files."
*/

String readString;
byte readBytes[];
String[] strings;
int byteSize = 7;
String debugText = "";

void setup() {
  size(640, 480);
  readString = loadStrings("nap/BWAY3.NAP")[0];
  //strings = decodeNBits(encodeNBits(readString, byteSize), byteSize);
  strings = splitByNumber(readString, byteSize);
  println("bytes: " + strings.length);
  println(strings);
}

void draw() {
  background(0);
  
  // TODO shape methods here
}

byte[] encodeNBits(String str, int n) {
    byte[] bytes = new byte[str.length() * n];
    for (int i = 0; i < str.length(); i++) {
        char ch = str.charAt(i);
        assert ch < int(pow(2,n));
        for (int j = 0; j < n; j++) 
            bytes[i * n + j] = (byte) ((ch >> (n - j)) & 1);
    }
    return bytes;
}

String[] decodeNBits(byte[] b, int n) {
  ArrayList stringsL= new ArrayList();
  for (int i=0; i<b.length; i+=n) {
    String s = "";
    for (int j=0; j<n; j++) {
      s += b[i+j];
    }
    stringsL.add(getCharFromInt(s, n));
  }
  String[] strings = new String[stringsL.size()];
  for (int i=0; i<strings.length; i++) {
    strings[i] = (String) stringsL.get(i);
  }
  return strings;
}

String getCharFromInt(String s, int n) {
  String returns = "";   
  char nextChar;
  for (int i = 0; i <= s.length()-n; i += n+1) { //this is a little tricky.  we want [0, 7], [9, 16], etc (increment index by 9 if bytes are space-delimited)
       nextChar = (char) Integer.parseInt(s.substring(i, i+n), 2);
       returns += nextChar;
  }
  return returns;
}

String[] splitByNumber(String s, int n) {
    return s.split("(?<=\\G.{" + n + "})");
}