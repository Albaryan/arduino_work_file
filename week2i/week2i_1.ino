int i,j;
int col,row;
int rows[4]={9,8,7,6};
int cols[4]={5,4,3,2};
int LED=10;

char chars[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

bool keypressed,match;

#define PASSLEN 5
char password[PASSLEN]={'?','?','?','?','?'};
char pass[PASSLEN]={'1','4','5','6','#'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

}

void loop() {
  keypressed=0;

  for(i=0;i<4;i++){
    pinMode(rows[i], INPUT_PULLUP);
  }

  for (i=0;i<4;i++){
    pinMode(cols[i],OUTPUT);
    digitalWrite(cols[i],LOW);

    for(j=0;j<4;j++) {
      if (!digitalRead(rows[j])) {
        row=j;
      }
    }

    digitalWrite(cols[i],HIGH);
  }

  
  pinMode(rows[row], OUTPUT);
  digitalWrite(rows[row],LOW);

  for(i=0;i<4;i++){
    pinMode(cols[i], INPUT_PULLUP);
    if (!digitalRead(cols[i])){
      while(!digitalRead(cols[i]));
      keypressed=1;
      col=i;
    }
  }

  if(keypressed) {
    for (i=0;i<PASSLEN;i++){
      if (i==PASSLEN-1) {
        password[i]=chars[row][col];
      } else {
        password[i]=password[i+1];
      }
      Serial.print(password[i]);
    }
    Serial.println(".");

    for (i=0;i<PASSLEN;i++) {
      if (password[i]==pass[i]){
        match=1;
      } else {
        match=0;
        break;
      }
    }
    if (match) {
      digitalWrite(LED,HIGH);
      delay(2000);
      digitalWrite(LED,LOW);
    }
  }
}
