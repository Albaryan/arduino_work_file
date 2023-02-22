#include <Servo.h>

Servo motor1;
Servo motor2;
int PWM1;
int PWM2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1.attach(3);
  motor2.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  PWM1=map(analogRead(A5),0,1023,0,180);
  PWM2=map(analogRead(A4),0,1023,0,180);

  motor1.write(PWM1);
  motor2.write(PWM2);
}

