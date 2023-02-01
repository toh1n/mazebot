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
    digitalHigh(led);

    if (reversePath[i] == 'S') {
      Serial.println("Taking Straight");
      delay(getBackToStartDelay);
    } else if (reversePath[i] == 'R') {
      Serial.println("Taking Right");
      delay(getBackToStartDelay);
    } else {
      Serial.println("Taking Left");
      delay(getBackToStartDelay);
    }

    digitalLow(buzzer);
    digitalLow(led);
    turn(reversePath[i]);
  }
  follow_line();
  turn('B');
}

void rotate180() {

  brake();
  delay(400);
  right();

  line_position = readBlackLine();
  while (sensorValueCal[6] > 400)  // wait for outer most sensor to find the line
  {
    line_position = readBlackLine();
  }

  line_position = readBlackLine();
  while (sensorValueCal[6] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readBlackLine();
  }

  line_position = readBlackLine();
  while (sensorValueCal[4] < threshold || sensorValueCal[3] < threshold)  // wait for outer most sensor to find the line
  {
    line_position = readBlackLine();
  }

  brake();
  delay(100);
}
