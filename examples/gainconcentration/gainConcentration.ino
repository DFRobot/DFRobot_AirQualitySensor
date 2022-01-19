/*!
 * @file gainConcentration.ino
 * @brief Get the current concentration of PM in the air
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2021-11-23
 * @url https://github.com/dfrobot/DFRobot_AirQualitySensor
 */
#include "DFRobot_AirQualitySensor.h"

#define I2C_ADDRESS    0x19
  DFRobot_AirQualitySensor particle(&Wire ,I2C_ADDRESS);

void setup(){
  Serial.begin(115200);

  //Sensor init, initialize I2C, determined by the communication method currently used
  while(!particle.begin()){
    Serial.println("NO Deivces !");
    delay(1000);
  }
  Serial.println("sensor begin success!");
  delay(1000);

  //Get sensor version number
  uint8_t version = particle.gainVersion();
  Serial.print("version is : ");
  Serial.println(version);
  delay(1000);
}

void loop() {
  /**
   *@brief  Get PM1.0 concentration
   *@param  PARTICLE_PM1_0_STANDARD   
   *@n      PARTICLE_PM2_5_STANDARD   
   *@n      PARTICLE_PM10_STANDARD    
   *@n      PARTICLE_PM1_0_ATMOSPHERE 
   *@n      PARTICLE_PM2_5_ATMOSPHERE 
   *@n      PARTICLE_PM10_ATMOSPHERE  
   */  
  uint16_t concentration = particle.gainParticleConcentration_ugm3(PARTICLE_PM1_0_STANDARD);
  Serial.print("PM1.0 concentration:");
  Serial.print(concentration);
  Serial.println(" mg/m3");
  delay(1000);
}
