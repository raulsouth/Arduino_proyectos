# DFRobot_Cosmo
- [中文版](./README_CN.md)

Cosmo is a STEAM educational robot based on Arduino .

![effect picture](./resources/images/DFRobot_Cosmo-1.png) 

## Product Link(https://www.dfrobot.com/)

## Table of Contents

* [Summary](#Summary)
* [Installation](#Installation)
* [Methods](#Methods)
* [Compatibility](#Compatibility)
* [History](#History)
* [Credits](#Credits)

## Summary

  * This library provides the implementation methods for all functions of Cosmo, such as controlling motors, receiving Bluetooth commands, controlling WS2812, controlling RGB, obtaining light intensity, checking battery level, retrieving infrared sensor information, and gathering information from  patrol sensor, among others.

## Installation
Here's one way to use this library:
1. First download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo inside that folder.


## Methods

```C++
  /**
   * @fn begin
   * @brief subclass initialization function
   * @return bool type, means returning initialization status
   * @retval true is success
   * @retval false is false
   */
  int begin(void);
  /**
   * @fn I2CWirte
   * @brief Write register function
   * @param Reg  Register address 8bits
   * @param data data to be written
   * @return None
   */
  void I2CWirte(uint8_t Reg ,uint8_t data);
  /**
   * @fn I2CRead
   * @brief Read register function
   * @param reg  Register address 8bits
   * @param data Storage and buffer for data to be read
   * @param datalen Length of data to be read
   * @return None
   */
  void I2CRead(uint8_t Reg ,uint8_t *data ,uint8_t datalen);
  /**
   * @fn servoMotorCtrl
   * @brief Ctrl the Servomotor
   * @param servoMotorPin  pin of Servomotor
   * @n Optional pin：D3 D6 D9 D10
   * @param angle  0 to 180
   * @return None
   */
  void servoMotorCtrl( uint8_t servoMotorPin,uint8_t angle);
  /**
   * @fn ws2812Set
   * @brief Setting color of the Ws2812
   * @param satrNum  star num
   * @n The value ranges from RGB0 to RGB3 and cannot be larger than the end position
   * @param endNum  end num
   * @n The value ranges from RGB0 to RGB3 and cannot be Less  than the star position
   * @param R  0-255
   * @param G  0-255
   * @param B  0-255
   * @return None
   */
  void ws2812Set(uint8_t satrNum,uint8_t endNum,uint8_t R,uint8_t G,uint8_t B);
  /**
   * @fn blinkLed
   * @brief Turn on/off led
   * @param cmd  Turn on:eBlinkOn   Turn off:eBlinkOff
   * @return None
   */
  void blinkLed(eBlinkTurn_t cmd);
  /**
   * @fn rgbSet
   * @brief Set color of the RGB
   * @param rgb  eRgbLeft or eRgbRight or eRgbAll
   * @param cmd  color:eRGBCmd_t
   * @n RGB_R  
   * @n RRGB_G 
   * @n RRGB_B  
   * @n RRGB_RB 
   * @n RRGB_RG 
   * @n RRGB_GB 
   * @n RRGB_RGB
   * @n RRGB_OFF
   * @return None
   */
  void rgbSet(eRgbSelect_t rgb,eRgbCmd_t cmd);
  /**
   * @fn rgbSetOff
   * @brief Close all rgb 
   * @param rgb  eRgbLeft or eRgbRight or eRgbAll
   * @return None
   */
  void rgbSetOff(eRgbSelect_t rgb)
  /**
   * @fn rgbGradualChange
   * @brief rgb Color gradient
   * @param rgb  eRgbLeft or eRgbRight or eRgbAll
   * @param Grade   Grade 1-5
   * @return None
   */
void rgbGradualChange(eRgbSelect_t rgb,uint8_t Grade);
  /**
   * @fn rgbBlink
   * @brief rgb colors flash
   * @param rgb  eRgbLeft or eRgbRight or eRgbAll
   * @param num  number of flash ：0-255
   * @param Grade number of Grade 1-5
   * @param cmd The colors are selected from the enumeration eRgbCmd t
   * @return None
   */
void rgbBlink(eRgbSelect_t rgb,uint8_t num,uint8_t Grade,eRgbCmd_t cmd);
  /**
   * @fn readPatrol
   * @brief Read the status of the Line patrol sensor
   * @param num   Line patrol sensor num: one of ePatrolNum_t
   * @return bright-off:0 bright-on:1
   */
  uint8_t readPatrol(ePatrolNum_t num);
  /**
   * @fn readPatrolVoltage
   * @brief Read the voltage of the Line patrol sensor
   * @param num    Line patrol sensor num: one of ePatrolNum_t
   * @return voltage :0-4095
   */
  uint16_t readPatrolVoltage(ePatrolNum_t num);
  /**
   * @fn getLight
   * @brief Acquisition of light intensity
   * @param cmd  light sensor:  eLightLeft or eLightRight
   * @return light data :0-1023
   */
  uint16_t getLight(eLightSelect_t cmd);
  /**
   * @fn getURM10
   * @brief Acquisition distance,  unit is cm
   * @return Distance data :-1-300 cm Timeout or Error: -1
   */
  float getURM10(void);
  /**
   * @fn IRReceiveEnable
   * @brief Enable infrared received 
   * @return None
   */
  void IRReceiveEnable(void);
  /**
   * @fn IRReceive
   * @brief Obtain infrared received data
   * @return Received data：0-255
   */
  uint8_t IRReceive(void);
  /**
   * @fn getBatteryData
   * @brief Obtain the remaining battery power
   * @param num  Lithium-ion battery: eLithium  Alkaline battery: eAlkaline
   * @return battery power：0-100
   */
  uint8_t getBatteryData(eBatteryType_t type);
  /**
   * @fn getVersion
   * @brief Get the Version of Cosmo.
   * @return version
   */
  String getVersion(void);
  /**
   * @fn lineTraking
   * @brief  Stop line patrol or Start line patrol
   * @param cmd  Stop line patrol: eTrakingOff  Start line patrol: eTrakingOn
   * @return 
   */
  void lineTraking(eTrakingTurn_t cmd);
   /**
   * @fn getCross
   * @brief Get the type of Cross road
   * @return type of Cross road
   * @retval 1：eStateCrossing    2：eStateLeftRight   3：eStateLeftStright   4：eStateRightStright
   */
  uint8_t getCross(void);
  /**
   * @fn setCross
   * @brief Setting the action for this intersectiond
   * @param crossId  type of Cross road
   * @param cmd  Action command  
   * @n eTurnLeft , eTurnRight , eTurnStright,eTurnStop  
   * @return 
   */
  void setCross(eCross_t crossId,eTurnCmd_t cmd);
  /**
   * @fn motorSet
   * @brief Setting motor parameters 
   * @param motor  Left motor: eMotorLeft, Right motor: eMotorRight All:eMotorAll
   * @param Dir  Forward turning: eMotorForward backward turning:eMotorReverse
   * @param speed  0-255
   * @return 
   */
  void motorSet(eMotorSelect_t motor,eDirection_t Dir,uint8_t speed);
  /**
   * @fn motorStop
   * @brief Stop motor operation
   * @param motor   Left motor: eMotorLeft, Right motor: eMotorRight All:eMotorAll
   * @return 
   */
  void motorStop(eMotorSelect_t motor);
  /**
   * @fn motorTypeSet
   * @brief Set the type of motor 
   * @return 
   */
  void motorTypeSet(uint16_t type);
  /**
   * @fn tone
   * @brief Instead of Arduino's own tone function to drive the buzzer
   * @param tonePin   beep pin
   * @param frequency  frequency of beep
   * @param duration   duration  of beep
   * @return 
   */
  void tone(u8 tonePin, int frequency, int duration);

```

## Compatibility

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |
## History

- 2024/10/16 - Version 1.0.0 released.

## Credits

Written by lr(rong.li@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))
