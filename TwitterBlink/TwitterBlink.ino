// Twitter tweet Arduino communication by:
// Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
// https://github.com/amicojeko

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


// BEGIN NEOPIXEL CODE
#define PIN 6
#define NUM_LEDS 4
#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
int gamma[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
  10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
  17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
  37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
  51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
  69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
  90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
  115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
  144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
  177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
  215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

// END NEOPIXEL


#include <Bridge.h>
#include <Process.h>

const int led    = 13; // LED Pin 13
const int buzzer = 9;  // buzzer to arduino pin 9

// set folder directory of python scripts
const String SCRIPT_DIR = "/root/python/TwitterBlink/";

const String python_command = "/usr/bin/python " + SCRIPT_DIR + "streaming.py";
const String kill_command = SCRIPT_DIR + "kill_processes.sh";
Process p;

char go_buffer[2];
// still not sure if I should have used a bool instead
// btw with int I can handle more states
int  go = 0;

void setup() {

  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  // hardware initialization
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Bridge.begin(); // Initialize the Bridge Library

  p.runShellCommand(kill_command);   // Kill all running python scripts if any

  p.runShellCommandAsynchronously(python_command);
}

void loop() {
  // read the "go" Bridge var and copies it into the go_buffer variable
  Bridge.get("go", go_buffer, 2);

  // convert the bugger into an int variable (should I have used bool instead?)
  go = atoi(go_buffer);

  if (go == 1) {
    newTweet();
  } else {
    delay(50);
  }

}
