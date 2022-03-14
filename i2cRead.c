#include "config.h"
#include "i2cCheckBusIdle.h"
uint8_t i2cRead(void)
{
    i2cCheckBusIdle();
    uint8_t readByte = 0;
    SSPCON2bits.RCEN = HI;              // User sets the RCEN bit of the SSPCON2 register and the master clocks in a byte from the slave
   
    while(!SSPSTATbits.BF);     // while buffer is not full keep reading data into it
    PIR1bits.SSP1IF = LO;                               // After the 8th falling edge of SCL, SSPIF and BF are set
                                             // Master clears SSPIF and reads the received byte from SSPUF, clears BF.
    readByte = SSP1BUF;                 //copy received data into variable 'readByte'
    
   
    SSP1CON2bits.ACKDT = HI; // if ackflag = 0, ACK sent from master to slave, if ackflag = 1, NAK sent from master to slave
    SSP1CON2bits.ACKEN = HI;    // Masters ACK is clocked out to the slave and SSPIF is set
    while(SSP1CON2bits.ACKEN); //wait for ACK to complete
    PIR1bits.SSP1IF = LO;                            // User clears SSPIF
                                // Master sends a not ACK or Stop to end communication.
    return readByte;            // return received byte to calling function/ variable
}
