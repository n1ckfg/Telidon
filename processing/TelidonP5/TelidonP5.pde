String filePath = "nap/boom.nap";
NapDraw nap;

void setup() {
  size(640, 640, P2D);
  nap = new NapDraw(filePath);
  noSmooth();
}

void draw() {
  nap.draw();
}