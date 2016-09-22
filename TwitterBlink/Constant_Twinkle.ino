/**
 * Constantly twinkles without tweets - Phase 1
 */
void constantTwinkle() {

if (random(20) == 1) {
    uint16_t i = random(Pixels);                       //Select one random pixel
    if (greenStates[i] < 1 && blueStates[i] < 1) {     //Is it on or off. If off, turn on with specific colour
      greenStates[i] = 50;                             //Sets how much of each colour/brightness
      blueStates[i] = 50;
    }
  }

  for (uint16_t l = 0; l < Pixels; l++) {
    if (greenStates[l] > 1 || blueStates[l] > 1) {
      strip_1.setPixelColor(l, 0, greenStates[l], blueStates[l]);
      strip_2.setPixelColor(l, 0, greenStates[l], blueStates[l]);
      strip_3.setPixelColor(l, 0, greenStates[l], blueStates[l]);
      strip_4.setPixelColor(l, 0, greenStates[l], blueStates[l]);

/**
 * Fade until light is off (0)
 */
      if (greenStates[l] > 1) {
        greenStates[l] = greenStates[l] * fadeRate;
      } else {
        greenStates[l] = 0;
      }

      if (blueStates[l] > 1) {
        blueStates[l] = blueStates[l] * fadeRate;
      } else {
        blueStates[l] = 0;
      }

    }
    else {                                     //Set colour to black/"off"
      strip_1.setPixelColor(l, 0, 0, 0);
      strip_2.setPixelColor(l, 0, 0, 0);
      strip_3.setPixelColor(l, 0, 0, 0);
      strip_4.setPixelColor(l, 0, 0, 0);
    }
  }
  strip_1.show();                             //Show colours
  strip_2.show();
  strip_3.show();
  strip_4.show();

  delay(1);
}

