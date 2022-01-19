# DFRobot_AirQualitySensor

- [中文版](./README_CN.md)

Based on the principle of laser scattering, the PM2.5 air quality sensor employs a digital universal particle sensor that can continuously collect and calculate the number of suspended particles of different sizes in the air per unit volume, which is particle concentration distribution, and then convert it to quality concentration and output data via I2C interface. The sensor can be embedded in various instruments and meters or environmental improvement equipment related to the concentration of suspended particulate matter in the air to provide timely and accurate concentration data.

![正反面svg效果图](./resources/images/SEN0460.png)

## Product Link（[https://www.dfrobot.com/product-2439.html](https://www.dfrobot.com/product-2439.html)）

    SKU：SEN0460

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

This library provides sample codes to obtain the percentage or number of particles of different particle sizes in air.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
   /**
    * @fn begin
    * @brief Init
    * @return Bool type, indicate whether init succeeded
    * @retval True Succeeded
    * @retval False Failed
    */
   bool begin(void);      
   /**
    * @fn gainParticleConcentration_ugm3
    * @brief Get particle concentration of a specific type
    * @param type: Set PM type to be output
    * @n          PARTICLE_PM1_0_STANDARD
    * @n          PARTICLE_PM2_5_STANDARD
    * @n          PARTICLE_PM10_STANDARD
    * @n          PARTICLE_PM1_0_ATMOSPHERE
    * @n          PARTICLE_PM2_5_ATMOSPHERE
    * @n          PARTICLE_PM10_ATMOSPHERE
    * @return uint16_t type, indicate returning the particle concentration of the specific type
    */
   uint16_t gainParticleConcentration_ugm3(uint8_t type);      
   /**
    * @fn gainParticleNum_Every0_1L
    * @brief Get the number of particles in 0.1L of air
    * @param type: Set particle type to be output
    * @n          PARTICLENUM_0_3_UM_EVERY0_1L_AIR
    * @n          PARTICLENUM_0_5_UM_EVERY0_1L_AIR
    * @n          PARTICLENUM_1_0_UM_EVERY0_1L_AIR
    * @n          PARTICLENUM_2_5_UM_EVERY0_1L_AIR
    * @n          PARTICLENUM_5_0_UM_EVERY0_1L_AIR
    * @n          PARTICLENUM_10_UM_EVERY0_1L_AIR
    * @return uint16_t type, indicate the particle number in every 0.1L of air
    */
   uint16_t gainParticleNum_Every0_1L(uint8_t type);      
   /**
    * @fn gainVersion
    * @brief Get firmware version
    * @return uint8_t type, firmware version
    */
   uint8_t gainVersion(void);      
   /**
    * @fn setLowpower
    * @brief Control the sensor to enter low-power mode
    */
   void setLowpower(void);      
   /**
    * @fn awake
    * @brief Wake up sensor
    */
   void awake(void);
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

- 2021/11/23 - Version 1.0.0 released.


## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
