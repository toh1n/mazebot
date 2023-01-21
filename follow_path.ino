void follow_path() {
  while (1) {

    brake();
    for (int i = 0; i < 5; i++) {
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
      digitalHigh(led);

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
      digitalLow(led);
      turn(path[i]);
    }
    follow_line();
  }
}
