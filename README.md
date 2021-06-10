# DFRobot_AirQualitySensor
DFRobot's Air Quality Sensor

## DFR0bot_AirQualitySensor Library for Arduino
---------------------------------------------------------



## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>

## Installation

To use this library download the zip file, uncompress it to a folder named Installation.
Download the zip file first to use this library and uncompress it to a folder named Installation.

## Methods

```C++
/*!
 *  @brief 获取指定颗粒物类型的浓度
 *  @param 颗粒物类型:PARTICLE_PM1_0_STANDARD  
                      PARTICLE_PM2_5_STANDARD  
                      PARTICLE_PM10_STANDARD   
                      PARTICLE_PM1_0_ATMOSPHERE
                      PARTICLE_PM2_5_ATMOSPHERE
                      PARTICLE_PM10_ATMOSPHERE 
 *  @return 浓度（ug/m3）
 */
    uint16_t gainParticleConcentration_ugm3(uint8_t type);
    /*!
 *  @brief 获取在0.1升空气中的颗粒物的个数
 *  @param 颗粒物类型:PARTICLENUM_0_3_UM_EVERY0_1L_AIR
                      PARTICLENUM_0_5_UM_EVERY0_1L_AIR
                      PARTICLENUM_1_0_UM_EVERY0_1L_AIR
                      PARTICLENUM_2_5_UM_EVERY0_1L_AIR
                      PARTICLENUM_5_0_UM_EVERY0_1L_AIR
                      PARTICLENUM_10_UM_EVERY0_1L_AIR 
 *  @return 个数
 */
    uint16_t gainParticleNum_Every0_1L(uint8_t type);
    /*!
 *  @brief 向传感器的指定寄存器写入数据
 *  @param Reg ：需要写入的寄存器地址
 *         Data：等待写入寄存器的数据
 *         len ：等待写入的数据的长度
 *  @return 没有返回值
 */
    uint8_t gainVersion();
```
## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266|      √       |              |             | 
Mega2560  |      √       |             |            | 
Arduino uno |       √      |             |            | 
Leonardo  |      √       |              |             | 
Micro:bit  |      √       |              |             | 



## History

- 19,05, 2021 - Version 0.2 released.


## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))