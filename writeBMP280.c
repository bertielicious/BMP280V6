#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cStop.h"
void writeBMP280(uint8_t REG_ADDRESS, uint8_t dataByte)
{
    i2cCheckBusIdle();
    i2cStart();                     // issue the start condition
    i2cWrite(BMP280_WRITE_ADDR);    // send the write slave address to BMP280 which is 0xEC
    i2cWrite(REG_ADDRESS);          // send control byte which is the address of the register inside the BMP280 we want to write to
    i2cWrite(dataByte);             // send the data we want to write into the register address of the BMP280 we selected one the line above
    i2cStop();                      // issue stop condition
}
