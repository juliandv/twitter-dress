// Twitter tweet Arduino/linux communication by:
// Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
// https://github.com/amicojeko


// TO START:
// power Arduino Yun
// wait 1-2 minutes for linux to boot and WiFi to connect (presuming previosuly connected WiFi is available)
// restart the arduino side by double tapping the 32U4 button twice
// after about 15 seconds, the streaming connection should be active and tweets will trigger the Neopixels

/**
 * Neopixel Library
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
/**
 * Bridge Library
 */
#include <Bridge.h>
#include <Process.h>

/**
 * Neopixel Variables
 */
#define Pixels_1 9
#define Pixels_2 15
#define Pixels_3 14
#define Pixels_4 8

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(Pixels_1, 8,  NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(Pixels_2, 9,  NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(Pixels_3, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(Pixels_4, 11, NEO_GRB + NEO_KHZ800);

float blueStates1[Pixels_1];
float greenStates1[Pixels_1];

float blueStates2[Pixels_2];
float greenStates2[Pixels_2];

float blueStates3[Pixels_3];
float greenStates3[Pixels_3];

float blueStates4[Pixels_4];
float greenStates4[Pixels_4];

float fadeRate = 0.96;

/**
 * Linino Python directories
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
int phase = 1;
// constant = 1;
// twitter = 2;

const int twinkleLength = 2000; //Twinkle length
//const int PHASE_1_BTN = 12;     //Phase 1 - Constant Twinkle and Twitter switch pin
//const int PHASE_2_BTN = 2;      //Phase 2 - Off
//int button1;
//int button2;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("BEGIN SERIAL");
  pinMode(LED_BUILTIN, OUTPUT);

  strip_1.begin();
  strip_1.show();

  strip_2.begin();
  strip_2.show();

  strip_3.begin();
  strip_3.show();

  strip_4.begin();
  strip_4.show();

turnPixelsOff();

//  Bridge.begin(); // Initialize the Bridge Library
//  p.runShellCommand(kill_command);   // Kill all running python scripts if any
//  p.runShellCommandAsynchronously(python_command);


  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  switchPhases();      //Execute phase
}


