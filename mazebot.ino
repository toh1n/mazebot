#include "defines.h"

void setup() {
  pinAsOutput(rightMotor1);
  pinAsOutput(rightMotor2);
  pinAsOutput(rightMotorPWM);
  pinAsOutput(leftMotor1);
  pinAsOutput(leftMotor2);
  pinAsOutput(leftMotorPWM);
  pinAsOutput(led);
  pinAsOutput(buzzer);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  while (digitalRead(button) == 1)
  {
    digitalRead(button);
  }

  delay(1000);

  Serial.println("Hello Tohin!");
  Serial.println("Now Finding the sortest path!!!");

  MazeSolve();
  getBackToStart();
  follow_path();

}
