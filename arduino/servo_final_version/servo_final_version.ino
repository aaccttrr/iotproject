//Adam Cotter
//Code fully works using load cell and servo

#include <Servo.h>
#include "HX711.h"

const int pinServo = 4;
HX711 scale(3,2);

float calibration_factor = 800; // this calibration factor is adjusted according to my load cell
float units;
float ounces;

long weight;
int pos = 0;

Servo groveServo;

void setup() {
  // put your setup code here, to run once:
  scale.set_scale();
  scale.tare();
  Serial.begin(9600);
  groveServo.attach(pinServo);
  randomSeed(42);
  groveServo.write(40);
  Serial.print("ready");
  long zero_factor = scale.read_average();
}

void loop() {
  // put your main code here, to run repeatedly:
  scale.set_scale(calibration_factor);
  //generate random number
  weight = random(0,5);
  delay(1000);
  
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  ounces = units * 0.035274;
  Serial.print(units);
  Serial.print(" grams"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 1;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 1;
  }
  
  
if((units<7.0)&&(units<30.0)){
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
  
}
