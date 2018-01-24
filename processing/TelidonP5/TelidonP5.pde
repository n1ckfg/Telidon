String filePath = "nap/image.003.nap";
byte[] bytes;
String[] strings;

void setup() {
  size(320, 240);
  bytes = loadBytes(filePath);
  strings = loadStrings(filePath);
  
  String[] foo = { testImg2 };
  printBytesFromStringArray(foo);
}

void draw() {
  background(0);
  // TODO shape methods here
}