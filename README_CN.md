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
    /**
     * @fn begin
     * @brief 初始化
     * @return bool类型，表示初始化是否成功
     * @retval True 成功
     * @retval False 失败
     */
    bool begin(void);

    /**
     * @fn gainParticleConcentration_ugm3
     * @brief 获取指定颗粒物类型的浓度
     * @param type:设置需要输出的颗粒物的类型
     * @n          PARTICLE_PM1_0_STANDARD
     * @n          PARTICLE_PM2_5_STANDARD
     * @n          PARTICLE_PM10_STANDARD
     * @n          PARTICLE_PM1_0_ATMOSPHERE
     * @n          PARTICLE_PM2_5_ATMOSPHERE
     * @n          PARTICLE_PM10_ATMOSPHERE
     * @return uint16_t类型，表示返回指定颗粒物类型的浓度
     */
    uint16_t gainParticleConcentration_ugm3(uint8_t type);

    /**
     * @fn gainParticleNum_Every0_1L
     * @brief 获取在0.1升空气中的颗粒物的个数
     * @param type:设置需要输出的颗粒物的类型
     * @n          PARTICLENUM_0_3_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_0_5_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_1_0_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_2_5_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_5_0_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_10_UM_EVERY0_1L_AIR
     * @return uint16_t类型，每0.1升气体中的颗粒物的个数
     */
    uint16_t gainParticleNum_Every0_1L(uint8_t type);

    /**
     * @fn gainVersion
     * @brief 获取固件版本
     * @return uint8_t类型，固件版本
     */
    uint8_t gainVersion(void);

    /**
     * @fn setLowpower
     * @brief 控制传感器进入低功耗模式
     */
    void setLowpower(void);

    /**
     * @fn awake
     * @brief 控制传感器唤醒
     */
    void awake(void);
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

- 23,11, 2021 - Version 1.0 released.


## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))