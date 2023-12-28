#include <SoftwareSerial.h>

//Create software serial object to communicate with HC-05
SoftwareSerial mySerial(3, 2); //HC-05 Tx & Rx is connected to Arduino #3 & #2
int LB = A1;
int LF = A2;
int RB = A3;
int RF = A0;

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and HC-05
  mySerial.begin(9600);

  Serial.println("Initializing...");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  printf("\n");
  if(mySerial==49)//MOVE FRONT
  digitalWrite(LB,LOW);
  digitalWrite(LF,HIGH);
  digitalWrite(RB,LOW);
  digitalWrite(RF,HIGH);

   if(mySerial==50)//MOVE BACK
  digitalWrite(LB,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(RB,HIGH);
  digitalWrite(RF,LOW);
  
   if(mySerial==51)//TURN LEFT
  digitalWrite(LB,LOW);
  digitalWrite(LF,HIGH);
  digitalWrite(RB,LOW);
  digitalWrite(RF,LOW);

   if(mySerial==52)//TURN RIGHT
  digitalWrite(LB,LOW);
  digitalWrite(LF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(RF,HIGH);
}