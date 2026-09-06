/*!
 * @file        getPatrolSensor.ino
 * @brief       this demo demonstrates how to get LineWalkingSensor data
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;


 /*After unchecking any of the comments below, view the effect through the serial port*/
#define SHOW_READPATROL
// #define SHOW_READPATROLVOLTAGE

void setup() {
  myCosmo.begin();
}
 
void loop() {
  int data =0;
  #ifdef SHOW_READPATROL
    Serial.print("  L2:");
    data=myCosmo.readPatrol(eL2);
    Serial.print(data);
    Serial.print("  L1:");
    data=myCosmo.readPatrol(eL1);
    Serial.print(data);
    Serial.print("  M:");
    data=myCosmo.readPatrol(eM);
    Serial.print(data);
    Serial.print("  R1:");
    data=myCosmo.readPatrol(eR1);
    Serial.print(data);
    Serial.print("  R2:");
    data=myCosmo.readPatrol(eR2);
    Serial.println(data);
    delay(500);
  #endif

  #ifdef SHOW_READPATROLVOLTAGE
    Serial.print("  L2:");
    data=myCosmo.readPatrolVoltage(eL2);
    Serial.print(data);
    Serial.print("  L1:");
    data=myCosmo.readPatrolVoltage(eL1);
    Serial.print(data);
    Serial.print("  M:");
    data=myCosmo.readPatrolVoltage(eM);
    Serial.print(data);
    Serial.print("  R1:");
    data=myCosmo.readPatrolVoltage(eR1);
    Serial.print(data);
    Serial.print("  R2:");
    data=myCosmo.readPatrolVoltage(eR2);
    Serial.println(data);
    delay(500); 
  #endif
}