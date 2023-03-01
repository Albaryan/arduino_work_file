#include <Adafruit_NeoPixel.h>

int PIN=3, NUMPIXELS=8;

Adafruit_NeoPixel pixels= Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

String input;

int sol() {
  for (int i=0; i<8; i++){
    pixels.setPixelColor(i,pixels.Color(255,0,0));
    pixels.show();
    delay(100);
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();
  }

}

int sag() {
  for (int i=8; i>-1; i--){
    pixels.setPixelColor(i,pixels.Color(255,0,0));
    pixels.show();
    delay(100);
    pixels.setPixelColor(i,pixels.Color(0,0,0));
    pixels.show();
  }

}
 
void setup() {
    Serial.begin(9600); 

    pixels.begin();
 
    Serial.println("Type something!");
}
 
void loop() {
    if(Serial.available()){
        input = Serial.readStringUntil('\n');
        if (input.equals("sol")) {
          sol();
        } else if (input.equals("sağ")){
          sag();
        }
    }
}
