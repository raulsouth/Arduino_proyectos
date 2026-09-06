/*!
 * @file        getBatteryData.ino
 * @brief       this demo demonstrates how to get data of battery 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
int data ;
void setup() {
  myCosmo.begin();
}
 
void loop() {
  data=myCosmo.getBatteryData(eLithium);// Lithium battery or Alkaline battery
  Serial.print("BatteryData: ");
  Serial.print(data);
  Serial.println("% ");
  delay(1000);
}