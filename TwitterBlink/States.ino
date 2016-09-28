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
      twinkle();
      break;
    case 2: //Twitter
      //Read the "go" Bridge var and copies it into the go_buffer variable
      Bridge.get("go", go_buffer, 2);

      //Convert the bugger into an int variable (should I have used bool instead?)
      go = atoi(go_buffer);

      if (go == 1) {

        // get current time since startup
        unsigned long currentMillis = millis();
        // loop twinkle code for twinkleLength mills
        if (currentMillis <= currentMillis + twinkleLength) {
            twinkle();
        }
        Bridge.put("go", String(0));   // reset the new tweet 'go' variable to 0
      } else {
        delay(30); // or else wait a bit then check if there is a new tweet
      }
      break;
    case 3: //Off
      // Do nothing
      break;
  }
}
