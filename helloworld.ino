/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

#include <Servo.h>
#define pinLED 13

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void playSong(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
Servo myservo[99];

int flag = 'd';
void setup() {
  // iterate over the notes of the melody:
// put your setup code here, to run once:
  myservo[0].attach(11);//basement
  myservo[1].attach(12);//big arm
  myservo[2].attach(13);//small arm
  myservo[3].attach(9);//wrist
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);
  
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

 if(Serial.available()){
  flag = Serial.read();
 }
 if(flag=='1'){
  digitalWrite(13,HIGH);
 }
 if(flag == '0'){
  digitalWrite(13,LOW);
 }
if(flag == 'L'){
   digitalWrite(13,HIGH);
  delay(1500);
  digitalWrite(13,LOW);
  delay(1500);
}
if(flag == 'P'){
  playSong();
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
