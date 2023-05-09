#include <SPI.h>

#define ONE 0b110
#define ZERO 0b100

#define CLK_i 5
#define DT_i 6
#define SW_i 7

#define R_o 0
#define G_o 255
#define B_o 255

#define NUMPIXELS 8

int i,j,biggest,lowest;

float k[3]={R_o/255.0,G_o/255.0,B_o/255.0};
float o[3]={R_o,G_o,B_o};

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
  delayMicroseconds(50);
}

int bright(int color, int index) {
  color = color+(((k[index])*50)+0.5);

  if (color > o[index]) {
    color=0;
  }

  return color;
  
}



void setup() {
  pinMode(CLK_i,INPUT);
  pinMode(DT_i,INPUT);
  pinMode(SW_i,INPUT_PULLUP);
  SPI.beginTransaction(SPISettings(2400000,MSBFIRST,SPI_MODE0));
}



int colors[3]={R_o,G_o,B_o};
int pixel=0;
int CLK_o=1;
int CLK;
int DT;

void loop() {
  drawpixel(pixel,colors[0],colors[1],colors[2]);

  if (!digitalRead(SW_i)){
    while(!digitalRead(SW_i));
    for (int m=0;m<3;m++) {
      colors[m]=bright(colors[m],m);
    }
  }


  DT=digitalRead(DT_i);
  CLK=digitalRead(CLK_i);

  if (CLK!=CLK_o) {
    CLK_o=CLK;

    if (CLK==LOW && DT==LOW) {
      pixel++;

      if (pixel==NUMPIXELS) {
        pixel=0;
      }
    } else if (CLK==LOW && DT==HIGH) {
      pixel--;
      if (pixel==-1){

        pixel=NUMPIXELS-1;
      }
    }
  }
}
