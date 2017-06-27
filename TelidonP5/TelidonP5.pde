/*
http://www.fileformat.info/format/naplps/egff.htm
https://www.leadtools.com/help/leadtools/v19/main/api/napfmt.html
http://fileformats.archiveteam.org/wiki/NAPLPS
http://www.martinreddy.net/gfx/2d/NAP.txt
http://ascii.cl/control-characters.htm
https://stackoverflow.com/questions/36519977/how-to-convert-string-into-a-7-bit-binary

"NAPLPS defines line, box, circle, arc, polyline, polygon, spline, bitmaps, and fonts, both in 
palette and 24-bit color...as a stream of 7-bit or 8-bit ASCII characters. The coordinate model 
is right-handed Cartesian, meaning that X and Y coordinates increase toward the upper-right of 
the screen. A NAPLPS code sequence begins with the characters ESC 25 41 [27 25 41] and ends with the 
sequence ESC 25 40 [27 25 40]. NAPLPS code sequences are designed with an eye toward avoiding standard 
terminal escape sequences such as those provided by VT100 and ANSI. NAPLPS files are basically 
segments of the NAPLPS data stream redirected to a file. Properly formatted, NAPLPS data files 
are not unlike uuencoded binary files."
*/

String[] lines;
String[] strings;
int[] ints;

PImage img;
int byteSize = 7;
int imgWidth = 28;
int imgHeight = 16;
int imgScale = 20;

String text = "";

void setup() {
  size(50, 50);
  surface.setSize(imgWidth * imgScale, imgHeight * imgScale);
  lines = loadStrings("nap/image.001.nap");
  ints = decoderInt(encodeToNBits(lines[0], byteSize), byteSize);
  strings = decoderStr(encodeToNBits(lines[0], byteSize), byteSize);
  println("bytes: " + ints.length);
  println(strings);
  img = createImage(imgWidth*100, imgHeight, RGB);
  img.loadPixels();
  
  for (int i=0; i<ints.length; i++) {
    img.pixels[i] = color(ints[i] * 255);
    if (i==0) {
      text += ints[i];
    } else {
      text += " " + ints[i];
    }
  }
  
  img.updatePixels();
  println(text);
}

void draw() {
  background(0);
  image(img, 0, 0, width, height);
}

byte[] encodeToNBits(String str, int n) {
    byte[] bytes = new byte[str.length() * n];
    for (int i = 0; i < str.length(); i++) {
        char ch = str.charAt(i);
        assert ch < int(pow(2,n));
        for (int j = 0; j < n; j++) 
            bytes[i * n + j] = (byte) ((ch >> (n - j)) & 1);
    }
    return bytes;
}

byte[] encodeTo7Bits(String str) {
    byte[] bytes = new byte[str.length() * 7];
    for (int i = 0; i < str.length(); i++) {
        char ch = str.charAt(i);
        assert ch < 128;
        for (int j = 0; j < 7; j++) 
            bytes[i * 7 + j] = (byte) ((ch >> (7 - j)) & 1);
    }
    return bytes;
}

int[] decoderInt(byte[] b, int n) {
  ArrayList intsL= new ArrayList();
  for (int i=0; i<b.length; i+=n) {
    String s = "";
    for (int j=0; j<byteSize; j++) {
      s += b[i+j];
    }
    intsL.add(int(s));
  }
  int[] ints = new int[intsL.size()];
  for (int i=0; i<ints.length; i++) {
    ints[i] = (int) intsL.get(i);
  }
  return ints;
}

String[] decoderStr(byte[] b, int n) {
  ArrayList stringsL= new ArrayList();
  for (int i=0; i<b.length; i+=n) {
    String s = "";
    for (int j=0; j<byteSize; j++) {
      s += b[i+j];
    }
    stringsL.add(hex(byte(int(s))));
  }
  String[] strings = new String[stringsL.size()];
  for (int i=0; i<ints.length; i++) {
    strings[i] = (String) stringsL.get(i);
  }
  return strings;
}