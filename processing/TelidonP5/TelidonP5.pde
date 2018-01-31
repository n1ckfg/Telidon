String filePath = "nap/boom.nap";
NapDraw nap;

void setup() {
  size(640, 640, P2D);
  nap = new NapDraw(filePath);
}

void draw() {
  background(0);
  nap.draw();
}