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

import time
import smbus
import spidev
import os
import math
import RPi.GPIO as GPIO

I2C_MODE                  = 0x01

class dfrobot_airqualitysensor(object):

  #选择颗粒物的类型
  PARTICLE_PM1_0_STANDARD   = 0X05
  PARTICLE_PM2_5_STANDARD   = 0X07
  PARTICLE_PM10_STANDARD    = 0X09
  PARTICLE_PM1_0_ATMOSPHERE = 0X0B
  PARTICLE_PM2_5_ATMOSPHERE = 0X0D
  PARTICLE_PM10_ATMOSPHERE  = 0X0F
  PARTICLENUM_0_3_UM_EVERY0_1L_AIR = 0X11
  PARTICLENUM_0_5_UM_EVERY0_1L_AIR = 0X13
  PARTICLENUM_1_0_UM_EVERY0_1L_AIR = 0X15
  PARTICLENUM_2_5_UM_EVERY0_1L_AIR = 0X17
  PARTICLENUM_5_0_UM_EVERY0_1L_AIR = 0X19
  PARTICLENUM_10_UM_EVERY0_1L_AIR  = 0X1B
  PARTICLENUM_GAIN_VERSION = 0X1D

  def __init__(self ,bus ,Baud):
    if bus != 0:
      self.i2cbus = smbus.SMBus(bus)
      self.__uart_i2c = I2C_MODE 
      
  '''
   *  @brief 获取指定颗粒物类型的浓度
   *  @param type:PARTICLE_PM1_0_STANDARD  
                      PARTICLE_PM2_5_STANDARD  
                      PARTICLE_PM10_STANDARD   
                      PARTICLE_PM1_0_ATMOSPHERE
                      PARTICLE_PM2_5_ATMOSPHERE
                      PARTICLE_PM10_ATMOSPHERE 
   *  @return 浓度（ug/m3）
  '''
  def gain_particle_concentration_ugm3(self,PMtype):
    buf = self.read_reg(PMtype,2)
    concentration = (buf[0] << 8) + buf[1]
    return concentration   

  '''
   *  @brief 获取在0.1升空气中的颗粒物的个数
   *  @param type:PARTICLENUM_0_3_UM_EVERY0_1L_AIR
                      PARTICLENUM_0_5_UM_EVERY0_1L_AIR
                      PARTICLENUM_1_0_UM_EVERY0_1L_AIR
                      PARTICLENUM_2_5_UM_EVERY0_1L_AIR
                      PARTICLENUM_5_0_UM_EVERY0_1L_AIR
                      PARTICLENUM_10_UM_EVERY0_1L_AIR 
   *  @return 个数
   '''
  def gain_particlenum_every0_1l(self,PMtype):
    buf = self.read_reg(PMtype,2)
    particlenum = (buf[0] << 8) + buf[1]
    return particlenum;

  '''
   *  @brief 向传感器的指定寄存器写入数据
   *  @param NULL
   *  @return 没有返回值
   '''
  def gain_version(self):
    version = self.read_reg(self.PARTICLENUM_GAIN_VERSION,1)
    return version[0]
      
'''
  @brief An example of an i2c interface module
'''
class dfrobot_airqualitysensor_I2C(dfrobot_airqualitysensor):
  def __init__(self ,bus ,addr):
    self.__addr = addr
    super(dfrobot_airqualitysensor_I2C, self).__init__(bus,0)

  '''
    @brief writes data to a register
    @param reg register address
    @param value written data
  '''
  def write_reg(self, reg, data):
    while 1:
      try:
        self.i2cbus.write_i2c_block_data(self.__addr ,reg ,data)
        return
      except:
        print("please check connect!")
        #os.system('i2cdetect -y 1')
        time.sleep(1)
        return
  '''
    @brief read the data from the register
    @param reg register address
    @param value read data
  '''
  def read_reg(self, reg ,len):
    try:
      rslt = self.i2cbus.read_i2c_block_data(self.__addr ,reg ,len)
      #print rslt
    except:
      rslt = -1
    return rslt
    
