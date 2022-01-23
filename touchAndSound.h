int touchState[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int prevTouchState[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int wavArray[] = {"TRACK1.WAV", "TRACK2.WAV", "TRACK3.WAV", "TRACK4.WAV", "TRACK5.WAV", "TRACK6.WAV", "TRACK7.WAV", "TRACK8.WAV", "TRACK9.WAV", "TRACK10.WAV", "TRACK11.WAV", "TRACK12.WAV", "TRACK13.WAV", "TRACK14.WAV", "TRACK15.WAV", "TRACK16.WAV", "TRACK17.WAV", "TRACK18.WAV", "TRACK19.WAV", "TRACK20.WAV", "TRACK21.WAV", "TRACK22.WAV", "TRACK23.WAV", "TRACK24.WAV", "TRACK25.WAV", "TRACK26.WAV", "TRACK27.WAV", "TRACK28.WAV", "TRACK29.WAV", "TRACK30.WAV"};
int lastTouched = -1;

void checkTouch() {
    currtouched1 = mprBoard_A.touched();
    currtouched2 = mprBoard_B.touched();
    currtouched3 = mprBoard_C.touched();

    for (uint8_t i=0; i<12; i++) {
        //For A----------------------------------------------------------
        if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
        touchState[i] = 1;
        }
        if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
        touchState[i] = 0;
        }
        //For B----------------------------------------------------------
        if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
        touchState[i+10] = 1;
        }
        if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
        touchState[i+10] = 0;
        }
        //For C----------------------------------------------------------
        if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
        touchState[i+20] = 1;
        }
        if (!(currtouched3 & _BV(i)) && (lasttouched3 & _BV(i)) ) {
        touchState[i+20] = 0;
        }
    }
    lasttouched1 = currtouched1;
    lasttouched2 = currtouched2;
    lasttouched3 = currtouched3;
}

void playSound() {
  int knob = analogRead(volumePin); // knob = 0 to 1023
  float gain = (float)knob / 1023.0;
  sgtl5000_1.volume(gain);
  for(int i = 0; i < 30; i++){
    if(touchState[i] != prevTouchState[i]){
      prevTouchState[i] = touchState[i];
      Serial.print("button ");
      Serial.print(i);
      if(touchState[i] == 1){
        Serial.println(" touched");
        playSdWav1.play(wavArray[i]); // filenames are always uppercase 8.3 format
        lastTouched = i;
      }else{
        Serial.println(" released");
        if(i == lastTouched){
          //playSdWav1.stop();
        }
      }
    }
  }
}
