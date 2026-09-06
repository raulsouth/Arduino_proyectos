/*!
 * @file        motorCtrl.ino
 * @brief       this demo demonstrates how to control motor of Cosmo .
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
  myCosmo.motorSet(eMotorLeft,eMotorForward,100);
  myCosmo.motorSet(eMotorRight,eMotorForward,100);
  delay(1000);
  myCosmo.motorSet(eMotorAll,eMotorForward,0);
  delay(100);
  myCosmo.motorSet(eMotorLeft,eMotorForward,100);
  myCosmo.motorSet(eMotorRight,eMotorReverse,100);
  delay(300);
  myCosmo.motorSet(eMotorAll,eMotorForward,0);
  delay(100);
}