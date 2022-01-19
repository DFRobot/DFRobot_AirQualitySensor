# -*- coding: utf-8 -*
'''!
  @file lowPower.py
  @brief Turn the sensor on or off periodically
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
  airqualitysensor.set_lowpower()
  time.sleep(5) 
  airqualitysensor.awake()
  time.sleep(5) 

if __name__ == "__main__":
  setup()
  while True:
    loop()
