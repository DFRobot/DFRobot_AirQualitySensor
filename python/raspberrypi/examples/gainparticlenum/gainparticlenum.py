# -*- coding: utf-8 -*
'''
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V0.1
  * @date        2021-05-20
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_AirQualitySensor
'''
import sys
import os
import time

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
from dfrobot_airqualitysensor import *

I2C_1       = 0x01               # I2C_1 使用i2c1接口驱动传感器， 可以调整为i2c0但是需要配置树莓派的文件
I2C_ADDRESS = 0x19               # I2C 设备的地址，可以更改A1、A0来更换地址，默认地址为0x54
airqualitysensor = dfrobot_airqualitysensor_I2C(I2C_1 ,I2C_ADDRESS)

def setup():
  time.sleep(1) 
  version = airqualitysensor.gain_version()
  print "version is : " + str(version)
  time.sleep(1) 
  
def loop():
  concentration = airqualitysensor.gain_particle_concentration_ugm3(airqualitysensor.PARTICLE_PM1_0_STANDARD)
  print "PM1.0 concentration:" + str(concentration) + " mg/m3"
  time.sleep(1) 

if __name__ == "__main__":
  setup()
  while True:
    loop()