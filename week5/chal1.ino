#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 8
int i=0;
int BRIGHTNESS=0;

Adafruit_NeoPixel NeoPixel = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int CLK_old=1;
int DT,CLK;

int R_1=128,G_1=0,B_1=0;
int R_2=59 , G_2=185 , B_2=255;

int bm;

void setup() {
  NeoPixel.begin();
  pinMode(2, INPUT_PULLUP);
  pinMode(4,INPUT);
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (bm){
    NeoPixel.setPixelColor(i,NeoPixel.Color(R_1, G_1, B_1));
    NeoPixel.setBrightness(BRIGHTNESS);
  } else {
    NeoPixel.setPixelColor(i,NeoPixel.Color(R_2, G_2, B_2));
    NeoPixel.setBrightness(BRIGHTNESS);
  }

  if (!digitalRead(2)){
    //NeoPixel.setPixelColor(i++,NeoPixel.Color(0,0,0));
    BRIGHTNESS+=50;
    if (BRIGHTNESS==300) {BRIGHTNESS=0;}
    while (!digitalRead(2));
  }
  

  DT=digitalRead(5);
  CLK=digitalRead(4);

  if (CLK!=CLK_old) {
    CLK_old=CLK;
    NeoPixel.setPixelColor(i,NeoPixel.Color(0,0,0));
    
    if (CLK==LOW && DT==LOW) {
      i++;
      bm= !bm;
      if (i==8) {
        i=0;
        
      }
    } else if (CLK==LOW && DT==HIGH) {
      i--;
      bm = !bm;
      if (i==-1){
        i=7;
        
      }
    }
  }

  NeoPixel.show();
  
}
