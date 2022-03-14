#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cRead.h"
#include "i2cReStart.h"
#include "i2cStop.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "split0To99.h"
#include "write8x8ToOled.h"
void readRegDispOled (uint8_t slaveAddW, uint8_t regAdd, uint8_t column, uint8_t page)
{
    uint8_t temp, temp_data;
    splitData dig;
    i2cCheckBusIdle();
    i2cStart();     // issue start condition to begin i2c exchange
    i2cWrite(slaveAddW); // send slave address write mode
    i2cWrite(regAdd); // send device id register address
    i2cReStart();   // repeated start condition generated
    i2cWrite(slaveAddW + 1); // send slave address read mode
    temp = i2cRead();
    i2cStop();
    if(temp != temp_data)    // if temperature has changed
        {
            temp_data = temp;
            temp_data = temp_data%100;// knock off the hundreds digit
            dig = split0To99(temp_data);
            setPageAddress(page);
            setColumnAddress(column);
         //   write8x8ToOled(dig.tens);
            setColumnAddress(column + 8);
          //  write8x8ToOled(dig.units);
        }
        
}
