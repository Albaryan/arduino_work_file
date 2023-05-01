int i,j;
int col,row;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  for(i=6;i<10;i++){
    pinMode(i, INPUT_PULLUP);
  }

  for (i=2;i<6;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);

    for(j=6;j<10;j++) {
      if (!digitalRead(j)) {
        Serial.println(j);
        row=j;
      }
    }

    digitalWrite(i,HIGH);
  }

  if (row) {
    pinMode(row, OUTPUT);
    digitalWrite(row,LOW);

    for(i=2;i<6;i++){
      pinMode(i, INPUT_PULLUP);
      if (!digitalRead(i)){
        while(!digitalRead(i));
        col=i;
      }
    }
  }

  
  row=0;
}
