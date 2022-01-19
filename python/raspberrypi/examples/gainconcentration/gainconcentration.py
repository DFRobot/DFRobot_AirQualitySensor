# -*- coding: utf-8 -*
'''!
  @file gainconcentration.py
  @brief The sensor can obtain PM concentration in the air.
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @version  V1.0.0
  @date  2021-11-23
  @url https://github.com/dfrobot/DFRobot_AirQualitySensor
'''
import sys
import os
import time

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
from DFRobot_AirQualitySensor import *

I2C_1       = 0x01               # I2C_1 Use i2c1 interface (or i2c0 with configuring Raspberry Pi file) to drive sensor
I2C_ADDRESS = 0x19               # I2C Device address, which can be changed by changing A1 and A0, the default address is 0x54
airqualitysensor = DFRobot_AirQualitySensor(I2C_1 ,I2C_ADDRESS)

def setup():
  time.sleep(1) 
  #Get firmware version
  version = airqualitysensor.gain_version()
  print ("version is : " + str(version))
  time.sleep(1) 
  
def loop():
  '''
    @brief Get PM concentration in the air: parameters available
    @n     PARTICLE_PM1_0_STANDARD   
    @n     PARTICLE_PM2_5_STANDARD  
    @n     PARTICLE_PM10_STANDARD  
    @n     PARTICLE_PM1_0_ATMOSPHERE 
    @n     PARTICLE_PM2_5_ATMOSPHERE
    @n     PARTICLE_PM10_ATMOSPHERE  
    @n     PARTICLENUM_0_3_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_0_5_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_1_0_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_2_5_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_5_0_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_10_UM_EVERY0_1L_AIR 
    @n     PARTICLENUM_GAIN_VERSION
  '''
  num = airqualitysensor.gain_particlenum_every0_1l(airqualitysensor.PARTICLENUM_0_3_UM_EVERY0_1L_AIR)
  print ("The number of particles with a diameter of 0.3um per 0.1 in lift-off is:" + str(num))
  time.sleep(1) 

if __name__ == "__main__":
  setup()
  while True:
    loop()
