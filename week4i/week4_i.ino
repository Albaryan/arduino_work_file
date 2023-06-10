#include <Wire.h>

void setup() {
  Wire.begin();
  send(0b00001000);
  send4bits(0b00100000);
  command(0b00001100,0);
}

int POT;
char b[6];
String str;
int i;

void loop() {

  POT=map(analogRead(A3),0,1023,0,1000);

  str=String(POT);

  str.toCharArray(b,6);

  for (i=0;i<6;i++) {
    if (b[i]=='\0'){
      break;
    }
    command(b[i],1);
  }
  command(1,0);

}

void send(int data){
  Wire.beginTransmission(0x27);
  Wire.write(data);
  Wire.endTransmission();
}

void send4bits(int data){
  send(data);
  send(data | 0b00000100);
  send(data);
}

void command(int data, int mode) {
  int MSB=(data)&0xf0;
  int LSB=(data<<4)&0xf0;
  send4bits(MSB|mode);
  send4bits(LSB|mode);
}
