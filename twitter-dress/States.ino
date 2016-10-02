/**
   Checks pin connection as switch and changes phases accordingly
*/
void checkSwitches() {
  // read buttons
  button1 = digitalRead(PHASE_1_BTN);
  button2 = digitalRead(PHASE_2_BTN);


  // if switch 2 is connected
  if ( button2 == LOW ) {
    phase = 3;
    //Off
  } else {
    // if switch 1 is connected
    if ( button1 == LOW ) {
      //If connection is made, switch phases
      phase = 1;
      //Constant twinkle
    } else {
      phase = 2;
      //Twitter

    }
  }
}

/**
   Takes number of phase and executes
*/
void switchPhases() {

  switch ( phase )
  {
    case 1: //Constant Twinkle
      Serial.println("CONSTANT TWINKLE STATE");

      constantTwinkle();
      break;
    case 2: //Twitter
      Serial.println("TWITTER STATE");

      //Read the "go" Bridge var and copies it into the go_buffer variable
      Bridge.get("go", go_buffer, 2);
      //Convert the bugger into an int variable (should I have used bool instead?)
      go = atoi(go_buffer);

      if (go == 1) {
//        digitalWrite(LED_BUILTIN, HIGH);
        // get current time since startup
        unsigned long currentMillis = millis();
        unsigned long twinkleUntil = currentMillis + twinkleLength;
        Serial.println(currentMillis);
        // loop twinkle code for twinkleLength mills
        while (currentMillis <= twinkleUntil) {
          Serial.println("New tweet! Twinkle...");
          twinkle();
          currentMillis = millis();
        }

        turnPixelsOff();
//        digitalWrite(LED_BUILTIN, LOW);
        Bridge.put("go", String(0));   // reset the new tweet 'go' variable to 0

      } else {
        delay(40); // or else wait a bit then check if there is a new tweet
      }
      break;
    case 3: //Off
      Serial.println("OFF STATE");
      // Do nothing
      delay(10);
      break;
  }
}

void colorWipe1(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip_1.numPixels(); i++) {
    strip_1.setPixelColor(i, c);
    strip_1.show();
  }
}
void colorWipe2(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip_2.numPixels(); i++) {
    strip_2.setPixelColor(i, c);
    strip_2.show();
  }
}
void colorWipe3(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip_3.numPixels(); i++) {
    strip_3.setPixelColor(i, c);
    strip_3.show();
  }
}
void colorWipe4(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip_4.numPixels(); i++) {
    strip_4.setPixelColor(i, c);
    strip_4.show();
  }
}
