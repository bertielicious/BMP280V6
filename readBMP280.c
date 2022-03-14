/*This function accepts a BMP280 register address (0x00 to 0xFF) to be read from, and then returns the 
 register contents (0x00 to 0xFF) to the caller*/


#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cRead.h"
#include "i2cReStart.h"
#include "i2cStop.h"

uint8_t readBMP280(uint8_t REG_ADDRESS)
{
    uint8_t registerContents;
    i2cCheckBusIdle();
    i2cStart();                     // issue the start condition
    i2cWrite(0xec);    //write address BMP280 is 0xEC or 0b11101100 lsb is R/W bit
    i2cWrite(REG_ADDRESS);          // CHIP_ID_REG address 0xD0
    i2cReStart();
    i2cWrite(0xed);     // read address BMP280 is 0xED
    registerContents = i2cRead();
    return registerContents;
}
