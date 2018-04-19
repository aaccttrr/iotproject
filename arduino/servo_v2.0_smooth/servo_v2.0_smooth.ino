//Adam Cotter
//Working using random numbers instead of laod cell input

#include <Servo.h>
#include "HX711.h"

const int pinServo = 3;
long weight;
int pos = 0;

Servo groveServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  groveServo.attach(pinServo);
  randomSeed(42);
  groveServo.write(40);
}

void loop() {
  // put your main code here, to run repeatedly:

  //generate random number
  weight = random(0,5);
  delay(1000);
  
  

   for(pos = 0; pos < 145; pos += 5) // goes from 0 degrees to 180 degrees
 {         // in steps of 1 degree
 groveServo.write(pos);    // tell servo to go to position in
          // variable 'pos'
 delay(30);      // waits 15ms for the servo to reach
          // the position
 }
 delay(1000);

 for(pos = 140; pos>=50; pos-=2)  // goes from 180 degrees to 0 degrees
 {       
 groveServo.write(pos);    // tell servo to go to position in
          // variable 'pos'
 delay(30);      // waits 15ms for the servo to reach
          // the position
 }
  
}
