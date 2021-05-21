#include "DFRobot_AirQualitySensor.h"

uint16_t DFRobot_AirQualitySensor::gainParticleConcentration_ugm3(uint8_t type)
{
  uint8_t buf[2];
  readReg(type, buf, 2);
  uint16_t concentration = ((uint16_t)buf[0] << 8) + (uint16_t)buf[1];
  return concentration;
}

uint16_t DFRobot_AirQualitySensor::gainParticleNum_Every0_1L(uint8_t type)
{
  uint8_t buf[2];
  readReg(type, buf, 2);
  uint16_t particlenum = ((uint16_t)buf[0] << 8) + (uint16_t)buf[1];
  return particlenum;
}

uint8_t DFRobot_AirQualitySensor::gainVersion()
{
  uint8_t version = 0 ;
  readReg(PARTICLENUM_GAIN_VERSION, &version, 1);
  return version;
}

//IIC底层通信
DFRobot_AirQualitySensor_I2C::DFRobot_AirQualitySensor_I2C(TwoWire *pWire, uint8_t addr)
{
  _pWire = pWire;
  this->_I2C_addr = addr;
}

bool DFRobot_AirQualitySensor_I2C::begin()
{
  _pWire->begin();
  _pWire->beginTransmission(_I2C_addr);
  if (_pWire->endTransmission() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void DFRobot_AirQualitySensor_I2C::writeReg(uint8_t Reg, void *pData, uint8_t len)
{
  uint8_t *Data = (uint8_t *)pData;
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(Reg);
  for (uint8_t i = 0; i < len; i++)
  {
    _pWire->write(Data[i]);
  }
  _pWire->endTransmission();
}

int16_t DFRobot_AirQualitySensor_I2C::readReg(uint8_t Reg, uint8_t *Data, uint8_t len)
{
  int i = 0;
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(Reg);
  if (_pWire->endTransmission() != 0)
  {
    return -1;
  }
  _pWire->requestFrom((uint8_t)this->_I2C_addr, (uint8_t)len);
  while (_pWire->available())
  {
    Data[i++] = _pWire->read();
  }
  return len;
}