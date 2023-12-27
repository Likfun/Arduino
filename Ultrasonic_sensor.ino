// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400	

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int count=0;
int distance;
int state=1;

void setup() {
	Serial.begin(9600);
}

void loop() {
  distance=sonar.ping_cm();
	Serial.print("Distance = ");
	Serial.print(distance);
	Serial.print(" cm");
  Serial.print(" state: ");
  Serial.print(state);
  Serial.println(" time: ");
  Serial.println(millis()/1000);
  
	delay(50);
  if (distance==0){
    count++;
  }
  if (count==10 && state==1){
    Serial.println("stop");
    state=0;
    delay(10);
    exit(0);

  }
}

