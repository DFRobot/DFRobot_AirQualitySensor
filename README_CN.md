# DFRobot_AirQualitySensor

- [English Version](./README.md)

PM2.5空气质量传感器采用的是一款基于激光散射原理的数字式通用颗粒物传感器，可连续采集并计算单位体积内空气中不同粒径的悬浮颗粒物个数，即颗粒物浓度分布，进而换算成为质量浓度，并利用I2C接口输出相关数据。本传感器可嵌入各种与空气中悬浮颗粒物浓度相关的仪器仪表或环境改善设备，为其提供及时准确的浓度数据。

![正反面svg效果图](./resources/images/SEN0460.png)

## 产品链接（[https://www.dfrobot.com.cn/goods-3355.html](https://www.dfrobot.com.cn/goods-3355.html)）

    SKU：SEN0460

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

这个库提供了获取空气中指定颗粒物大小以百分比或者以个数输出的例程

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```C++
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
``` 

## 兼容性

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266|      √       |              |             | 
Mega2560  |      √       |             |            | 
Arduino uno |       √      |             |            | 
Leonardo  |      √       |              |             | 
Micro:bit  |      √       |              |             | 

## 历史

- 2021/11/23 - 1.0.0 版本

## 创作者

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))