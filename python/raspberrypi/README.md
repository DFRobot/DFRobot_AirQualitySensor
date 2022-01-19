# DFRobot_AirQualitySensor

- [中文版](./README_CN.md)

Based on the principle of laser scattering, the PM2.5 air quality sensor employs a digital universal particle sensor that can continuously collect and calculate the number of suspended particles of different sizes in the air per unit volume, which is particle concentration distribution, and then convert it to quality concentration and output data via I2C interface. The sensor can be embedded in various instruments and meters or environmental improvement equipment related to the concentration of suspended particulate matter in the air to provide timely and accurate concentration data.

![正反面svg效果图](../../resources/images/SEN0460.png)

## Product Link（[https://www.dfrobot.com/product-2439.html](https://www.dfrobot.com/product-2439.html)）

  SKU：SEN0460

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

This library provides routines to get the size of specified particles in the air output as percentage or number.

## Installation

Download the library to Raspberry Pi before use, then open the routine folder. Input python gainconcentration.py into the command line to execute a routine gainconcentration.py.

## Methods

```python
    '''!
      @brief Get concentration of specified type of PM
      @param type PARTICLE_PM1_0_STANDARD
      @n          PARTICLE_PM2_5_STANDARD  
      @n          PARTICLE_PM10_STANDARD   
      @n          PARTICLE_PM1_0_ATMOSPHERE
      @n          PARTICLE_PM2_5_ATMOSPHERE
      @n          PARTICLE_PM10_ATMOSPHERE 
      @return Concentration（ug/m3）
    '''
    def gain_particle_concentration_ugm3(self,PMtype):

    '''!
      @brief Get the number of PM in 0.1L of air
      @param type PARTICLENUM_0_3_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_0_5_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_1_0_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_2_5_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_5_0_UM_EVERY0_1L_AIR
      @n          PARTICLENUM_10_UM_EVERY0_1L_AIR 
      @return PM number
    '''
    def gain_particlenum_every0_1l(self,PMtype):

    '''!
      @brief Write data to the specified register of the sensor
      @return Firmware version
    '''
    def gain_version(self):

    '''
      @brief Control the sensor to enter low-power mode
    '''
    def set_lowpower(self):

    '''
      @brief Control sensor awaking
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
``` 

## Compatibility

| MCU         | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :--: | :----: | :----: | :--: |
| RaspberryPi2 |      |        |   √    |      |
| RaspberryPi3 |      |        |   √    |      |
| RaspberryPi4 |  √   |        |        |      |

* Python version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :--: | :----: | :----: | ---- |
| Python2 |  √   |        |        |      |
| Python3 |  √   |        |        |      |

## History

- 2021/11/23 - 1.0.0 version

## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
