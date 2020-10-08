#include <Servo.h>
#define pinLED 13
int input=60;
Servo myservo[99];

int flag = 'd';
void setup() {
  // put your setup code here, to run once:
  myservo[0].attach(11);//basement
  myservo[1].attach(12);//big arm
  myservo[2].attach(13);//small arm
  myservo[3].attach(9);//wrist
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()){
  flag = Serial.read();
 }

 if(flag == 'd'){
   myservo[2].write(100);
   myservo[0].write(90);
   delay(500);
  myservo[1].write(20);
  delay(500);
  myservo[3].write(0);
  delay(500);
 }
 else if(flag == 'u'){
  myservo[1].write(110);
   delay(500);
  myservo[0].write(0);
  delay(500);
  myservo[2].write(30);
  delay(500);
  myservo[3].write(180);
  delay(500);
 }
 
}

void readin() {
  
}
