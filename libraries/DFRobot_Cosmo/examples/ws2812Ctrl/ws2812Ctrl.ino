/*!
 * @file        ws2812Ctrl.ino
 * @brief       this demo demonstrates how to use ws2812
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
/*
satrNum – star num The value ranges from 0 to 3 and cannot be larger than the end position
endNum – end num The value ranges from 0 to 3 and cannot be Less than the star position
R – 0-255
G – 0-255
B – 0-255
*/
void setup() {
  myCosmo.begin();
  myCosmo.ws2812Set(0,0,100,0,0);//red
  myCosmo.ws2812Set(1,1,0,100,0);//green
  myCosmo.ws2812Set(2,2,0,0,100);//blue
  myCosmo.ws2812Set(3,3,100,100,100);//white
  delay(5000);// wait 5s
}
 
void loop() {
  myCosmo.ws2812Set(0,3,100,0,0);
  delay(1000);
  myCosmo.ws2812Set(0,3,0,100,0);
  delay(1000);
  myCosmo.ws2812Set(0,3,0,0,100);
  delay(1000);
}