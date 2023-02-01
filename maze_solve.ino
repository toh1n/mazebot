void mazeSolve() {
  while (1) {
    follow_line();

    brake();
    delay(10);

    digitalHigh(buzzer);
    digitalHigh(led);

    unsigned char found_left = 0;
    unsigned char found_straight = 0;
    unsigned char found_right = 0;

    readBlackLine();
    if (sensorValueCal[0] > 450 || sensorValueCal[1] > 450) {
      found_left = 1;
      Serial.println("Found Left <--");
    }

    if (sensorValueCal[7] > threshold) {
      found_right = 1;
      Serial.println("Found Right -->");
    }

    analogWrite(rightMotorPWM, rightMaxSpeed);
    analogWrite(leftMotorPWM, leftMaxSpeed);

    delay(80);

    readBlackLine();
    if (sensorValueCal[1] > threshold || sensorValueCal[2] > threshold || sensorValueCal[3] > threshold || sensorValueCal[4] > threshold || sensorValueCal[5] > threshold || sensorValueCal[6] > threshold) {
      found_straight = 1;
      Serial.println("Found Straight --");
    }


    readBlackLine();
    if (sensorValueCal[0] > threshold && sensorValueCal[1] > threshold && sensorValueCal[2] > threshold && sensorValueCal[3] > threshold && sensorValueCal[4] > threshold && sensorValueCal[5] > threshold && sensorValueCal[6] > threshold) {
      digitalLow(buzzer);
      digitalLow(led);
      break;
    }

    digitalLow(buzzer);
    digitalLow(led);

    unsigned char dir = select_turn(found_left, found_straight, found_right);
    turn(dir);
    path[path_length] = dir;
    path_length++;
    simplify_path();
  }
}
