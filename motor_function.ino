void left() {
  digitalHigh(rightMotor1);
  digitalLow(rightMotor2);
  digitalHigh(leftMotor1);
  digitalLow(leftMotor2);
  analogWrite(rightMotorPWM, speedturnR);
  analogWrite(leftMotorPWM, speedturnL);
}

void right() {
  digitalLow(rightMotor1);
  digitalHigh(rightMotor2);
  digitalLow(leftMotor1);
  digitalHigh(leftMotor2);
  analogWrite(rightMotorPWM, speedturnR);
  analogWrite(leftMotorPWM, speedturnL);
}

void back() {
  digitalLow(rightMotor1);
  digitalHigh(rightMotor2);
  digitalLow(leftMotor1);
  digitalHigh(leftMotor2);
  analogWrite(rightMotorPWM, speedturnR);
  analogWrite(leftMotorPWM, speedturnL);
}

void straight() {
  digitalLow(rightMotor2);
  digitalHigh(rightMotor1);
  digitalLow(leftMotor1);
  digitalHigh(leftMotor2);
  analogWrite(rightMotorPWM, speedturnR);
  analogWrite(leftMotorPWM, speedturnL);
}

void brake() {
  analogWrite(rightMotorPWM, 0);
  analogWrite(leftMotorPWM, 0);
}