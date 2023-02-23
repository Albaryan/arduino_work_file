#include <Servo.h>
Servo motor1;
Servo motor2;
int HORZ;
int VERT;

void setup() {
  // put your setup code here, to run once:
  motor1.attach(3);
  motor2.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  HORZ=map(analogRead(A4),0,1023,0,180);
  VERT=map(analogRead(A5),0,1023,0,180);

  motor1.write(HORZ);
  motor2.write(VERT);
}
