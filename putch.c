#include "config.h"

void putch(uchar byte)
{
    
    
    //while( ! TXIF)
    while(PIR1bits.TXIF == LO)   //while TXREG busy transmitting data
    {
        continue;               //wait for transmission to finish
    }
        TXREG = byte;// load character  into TXREG ready for transmission              
    
    
}
