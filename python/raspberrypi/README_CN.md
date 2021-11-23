# DFRobot_AirQualitySensor
- [English Version](./README.md)

## DFR0bot_AirQualitySensor Library for Arduino
---------------------------------------------------------
空气质量传感器，用来获取空气中颗粒物的浓度，进而判断此时环境中的空气质量
![正反面svg效果图](./resources/images/SEN0460svg1.png)

## Product Link（链接到中文商城）
SKU：SEN0460

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

这是一个用于复杂环境中检测空气中颗粒物浓度的传感器，检具低功耗

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_AirQualitySensor.
Download the zip file first to use this library and uncompress it to a folder named DFRobot_AirQualitySensor.

## Methods
    '''!
      @brief 获取指定颗粒物类型的浓度
      @param type PARTICLE_PM1_0_STANDARD
      @n          PARTICLE_PM2_5_STANDARD  
      @n          PARTICLE_PM10_STANDARD   
      @n          PARTICLE_PM1_0_ATMOSPHERE
      @n          PARTICLE_PM2_5_ATMOSPHERE
      @n          PARTICLE_PM10_ATMOSPHERE 
      @return 浓度（ug/m3）
    '''
    def gain_particle_concentration_ugm3(self,PMtype):

    '''!
      @brief 获取在0.1升空气中的颗粒物的个数
      @param type PARTICLENUM_0_3_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_0_5_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_1_0_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_2_5_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_5_0_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_10_UM_EVERY0_1L_AIR 
      @return 颗粒物个数
    '''
    def gain_particlenum_every0_1l(self,PMtype):

    '''!
      @brief 向传感器的指定寄存器写入数据
      @return 固件版本
    '''
    def gain_version(self):

    '''
      @brief 控制传感器进入低功耗模式
    '''
    def set_lowpower(self):

    '''
      @brief 控制传感器唤醒
    '''
    def awake(self):

    '''
      @brief writes data to a register
      @param reg register address
      @param data written data
    '''
    def write_reg(self, reg, data):

    '''
      @brief read the data from the register
      @param reg register address
      @param data read data
    '''
    def read_reg(self, reg ,len):
## Compatibility
MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
raspberry  |      √       |             |            | 
## History

- 23,11, 2021 - Version 1.0 released.


## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))