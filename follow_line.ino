void follow_line()  //follow the line
{
  digitalLow(rightMotor2); // Left Motor Backward
  digitalHigh(rightMotor1); // Right Motor Forward
  digitalLow(leftMotor1); // Left Motor Backforward
  digitalHigh(leftMotor2); // Left Motor Forward
  int lastError = 0;
  while (1) {

    line_position = readBlackLine();

    int error = line_position - 3500;
    int error1 = error - lastError;
    int error2 = (2.0 / 3.0) * error2 + error;
    int motorSpeed = Kp * error + Kd * error1 + Ki * error2;

    int rightMotorSpeed = rightMaxSpeed - motorSpeed;
    int leftMotorSpeed = leftMaxSpeed + motorSpeed;
    lastError = error;

    if (rightMotorSpeed > MaxSpeed) rightMotorSpeed = MaxSpeed;  // prevent the motor from going beyond max speed
    if (leftMotorSpeed > MaxSpeed) leftMotorSpeed = MaxSpeed;    // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0) rightMotorSpeed = 0;
    if (leftMotorSpeed < 0) leftMotorSpeed = 0;

    analogWrite(rightMotorPWM, rightMotorSpeed);
    analogWrite(leftMotorPWM, leftMotorSpeed);

    //    for(int i=0;i<8;i++)
    //    {
    //      Serial.print(sensorValueCal[i]);
    //      Serial.print(" ");
    //
    //    }
    //
    //    Serial.println();

    readBlackLine();
    if (sensorValueCal[0] > threshold || sensorValueCal[7] > threshold) {
      analogWrite(rightMotorPWM, rightMaxSpeed);
      analogWrite(leftMotorPWM, leftMaxSpeed);
      return;
    }
    if (sensorValueCal[0] < threshold && sensorValueCal[1] < threshold && sensorValueCal[2] < threshold && sensorValueCal[3] < threshold && sensorValueCal[4] < threshold && sensorValueCal[5] < threshold && sensorValueCal[6] < threshold && sensorValueCal[6] < threshold) {

      delay(50);
      if (sensorValueCal[0] > threshold && sensorValueCal[1] > threshold && sensorValueCal[2] > threshold && sensorValueCal[3] > threshold && sensorValueCal[4] > threshold && sensorValueCal[5] > threshold && sensorValueCal[6] > threshold && sensorValueCal[6] < threshold) {
        follow_line();
      } else {
        analogWrite(rightMotorPWM, rightMaxSpeed);
        analogWrite(leftMotorPWM, leftMaxSpeed);
        return;
      }
    }
  }
}
