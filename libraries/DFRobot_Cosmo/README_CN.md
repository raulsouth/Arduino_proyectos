# DFRobot_Cosmo
- [English Version](./README.md)

Cosmo 是一款基于 Arduino 的 STEAM 教育机器人。


![正面svg效果图](./resources/images/DFRobot_Cosmo-1.png) 

## 产品链接(https://www.dfrobot.com.cn/)

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

  * 这个库提供了Cosmo所有功能的实现方法如：控制电机、接收蓝牙命令、控制WS2812、控制RGB、获取光线强度、获取电池电量、获取红外传感器信息、获取巡线信息等。

## 库安装
这里提供一种使用本库的方法：<br>
1.首先下载库文件,将其粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.<br>


## 方法

```C++

  /**
   * @fn begin
   * @brief 子类初始化函数
   * @return Bool类型，表示返回初始化状态
   * @retval true 表示成功 
   * @retval false 表示失败
   */
  int begin(void);
  /**
   * @fn I2CWirte
   * @brief 写寄存器功能
   * @param Reg  寄存器地址（8bits）
   * @param data 要写入的数据
   * @return None
   */
  void I2CWirte(uint8_t Reg ,uint8_t data);
  /**
   * @fn I2CRead
   * @brief 读寄存器函数
   * @param reg  存器地址（8bits）
   * @param data 用于存储读取数据的缓冲区
   * @param datalen 要读取的数据长度
   * @return 
   */
  void I2CRead(uint8_t Reg ,uint8_t *data ,uint8_t datalen);
  /**
   * @fn servoMotorCtrl
   * @brief 控制舵机
   * @param servoMotorPin  舵机引脚
   * @n 可选引脚：D3 D6 D9 D10
   * @param angle  角度 0 to 180
   * @return 
   */
  void servoMotorCtrl( uint8_t servoMotorPin,uint8_t angle);
  /**
   * @fn ws2812Set
   * @brief 设置Ws2812的颜色
   * @param satrNum  Ws2812灯的起始起始位置 
   * @n 范围 RGB0-RGB3 从枚举类型中选择，不能大于结束位置
   * @param endNum  Ws2812灯的结束位置
   * @n 范围 RGB0-RGB3  从枚举类型中选择 ，不能小于开始位置
   * @param R  0-255
   * @param G  0-255
   * @param B  0-255
   * @return 
   */
  void ws2812Set(uint8_t satrNum,uint8_t endNum,uint8_t R,uint8_t G,uint8_t B);
  /**
   * @fn blinkLed
   * @brief 打开/关闭 Led
   * @param cmd  打开:eBlinkOn   关闭:eBlinkOff
   * @return 
   */
  void blinkLed(eBlinkTurn_t cmd);
  /**
   * @fn rgbSet
   * @brief 设置RGB的颜色
   * @param RGB  左 ：eRgbLeft  右 ：eRgbRight  全部: eRgbAll
   * @param cmd  颜色:eRGBCmd_t
   * @n RGB_R  
   * @n RRGB_G 
   * @n RRGB_B  
   * @n RRGB_RB 
   * @n RRGB_RG 
   * @n RRGB_GB 
   * @n RRGB_RGB
   * @n RRGB_OFF
   * @return 
   */
  void rgbSet(eRgbSelect_t rgb,eRgbCmd_t cmd);
  /**
   * @fn rgbSetOff
   * @brief 关闭所有RGB
   * @param rgb  左 ：eRgbLeft  右 ：eRgbRight  全部: eRgbAll
   * @return None
   */
  void rgbSetOff(eRgbSelect_t rgb)
  /**
   * @fn rgbGradualChange
   * @brief RGB颜色渐变
   * @param RGB   左 ：eRgbLeft  右 ：eRgbRight  全部: eRgbAll
   * @param Grade   渐变速度等级 1-5
   * @return 
   */
void rgbGradualChange(eSelect_t rgb,uint8_t Grade);
  /**
   * @fn rgbBlink
   * @brief RGB颜色闪烁
   * @param RGB   左 ：eRgbLeft  右 ：eRgbRight  全部: eRgbAll
   * @param num   闪烁次数： 0-255
   * @param Grade 闪烁速度等级： 1-5
   * @param cmd   颜色从枚举eRgbCmd_t中选择
   * @return 
   */
void rgbBlink(eRgbSelect_t rgb,uint8_t num,uint8_t Grade,eRgbCmd_t cmd);
  /**
   * @fn readPatrol
   * @brief 读取巡线传感器的状态
   * @param num  巡线传感器编号从枚举类型ePatrolNum_t中选
   * @return 灭灯:0 亮灯:1
   */
  uint8_t readPatrol(ePatrolNum_t num);
  /**
   * @fn readPatrolVoltage
   * @brief 读取传感器的电压
   * @param num   巡线传感器编号从枚举类型ePatrolNum_t中选
   * @return ADC data ：0-4095
   */
  uint16_t readPatrolVoltage(ePatrolNum_t num);
  /**
   * @fn getLight
   * @brief 光强采集
   * @param cmd 左传感器: eLightLeft  右传感器: eLightRight
   * @return 光强数据 :0-1023
   */
  uint16_t getLight(eLightSelect_t cmd);
  /**
   * @fn getURM10
   * @brief 获取距离 单位CM
   * @return 距离 :-1-300 cm 超时或错误：-1
   */
  float getURM10(void);
  /**
   * @fn IRReceiveEnable
   * @brief 使能红外接收
   * @return 
   */
  void IRReceiveEnable(void);
  /**
   * @fn IRReceive
   * @brief 获取红外接收的数据
   * @return 接收到的数据：0-255
   */
  uint8_t IRReceive(void);
  /**
   * @fn GetBatteryData
   * @brief 获取电池剩余电量
   * @param num  锂电池: eLithium  碱性电池: eAlkaline
   * @return 电量范围 0-100
   */
  uint8_t getBatteryData(eBatteryType_t type);
  /**
   * @fn getVersion
   * @brief 获取Cosmo的版本
   * @return 版本
   */
  String getVersion(void);
  /**
   * @fn lineTraking
   * @brief  开启或者关闭巡线
   * @param cmd  关闭巡线: eTrakingOff   开启巡线: eTrakingOn
   * @return 
   */
  void lineTraking(eTrakingTurn_t cmd);
   /**
   * @fn getCross
   * @brief 获取路口类型
   * @return 路口类型
   * @retval 1：eStateCrossing    2：eStateLeftRight   3：eStateLeftStright   4：eStateRightStright
   */
  uint8_t getCross(void);
  /**
   * @fn setCross
   * @brief 设置交叉路口的动作
   * @param crossid  路口类型
   * @param cmd  动作命令
   * @n  eTurnLeft , eTurnRight , eTurnStright,eTurnStop  
   * @return 
   */
  void setCross(eCross_t crossId,eTurnCmd_t cmd);
  /**
   * @fn motorSet
   * @brief 设置电机参数
   * @param motor 左电机: eMotorLeft, 右电机: eMotorRight 全部:eMotorAll
   * @param Dir  正转: eMotorForward  反转:eMotorReverse
   * @param speed 速度  0-255
   * @return 
   */
  void motorSet(eSelect_t motor,eDirection_t Dir,uint8_t speed);
  /**
   * @fn motorStop
   * @brief 停止电机运行
   * @param motor  左电机: eMotorLeft, 右电机: eMotorRight 全部:eMotorAll
   * @return 
   */
  void motorStop(eMotorSelect_t motor);
  /**
   * @fn motorTypeSet
   * @brief 设置电机类型
   * @return 
   */
  void motorTypeSet(uint16_t type);
  /**
   * @fn tone
   * @brief 代替Arduino自带的tone函数驱动蜂鸣器
   * @param tonePin    蜂鸣器引脚
   * @param frequency  蜂鸣声频率
   * @param duration   蜂鸣声时长
   * @return 
   */
  void tone(u8 tonePin, int frequency, int duration);

```

## 兼容性

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |

## 历史

- 2024/10/16 - V1.0.0 版本

## 创作者

Written by lr(rong.li@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))