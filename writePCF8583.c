#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"
/********************************************************************************
 * Overview: function allows us to write time/ date/ alarm to PCF8583
 * Input: uint8_t addrByte, uint8_t regAddr, uint8_t dataByte
 * Output: write time/ date/ alarm to PCF8583*********************************
 * Algorithm: initiate i2c start condition, then send slave address of PCF8583<<1|R/W bit.
 * now send Register address you wish to write data to. Then send the dataByte in BCD format,
 * followed by i2c stop condition
 *****************************************************************************/
void writePCF8583(uint8_t addrByte, uint8_t regAddr, uint8_t dataByte)
{
    i2cCheckBusIdle();
    i2cStart();
    i2cWrite(addrByte);     // r/w bit is 0 for write, address Byte = 0xa0
    i2cWrite(regAddr);
    i2cWrite(dataByte);
    i2cStop();    
}
