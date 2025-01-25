#include <Servo.h>

Servo thumbServo;
Servo indexServo;
Servo middleServo;
Servo ringServo;
Servo pinkyServo;

const int thumbPotPin = A0;
const int indexPotPin = A1;
const int middlePotPin = A2;
const int ringPotPin = A3;
const int pinkyPotPin = A4;

const int thumbServoPin = 3;
const int indexServoPin = 5;
const int middleServoPin = 6;
const int ringServoPin = 9;
const int pinkyServoPin = 10;

void setup() {
  thumbServo.attach(thumbServoPin);
  indexServo.attach(indexServoPin);
  middleServo.attach(middleServoPin);
  ringServo.attach(ringServoPin);
  pinkyServo.attach(pinkyServoPin);
}

void loop() {
  int thumbVal = analogRead(thumbPotPin);
  int indexVal = analogRead(indexPotPin);
  int middleVal = analogRead(middlePotPin);
  int ringVal = analogRead(ringPotPin);
  int pinkyVal = analogRead(pinkyPotPin);

  int thumbAngle = map(thumbVal, 0, 1023, 0, 180);
  int indexAngle = map(indexVal, 0, 1023, 0, 180);
  int middleAngle = map(middleVal, 0, 1023, 0, 180);
  int ringAngle = map(ringVal, 0, 1023, 0, 180);
  int pinkyAngle = map(pinkyVal, 0, 1023, 0, 180);

  thumbServo.write(thumbAngle);
  indexServo.write(indexAngle);
  middleServo.write(middleAngle);
  ringServo.write(ringAngle);
  pinkyServo.write(pinkyAngle);

  delay(15);
}
