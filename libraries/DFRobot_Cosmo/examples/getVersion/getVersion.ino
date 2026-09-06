/*!
 * @file        getVersion.ino
 * @brief       this demo demonstrates how to get version
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
//Baud rate:115200

void setup() {
  myCosmo.begin();
}
 
void loop() {
  String version =myCosmo.getVersion();
  Serial.println(version);
  delay(1000);
}