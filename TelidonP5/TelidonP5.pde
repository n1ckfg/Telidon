/*
http://www.fileformat.info/format/naplps/egff.htm
https://www.leadtools.com/help/leadtools/v19/main/api/napfmt.html
http://fileformats.archiveteam.org/wiki/NAPLPS
http://www.martinreddy.net/gfx/2d/NAP.txt
http://ascii.cl/control-characters.htm

"NAPLPS defines line, box, circle, arc, polyline, polygon, spline, bitmaps, and fonts, both in 
palette and 24-bit color...as a stream of 7-bit or 8-bit ASCII characters. The coordinate model 
is right-handed Cartesian, meaning that X and Y coordinates increase toward the upper-right of 
the screen. A NAPLPS code sequence begins with the characters ESC 25 41 [27 25 41] and ends with the 
sequence ESC 25 40 [27 25 40]. NAPLPS code sequences are designed with an eye toward avoiding standard 
terminal escape sequences such as those provided by VT100 and ANSI. NAPLPS files are basically 
segments of the NAPLPS data stream redirected to a file. Properly formatted, NAPLPS data files 
are not unlike uuencoded binary files."

NOTES

*/

byte b[];
String[] lines;

PImage img;
int imgWidth = 28;
int imgHeight = 16;
int imgScale = 20;

String text = "";

void setup() {
  size(50, 50);
  surface.setSize(imgWidth * imgScale, imgHeight * imgScale);
  b = loadBytes("boom.nap");
  println("bytes: " + b.length);
  img = createImage(imgWidth*100, imgHeight, RGB);
  img.loadPixels();
  
  for (int i=0; i<b.length; i++) {
    img.pixels[i] = b[i];
    if (i==0) {
      text += b[i];
    } else {
      text += " " + b[i];
    }
  }
  
  img.updatePixels();
  println(text);
}

void draw() {
  image(img, 0, 0, width, height);
}