#include <SPI.h>

#define ONE 0b110
#define ZERO 0b100

#define CLK_i 5
#define DT_i 6
#define SW_i 7

#define NUMPIXELS 8

int i,j,biggest,lowest;

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

int bright(int R,int G, int B) {

  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
  
  if (((R==255) || (G==255)) || (B==255)) {
      Serial.println("a");
    if ((R<=G) && (R<=B)) {
      lowest=R;
    } else if ((G<=R) && (G<=B)) {
      lowest =G;
    } else {
      lowest =B;
    }

    R=R-lowest;
    G=G-lowest;
    B=B-lowest;
  } else{
    R=R+50;
    G=G+50;
    B=B+50;
    Serial.println("b");
  }

  if ((R>=G) && (R>=B)) {
    biggest=R;
  } else if ((G>=R) && (G>=B)) {
    biggest =G;
  } else if ((B>=R) && (B>=G)){
    biggest = B;
  }


    Serial.println(biggest);
  Serial.println(lowest);

  if (biggest>=255) {
    R=R-(biggest-255);
    G=G-(biggest-255);
    B=B-(biggest-255);
  } 

  return R,G,B;

}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(CLK_i,INPUT);
  pinMode(DT_i,INPUT);
  pinMode(SW_i,INPUT_PULLUP);
  SPI.beginTransaction(SPISettings(2400000,MSBFIRST,SPI_MODE0));
}



int R=255,G=165,B=85;
int pixel=0;
int CLK_o=1;
int CLK;
int DT;

void loop() {
  drawpixel(pixel,R,G,B);
  if (!digitalRead(SW_i)){
    while(!digitalRead(SW_i)); //tuş basma
    R,G,B=bright(R,G,B);


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
