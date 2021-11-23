# -*- coding: utf-8 -*
'''!
  @file gainconcentration.py
  @brief 该传感器可以获取空气中相关颗粒物的浓度
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
  '''
    @brief 获取空气中颗粒物浓度:可供选择的参数
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
  concentration = airqualitysensor.gain_particle_concentration_ugm3(airqualitysensor.PARTICLE_PM1_0_STANDARD)
  print ("PM1.0 concentration:" + str(concentration) + " mg/m3")
  time.sleep(1) 

if __name__ == "__main__":
  setup()
  while True:
    loop()