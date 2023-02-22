int DT, CLK_now;
int CLK_old=HIGH;
int PWM=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  CLK_now=digitalRead(3);
  DT=digitalRead(2);
  analogWrite(5,PWM);

  if (CLK_now != CLK_old) {
    CLK_old=CLK_now;

    if (CLK_now==LOW && DT==HIGH) {
      if (PWM!=255) {
        PWM++;
      }
    }else if (CLK_now==LOW && DT==LOW) {
      if (PWM!=0) {
        PWM--;
      }
    }
  }

  Serial.println(PWM);
}
