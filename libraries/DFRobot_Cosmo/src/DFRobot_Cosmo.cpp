/*!
 * @file Cosmo.cpp
 * @brief Define the basic structure of class Cosmo
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [LR]<rong.li@dfrobot.com>
 * @version V1.0.0
 * @date 2024-07-23
 * @url https://github.com/DFRobot/DFRobot_Cosmo
 */
#include "DFRobot_Cosmo.h"



DFRobot_Cosmo::DFRobot_Cosmo()
{
   
}

int DFRobot_Cosmo::begin(void)
{
  Serial.begin(115200);
  Wire.begin();
  // Wire.setClock(400000);
  Wire.beginTransmission(0x10);
  while(Wire.endTransmission() != 0) {
    Serial.println("i2c connect error");
    delay(1000);
  } 
  I2CWirte(MY_SYS_INIT ,0x01);//Reset Ch583 
  delay(1000);
  Wire.beginTransmission(0x10);
  while(Wire.endTransmission() != 0) {
    Serial.println("i2c connect error");
    delay(1000);
  } 
  return 1;
}

void DFRobot_Cosmo::I2CWirte(uint8_t Reg ,uint8_t data)
{
  Wire.beginTransmission(SLAVE_ADDR);                 // transmit to device Address
  Wire.write(Reg);                               // sends one byte
  Wire.write(data);
  Wire.endTransmission();
}
void DFRobot_Cosmo::I2CRead(uint8_t Reg ,uint8_t *data ,uint8_t datalen)
{
  uint8_t i = 0;
  Wire.beginTransmission(SLAVE_ADDR);                 // transmit to device Address
  Wire.write(Reg);                               // sends one byte
  Wire.endTransmission();
  Wire.requestFrom((uint8_t)SLAVE_ADDR,datalen);
  while (Wire.available())                       // slave may send less than requested
    data[i++] = Wire.read();
}

void DFRobot_Cosmo::servoMotorCtrl( uint8_t servoMotorPin,uint8_t angle)
{ 
  switch (servoMotorPin)
  {
  case 3:
    myServo1.attach(servoMotorPin);
    myServo1.write(angle);
    break;
  case 6:
    myServo2.attach(servoMotorPin);
    myServo2.write(angle);
    break;
  case 9:
    myServo3.attach(servoMotorPin);
    myServo3.write(angle);
    break;
  case 10:
    myServo4.attach(servoMotorPin);
    myServo4.write(angle);
    break;
  default:
    break;
  }
}  

void DFRobot_Cosmo::setCross(eCross_t crossId,eTurnCmd_t cmd)
{
  switch (crossId)
  {
  case eStateCrossing:
    I2CWirte(CROSS_DEFAULT ,cmd);
    break;
  case eStateLeftRight:
    I2CWirte(T1_DEFAULT ,cmd);
    break;
  case eStateLeftStright:
    I2CWirte(T2_DEFAULT ,cmd);;
    break;
  case eStateRightStright:
    I2CWirte(T3_DEFAULT ,cmd);
    break;
  default:
    break;
  }
}

void DFRobot_Cosmo::lineTraking(eTrakingTurn_t cmd)
{
  if(cmd==eTrakingOn){/*Star*/
    I2CWirte(LINE_WALKING ,0x01);
  }else/*Stop*/
    I2CWirte(LINE_WALKING ,0x00);
}


uint8_t DFRobot_Cosmo::getCross(void)
{
  I2CRead(CAR_STATE ,&rxbuf[CAR_STATE] ,1);
  return rxbuf[CAR_STATE];
}

String DFRobot_Cosmo::getVersion(void)
{
  uint8_t versionlen=0;
  String version;
  I2CRead(VERSON_LEN ,&rxbuf[VERSON_LEN] ,1);
  versionlen = rxbuf[VERSON_LEN];
  I2CRead(VERSON_DATA ,&rxbuf[VERSON_DATA] ,versionlen);
  for(uint8_t j = 0; j < versionlen; j++) {
    version+=(char)rxbuf[VERSON_DATA+j];
    //  Serial.print((char)rxbuf[51+j]);
  } 
  // Serial.println();
  return version;
}
uint16_t DFRobot_Cosmo::getLight(eLightSelect_t cmd)
{
   uint16_t temp_light=0;
   I2CRead(LIGHTL_H ,&rxbuf[LIGHTL_H] ,4); 
   if(cmd==0)  temp_light= rxbuf[LIGHTL_H]<<8| rxbuf[LIGHTL_L];
   else  temp_light= rxbuf[LIGHTR_H]<<8| rxbuf[LIGHTR_L];
   return temp_light;
}

void DFRobot_Cosmo:: ws2812Set(uint8_t satrNum,uint8_t endNum,uint8_t R,uint8_t G,uint8_t B)
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    for(uint8_t i=satrNum; i<=endNum;i++){
        strip.setPixelColor(i, strip.Color(R, G, B));//strip.Color(255, 0, 0)：R G B
    }
    strip.show();
}

float DFRobot_Cosmo::getURM10(void)
{
   float disance=0;
   disance=urm10.getDistanceCM(4,5);
   return disance;
}

void DFRobot_Cosmo::blinkLed(eBlinkTurn_t cmd)
{
    pinMode(COSMO_LED_PIN, OUTPUT);
    if(cmd==eBlinkOn){
      digitalWrite(COSMO_LED_PIN, HIGH);
    }else{
      digitalWrite(COSMO_LED_PIN, LOW);
    }
        

}

void DFRobot_Cosmo::rgbSet(eRgbSelect_t rgb,eRgbCmd_t cmd)
{
    if(rgb==eRgbLeft){
      I2CWirte(RGB_L ,cmd);
    }else if(rgb==eRgbRight){
      I2CWirte(RGB_R ,cmd);
    }else if(rgb==eRgbAll){
      I2CWirte(RGB_L ,cmd);
      I2CWirte(RGB_R ,cmd);
    }
}

void DFRobot_Cosmo::rgbSetOff(eRgbSelect_t rgb)
{
    if(rgb==eRgbLeft){
      I2CWirte(RGB_L ,eRgbOff);
    }else if(rgb==eRgbRight){
      I2CWirte(RGB_R ,eRgbOff);
    }else if(rgb==eRgbAll){
      I2CWirte(RGB_L ,eRgbOff);
      I2CWirte(RGB_R ,eRgbOff);
    }
}

void DFRobot_Cosmo::rgbGradualChange(eRgbSelect_t rgb,uint8_t Grade)
{
  if((Grade>5)||(Grade==0))
    return;
  if(rgb==eRgbLeft){
    I2CWirte(RGB_GRADUAL_CHANGE_GRADE_L ,Grade);
  } else if(rgb==eRgbRight){
    I2CWirte(RGB_GRADUAL_CHANGE_GRADE_R ,Grade);
  }
  else if(rgb==eRgbAll){
    I2CWirte(RGB_GRADUAL_CHANGE_GRADE_L ,Grade);
    I2CWirte(RGB_GRADUAL_CHANGE_GRADE_R ,Grade);
  }
}

void DFRobot_Cosmo::rgbBlink(eRgbSelect_t rgb,uint8_t num,uint8_t Grade,eRgbCmd_t cmd)
{
  if((Grade>5)||(Grade==0))
    return;
  if(rgb==eRgbLeft){
    I2CWirte(RGB_L ,cmd);
    I2CWirte(RGB_BLINK_GRADE_L ,Grade);
    I2CWirte(RGB_BLINK_NUM_L ,num);
  }else if(rgb==eRgbRight){
    I2CWirte(RGB_R ,cmd);
    I2CWirte(RGB_BLINK_GRADE_R ,Grade);
    I2CWirte(RGB_BLINK_NUM_R ,num);
  }else if(rgb==eRgbAll){
    I2CWirte(RGB_L ,cmd);
    I2CWirte(RGB_BLINK_GRADE_L ,Grade);
    I2CWirte(RGB_BLINK_NUM_L ,num);
    I2CWirte(RGB_R ,cmd);
    I2CWirte(RGB_BLINK_GRADE_R ,Grade);
    I2CWirte(RGB_BLINK_NUM_R ,num);
  }
}

uint8_t DFRobot_Cosmo::readPatrol(ePatrolNum_t num)
{
  I2CRead(BLACK_ADC_STATE ,&rxbuf[BLACK_ADC_STATE] ,1);
  if(rxbuf[BLACK_ADC_STATE]&(1<<(4-num)))//max=4
    return 1;
  else
    return 0;
}

uint16_t DFRobot_Cosmo::readPatrolVoltage(ePatrolNum_t num)
{
  uint16_t temp_data=0;
  I2CRead(ADC_COLLECT_0+num*2 ,&rxbuf[ADC_COLLECT_0+num*2] ,2);
  temp_data= rxbuf[ADC_COLLECT_0+num*2]*255 +rxbuf[ADC_COLLECT_0+num*2+1];
  return temp_data;
}

uint8_t DFRobot_Cosmo::getBatteryData(eBatteryType_t type)
{
  uint16_t temp_data=0;
  if(type)
    I2CWirte(BATTERY_SET ,1);
  else
    I2CWirte(BATTERY_SET ,0);  
  delay(50);
  rxbuf[BATTERY]=0;
  I2CRead(BATTERY ,&rxbuf[BATTERY],1);
  temp_data=rxbuf[BATTERY];
  return temp_data;
}

void  DFRobot_Cosmo::IRReceiveEnable(void)
{
  myIRRecv.enableIRIn(); // Start the receiver
}

uint8_t DFRobot_Cosmo::IRReceive(void)
{
  decode_results results;
  if (myIRRecv.decode(&results)) {
    myIRRecv.resume(); // Receive the next value
    if(results.value!=0xffffffff)
      return results.value;
    else
      return 0;
  }
  return 0;
}

void DFRobot_Cosmo::motorSet(eMotorSelect_t motor,eDirection_t Dir,uint8_t speed)
{
    if (motor==eMotorLeft){
      I2CWirte(MOTOR_0,Dir);
      I2CWirte(SPEED_0,speed);
    }else if (motor==eMotorRight){
      I2CWirte(MOTOR_1,Dir);
      I2CWirte(SPEED_1,speed);
    }else if(motor==eMotorAll){
      I2CWirte(MOTOR_1,Dir);
      I2CWirte(SPEED_1,speed);
      I2CWirte(MOTOR_0,Dir);
      I2CWirte(SPEED_0,speed);
    }
}

void DFRobot_Cosmo::motorStop(eMotorSelect_t motor)
{
    if (motor==eMotorLeft){
      I2CWirte(SPEED_0,0);
    }else if (motor==eMotorRight){   
      I2CWirte(SPEED_1,0);
    }else if(motor==eMotorAll){
      I2CWirte(SPEED_0,0);
      I2CWirte(SPEED_1,0);
    }
} 

void DFRobot_Cosmo::motorTypeSet(uint16_t type)
{
  I2CWirte(MOTOR_TYPE_H,(uint8_t)(type>>8));
  I2CWirte(MOTOR_TYPE_L,(uint8_t)type);
}

#ifdef BLE_EN
void  DFRobot_Cosmo::BLEModule(eBLEModule_t cmd)
{
  I2CWirte(BLEMODULE ,cmd);
}
void DFRobot_Cosmo::BLEDefaultCmd(uint8_t cmd)
{
  static uint8_t servoNum1=20;
  static uint8_t servoNum2=20;
  static uint8_t servoNum3=20;
  static uint8_t servoNum4=20;
  switch (cmd) {
    case eBleForward:
      motorSet(eMotorAll,eMotorForward,200);
      delay(100);
      motorSet(eMotorAll,eMotorForward,0);
      break;
    case eBleBackward:
      motorSet(eMotorAll,eMotorReverse,200);
      delay(100);
      motorSet(eMotorAll,eMotorReverse,0);
      break;
    case eBleLeft:
      motorSet(eMotorRight,eMotorForward,200);
      motorSet(eMotorLeft,eMotorForward,0);
      delay(100);
      motorSet(eMotorAll,eMotorForward,0);
      break;
    case eBleRight:
      motorSet(eMotorLeft,eMotorForward,200);
      motorSet(eMotorRight,eMotorForward,0);
      delay(100);
      motorSet(eMotorAll,eMotorForward,0);
      break;
    case eBleRgbR:
      rgbSet(eRgbAll,eRgbRed);
      break;
    case eBleRgbG:
      rgbSet(eRgbAll,eRgbGreen);
      break;
    case eBleRgbB:
      rgbSet(eRgbAll,eRgbYellow);
      break;
    case eBleRgbRB:
      rgbSet(eRgbAll,eRgbBlue);
      break;
    case eBleRgbRG:
      rgbSet(eRgbAll,eRgbPurple);
      break;
    case eBleRgbGB:
      rgbSet(eRgbAll,eRgbCyan);
      break;
    case eBleRgbRGB:
      rgbSet(eRgbAll,eRgbWhite);
      break;
    case eBleRgbOff:
      rgbSet(eRgbAll,eRgbOff);
      break;
    case eBleServo1Right:
      if(servoNum1<=180)servoNum1+=5;
      servoMotorCtrl(3,servoNum1);
      break;
    case eBleServo1Left:
      if(servoNum1>0) servoNum1-=5;
      servoMotorCtrl(3,servoNum1);
      break;
    case eBleServo2Right:
      if(servoNum2<=180)servoNum2+=5;
      servoMotorCtrl(6,servoNum2);
      break;
    case eBleServo2Left:
      if(servoNum2>0) servoNum2-=5;
      servoMotorCtrl(6,servoNum2);
      break;
    case eBleServo3Right:
      if(servoNum3<=180)servoNum3+=5;
      servoMotorCtrl(9,servoNum3);
      break;
    case eBleServo3Left:
      if(servoNum3>0) servoNum3-=5;
      servoMotorCtrl(9,servoNum3);
      break;
    case eBleServo4Right:
      if(servoNum4<=180)servoNum4+=5;
      servoMotorCtrl(10,servoNum4);
      break;
    case eBleServo4Left:
      if(servoNum4>0) servoNum4-=5;
      servoMotorCtrl(10,servoNum4);
      break;
    default:
      break;
   }
}

 uint8_t DFRobot_Cosmo::BLEGetCmd(void){
    I2CRead(BLECMD ,&rxbuf[BLECMD],1);
    return rxbuf[BLECMD];
 }
#endif
// Function that drives the passive buzzer
void DFRobot_Cosmo::tone(u8 tonePin, int frequency, int duration) {
  pinMode(tonePin, OUTPUT);            //init
  if(frequency==0)return;               //reset
  int period = 1000000L / frequency;    //period 1MHZ / fre
  int pulse = period / 2;               //Duration of high and low levels 50%
  for (long i = 0; i < duration * 1000L; i += period) {
    digitalWrite(tonePin, HIGH);        //Set pin to high
    delayMicroseconds(pulse);           // time to stay high
    digitalWrite(tonePin, LOW);         //Set pin to low
    delayMicroseconds(pulse);           // time to stay low
  }
}