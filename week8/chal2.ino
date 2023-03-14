#include <LedControl.h>

LedControl led= LedControl(5, 7, 6, 1);

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(5,OUTPUT);

  led.setIntensity(0,10);
  led.shutdown(0,false);
  led.clearDisplay(0);

}

int clk_o=1;

int ledX=7,ledY=0;

bool rot=0;

void loop() {
  // put your main code here, to run repeatedly:
  int clk=digitalRead(2);
  int dt=digitalRead(3);

  led.setLed(0,ledY,ledX,1); 

  if (!digitalRead(4)) {
    rot=!rot;
    delay(100);
  }
  
  if (clk_o!=clk && rot) {
    led.setLed(0,ledY,ledX,0);
    clk_o=clk;
    if (!clk && !dt) {
      ledY++;
    } else if (!clk && dt) {
      ledY--;
    }
  }

  if (clk_o!=clk && !rot) {
    led.setLed(0,ledY,ledX,0);
    clk_o=clk;
    if (!clk && !dt) {
      ledX++;
    } else if (!clk && dt) {
      ledX--;
    }
  }

  if (ledX>7) {
    ledX=7;
  } else if(ledX<0) {
    ledX=0;
  } else if (ledY>7) {
    ledY=7;
  } else if (ledY<0) {
    ledY=0;
  }
}

