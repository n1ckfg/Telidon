String filePath = "nap/boom.nap";
byte[] bytes;
String[] strings;

void setup() {
  size(320, 240);
  bytes = loadBytes(filePath);
  
  // https://stackoverflow.com/questions/26930066/bytebuffer-switch-endianness
  // https://stackoverflow.com/questions/13553349/bytebuffer-little-endian-insert-not-working
  ByteBuffer buf = ByteBuffer.allocate(bytes.length);
  buf.asCharBuffer();
  for (int i=0; i<bytes.length; i++) {
    buf.put(i,bytes[i]);
  }
  buf.order(ByteOrder.LITTLE_ENDIAN);
  for (int i=0; i<buf.capacity()-1; i++) {
    print(buf.get(i) + ", ");
  }
}

void draw() {
  background(0);
  // TODO shape methods here
}

// 24, 27, 34, 70, 27, 69, 31, 64, 64, 14, 32, 127, 79, 33, 77, 64, 64, 73, 64, 35, 64, 64, 82, 64, 64, 62, 112, 64, 64, 64, 55, 66, 99, 105, 89, 71, 86, 70
// 24, 27, 34, 70, 27, 69, 31, 64, 64, 14, 32, 127, 79, 33, 77, 64, 64, 73, 64, 35, 64, 64, 82, 64, 64, 62, 116, 64, 64, 64, 36, 66, 93, 68, 110, 41, 71, 80