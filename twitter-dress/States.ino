/**
   Checks pin connection as switch and changes phases accordingly
*/
void checkSwitches() {
  phase1  = digitalRead(PHASE_1_BTN);
  // read buttons
  phase2 = digitalRead(PHASE_2_BTN);

  if ( phase1 == LOW ) {
    //If connection is made, switch phases
    phase = 1;
    //Constant twinkle
  }

  if ( phase1 == HIGH ) {
    phase = 2;
    //Twitter
  }

  if ( phase2 == LOW ) {
    phase = 3;
    //Off
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

      twinkle();
      break;
    case 2: //Twitter
      Serial.println("TWITTER STATE");

      //Read the "go" Bridge var and copies it into the go_buffer variable
      Bridge.get("go", go_buffer, 2);
      //Convert the bugger into an int variable (should I have used bool instead?)
      go = atoi(go_buffer);

      if (go == 1) {

        // get current time since startup
        unsigned long currentMillis = millis();
        unsigned long twinkleUntil = currentMillis + twinkleLength;
        Serial.println(currentMillis);
        // loop twinkle code for twinkleLength mills
        while(currentMillis <= twinkleUntil) {
            Serial.println("New tweet! Twinkle...");
            twinkle();
            currentMillis = millis();
        }
          strip_1.show();
          strip_2.show();
          strip_3.show();
          strip_4.show();
        Bridge.put("go", String(0));   // reset the new tweet 'go' variable to 0
      } else {
        delay(30); // or else wait a bit then check if there is a new tweet
      }
      break;
    case 3: //Off
      Serial.println("OFF STATE");
      // Do nothing
      delay(10);
      break;
  }
}
