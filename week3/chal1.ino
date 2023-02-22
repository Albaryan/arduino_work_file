#include <Servo.h>
int degree;
Servo motor;

void setup() {
  // put your setup code here, to run once:
  motor.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  degree=map(analogRead(A5),0,1023,0,180);
  motor.write(degree);
}
