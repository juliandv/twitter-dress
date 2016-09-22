// Twitter tweet Arduino communication by:
// Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
// https://github.com/amicojeko

/**
 * Neopixel Library
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
/**
 * Twitter Library
 */
#include <Bridge.h>
#include <Process.h>

/**
 * Neopixel Variables
 */
#define Pixels 15

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(Pixels, 1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(Pixels, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(Pixels, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(Pixels, 4, NEO_GRB + NEO_KHZ800);

float blueStates[Pixels];
float greenStates[Pixels];
float fadeRate = 0.96;

/**
 * Twitter Variables
 */
const String SCRIPT_DIR = "/root/python/TwitterBlink/";    //Set folder directory of python scripts
const String python_command = "/usr/bin/python " + SCRIPT_DIR + "streaming.py";
const String kill_command = SCRIPT_DIR + "kill_processes.sh";

Process p;

char go_buffer[2];
// still not sure if I should have used a bool instead
// with int I can handle more states
int  go = 0;

/**
 * General Variables
 */
int phase;

const int PIN_PHASE_1 = 5;         //Phase 1 - Constant Twinkle switch pin
const int PIN_PHASE_2 = 6;         //Phase 2 - Twitter switch pin
const int PIN_PHASE_3 = 7;         //Phase 3 - Off pin

void setup() {

  pinMode(PIN_PHASE_1, INPUT);
  pinMode(PIN_PHASE_2, INPUT);
  pinMode(PIN_PHASE_3, INPUT);

  phase = 3;                      //Start with lights off/phase 3

  strip_1.begin();
  strip_1.show();

  strip_2.begin();
  strip_2.show();

  strip_3.begin();
  strip_3.show();

  strip_4.begin();
  strip_4.show();


  for (uint16_t l = 0; l < Pixels; l++) {
    greenStates[l] = 0;
    blueStates[l] = 0;
  }

  Bridge.begin(); // Initialize the Bridge Library
  p.runShellCommand(kill_command);   // Kill all running python scripts if any
  p.runShellCommandAsynchronously(python_command);
}

void loop() {

  checkSwitches();     //Check which phase is switched on
  switchPhases();      //Execute phase
}

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


