//Adam Cotter
//Working using random numbers instead of laod cell input

#include <Servo.h>
#include "HX711.h"

const int pinServo = 3;
long weight;

Servo groveServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  groveServo.attach(pinServo);
  randomSeed(42);
}

void loop() {
  // put your main code here, to run repeatedly:

  //generate random number
  weight = random(0,5);
  delay(1000);

  if(weight == 0){
    groveServo.write(90);
    delay(1000);
    groveServo.write(-90);
    delay(1000);
  }
  
}
