#include <Adafruit_NeoPixel.h>
#include <Keypad.h>

int BRIGHTNESS=50;
int i=0;
int NUMPIXELS=8;
int PIN=2;
char keys[4][4] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4]={10,9,8,7};
byte colPins[4]={6,5,4,3};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4,4);

Adafruit_NeoPixel NeoPixel = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  NeoPixel.begin();
  Serial.begin(9600);

}

void loop() {
  char key=keypad.getKey();
  NeoPixel.setBrightness(BRIGHTNESS);
  NeoPixel.setPixelColor(i,NeoPixel.Color(0,0,0));

  switch (key) {
    case '1':
      i=0;
      break;
    case '2':
      i=1;
      break;
    case '3':
      i=2;
      break;
    case '4':
      i=3;
      break;
    case '5':
      i=4;
      break;
    case '6':
      i=5;
      break;
    case '7':
      i=6;
      break;
    case '8':
      i=7;
      break;
    case 'A':
      BRIGHTNESS+=50;
      break;
    case 'B':
      BRIGHTNESS-=50;
      break;
  }

  if (BRIGHTNESS==300) {
    BRIGHTNESS=250;
  } else if (BRIGHTNESS == -50) {
    BRIGHTNESS=0;
  }

  Serial.println(key);

  NeoPixel.setPixelColor(i,NeoPixel.Color(255,255,0));
  NeoPixel.show();
}
