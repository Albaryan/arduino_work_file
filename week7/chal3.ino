#include <Keypad.h>
#include <TM1637.h>

TM1637 tm(11,12);

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[4] = {9,8,7,6};
byte colPins[4] = {5,4,3,2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4,4);

char nums[4]={'0' , '0' , '0' , '0'};

int i=0;

void setup() {
  // put your setup code here, to run once:
  tm.init();
  tm.set(BRIGHT_TYPICAL);
  for (i; i<4; i++) {
    tm.display(i,nums[i]-'0');
  }
  i=0;
}


void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();

  if (isdigit(key)) {
    tm.display(i,key-'0');
    i++;
    if (i>3) {
      i=3;
    } 
  } else if (key=='*') {
    for (i=0; i<4; i++) {
      tm.display(i,nums[i]-'0');
    }
    i=0;
  } else if (key=='#') {
    tm.display(i,nums[i]-'0');
    i--;
    if (i<0) {
      i=0;
    }
  }
}
