void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int PWM=map(analogRead(A0),0,1023,0,255);
  analogWrite(3,PWM);
}
