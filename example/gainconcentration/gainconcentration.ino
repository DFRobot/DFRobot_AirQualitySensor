/*!
  * @file gainconcentration.ino
  * @brief 获取此时空气中颗粒物的浓度
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
 *@brief : 获取PM1.0浓度
 *@param :PARTICLE_PM1_0_STANDARD   
          PARTICLE_PM2_5_STANDARD   
          PARTICLE_PM10_STANDARD    
          PARTICLE_PM1_0_ATMOSPHERE 
          PARTICLE_PM2_5_ATMOSPHERE 
          PARTICLE_PM10_ATMOSPHERE  
*/  
  uint16_t concentration = particle.gainParticleConcentration_ugm3(PARTICLE_PM1_0_STANDARD);
  Serial.print("PM1.0 concentration:");
  Serial.print(concentration);
  Serial.println(" mg/m3");
  delay(1000);
}
