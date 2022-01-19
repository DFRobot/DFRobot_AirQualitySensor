/*!
 * @file lowPower.ino
 * @brief Turn the sensor on or off periodically
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2021-11-23
 * @url https://github.com/dfrobot/DFRobot_AirQualitySensor
 */
#include "DFRobot_AirQualitySensor.h"

#define I2C_ADDRESS 0x19
DFRobot_AirQualitySensor particle(&Wire, I2C_ADDRESS);

void setup()
{
  Serial.begin(115200);
  //Sensor init, initialize I2C, determined by the communication method currently used
  while (!particle.begin())
  {
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

void loop()
{
  //Turn the sensor on or off every 5 seconds
  particle.setLowpower();
  delay(5000);
  particle.awake();
  delay(5000);
}
