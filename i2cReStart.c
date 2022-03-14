#include "config.h"
#include "i2cCheckBusIdle.h"
void i2cReStart(void)
{
    SSP1CON2bits.RSEN = HI; //initiate re-start condition  
    while(SSP1CON2bits.RSEN);  // wait for repeated start to complete
    PIR1bits.SSP1IF = 0;  // clear interrupt flag
    i2cCheckBusIdle();
}
