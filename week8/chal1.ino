#include <LedControl.h> //Kütüphanemizi dahil edelim 

//Pin numaralarını tanımlıyoruz 
#define CLK 5 
#define CS 6 
#define DIN 7 
#define MaxSayisi 1  //Bağlı olan dot matrix sayısı 

const long delay_suresi = 200; //Kodda kullanacağımız delay süresi 

LedControl led = LedControl(DIN, CLK, CS, MaxSayisi);

int lights[][8] {
  {0,1,1,1,1,1,1,1},
  {1,0,0,0,0,1,0,0}
};

byte images[]=
 {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   B01111111,
   B10001000,
   B10001000,
   B10001000,
   B10001000,
   B01111111,
   0,
   0,
   B11111111,
   0,
   0,
   B01111111,
   B10010000,
   B10010000,
   B01100000,
   0,
   0,
   B11111111,
   B10010001,
   B10010001,
   B10010001,
   0,
   0,
   B11111111,
   B10010000,
   B10010000,
   B01101111,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0
 };
 
 int sel=7;

 void setup()
 {
   led.setIntensity(0, 10);  //Parlaklık ayarı
   led.shutdown(0, false);   //Led matrixi aktif hale getirme
   led.clearDisplay(0);
 }
 void loop()
 {
   for (int i = 0; i < 8; i++)
   {
     led.setColumn(0,i,images[sel-i]);
   }
   sel++;
   delay(100);
   if (sel==42) {
     sel=7;
   }
 }
