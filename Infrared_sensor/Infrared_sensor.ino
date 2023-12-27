int LB = A1;
int LF = A2;
int RB = A3;
int RF = A0;
int IR = 11;
int IL = 12;
int PL = 3;
int PR = 10;



void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  pinMode(LB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(IL, INPUT);
  pinMode(PR, OUTPUT);
  pinMode(PL, OUTPUT);
}


void loop(){
  if (digitalRead(IR)==0 and digitalRead(IL)==0){//move forward
    analogWrite(PR,80);
    analogWrite(PL,80);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
    delay(50);
  }
  if (digitalRead(IR)==0 and digitalRead(IL)==1){//turn rght
    analogWrite(PR,255);
    analogWrite(PL,255);
    digitalWrite(RF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,HIGH);
    delay(50);
  }
  if (digitalRead(IR)==1 and digitalRead(IL)==0){//turn left
    analogWrite(PR,245);
    analogWrite(PL,245);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(RF,LOW);
    delay(50);
  }
  if (digitalRead(IR)==1 and digitalRead(IL)==1){//stop
    analogWrite(PR,80);
    analogWrite(PL,80);
    digitalWrite(LB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(RF,LOW);
    delay(50);
  }
}


