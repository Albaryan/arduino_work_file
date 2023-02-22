int DT, CLK_now;
int CLK_old=HIGH;
int LED=2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  for (int i=2;i!=10; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  CLK_now=digitalRead(12);
  DT=digitalRead(13);
  digitalWrite(LED,HIGH);

  if (CLK_now != CLK_old) {
    CLK_old=CLK_now;

    if (CLK_now==LOW && DT==HIGH) {
      digitalWrite(LED,LOW);
      if (LED!=2) {
        LED--;
      } else{
        LED=9;
      }
      
    }else if (CLK_now==LOW && DT==LOW) {
      digitalWrite(LED,LOW);
      if (LED!=9) {
        LED++;
      } else{
        LED=2;
      }
    }
  }
}
