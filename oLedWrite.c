#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"

void oLedWrite(uint8_t oLedAdd, uint8_t ctrlByte, uint8_t dataByte)
{
    i2cCheckBusIdle();
    i2cStart();
    i2cWrite(oLedAdd);                 
    i2cWrite(ctrlByte);      // 0x00 = command, 0x40 = display data          
    i2cWrite(dataByte);                 
    i2cStop();
}
