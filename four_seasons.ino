/*
Four Seasons code for Teensy 4

gawainhewitt.co.uk
https://github.com/gawainhewitt
*/

#include "mpr121.h"
#include "wavFilePlayer.h"
#include "reboot.h"
#include "stepper.h"
#include "constants.h"
#include "touchAndSound.h"

void setup() {
  Serial.begin(9600);
  init_mpr121();
  init_player();
  initReboot();
  initStepper();
}

void loop() {

  if(digitalRead(rebootButton) == LOW){
    doReboot();
  }

  checkTouch();

  playSound();

  turnTree();
}
