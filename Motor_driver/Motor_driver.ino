#include <LiquidCrystal.h>

int LB = A1;//Left back pin
int LF = A2;//Left front pin
int RB = A3;//Right back pin
int RF = A0;//Right front pin
int PL = 3;//Enable pin left
int PR = 2;//Enable pin right


void setup() {
  // put your setup code here, to run once:
  pinMode(LB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(PR, OUTPUT);

}

void loop() {
    analogWrite(PR,170);//speed of 170
    analogWrite(PL,170);
    digitalWrite(RF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(LF,HIGH);//turning left forward
    digitalWrite(LB,LOW);
    delay(1000);
    analogWrite(PR,170);
    analogWrite(PL,170);
    digitalWrite(RF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,LOW);//stop
    delay(1000);
    analogWrite(PR,170);
    analogWrite(PL,170);
    digitalWrite(RF,HIGH);//turning right forward
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,LOW);
    delay(1000);
    analogWrite(PR,170);
    analogWrite(PL,170);
    digitalWrite(RF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,LOW);//stop again
    delay(1000);
}
