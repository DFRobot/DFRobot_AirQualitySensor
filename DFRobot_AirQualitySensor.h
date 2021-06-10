/*!
  * @file DFRobot_AirQualitySensor.h
  * @brief 该传感器可以获取空气中相关颗粒物的浓度
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @licence     The MIT License (MIT)
  * @author      PengKaixing(kaixing.peng@dfrobot.com)
  * @version     V0.1
  * @date        2021-05-20
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/dfrobot/DFRobot_AirQualitySensor
  */

#ifndef __DFR0bot_AIR_H__
#define __DFR0bot_AIR_H__

#include "Arduino.h"
#include <Wire.h>

// Open this macro to see the program running in detail
//#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...)                     \
    {                                \
        Serial.print("[");           \
        Serial.print(__FUNCTION__);  \
        Serial.print("(): ");        \
        Serial.print(__LINE__);      \
        Serial.print(" ] 0x");         \
        Serial.println(__VA_ARGS__,HEX); \
    }
#else
#define DBG(...)
#endif

/*
  DFR0460 主动上报协议
   * -----------------------------------------------------------------------------------------------------------
   * | reg0  | reg1     |    reg2   |    reg3    |   reg4   |  reg5  +  reg6   |  reg7   +  reg8  | reg9 +
   * ----------------------------------------------------------------------------------------------------------
   * |reserve |reserve |    reserve |   reserve  |  reserve | PM1.0 浓度（H+L）|   PM2.5 浓度     | PM10 
   * -----------------------------------------------------------------------------------------------------------
   * 
   * -----------------------------------------------------------------------------------------------------------
   *  reg10  | reg11  +   reg12   |    reg13    +  reg14  |reg15   +  reg16 | reg17  + reg18     |
   * -----------------------------------------------------------------------------------------------------------
   *  浓度   |PM1.0 浓度（大气下）|  PM2.5 浓度（大气下）  | PM10 浓度（大气下） | 0.3um颗粒物个数/0.1L空气|
   * -----------------------------------------------------------------------------------------------------------
   * 
   * -----------------------------------------------------------------------------------------------------------
   * |    reg19  + reg20    | reg21   +    reg22 |  reg23  +  reg24     |  reg25   +  reg26   | reg27 +
   * -----------------------------------------------------------------------------------------------------------
   * | 0.5um颗粒物个数/0.1L空气|1.0um颗粒物个数/0.1L空气 | 2.5um颗粒物个数/0.1L空气|5.0um颗粒物个数/0.1L空气| 
   * -----------------------------------------------------------------------------------------------------------
   * 
   * -----------------------------------------------------------------------------------------------------------
   *         reg28         |   reg29  | 
   * -----------------------------------------------------------------------------------------------------------
   * 10um颗粒物个数/0.1L空气 |   版本号  | 
   * -----------------------------------------------------------------------------------------------------------
*/

#define PARTICLE_PM1_0_STANDARD   0X05
#define PARTICLE_PM2_5_STANDARD   0X07
#define PARTICLE_PM10_STANDARD    0X09
#define PARTICLE_PM1_0_ATMOSPHERE 0X0B
#define PARTICLE_PM2_5_ATMOSPHERE 0X0D
#define PARTICLE_PM10_ATMOSPHERE  0X0F

#define PARTICLENUM_0_3_UM_EVERY0_1L_AIR 0X11
#define PARTICLENUM_0_5_UM_EVERY0_1L_AIR 0X13
#define PARTICLENUM_1_0_UM_EVERY0_1L_AIR 0X15
#define PARTICLENUM_2_5_UM_EVERY0_1L_AIR 0X17
#define PARTICLENUM_5_0_UM_EVERY0_1L_AIR 0X19
#define PARTICLENUM_10_UM_EVERY0_1L_AIR  0X1B

#define PARTICLENUM_GAIN_VERSION 0X1D

class DFRobot_AirQualitySensor
{
  public:
    DFRobot_AirQualitySensor(){};
    ~DFRobot_AirQualitySensor(){};
/*!
 *  @brief 获取指定颗粒物类型的浓度
 *  @param type:PARTICLE_PM1_0_STANDARD  
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
 *  @param type:PARTICLENUM_0_3_UM_EVERY0_1L_AIR
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
 *  @param NULL
 *  @return 没有返回值
 */
    uint8_t gainVersion();
  protected:
/*!
 *  @brief 向传感器的指定寄存器写入数据
 *  @param Reg ：需要写入的寄存器地址
 *         Data：等待写入寄存器的数据
 *         len ：等待写入的数据的长度
 *  @return 没有返回值
 */
    virtual void writeReg(uint8_t Reg, void *Data, uint8_t len) = 0;

/*!
 *  @brief 从指定传感器中获取指定长度的数据
 *  @param INITIATIVE：传感器主动上报
 *         PASSIVITY ：主控发送请求，传感器才能上报数据
 *  @return status  ：init status
 *          true is ：init success
 *          false is：init error
 */
    virtual int16_t readReg(uint8_t Reg, uint8_t *Data, uint8_t len) = 0;

  private:
};

class DFRobot_AirQualitySensor_I2C : public DFRobot_AirQualitySensor
{
  public:
    DFRobot_AirQualitySensor_I2C(TwoWire *pWire = &Wire, uint8_t addr = 0x19);
    ~DFRobot_AirQualitySensor_I2C(){};
/*!
 *  @brief IIC初始化
 *  @param NULL
 *  @return true:成功
 *          false：失败
 */
    bool begin();
  protected:
    void writeReg(uint8_t Reg, void *Data, uint8_t len);
    int16_t readReg(uint8_t Reg, uint8_t *Data, uint8_t len);

  private:
    TwoWire *_pWire;
    uint8_t _I2C_addr;
};

#endif