// include the library code:
#include <LiquidCrystal.h>
#include<Wire.h>
//MPU
float RateRoll, RatePitch, RateYaw;
float AccX, AccY, AccZ;
float AngleRoll, AnglePitch;
float LoopTimer;
int angle;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(8,9,4,5,6,7);
//use this code placement
int LB = A1;
int LF = A2;
int RB = A3;
int RF = A0;
int IR = 11;
int IL = 12;// be4 is 8
int PL = 3;
int PR = 10;//be4 is 6, assume all PL=PR, be4 is 2
int EN = 2;// be4 is 9 wrong
//const int MPU_addr=0x68;
//int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int pulses;
int distance;
int preven;
int curren;
int counter;
int stopflag;
int flag;


void gyro_signals(void) {
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(); 
  Wire.requestFrom(0x68,6);
  int16_t AccXLSB = Wire.read() << 8 | Wire.read();
  int16_t AccYLSB = Wire.read() << 8 | Wire.read();
  int16_t AccZLSB = Wire.read() << 8 | Wire.read();
  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x8);
  Wire.endTransmission();                                                   
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  int16_t GyroX=Wire.read()<<8 | Wire.read();
  int16_t GyroY=Wire.read()<<8 | Wire.read();
  int16_t GyroZ=Wire.read()<<8 | Wire.read();
  RateRoll=(float)GyroX/65.5;
  RatePitch=(float)GyroY/65.5;
  RateYaw=(float)GyroZ/65.5;
  AccX=(float)AccXLSB/4096;
  AccY=(float)AccYLSB/4096;
  AccZ=(float)AccZLSB/4096;
  AngleRoll=atan(AccY/sqrt(AccX*AccX+AccZ*AccZ))*1/(3.142/180);
  AnglePitch=-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);
}

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
  counter=0;
  stopflag=1;
  flag=1;
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Wire.setClock(400000);
  Wire.begin();
  delay(250);
  Wire.beginTransmission(0x68); 
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(); 
}
void climb(){
  analogWrite(PR,255);
    analogWrite(PL,255);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
    delay(1500);
    
    analogWrite(PR,255);
    analogWrite(PL,255);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,LOW);
    delay(1350);

    analogWrite(PR,255);
    analogWrite(PL,255);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
    delay(1500);
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
    gyro_signals();
  angle=(int)(AccZ*90);
  follow();
  if (angle >= 30 && flag==1){
    flag=0;
    climb();
  }
  
      

 curren=digitalRead(EN);
  if (preven!=curren){
    preven=curren;
    pulses++;
  }
  else{preven=curren;
  }
  distance=pulses/2.2;
  if (distance>=90 && stopflag==1){
    digitalWrite(LB,LOW);
    digitalWrite(LF,LOW);
    digitalWrite(RB,LOW);
    digitalWrite(RF,LOW);
    stopflag=0;
    delay(3000);
    analogWrite(PR,180);
    analogWrite(PL,180);
    digitalWrite(LB,LOW);
    digitalWrite(LF,HIGH);
    digitalWrite(RB,LOW);
    digitalWrite(RF,HIGH);
  }
  lcd.setCursor(1,0);
  lcd.print("distance:");
  lcd.print(distance);
  lcd.print("cm");
  }



