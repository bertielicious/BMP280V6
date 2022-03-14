#include "config.h"
void configI2C(void)
{
    TRISBbits.TRISB6 = HI;      // set RB6 and RB4 as open drain with 3.3k pull up resistors
    TRISBbits.TRISB4 = HI;
    SSPCON1bits.SSP1M3 = HI;    //I2C Master mode, clock = FOSC / (4 * (SSPADD+1))7
    SSPCON1bits.SSP1M2 = LO;
    SSPCON1bits.SSP1M1 = LO;
    SSPCON1bits.SSP1M0 = LO;
    SSPADD = 9; // SSPADD =  ((SCL period/4) * Fosc) - 1        
                //= ((10us/4) * 4MHz) - 1 = 9
    SSPCON1bits.SSPEN = HI;     // I2C module enabled by setting SSPEN bit
}
