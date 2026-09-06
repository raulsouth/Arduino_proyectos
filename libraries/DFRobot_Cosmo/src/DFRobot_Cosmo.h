#ifndef __DFROBOT_COSMO_H_
#define __DFROBOT_COSMO_H_

#include "Wire.h"
#include "Servo.h"
#include "Cosmo_URM10/Cosmo_URM10.h"
#include "Cosmo_Ws2812/Cosmo_Ws2812.h"
#include "Cosmo_IRremote/Cosmo_IRremote.h"


// #define BLE_EN //enable BLE 

#define COSMO_BEEP_PIN 11
#define COSMO_LED_PIN  13

/**
 * @enum eBLEModule_t
 * @brief module on or off
 */
typedef enum {
  eenable =1,       /**< enable */ 
  edisable =0,       /**< disable*/
}eBLEModule_t;
/**
 * @enum eCross_t
 * @brief Crossing
 */
typedef enum {
  eStateCrossing =1,       /**< a crossroads */ 
  eStateLeftRight =2,     /**< a T-junction where you can only turn left or right */ 
  eStateLeftStright=3,    /**< a T-intersection that can only turn left or go straight */ 
  eStateRightStright=4    /**< a T-intersection that can only turn right or go straight */ 
}eCross_t;

/**
 * @enum eRgbSelect_t
 * @brief Right and Left and All
 */
typedef enum {
  eRgbLeft = 0,     /**< LEFT */ 
  eRgbRight = 1,    /**< RIGHT */ 
  eRgbAll = 2,      /**< ALL */ 
}eRgbSelect_t;

/**
 * @enum eMotorSelect_t
 * @brief Right and Left and All
 */
typedef enum {
  eMotorLeft = 0,     /**< LEFT */ 
  eMotorRight = 1,    /**< RIGHT */ 
  eMotorAll = 2,      /**< ALL */ 
}eMotorSelect_t;

/**
 * @enum eBLINKTurn_t
 * @brief turn on or turn off
 */
typedef enum {
  eBlinkOn = 1,     /**< ON */ 
  eBlinkOff = 0,    /**< OFF */ 
}eBlinkTurn_t;

/**
 * @enum eMotorTurn_t
 * @brief turn on or turn off
 */
typedef enum {
  eMotorOn = 1,     /**< ON */ 
  eMotoroff = 0,    /**< OFF */ 
}eMotorTurn_t;

/**
 * @enum eTrakingTurn_t
 * @brief turn on or turn off
 */
typedef enum {
  eTrakingOn = 1,     /**< ON */ 
  eTrakingOff = 0,    /**< OFF */ 
}eTrakingTurn_t;

/**
 * @enum eLightSelect_t
 * @brief Right and Left
 */
typedef enum {
  eLightLeft = 0,     /**< LEFT */ 
  eLightRight = 1,    /**< RIGHT */ 
}eLightSelect_t;



/**
 * @enum ePatrolNum_t
 * @brief select partrol sensor
 */
typedef enum {
  eL2 = 0,    /**< L2 */ 
  eL1 = 1,    /**< L1 */ 
  eM = 2,     /**< M */ 
  eR1 = 3,    /**< R1 */ 
  eR2 = 4,    /**< R2 */ 
}ePatrolNum_t;

/**
 * @enum eDirection_t  
 * @brief FORWARD or REVERSE
 */
typedef enum {
  eMotorForward = 0,    /**< FORWARD */ 
  eMotorReverse =1,     /**< REVERSE */ 
}eDirection_t;


/**
 * @enum eRgbCmd_t
 * @brief rgb command
 */
typedef enum {
  eRgbRed  = 0x01,   /**< Red */ 
  eRgbGreen =0x02,     /**< Green */ 
  eRgbYellow = 0x03,  /**< Yellow */ 
  eRgbBlue  =0x04,    /**< Blue */ 
  eRgbPurple = 0x05,  /**< Purple */ 
  eRgbCyan  =0x06,   /**< Cyan */ 
  eRgbWhite  = 0x07, /**< White */
  eRgbOff  =0x08   /**< Off */
}eRgbCmd_t;

/**
 * @enum eBLECmd_t
 * @brief Bluetooth command
 */
typedef enum {
  eBleForward =  1,         /**< advance */ 
  eBleBackward = 2,         /**< astern */  
  eBleLeft = 3,             /**< turn left */  
  eBleRight =  4,           /**< turn right */ 
  eBleRgbR = 5,            /**< Red */  
  eBleRgbG = 6,            /**< Green */  
  eBleRgbB = 7,            /**< Blue */ 
  eBleRgbRB = 8,           /**< Purple */  
  eBleRgbRG = 9,           /**< Yellow */ 
  eBleRgbGB =10,           /**< Cyan */  
  eBleRgbRGB = 11,         /**< White */    
  eBleRgbOff = 12 ,         /**< Off */ 
  eBleServo1Right = 13,    /**< servo1 turn right */ 
  eBleServo1Left= 14,      /**< servo1 turn left */ 
  eBleServo2Right = 15,    /**< servo2 turn right */ 
  eBleServo2Left  = 16,    /**< servo2 turn left */
  eBleServo3Right =  17,   /**< servo3 turn right */ 
  eBleServo3Left =18,      /**< servo3 turn left */
  eBleServo4Right = 19,    /**< servo4 turn right */ 
  eBleServo4Left = 20,     /**< servo4 turn left */
}eBLECmd_t;

/**
 * @enum eTurnCmd_t
 * @brief Bluetooth command
 */
typedef enum {
  eTurnLeft  =1,         /**< turn left */  
  eTurnRight =2 ,        /**< turn right */  
  eTurnStright= 3,       /**< go  stright*/  
  eTurnStop =4           /**< stop */  
}eTurnCmd_t;

/**
 * @enum eBatteryType_t
 * @brief type of battery
 */
typedef enum {
  eLithium  =   0 ,        //Lithium ion battery
  eAlkaline =   1        //Alkaline battery
}eBatteryType_t;


class DFRobot_Cosmo
{
protected:
  Cosmo_URM10 urm10;
  Cosmo_Ws2812 strip = Cosmo_Ws2812(4, 12, NEO_GRB + NEO_KHZ800); //WS2812 pin 12
  Cosmo_IRrecv myIRRecv=Cosmo_IRrecv(2);      //IR PIN
  uint8_t rxbuf[120]  = {0} ;     //Receive buf
  uint8_t version = 0;             // Version len
  Servo myServo1;
  Servo myServo2;
  Servo myServo3;
  Servo myServo4;
public:
  #define SLAVE_ADDR 0x10                   // Slave IIC address
  #define         MOTOR_0                     0
  #define         SPEED_0                     1
  #define         MOTOR_1                     2
  #define         SPEED_1                     3

  #define         RGB_L                       11
  #define         RGB_R                       12
  #define         RGB_BLINK_NUM_L             13
  #define         RGB_BLINK_GRADE_L           14
  #define         RGB_BLINK_NUM_R             15
  #define         RGB_BLINK_GRADE_R           16
  #define         RGB_GRADUAL_CHANGE_GRADE_L  17
  #define         RGB_GRADUAL_CHANGE_GRADE_R  18


  #define         SERVO_1                     20
  #define         SERVO_2                     21

  #define         BLACK_ADC_STATE             29
  #define         ADC_COLLECT_0               30
  #define         ADC_COLLECT_1               32
  #define         ADC_COLLECT_2               34
  #define         ADC_COLLECT_3               36
  #define         ADC_COLLECT_4               38

  #define         LIGHTL_H                    41
  #define         LIGHTL_L                    42
  #define         LIGHTR_H                    43
  #define         LIGHTR_L                    44
  #define         BATTERY_SET                 45
  #define         BATTERY                     46
  #define         MOTOR_TYPE_H                47
  #define         MOTOR_TYPE_L                48
  #define         VERSON_LEN                  50
  #define         VERSON_DATA                 51
  #define         MY_SYS_INIT                 70
  #define         LINE_WALKING                71
  #define         LINE_SPEED_GRADE            72
  #define         CAR_STATE                   73
  #define         CROSS_DEFAULT               75
  #define         T1_DEFAULT                  76
  #define         T2_DEFAULT                  77
  #define         T3_DEFAULT                  78
  #define         BLECMD                      80
  #define         BLEMODULE                       81  
   /**
   * @fn begin
   * @brief subclass initialization function
   * @return bool type, means returning initialization status
   * @retval true is success
   */
  int begin(void);
  /**
   * @fn iicWirte
   * @brief Write register function
   * @param Reg  Register address 8bits
   * @param data data to be written
   * @return None
   */
  void I2CWirte(uint8_t Reg ,uint8_t data);
  /**
   * @fn I2C_Read
   * @brief Read register function
   * @param reg  Register address 8bits
   * @param data Storage and buffer for data to be read
   * @param datalen Length of data to be read
   * @return None
   */
  void I2CRead(uint8_t Reg ,uint8_t *data ,uint8_t datalen);
  /**
   * @fn servoMotorCtrl
   * @brief Ctrl the servo motor
   * @param servoMotorPin  pin of servo motor
   * @n Optional pin：D3 D6 D9 D10
   * @param angle  0 to 180
   * @return None
   */
  void servoMotorCtrl(uint8_t servoMotorPin,uint8_t angle);
  /**
   * @fn ws2812Set
   * @brief Setting color of the Ws2812
   * @param satrNum  star num
   * @n The value ranges from 0 to 3 and cannot be larger than the end position
   * @param endNum  end num
   * @n The value ranges from 0 to 3 and cannot be Less  than the star position
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
   * @brief Set color of the rgb
   * @param rgb  eRgbLeft or eRgbRight or eRgbAll
   * @param cmd  color:eRgbCmd_t
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
  void rgbSetOff(eRgbSelect_t rgb);
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
   * @param rgb eRgbLeft or eRgbRight or eRgbAll
   * @param num  number of flash ：0-255
   * @param Grade number of Grade 1-5
   * @param cmd The colors are selected from the enumeration eRgbCmd t
   * @return None
   */
  void rgbBlink(eRgbSelect_t rgb,uint8_t num,uint8_t Grade,eRgbCmd_t cmd);
  /**
   * @fn readPatrol
   * @brief Read the status of the Line patrol sensor
   * @param num   Line patrol sensor num:  of ePatrolNum_t
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
   * @return Distance data :0-1023
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
   * @fn BLEModule
   * @brief Enable or disable the Bluetooth module
   * @n 0:disable 1:enable
   */
  #ifdef BLE_EN
  void BLEModule(eBLEModule_t cmd);
  /**
   * @fn BLEDefaultCmd
   * @brief Restore the default Settings of the Bluetooth command
   * @param cmd  Received Bluetooth command
   * @return 
   */
  void BLEDefaultCmd(uint8_t cmd);
  /**
   * @fn BLEGetCmd
   * @brief Get the Bluetooth command
   * @return 0-255 
   */
  uint8_t BLEGetCmd(void);
   /**
   * @fn getCross
   * @brief Get the type of Cross road
   * @return type of Cross road
   * @retval 1：eStateCrossing    2：eStateLeftRight   3：eStateLeftStright   4：eStateRightStright
   */
  #endif
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
   * @param motor  Left motor: eMotorLeft, Right motor: eMotorRight All:eMotorAll
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
   * @brief Instead of using the tone driver to produce beeps.
   * @param tonePin   beep pin
   * @param frequency  frequency of beep
   * @param duration   duration  of beep
   * @return 
   */
  void tone(u8 tonePin, int frequency, int duration);

  DFRobot_Cosmo();
};





#endif