import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import javax.imageio.ImageIO;
import java.util.Base64;

// ~ ~ ~ ASCII ~ ~ ~
// http://ascii.cl/control-characters.htm
// https://stackoverflow.com/questions/36519977/how-to-convert-string-into-a-7-bit-binary
// http://www.dcode.fr/ascii-code
// https://forum.processing.org/one/topic/need-help-in-converting-data-types.html

byte[] readNBits(String str, int n) {
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
  // We want [0, 7], [9, 16], etc (increment index by 9 if bytes are space-delimited).
  for (int i = 0; i <= s.length()-n; i += n+1) {
       nextChar = (char) Integer.parseInt(s.substring(i, i+n), 2);
       returns += nextChar;
  }
  return returns;
}

String[] splitByNum(String s, int n) {
    return s.split("(?<=\\G.{" + n + "})");
}

String[] splitByChar(String[] s, String delim) {
    return splitTokens(join(s, ""), delim);
}

// ~ ~ ~ BASE64 ~ ~ ~
// https://forum.processing.org/two/discussion/6958/pimage-base64-encode-and-decode
// https://www.mkyong.com/java/how-to-convert-byte-to-bufferedimage-in-java/
// https://stackoverflow.com/questions/2305966/why-do-i-get-the-unhandled-exception-type-ioexception

PImage decodePImageFromBase64(String i_Image64) {
  PImage returns = null;
  try {
    byte[] decodedBytes = Base64.getDecoder().decode(i_Image64);
    ByteArrayInputStream in = new ByteArrayInputStream(decodedBytes);
    BufferedImage bImageFromConvert = ImageIO.read(in);
    BufferedImage convertedImg = new BufferedImage(bImageFromConvert.getWidth(), bImageFromConvert.getHeight(), BufferedImage.TYPE_INT_ARGB);
    convertedImg.getGraphics().drawImage(bImageFromConvert, 0, 0, null);
    returns = new PImage(convertedImg); 
  } catch (IOException ie) { }
  return returns;
}

String decodeStringFromBase64(String input) {
  String returns = null;
  byte[] decodedBytes = Base64.getDecoder().decode(input);
  ByteArrayInputStream in = new ByteArrayInputStream(decodedBytes);
  returns = in.toString();
  return returns;
}

// https://stackoverflow.com/questions/4513498/java-bytes-to-floats-ints
int asInt(byte[] bytes) {
  return (bytes[0] & 0xFF) 
         | ((bytes[1] & 0xFF) << 8) 
         | ((bytes[2] & 0xFF) << 16) 
         | ((bytes[3] & 0xFF) << 24);
}

float asFloat(byte[] bytes) {
  return Float.intBitsToFloat(asInt(bytes));
}

// https://forum.processing.org/two/discussion/23446/saving-multi-dimensional-arrays
// https://forum.processing.org/one/topic/writing-and-reading-a-mixture-of-ints-and-float-to-from-a-file.html
void serializeFloats(float[] _floats, String _fileName) {
  try {
    java.io.FileOutputStream fileOut = new java.io.FileOutputStream(sketchPath("") + "/" + _fileName);
    java.io.ObjectOutputStream out = new java.io.ObjectOutputStream(fileOut);
    out.writeObject(_floats);
    out.close();
    fileOut.close();
  } catch(IOException i) {
    i.printStackTrace();
  }
}

// http://forum.arduino.cc/index.php?topic=180456.0
void floatsToBytes(float[] floats, String _fileName) {
  byte[] bytes = new byte[floats.length * 4];
  
  for(int i=0; i<floats.length; i++) {
    int fi = Float.floatToIntBits(floats[i]);
    bytes[(i*4)] = byte(fi & 0xFF);
    bytes[(i*4)+1] = byte((fi >> 8) & 0xFF);
    bytes[(i*4)+2] = byte((fi >> 16) & 0xFF);
    bytes[(i*4)+3] = byte((fi >> 24) & 0xFF);
  }
  
  saveBytes(_fileName, bytes);
}