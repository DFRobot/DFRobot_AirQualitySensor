/*!
 * @file gainparticlenum.ino
 * @brief Get the current number of PM in 0.1L of air
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

void setup() {
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
   *@brief Get the number of 0.3um PM in 0.1L of air
   *@param PARTICLENUM_0_3_UM_EVERY0_1L_AIR 
   *@n     PARTICLENUM_0_5_UM_EVERY0_1L_AIR 
   *@n     PARTICLENUM_1_0_UM_EVERY0_1L_AIR 
   *@n     PARTICLENUM_2_5_UM_EVERY0_1L_AIR 
   *@n     PARTICLENUM_5_0_UM_EVERY0_1L_AIR 
   *@n     PARTICLENUM_10_UM_EVERY0_1L_AIR   
   */  
  uint16_t num = particle.gainParticleNum_Every0_1L(PARTICLENUM_0_3_UM_EVERY0_1L_AIR);
  Serial.print("The number of particles with a diameter of 0.3um per 0.1 in lift-off is: ");
  Serial.println(num);
  delay(1000);
}
