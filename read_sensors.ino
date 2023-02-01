uint16_t readBlackLine() {
  bool onLine = false;
  uint32_t avg = 0;  // this is for the weighted total
  uint16_t sum = 0;  // this is for the denominator, which is <= 64000

  readCalibratedBlack();

  for (uint8_t i = 0; i < N_SENS; i++) {
    uint16_t value = sensor_values[i];

    // keep track of whether we see the line at all
    if (value > 200) { onLine = true; }

    // only average in values that are above a noise threshold
    if (value > 50) {
      avg += (uint32_t)value * (i * 1000);
      sum += value;
    }
  }

  if (!onLine) {
    // If it last read to the left of center, return 0.
    if (lastPosition < (N_SENS - 1) * 1000 / 2) {
      return 0;
    }
    // If it last read to the right of center, return the max.
    else {
      return (N_SENS - 1) * 1000;
    }
  }

  lastPosition = avg / sum;
  return lastPosition;
}

uint16_t readWhiteLine() {
  bool onLine = false;
  uint32_t avg = 0;  // this is for the weighted total
  uint16_t sum = 0;  // this is for the denominator, which is <= 64000

  readCalibratedWhite();

  for (uint8_t i = 0; i < N_SENS; i++) {
    uint16_t value = sensor_values[i];

    // keep track of whether we see the line at all
    if (value > 200) { onLine = true; }

    // only average in values that are above a noise threshold
    if (value > 50) {
      avg += (uint32_t)value * (i * 1000);
      sum += value;
    }
  }

  if (!onLine) {
    // If it last read to the left of center, return 0.
    if (lastPosition < (N_SENS - 1) * 1000 / 2) {
      return 0;
    }
    // If it last read to the right of center, return the max.
    else {
      return (N_SENS - 1) * 1000;
    }
  }

  lastPosition = avg / sum;
  return lastPosition;
}

void readCalibratedWhite() {

  for (int i = 0; i < N_SENS; i++) {
    sensor_values[i] = analogRead(N_SENS - (i + 1));
    int x = mapa(sensor_values[i], sens_max[i], sens_min[i], 0, 1000);
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
    sensorValueCal[i] = x;
  }
}
void readCalibratedBlack() {

  for (int i = 0; i < N_SENS; i++) {
    sensor_values[i] = analogRead(N_SENS - (i + 1));
    int x = mapa(sensor_values[i], sens_min[i], sens_max[i], 0, 1000);
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
    sensorValueCal[i] = x;
  }
}

long mapa(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
