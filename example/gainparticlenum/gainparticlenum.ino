/*!
  * @file gainparticlenum.ino
  * @brief 获取此时每0.1升空气中颗粒物的个数
    @n i2c 地址选择，默认i2c地址为0x19 
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V1.0
  * @date        2021-05-21
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_AirQualitySensor
*/
#include "DFRobot_AirQualitySensor.h"

#define I2C_ADDRESS    0x19
  DFRobot_AirQualitySensor_I2C particle(&Wire ,I2C_ADDRESS);

void setup() {
  Serial.begin(115200);
/**
  传感器初始化，用作初始化IIC，由此时使用的通信方式来决定
*/
  while(!particle.begin())
  {
    Serial.println("NO Deivces !");
    delay(1000);
  }
  Serial.println("sensor begin success!");
  delay(1000);
/**
  获取传感器版本号
*/
  uint8_t version = particle.gainVersion();
  Serial.print("version is : ");
  Serial.println(version);
  delay(1000);
}

void loop() {
/**
 *@brief : 获取每0.1升空气中0.3um颗粒物个数
 *@param :PARTICLENUM_0_3_UM_EVERY0_1L_AIR 
          PARTICLENUM_0_5_UM_EVERY0_1L_AIR 
          PARTICLENUM_1_0_UM_EVERY0_1L_AIR 
          PARTICLENUM_2_5_UM_EVERY0_1L_AIR 
          PARTICLENUM_5_0_UM_EVERY0_1L_AIR 
          PARTICLENUM_10_UM_EVERY0_1L_AIR   
*/  
  uint16_t num = particle.gainParticleNum_Every0_1L(PARTICLENUM_0_3_UM_EVERY0_1L_AIR);
  Serial.print("The number of particles with a diameter of 0.3um per 0.1 in lift-off is: ");
  Serial.println(num);
  delay(1000);
}
