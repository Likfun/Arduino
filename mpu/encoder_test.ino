#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int LB = A1;
int LF = A2;
int RB = A3;
int RF = A4;
int PL = 3;
int PR = 11;

int encoder_pin = 13;  // The pin the encoder is connected 
volatile byte pulses;  // number of pulses
// The number of pulses per revolution
// depends on your index disc!!
int distance;
int preven;
int curren;

void setup()
 {
   Serial.begin(9600);
   pinMode(encoder_pin, INPUT);
   lcd.begin(16, 2);
  pinMode(LB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(PR, OUTPUT);
   pulses = 0;
   analogWrite(PL,0);
    analogWrite(PR,0);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
    lcd.print("test");
    preven=0;
    curren=0;
 }

 void loop()
 {
  curren=digitalRead(encoder_pin);
  if (preven!=curren){
    preven=curren;
    pulses++;
  }
  else{preven=curren;
  }
  Serial.print("state = ");
   Serial.print(curren);
   Serial.print("  PULSES = ");
   Serial.print(pulses);
   distance = pulses/2.4;
   Serial.print("  DISTANCE = ");
   Serial.println(distance);
   lcd.clear();
   lcd.print("distance:");
   lcd.print(distance);
   lcd.print("cm");

  }
