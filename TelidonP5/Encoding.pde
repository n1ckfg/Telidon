/*
http://ascii.cl/control-characters.htm
https://stackoverflow.com/questions/36519977/how-to-convert-string-into-a-7-bit-binary
http://www.dcode.fr/ascii-code
*/

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

String[] splitByNumber(String s, int n) {
    return s.split("(?<=\\G.{" + n + "})");
}