String filePath = "nap/boom.nap";
NapDraw nap;
PFont font;
int fontSize = 36;

void setup() {
  size(640, 640, P2D);
  nap = new NapDraw(filePath);
  font = loadFont("Telidon-48.vlw");
  textFont(font, fontSize);
}

void draw() {
  background(0);
  nap.draw();
}