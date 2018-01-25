String filePath = "nap/boom.nap";
Naplps nap;

void setup() {
  size(320, 240);
  nap = new Naplps(loadStrings(filePath));
}

void draw() {
  background(0);
}