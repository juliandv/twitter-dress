// Twitter tweet Arduino communication by:
// Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
// https://github.com/amicojeko

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
  // hardware initialization: Either keep this or replace it with
  // your actual hardware configuration (i.e. servo)
pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
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

  if (go == 1){
    newTweet();
  } else {
    delay(50);
  }

}
