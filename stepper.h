// Define stepper pins

int driverPUL = 5;    // PUL- pin
int driverDIR = 4;    // DIR- pin

// Variables

int pd = 5000;       // Pulse Delay period for stepper - this sets the speed. Low numbers are fast
boolean setdir = HIGH; // Set Direction

unsigned long previousMicros = 0;
unsigned long interval = 30000;
int stepperCount = 0; // count how many steps we've stepped on the motor
int pulseRev = 400; // pulses per rev
boolean motorState = HIGH;

void initStepper() {
    pinMode (driverPUL, OUTPUT);
    pinMode (driverDIR, OUTPUT);
}

void turnTree(){
  if(playSdWav1.isPlaying() == true){
    unsigned long currentMicros = micros();
    if(currentMicros - previousMicros > interval) {
      // save the last time stepped
      previousMicros = currentMicros;
      digitalWrite(driverDIR,setdir);
      digitalWrite(driverPUL,motorState);
      motorState = !motorState;
      if(stepperCount < pulseRev*2){ // this is times 2 because we need to call this twice per step, once on, and once off
        stepperCount = stepperCount+1;
      }else{
        stepperCount = 0;
        //setdir = !setdir;
      }
    }
  }
}
