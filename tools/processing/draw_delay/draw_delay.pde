//   Written by John Durno, January 2018

int x1 = 20;
int x2 = 180;
int y1 = 20;
int y2 = 180;

int lastTime = millis();
int timeDelay = 1;
int i = x1;

void setup() {
  size(200,200);
  background(0);
}

void draw() {
  if ((millis() > lastTime + timeDelay) && (i <= x2)) {
     stroke(100,200,0);
     line(i,y1,i,y2);
     lastTime = millis();
     i = i+1;
   }  
}