#include "config.h"
void i2cWrite(uint8_t byte)
{
    SSP1BUF = byte;                 // byte is 7 bit address, RW bit is 0 (write) or 1 (read))
    while(PIR1bits.SSP1IF == LO);   // wait for all 8 bits to be sent to slave
    PIR1bits.SSP1IF = LO;           // clear SSP1IF interrupt flag
    __delay_us(5);
    if(SSP1CON2bits.ACKSTAT)       // if NACK received
    {
        SSP1CON2bits.PEN = HI;          // initiate stop condition
        while(SSP1CON2bits.PEN);  // wait for stop condition to complete
    }
}
