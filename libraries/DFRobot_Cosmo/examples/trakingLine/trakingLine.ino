/*!
 * @file        trakingLine.ino
 * @brief       this demo demonstrates how to make Cosmo to perform the operations of tracking and judging intersections
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [lr](rong.li@dfrobot.com)
 * @version     V1.0
 * @date        2024-10-16
 * @url         https://github.com/DFRobot/DFRobot_Cosmo
 */
#include <DFRobot_Cosmo.h>
DFRobot_Cosmo myCosmo;
uint32_t state=0;
/*If you need to judge the crossing, please uncomment below*/
#define JUDEGE_CROSS

void setup() {
  myCosmo.begin();
  myCosmo.getVersion();
  myCosmo.motorTypeSet(266);//Select motor type：266 rpm
  myCosmo.lineTraking(eTrakingOn);//Start of patrol
}
 

void loop() {
  /*If Cosmo reaches a junction, it is executed according to the command written by the user*/
  #ifdef JUDEGE_CROSS
  state=myCosmo.getCross();
  if(state==eStateCrossing ){
    myCosmo.setCross((eCross_t )state,eTurnRight); 
  }else if(state==eStateLeftRight){
    myCosmo.setCross((eCross_t )state,eTurnLeft);
  }else if(state==eStateLeftStright){
    myCosmo.setCross((eCross_t )state,eTurnLeft);
  }else if(state==eStateRightStright){
    myCosmo.setCross((eCross_t )state,eTurnRight);
  }
  #endif
  /*The real-time requirement of intersection identification is high, please print the serial port at the end*/
  if(state){Serial.println(state);}//Serial port printing
}