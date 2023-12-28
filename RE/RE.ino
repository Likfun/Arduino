// include the library code:
#include <LiquidCrystal.h>
#include<Wire.h>
#include <Wire.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(8,9,4,5,6,7);
//use this code placement
int LB = A1;
int LF = A2;
int RB = A3;
int RF = A0;
int IR = 11;
int IL = 12;
int PL = 3;
int PR = 10;
int EN = 2;

int pulses;
int distance;
int preven;
int curren;


void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(LB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(IL, INPUT);
  pinMode(PR, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(EN, INPUT);

  pulses=0;
  preven=0;
  curren=0;
}

void follow(){
  if (digitalRead(IR)==0 and digitalRead(IL)==0){
    //the code tht let it complete the course use 70 speed
    analogWrite(PR,80);
    analogWrite(PL,80);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
  }
  if (digitalRead(IR)==0 and digitalRead(IL)==1){
    analogWrite(PR,255);
    analogWrite(PL,255);
    digitalWrite(RF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,HIGH);
    delay(10);
  }
  if (digitalRead(IR)==1 and digitalRead(IL)==0){
    analogWrite(PR,245);
    analogWrite(PL,245);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(RF,LOW);
    delay(10);
  }
  if (digitalRead(IR)==1 and digitalRead(IL)==1){
    analogWrite(PR,80);
    analogWrite(PL,80);
    digitalWrite(LB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(RF,LOW);
  }
}

void loop() {
  follow(); 
//RE codes
curren=digitalRead(EN);
  if (preven!=curren){
    preven=curren;
    pulses++;}
  else{preven=curren;}
  distance=pulses/2.2;
  lcd.setCursor(1,0);
  lcd.print("distance:");
  lcd.print(distance);
  lcd.print("cm");
  }