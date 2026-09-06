/*!
 * @file        rgbCtrl.ino
 * @brief       this demo demonstrates how to use RGB
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;

/*Uncheck any of the comments below to see the effect*/
// #define SHOW_RGBSET
// #define SHOW_RGBBLINK
#define SHOW_RGBCHANGE

uint8_t temp[1]={0};

void setup() {
  myCosmo.begin();
  #ifdef  SHOW_RGBBLINK
    myCosmo.rgbBlink(eRgbLeft,5,3,eRgbGreen); // The left light flashes green five times at speed is 3
    myCosmo.rgbBlink(eRgbRight,5,3,eRgbPurple);// The right light flashes purple five times at speed is 3
  #endif
  #ifdef  SHOW_RGBCHANGE
    myCosmo.rgbGradualChange(eRgbLeft,3);   //Do the light gradient at speed 3
    myCosmo.rgbGradualChange(eRgbRight,3);  //Do the light gradient at speed 3  
  #endif
}
 
void loop() {
  #ifdef  SHOW_RGBSET
    myCosmo.rgbSet(eRgbLeft,eRgbRed);
    myCosmo.rgbSet(eRgbRight,eRgbRed);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbGreen);
    myCosmo.rgbSet(eRgbRight,eRgbGreen);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbYellow);
    myCosmo.rgbSet(eRgbRight,eRgbYellow);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbBlue);
    myCosmo.rgbSet(eRgbRight,eRgbBlue);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbPurple);
    myCosmo.rgbSet(eRgbRight,eRgbPurple);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbCyan);
    myCosmo.rgbSet(eRgbRight,eRgbCyan);
    delay(1000);
    myCosmo.rgbSet(eRgbLeft,eRgbWhite);
    myCosmo.rgbSet(eRgbRight,eRgbWhite);
    delay(1000);
    myCosmo.rgbSetOff(eRgbLeft);
    myCosmo.rgbSetOff(eRgbRight);
    delay(1000);
  #endif
}