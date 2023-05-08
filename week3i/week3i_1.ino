#include <SPI.h>

#define ONE 0b110
#define ZERO 0b100

#define CLK_i 5
#define DT_i 6
#define SW_i 7

#define NUMPIXELS 8

int i,j;

void draw(int color) {
  bool value[8]={0,0,0,0,0,0,0,0};

  for (j=8;j>0;j--) {
    value[j-1]=color%2;
    color=color/2;
  }

  for (j=0;j<8;j++) {
    if (value[j]) {
      SPI.transfer(ONE);
    }
    else {
      SPI.transfer(ZERO);
    }
  }

}

void drawpixel(int index,int R,int G, int B) {
  for (i=0 ; (i<NUMPIXELS) ; i++) {
    if (i==index) {
      draw(G);
      draw(R);
      draw(B);
    }
    else{
      draw(0);
      draw(0);
      draw(0);
    }
  }
  delayMicroseconds(40);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(CLK_i,INPUT);
  pinMode(DT_i,INPUT);
  pinMode(SW_i,INPUT_PULLUP);
  SPI.beginTransaction(SPISettings(2400000,MSBFIRST,SPI_MODE0));
}


int R=0,G=255,B=0;
int pixel=0;
int CLK_o=1;
int CLK;
int DT;

void loop() {
  drawpixel(pixel,R,G,B);
  if (!digitalRead(SW_i)){
    while(!digitalRead(SW_i)); //tuş basma


  }

  DT=digitalRead(5);
  CLK=digitalRead(4);

  if (CLK!=CLK_o) {
    CLK_o=CLK;
    
    if (CLK==LOW && DT==LOW) {
      pixel++;
      if (i==8) {
        i=0;
        
      }
    } else if (CLK==LOW && DT==HIGH) {
      pixel--;
      if (i==-1){
        i=7;
        
      }
    }
  }

}
