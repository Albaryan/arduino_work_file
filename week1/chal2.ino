long unsigned int cTime=0;
int delayTime=500;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT_PULLUP);
}

void loop() {
  if (millis()-cTime >= delayTime){
    digitalWrite(8,!digitalRead(8));
    cTime=millis();
  }
  if (!digitalRead(9)){
    delayTime+=250;
    if (delayTime>2000) {
      delayTime=500;
    }
    while (!digitalRead(9));
  }
  Serial.println(delayTime);
}
