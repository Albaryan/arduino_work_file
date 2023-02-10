long unsigned int cTime=0;
int delayTime=500;
int button=12;
int LED=2;

void setup() {
  Serial.begin(9600);
  for (int i=2; i<10 ; i++) {
    pinMode(i,OUTPUT);
  }
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED,HIGH);
  if (!digitalRead(button)){
    digitalWrite(LED,LOW);
    LED++;
    if (LED==10){
      LED=2;
    }
    while (!digitalRead(button)){
      delay(50);
    }
  }
}
