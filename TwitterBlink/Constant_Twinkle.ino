/**
 * Constantly twinkles without tweets - Phase 1
 */
void constantTwinkle() {

if (random(20) == 1) {
    uint16_t i = random(Pixels_1);
    if (greenStates1[i] < 1 && blueStates1[i] < 1) {
      greenStates1[i] = 0;
      blueStates1[i] = 150;
    }
  }
    if (random(20) == 1) {
    uint16_t i = random(Pixels_2);
    if (greenStates2[i] < 1 && blueStates2[i] < 1) {
      greenStates2[i] = 0;
      blueStates2[i] = 150;
    }
  }
    if (random(20) == 1) {
    uint16_t i = random(Pixels_3);
    if (greenStates3[i] < 1 && blueStates3[i] < 1) {
      greenStates3[i] = 0;
      blueStates3[i] = 150;
    }
  }
    if (random(20) == 1) {
    uint16_t i = random(Pixels_4);
    if (greenStates4[i] < 1 && blueStates4[i] < 1) {
      greenStates4[i] = 0;
      blueStates4[i] = 150;
    }
  }

  for (uint16_t l = 0; l < Pixels_1; l++) {
    if (greenStates1[l] > 1 || blueStates1[l] > 1) {
      strip_1.setPixelColor(l, 0, greenStates1[l], blueStates1[l]);

      if (greenStates1[l] > 1) {
        greenStates1[l] = greenStates1[l] * fadeRate;
      } else {
        greenStates1[l] = 0;
      }

      if (blueStates1[l] > 1) {
        blueStates1[l] = blueStates1[l] * fadeRate;
      } else {
        blueStates1[l] = 0;
      }

    } else {
      strip_1.setPixelColor(l, 0, 0, 0);
    }
  }

    for (uint16_t l = 0; l < Pixels_2; l++) {
    if (greenStates2[l] > 1 || blueStates2[l] > 1) {
      strip_2.setPixelColor(l, 0, greenStates2[l], blueStates2[l]);

      if (greenStates2[l] > 1) {
        greenStates2[l] = greenStates2[l] * fadeRate;
      } else {
        greenStates2[l] = 0;
      }

      if (blueStates2[l] > 1) {
        blueStates2[l] = blueStates2[l] * fadeRate;
      } else {
        blueStates2[l] = 0;
      }

    } else {
      strip_2.setPixelColor(l, 0, 0, 0);
    }
  }

    for (uint16_t l = 0; l < Pixels_3; l++) {
    if (greenStates3[l] > 1 || blueStates3[l] > 1) {
      strip_3.setPixelColor(l, 0, greenStates3[l], blueStates3[l]);

      if (greenStates3[l] > 1) {
        greenStates3[l] = greenStates3[l] * fadeRate;
      } else {
        greenStates3[l] = 0;
      }

      if (blueStates3[l] > 1) {
        blueStates3[l] = blueStates3[l] * fadeRate;
      } else {
        blueStates3[l] = 0;
      }

    } else {
      strip_3.setPixelColor(l, 0, 0, 0);
    }
  }

    for (uint16_t l = 0; l < Pixels_4; l++) {
    if (greenStates4[l] > 1 || blueStates4[l] > 1) {
      strip_4.setPixelColor(l, 0, greenStates4[l], blueStates4[l]);

      if (greenStates4[l] > 1) {
        greenStates4[l] = greenStates4[l] * fadeRate;
      } else {
        greenStates4[l] = 0;
      }

      if (blueStates4[l] > 1) {
        blueStates4[l] = blueStates4[l] * fadeRate;
      } else {
        blueStates4[l] = 0;
      }

    } else {
      strip_4.setPixelColor(l, 0, 0, 0);
    }
  }

  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();

  delay(1);

}

