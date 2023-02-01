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

  // int p = readBlackLine();
  //     for(int i=0;i<8;i++)
  //   {
  //     Serial.print(sensorValueCal[i]);
  //     Serial.print(" ");
  //   }

  //   Serial.println(p);

  while (digitalRead(button) == 1) {
    digitalRead(button);
  }

  delay(500);

  Serial.println("Hello Tohin!");
  Serial.println("Now Finding the sortest path!!!");

  mazeSolve();
  getBackToStart();
  follow_path();
}
