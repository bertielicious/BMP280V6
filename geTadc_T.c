#include "config.h"
#include "i2cCheckBusIdle.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cReStart.h"
#include "i2cRead.h"
#include "i2cStop.h"
/*******************************************************************************************************************
 * Function: geTadc_T
 * Overview: function reads the three temperature registers temp_msb, temp_lsb and temp_xlsb, combines them into a 32 bit value
 * Input: none
 * Output: 32 bit value adc_T which is the uncompensated temperature value
 *******************************************************************************************************************/
int32_t geTadc_T(void)
{
    uint8_t i;
    uint8_t temp_msb, temp_lsb, temp_xlsb;
    int32_t adc_T;
    for(i = 0; i < 3; i++)  // read registers temp_msb, temp_lsb, and temp_xlsb
    {
        i2cCheckBusIdle();
        i2cStart();     // issue start condition to begin i2c exchange
        i2cWrite(0xec); // send slave address write mode
        i2cWrite(0xfa + i); // send device id register address
        i2cReStart();   // repeated start condition generated
        i2cCheckBusIdle();
        i2cWrite(0xed); // send slave address read mode
        i2cCheckBusIdle();
        if(i == 0)
        {
            temp_msb = i2cRead(); //  read the temp_msb data byte from register 0xfa of the slave 
        }
        else if(i == 1)
        {
            temp_lsb = i2cRead(); //  read the temp_lsb data byte from register 0xfb of the slave 
        }
        else if(i == 2)
        {
            temp_xlsb = i2cRead(); // t read the temp_xlsb data byte from register 0xfc of the slave 
        }
        i2cStop();  
        i2cCheckBusIdle();
    }
    adc_T = (int32_t)(temp_msb<<12) | (int32_t)(temp_lsb<<4) | (int32_t)(temp_xlsb>>4);    // combine the temperature reads into one (20)bit 32 bit value
    return adc_T;
}
