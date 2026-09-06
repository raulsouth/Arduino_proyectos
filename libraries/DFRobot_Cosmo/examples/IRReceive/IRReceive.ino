/*!myCosmo
 * @file        IRReceive.ino
 * @brief       this demo demonstrates how to get Infrared sensor information
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
uint8_t data=0;

void setup() {
    myCosmo.begin();
    myCosmo.IRReceiveEnable();//init IR
}
 
void loop() {
  data=myCosmo.IRReceive();
  if(data){
    Serial.println(data);
  }
}