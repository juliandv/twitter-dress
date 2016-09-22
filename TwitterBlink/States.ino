/**
 * Checks pin connection as switch and changes phases accordingly
 */
void checkSwitches() {

    if ( PIN_PHASE_1 == HIGH ) {     //If connection is made, switch phases
    phase = 1;  //Constant twinkle
  }

  if ( PIN_PHASE_2 == HIGH ) {
    phase = 2;  //Twitter
  }

  if ( PIN_PHASE_3 == HIGH ) {
    phase = 3;  //Off
  }
}

/**
 * Takes number of phase and executes
 */
void switchPhases() {

    switch ( phase )
  {
    case 1: //Constant Twinkle
      constantTwinkle();
    break;
    case 2: //Twitter
      //Read the "go" Bridge var and copies it into the go_buffer variable
      Bridge.get("go", go_buffer, 2);

      //Convert the bugger into an int variable (should I have used bool instead?)
      go = atoi(go_buffer);

      if (go == 1) {
        newTweet();
      } else {
        delay(50);
      }
      break;
      case 3: //Off
      //Do nothing
      break;
  }
}
