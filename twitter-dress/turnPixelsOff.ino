void turnPixelsOff() {
  Serial.println("Turning all pixels off...");

  for (uint16_t l = 0; l < Pixels_1; l++) {
    greenStates1[l] = 0;
    blueStates1[l] = 0;
    strip_1.setPixelColor(l, 0, greenStates1[l], blueStates1[l]);
  }

  for (uint16_t l = 0; l < Pixels_2; l++) {
    greenStates2[l] = 0;
    blueStates2[l] = 0;
    strip_1.setPixelColor(l, 0, greenStates1[l], blueStates1[l]);
  }

  for (uint16_t l = 0; l < Pixels_3; l++) {
    greenStates3[l] = 0;
    blueStates3[l] = 0;
    strip_1.setPixelColor(l, 0, greenStates1[l], blueStates1[l]);
  }

  for (uint16_t l = 0; l < Pixels_4; l++) {
    greenStates4[l] = 0;
    blueStates4[l] = 0;
    strip_1.setPixelColor(l, 0, greenStates1[l], blueStates1[l]);
  }
  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();


}
