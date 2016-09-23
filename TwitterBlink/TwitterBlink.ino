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

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(Pixels, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(Pixels, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(Pixels, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(Pixels, 8, NEO_GRB + NEO_KHZ800);

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
int phase = 1;  //Start with constant twinkle

const int PHASE_1_BTN = 5;         //Phase 1 - Constant Twinkle and Twitter switch pin
const int PHASE_2_BTN = 6;     //Phase 2 - Off
int phase1;
int phase2;

void setup() {

    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(PHASE_1_BTN, INPUT_PULLUP);
  pinMode(PHASE_2_BTN, INPUT_PULLUP);

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

//  checkSwitches();     //Check which phase is switched on
  switchPhases();      //Execute phase
}


