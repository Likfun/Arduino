// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int LB = A1;
int LF = A2;
int RB = A3;
int RF = A5;
int IR = 11;
int IL = 8;
int PL = 5;
int PR = 6;
int EN = 13;

void setup() {
	Serial.begin(9600);
    {analogWrite(PL,170);
    analogWrite(PR,170);
    digitalWrite(RF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(LB,LOW);}
}

void loop() {
	Serial.print("Distance = ");
	Serial.print(sonar.ping_cm());
	Serial.println(" cm");
  int a=sonar.ping_cm();
  if(a<35)
    {analogWrite(PL,170);
    analogWrite(PR,170);
    digitalWrite(RF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(LB,LOW);}
else
    {analogWrite(PL,170);
    analogWrite(PR,170);
    digitalWrite(RF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(LB,LOW);}
}
