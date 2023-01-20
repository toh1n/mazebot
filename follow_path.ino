void follow_path() {
  while (1) {

    analogWrite(rightMotorPWM, 0);
    analogWrite(leftMotorPWM, 0);
    for (int i = 0; i < 10; i++) {
      digitalLow(led);
      delay(200);
      digitalHigh(led);
      delay(200);
    }

    while (digitalRead(button) == 1)
    {
      digitalRead(button);
    }
    delay(500);

    Serial.println("Taking sortest path.");


    for (int i = 0; i < path_length; i++) {

      follow_line();
      digitalHigh(buzzer);
      if (path[i] == 'S') {
        Serial.println("Taking Straight");
        delay(80);
      } else if (path[i] == 'R') {
        Serial.println("Taking Right");
        delay(80);
      } else {
        Serial.println("Taking Left");
        delay(80);
      }

      digitalLow(buzzer);

      turn(path[i]);
    }
    follow_line();
  }
}
