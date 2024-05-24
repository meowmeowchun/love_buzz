/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"
const int  BUTTON_PIN = 9;
int buttonState = 0;
// notes in the melody:
int melody[] = {
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
  16, 16, 8, 8, 16, 16, 16, 16, 16, 8, 16, 16, 16,
};

int melody2[] = {
  NOTE_F4, NOTE_F4, NOTE_F4, 0, NOTE_F4, 0, NOTE_F4, NOTE_D4, 0, NOTE_D4,
  NOTE_F4, NOTE_F4, NOTE_F4, 0, NOTE_G4, 0, NOTE_GS4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_F4, NOTE_G4, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations2[] = {
  8, 16, 16, 16, 16, 16, 8, 16, 16 ,3.2,
  8, 16, 16, 16, 16, 16, 8, 32, 32, 16, 16, 16, 16, 8 
};

void setup() {

  pinMode(9, INPUT_PULLUP);
  // iterate over the notes of the melody:

}

void loop() {
buttonState = digitalRead(BUTTON_PIN);
if(buttonState == 1){
  for (int thisNote = 0; thisNote < 105; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1500 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }}

  else {
    for (int thisNote = 0; thisNote < 25; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 1500 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration2 * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    
    }
  }}
