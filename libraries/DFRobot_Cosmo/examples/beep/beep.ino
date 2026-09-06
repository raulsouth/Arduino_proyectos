/*!
 * @file        beep.ino
 * @brief       this demo demonstrates how to drive the buzzer to play a piece of music
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#define NOTE_C4  261
#define NOTE_D4  293
#define NOTE_E4  329
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  493
#define NOTE_REST 0


#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;

float melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_C4,NOTE_D4,NOTE_E4,NOTE_REST
};
 
uint16_t noteDuration = 300; // Control the duration of MusicalNotes.

void setup() {
  myCosmo.begin(); 
}
 
void loop() {
  for (uint16_t i = 0; i < (uint16_t)sizeof(melody) / sizeof(melody[0]); i++) {
    if (melody[i] == NOTE_REST) {
      delay(noteDuration);
    } else {
      myCosmo.tone(COSMO_BEEP_PIN, melody[i], noteDuration);
    }
  }
}