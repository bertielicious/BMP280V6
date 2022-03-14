#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cReStart.h"
#include "i2cStop.h"
#include "i2cRead.h"
uint8_t readPCF8583(uint8_t slaveAddr, uint8_t registerAddr)
{
    uint8_t regRead;
    i2cCheckBusIdle();
    i2cStart();
    i2cWrite(slaveAddr);     // slave address RW = 0
    i2cWrite(registerAddr);     //seconds register
    i2cReStart();
    i2cWrite(slaveAddr + 1);     // slave address RW = 1
    regRead = i2cRead();
    i2cStop();
    return regRead;
}