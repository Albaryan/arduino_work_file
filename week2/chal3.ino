int PIN_1=2;
int PIN_8=9;
int LED=2;
int T;
int cTime=0;
int pTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=PIN_1; i!=PIN_8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  T=map(analogRead(A0),0,1023,50,2000);

  
  digitalWrite(LED,HIGH);

  pTime=millis();

  if (pTime-cTime >= T) {
    digitalWrite(LED,LOW);
    LED++;
    if (LED>PIN_8) {
      LED=2;
    }
    
    cTime=millis(); 
  }

  Serial.println(cTime);

}
