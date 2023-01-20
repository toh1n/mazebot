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
//  delay(2000);
  Serial.begin(9600);
}

void loop() {

  //   int pos = readLine();
  //    Serial.println(pos);

  while (digitalRead(button) == 1)
  {
    digitalRead(button);
  }

  delay(1000);

  Serial.println("Hello Tohin!");
  Serial.println("Now Finding the sortest path!!!");

  MazeSolve();
  getBackToStart();

  // Serial.print("Sortest path : ");
  // Serial.print(" ");
  // for (int i = 0; i < path_length; i++) {
  //   Serial.print(path[i]);
  //   Serial.print(" ");
  // }
  // Serial.println();

  follow_path();
}
