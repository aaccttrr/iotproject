#include <Servo.h>
const int pinServo = 3;

Servo groveServo;

void setup() {
  // put your setup code here, to run once:
  groveServo.attach(pinServo);
}

void loop() {
  // put your main code here, to run repeatedly:
  groveServo.write(90);
  delay(1000);
  groveServo.write(-90);
  delay(1000);
}
