#include <LedControl.h>

LedControl led= LedControl(5, 7, 6, 1);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  led.setIntensity(0,10);
  led.shutdown(0,false);
  led.clearDisplay(0);
}

int ledX=7,ledY=0;

bool rot=1;
bool way=0;

int sol=4,sag=2,yukari=8, asagi=3;

void loop() {
  
  led.setLed(0,ledY,ledX,1);
  delay(250);

  if(!digitalRead(yukari) && (rot || way)){

    rot=0;
    way=0;
  } else if (!digitalRead(sag) && (!rot || way)) {
    rot=1;
    way=0;
  } else if (!digitalRead(asagi) && (rot || !way)) {
    rot=0;
    way=1;
  } else if (!digitalRead(sol) && (!rot || !way)) {
    rot=1;
    way=1;
  }

  if (rot && way) {
    led.setLed(0,ledY,ledX,0);
    ledX++;
  } else if (rot && !way) {
    led.setLed(0,ledY,ledX,0);
    ledX--;
  } else if (!rot && way) {
    led.setLed(0,ledY,ledX,0);
    ledY++;
  } else if (!rot && !way) {
    led.setLed(0,ledY,ledX,0);
    ledY--;
  }

  if (ledX>7){
    ledX=7;
  } else if(ledX<0){
    ledX=0;
  } else if (ledY>7){
    ledY=7;
  } else if (ledY<0){
    ledY=0;
  }
}
