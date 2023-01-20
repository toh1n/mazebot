void follow_line()  //follow the line
{
  digitalLow(rightMotor2);
  digitalHigh(rightMotor1);
  digitalLow(leftMotor1);
  digitalHigh(leftMotor2);
  int lastError = 0;

  while (1) {

    line_position = readLine();

    int error = line_position - 3500;
    int error1 = error - lastError;
    int error2 = (2.0 / 3.0) * error2 + error;
    int motorSpeed = Kp * error + Kd * error1 + Ki * error2;

    int rightMotorSpeed =  rightMaxSpeed - motorSpeed;
    int leftMotorSpeed = leftMaxSpeed + motorSpeed;

    if (rightMotorSpeed > MaxSpeed) rightMotorSpeed = MaxSpeed;  // prevent the motor from going beyond max speed
    if (leftMotorSpeed > MaxSpeed) leftMotorSpeed = MaxSpeed;    // prevent the motor from going beyond max speed
    if (rightMotorSpeed < 0) rightMotorSpeed = 0;
    if (leftMotorSpeed < 0) leftMotorSpeed = 0;

    analogWrite(rightMotorPWM, rightMotorSpeed);
    analogWrite(leftMotorPWM, leftMotorSpeed);
    lastError = error;

    readLine();
    if (sensor_values[0] > threshold || sensor_values[7] > threshold) {
      analogWrite(rightMotorPWM, rightMaxSpeed);
      analogWrite(leftMotorPWM, leftMaxSpeed);
      return;
    }
    if (sensor_values[0] < threshold && sensor_values[1] < threshold && sensor_values[2] < threshold && sensor_values[3] < threshold && sensor_values[4] < threshold && sensor_values[5] < threshold && sensor_values[6] < threshold && sensor_values[6] < threshold) {

      delay(50);
      if (sensor_values[0] > threshold && sensor_values[1] > threshold && sensor_values[2] > threshold && sensor_values[3] > threshold && sensor_values[4] > threshold && sensor_values[5] > threshold && sensor_values[6] > threshold && sensor_values[6] < threshold) {
        follow_line();
      } else {
        analogWrite(rightMotorPWM, rightMaxSpeed);
        analogWrite(leftMotorPWM, leftMaxSpeed);
        return;
      }
    }
  }
}
