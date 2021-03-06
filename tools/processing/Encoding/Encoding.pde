import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import javax.imageio.ImageIO;
import java.util.Base64;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

// http://ascii.cl/control-characters.htm
// https://stackoverflow.com/questions/36519977/how-to-convert-string-into-a-7-bit-binary
// http://www.dcode.fr/ascii-code
// https://forum.processing.org/one/topic/need-help-in-converting-data-types.html

String[] stringsNumeric (byte[] bytes, int byteSize) {
  return splitByChar(decodeNBits(readNBits(new String(bytes), byteSize), byteSize), "?!#");
}

String[] stringsAscii (byte[] bytes, int byteSize) {
  return splitByNum(new String(bytes), byteSize);
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
int asInt32(byte[] bytes) {
  return (bytes[0] & 0xFF) | ((bytes[1] & 0xFF) << 8) | ((bytes[2] & 0xFF) << 16) | ((bytes[3] & 0xFF) << 24);
}

float asFloat32(byte[] bytes) {
  return Float.intBitsToFloat(asInt32(bytes));
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

// https://codescracker.com/java/program/java-program-convert-decimal-to-octal.htm
// https://stackoverflow.com/questions/13147109/decimal-to-octal-conversion
// http://www.neurophys.wisc.edu/comp/docs/ascii/
int octalToDecimal(int octal) {    
    int decimal = 0;    
    int n = 0;    
    while (true) {    
      if (octal == 0) {    
        break;    
      } else {    
          int temp = octal%10;    
          decimal += temp*Math.pow(8, n);    
          octal = octal/10;    
          n++;    
       }    
    }    
    return decimal;    
}   

int decimalToOctal(int decimal){
   int counter = 0;
   int octal = 0;
   while(decimal !=0) {
        int temp = (int) ((decimal%8) * Math.pow(10, counter));
        counter++;
        octal += temp;
        decimal /= 8;
    }
    return octal;
}

void printBytesFromStringArray(String[] input) {
  for (int i=0; i<input.length; i++) {
    int len = input[i].length();
    for (int j=0; j<len; j++) {
      byte b = (byte) input[i].charAt(j);
      
      print(b);
      if (j < len-1) {
        print(", ");
      } else {
        print("\n");
      }
    }
  }
}

void printBytesFromByteArray(byte[] input, int byteSize) {
  for (int i=0; i<input.length; i++) {
    byte b;
    if (byteSize == 7) {
      b = (byte) (input[i] & 0x7F);
    } else {
      b = (byte) (input[i] & 0xFF);
    }

    print(b);
    if (i < input.length-1) {
      print(", ");
    } else {
      print("\n");
    }
  }
}

void printIntsFromByteArray(byte[] input) {
  for (int i=0; i<input.length; i++) {
    int b = (int) input[i];
    print(b);
    if (i < input.length-1) {
      print(", ");
    } else {
      print("\n");
    }
  }
}

// https://stackoverflow.com/questions/26930066/bytebuffer-switch-endianness
// https://stackoverflow.com/questions/13553349/bytebuffer-little-endian-insert-not-workingv
void printBytesFromBuffer(byte[] input) {
  ByteBuffer buf = ByteBuffer.allocate(input.length);
  buf.asCharBuffer();
  for (int i=0; i<input.length; i++) {
    buf.put(i,input[i]);
  }
  buf.order(ByteOrder.LITTLE_ENDIAN);
  for (int i=0; i<buf.capacity()-1; i++) {
    print(buf.get(i) + ", ");
  }
}