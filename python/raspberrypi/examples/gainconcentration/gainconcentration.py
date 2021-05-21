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

I2C_1       = 0x01               # I2C_1 ʹ��i2c1�ӿ������������� ���Ե���Ϊi2c0������Ҫ������ݮ�ɵ��ļ�
I2C_ADDRESS = 0x19               # I2C �豸�ĵ�ַ�����Ը���A1��A0��������ַ��Ĭ�ϵ�ַΪ0x54
airqualitysensor = dfrobot_airqualitysensor_I2C(I2C_1 ,I2C_ADDRESS)

def setup():
  time.sleep(1) 
  version = airqualitysensor.gain_version()
  print "version is : " + str(version)
  time.sleep(1) 
  
def loop():
  num = airqualitysensor.gain_particlenum_every0_1l(airqualitysensor.PARTICLENUM_0_3_UM_EVERY0_1L_AIR)
  print "The number of particles with a diameter of 0.3um per 0.1 in lift-off is:" + str(num)
  time.sleep(1) 

if __name__ == "__main__":
  setup()
  while True:
    loop()