/*!
 * @file lowPower.ino
 * @brief 周期性打开或者关闭传感器
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0
 * @date  2021-11-23
 * @url https://github.com/dfrobot/DFRobot_AirQualitySensor
 */
#include "DFRobot_AirQualitySensor.h"

#define I2C_ADDRESS 0x19
DFRobot_AirQualitySensor particle(&Wire, I2C_ADDRESS);

void setup()
{
  Serial.begin(115200);
  //传感器初始化，用作初始化IIC，由此时使用的通信方式来决定
  while (!particle.begin())
  {
    Serial.println("NO Deivces !");
    delay(1000);
  }
  Serial.println("sensor begin success!");
  delay(1000);
  
  //获取传感器版本号
  uint8_t version = particle.gainVersion();
  Serial.print("version is : ");
  Serial.println(version);
  delay(1000);
}

void loop()
{
  //以5秒为一个循环打开或关闭传感器
  particle.setLowpower();
  delay(5000);
  particle.awake();
  delay(5000);
}
