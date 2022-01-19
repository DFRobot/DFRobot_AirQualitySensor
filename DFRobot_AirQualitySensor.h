/*!
 * @file DFRobot_AirQualitySensor.h
 * @brief The sensor can obtain PM concentration in the air.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2020-11-23
 * @url https://github.com/dfrobot/DFRobot_AirQualitySensor
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
    DFRobot_AirQualitySensor(TwoWire *pWire = &Wire, uint8_t addr = 0x19);
    ~DFRobot_AirQualitySensor(void){};
    /**
     * @fn begin
     * @brief Init
     * @return Bool type, indicate whether init succeeded
     * @retval True Succeed
     * @retval False Failed
     */
    bool begin(void);

    /**
     * @fn gainParticleConcentration_ugm3
     * @brief Get PM concentration of a specified type
     * @param type: Set PM types to be output
     * @n          PARTICLE_PM1_0_STANDARD
     * @n          PARTICLE_PM2_5_STANDARD
     * @n          PARTICLE_PM10_STANDARD
     * @n          PARTICLE_PM1_0_ATMOSPHERE
     * @n          PARTICLE_PM2_5_ATMOSPHERE
     * @n          PARTICLE_PM10_ATMOSPHERE
     * @return uint16_t type, indicate returning the PM concentration of the specified type
     */
    uint16_t gainParticleConcentration_ugm3(uint8_t type);

    /**
     * @fn gainParticleNum_Every0_1L
     * @brief Get the number of PM in 0.1L of air
     * @param type: Set PM types to be output
     * @n          PARTICLENUM_0_3_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_0_5_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_1_0_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_2_5_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_5_0_UM_EVERY0_1L_AIR
     * @n          PARTICLENUM_10_UM_EVERY0_1L_AIR
     * @return uint16_t type, indicate the particle numbers in every 0.1L of air
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

  protected:
    /**
     * @fn writeReg
     * @brief Write data to the specified register of the sensor
     * @param Register address to be written
     * @n     Reg ：register address
     * @param Data to be written to register
     * @n     Data：data pointer to the register
     * @param Length of data to be written
     * @n     len ：length of the data
     */
    void writeReg(uint8_t Reg, void *Data, uint8_t len);

    /**
     * @fn readReg
     * @brief Read data from the specified register of the sensor
     * @param Register address to be read
     * @n     Reg ：register address
     * @param The register data to be read
     * @n     Data：data pointer to the register
     * @param Length of the data to be read
     * @n     len ：length of the data
     */
    int16_t readReg(uint8_t Reg, uint8_t *Data, uint8_t len);

  private:
    TwoWire *_pWire;
    uint8_t _I2C_addr;
};
#endif
