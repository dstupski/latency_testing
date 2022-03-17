#include <Adafruit_PWMServoDriver.h>
int state_1=0;
int state_2 =0;
int Intensity =100;
int mode = -1;
int Freq;
int incomingByte;
unsigned long milli=millis();
unsigned long duration =50;
int pin0 = 3;
int pin1 =5;


void setup() {
  Serial.begin(19200);
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  analogWrite(pin0, 0);
  analogWrite(pin1, 0);
 
  

  
   
 

}

void loop() {
  if (Serial.available()){
    incomingByte = Serial.read();
  }
  
  if(incomingByte =='y'){
    analogWrite(pin0, 255);
    analogWrite(pin1, 255);
    state_1=1;
    duration = 500;
    milli =millis();
    incomingByte=' ';
    
    
    
 
  }
 if(incomingByte =='j'){
    analogWrite(pin0, 255);
    analogWrite(pin1, 255);
    state_1=1;
    duration = 1600;
    milli =millis();
    incomingByte=' ';
 }
 if(incomingByte =='q'){
   analogWrite(pin0, 255);
   analogWrite(pin1, 255);
    state_1=1;
    duration = 400;
    milli =millis();
    incomingByte=' ';
 }
if(incomingByte =='i'){
    analogWrite(pin0, 255);
    analogWrite(pin1, 255);
    state_1=1;
    duration = 100;
    milli =millis();
    incomingByte=' ';
 } 
if(incomingByte =='o'){
    analogWrite(pin0, 255);
    analogWrite(pin1, 255);
    state_1=1;
    duration = 25;
    milli =millis();
    incomingByte=' ';
 } 
if (state_1==1 and millis()-milli>duration){
  analogWrite(pin1, 0);
  analogWrite(pin0, 0);
  state_1=0;

  
   
}
}    
  

  
