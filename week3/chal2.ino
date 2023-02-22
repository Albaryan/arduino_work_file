int LED_1,LED_2;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  LED_1= map(analogRead(A5),0,1023,0,255);
  LED_2= map(analogRead(A4),0,1023,0,255);

  analogWrite(3,LED_1);
  analogWrite(5,LED_2);
}
