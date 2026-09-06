/*!
 * @file        getLight.ino
 * @brief       this demo demonstrates how to get light data
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
int data = 0;


void setup() {
  myCosmo.begin();
}
 
void loop() {
  Serial.print("  Left Light:");
  data=myCosmo.getLight(eLightLeft);
  Serial.print(data);
  Serial.print("  Right Light:");
  data=myCosmo.getLight(eLightRight);
  Serial.println(data);
  delay(100);
}