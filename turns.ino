void turn(char dir) {
  switch (dir) {

    case 'L':
      left();
      line_position = readBlackLine();
      while (sensorValueCal[1] < turnThreshold) {
        line_position = readBlackLine();
      }

      line_position = readBlackLine();
      while (sensorValueCal[2] < turnThreshold || sensorValueCal[3] < turnThreshold || sensorValueCal[4] < turnThreshold)  // wait for outer most sensor to find the line
      {
        line_position = readBlackLine();
      }

      brake();
      delay(30);
      break;

    // Turn right 90deg
    case 'R':
      right();

      line_position = readBlackLine();
      while (sensorValueCal[6] < turnThreshold)  // wait for outer most sensor to find the line
      {
        line_position = readBlackLine();
      }

      line_position = readBlackLine();
      while (sensorValueCal[5] < turnThreshold || sensorValueCal[4] < turnThreshold || sensorValueCal[3] < turnThreshold)  // wait for outer most sensor to find the line
      {
        line_position = readBlackLine();
      }

      brake();
      delay(30);
      break;

    // Turn right 180deg to go back
    case 'B':
      back();
      line_position = readBlackLine();
      while (sensorValueCal[6] < turnThreshold)  // wait for outer most sensor to find the line
      {
        line_position = readBlackLine();
      }

      line_position = readBlackLine();
      while (sensorValueCal[4] < turnThreshold && sensorValueCal[3] < turnThreshold)  // wait for outer most sensor to find the line
      {
        line_position = readBlackLine();
      }

      brake();
      delay(40);
      break;

    case 'S':
      //      straight();
      //      delay(80);
      //
      //      brake();
      //      delay(5);
      break;
  }
}



char select_turn(unsigned char found_left, unsigned char found_straight, unsigned char found_right) {

  if (found_left)
    return 'L';
  else if (found_straight)
    return 'S';
  else if (found_right)
    return 'R';
  else
    return 'B';
}



void simplify_path() {

  if (path_length < 3 || path[path_length - 2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for (i = 1; i <= 3; i++) {
    switch (path[path_length - i]) {
      case 'R':
        total_angle += 90;
        break;
      case 'L':
        total_angle += 270;
        break;
      case 'B':
        total_angle += 180;
        break;
    }
  }

  total_angle = total_angle % 360;

  switch (total_angle) {
    case 0:
      path[path_length - 3] = 'S';
      break;
    case 90:
      path[path_length - 3] = 'R';
      break;
    case 180:
      path[path_length - 3] = 'B';
      break;
    case 270:
      path[path_length - 3] = 'L';
      break;
  }
  path_length -= 2;
}
