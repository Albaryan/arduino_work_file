#include <Keypad.h>

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[4] = {9,8,7,6};
byte colPins[4] = {5,4,3,2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, 4,4);

char password[5]={'1','4','5','6','#'};
char pressed[5]={'?','?','?','?','?'};

int i;
int pass=1;
int flag=1;

void setup() {
  Serial.begin(9600);

  pinMode(10,OUTPUT);
}

void loop() {
  char key=keypad.getKey();

  digitalWrite(10,LOW);
  
  if (key) {
    for (i=0; i<4;i++) {
      pressed[i]=pressed[i+1];
    }
    pressed[i]=key;
  }
  for (i=0;i<5;i++){
    Serial.print(pressed[i]);
    Serial.println(password[i]);
    if (pressed[i] != password[i]) {
      pass=0;
      flag=1;
      break;
    } else {
      pass=1;
    }
  }
  if (pass && flag) {
    digitalWrite(10,HIGH);
    delay(2000);
    digitalWrite(10,LOW);
    flag=0;
  }
}
