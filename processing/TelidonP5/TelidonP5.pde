String filePath = "nap/boom.nap";
NapDraw nap;

void setup() {
  size(50, 50, P2D);
  nap = new NapDraw(filePath);
  surface.setSize(nap.texWidth * 2, nap.texHeight * 2);
  noSmooth();
}

void draw() {
  nap.draw();
}