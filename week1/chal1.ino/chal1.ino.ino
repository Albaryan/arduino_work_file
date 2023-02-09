void setup() {

  Serial.begin(9600);         //Start communication with Serial Monitor
  pinMode(9,INPUT_PULLUP);    //Set pin 9 as switch 
  pinMode(8,OUTPUT);          //Set pin 8 as output
}

void loop() {
 
  if (!digitalRead(9)) {              //Check if pin 9 is pressed
    digitalWrite(8,!digitalRead(8));  //Reverse pin 8's value
    while (!digitalRead(9)){delay(10)};          //Loop if pin 9 is held
  };
  
}
