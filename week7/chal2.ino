#include <TM1637.h>

TM1637 tm(2,3);

void setup() {
  // put your setup code here, to run once:
  tm.init();
  tm.set(BRIGHT_TYPICAL);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
}


unsigned int counter =0;

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(12)) {
    counter++;
    delay(50);
  } else if (!digitalRead(13)) {
    counter--;
    delay(50);
  }
  

  tm.display(3,counter%16);
  tm.display(2,(counter/16)%16);
  tm.display(1,(counter/256)%16);
  tm.display(0,(counter/4096)%16);

  if (counter== 65536) {
    counter =0;
  }
}

