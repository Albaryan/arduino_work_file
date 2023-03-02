#include <LiquidCrystal_I2C.h>
int POT;

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() {
 POT=map(analogRead(A3),0,1023,0,10000);
 lcd.setCursor(0,0);
 // Pot 10k varsayılarak
 lcd.print(POT);
delay(100);
 lcd.clear();
}
