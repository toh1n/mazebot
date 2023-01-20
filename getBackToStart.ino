void getBackToStart() {

  Serial.print("Sortest path : ");
  Serial.print(" ");
  for (int i = 0; i < path_length; i++) {
    Serial.print(path[i]);
    Serial.print(" ");
  }
  Serial.println();

  rotate180();

  int j = 0;
  for (int i = path_length - 1; i >= 0; i--) {
    if (path[i] == 'L') {
      reversePath[j] = 'R';
    } else if (path[i] == 'R') {
      reversePath[j] = 'L';
    } else if (path[i] == 'S') {
      reversePath[j] = 'S';
    } else {
      reversePath[j] = 'B';
    }
    j++;
  }

  Serial.print("Sortest reverse path : ");
  Serial.print(" ");
  for (int i = 0; i < path_length; i++) {
    Serial.print(reversePath[i]);
    Serial.print(" ");
  }
  Serial.println();


  for (int i = 0; i < path_length; i++) {
    follow_line();
    digitalHigh(buzzer);
    if (reversePath[i] == 'S') {
      Serial.println("Taking Straight");
      delay(90);
    } else if (reversePath[i] == 'R') {
      Serial.println("Taking Right");
      delay(90);
    } else {
      Serial.println("Taking Left");
      delay(90);
    }

    digitalLow(buzzer);
    turn(reversePath[i]);
  }
  follow_line();
  turn('B');
}

void rotate180() {

  analogWrite(rightMotorPWM, 0);
  analogWrite(leftMotorPWM, 0);
  delay(400);

  digitalLow(rightMotor1);
  digitalHigh(rightMotor2);
  digitalLow(leftMotor1);
  digitalHigh(leftMotor2);
  analogWrite(rightMotorPWM, speedturnR);
  analogWrite(leftMotorPWM, speedturnL);

  line_position = readLine();

  while (sensor_values[6] > 400)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }
  
  line_position = readLine();

  while (sensor_values[6] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }
  line_position = readLine();

  while (sensor_values[4] < threshold || sensor_values[3] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readLine();
  }
  analogWrite(rightMotorPWM, 0);
  analogWrite(leftMotorPWM, 0);
  delay(100);
}