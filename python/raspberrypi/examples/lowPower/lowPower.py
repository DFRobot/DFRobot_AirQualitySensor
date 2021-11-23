# -*- coding: utf-8 -*
'''!
  @file lowPower.py
  @brief 周期性打开或者关闭传感器
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @version  V1.0
  @date  2021-11-23
  @url https://github.com/dfrobot/DFRobot_AirQualitySensor
'''
import sys
import os
import time

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
from DFRobot_AirQualitySensor import *

I2C_1       = 0x01               # I2C_1 使用i2c1接口驱动传感器， 可以调整为i2c0但是需要配置树莓派的文件
I2C_ADDRESS = 0x19               # I2C 设备的地址，可以更改A1、A0来更换地址，默认地址为0x54
airqualitysensor = DFRobot_AirQualitySensor(I2C_1 ,I2C_ADDRESS)

def setup():
  time.sleep(1) 
  #获取固件版本
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