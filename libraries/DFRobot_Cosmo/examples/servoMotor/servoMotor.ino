/*!myCosmo
 * @file        servoMotor.ino
 * @brief       this demo demonstrates how to make Cosmo to control servo motor
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <Arduino.h>
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;

void setup() {
  myCosmo.begin();
}
 
/*D3 D6 D9 D10*/
void loop() {
  myCosmo.servoMotorCtrl(3,20);               // tell servo to go to position in variable 'pos' 
  myCosmo.servoMotorCtrl(6,20);               // tell servo to go to position in variable 'pos'
  myCosmo.servoMotorCtrl(9,20);               // tell servo to go to position in variable 'pos'
  myCosmo.servoMotorCtrl(10,20);              // tell servo to go to position in variable 'pos'
  delay(1000);                                 // waits 1000ms for the servo to reach the position
  myCosmo.servoMotorCtrl(3,90);               // tell servo to go to position in variable 'pos'
  myCosmo.servoMotorCtrl(6,90);               // tell servo to go to position in variable 'pos'
  myCosmo.servoMotorCtrl(9,90);               // tell servo to go to position in variable 'pos'
  myCosmo.servoMotorCtrl(10,90);              // tell servo to go to position in variable 'pos'
  delay(1000);                                 // waits 1000ms for the servo to reach the position
}