/*!
 * @file        blinkLed.ino
 * @brief       this demo demonstrates how to blink led
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;

void setup() {
  myCosmo.begin();
}
 
void loop() {
  myCosmo.blinkLed(eBlinkOn);
  delay(500);
  myCosmo.blinkLed(eBlinkOff);
  delay(500);
}