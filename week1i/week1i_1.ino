#include <TimerOne.h>

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(20000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Timer1.pwm(9,map(analogRead(A5),0,1023,25,125));
}

