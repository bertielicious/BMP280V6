/*22.6.9 STOP CONDITION TIMING
A Stop bit is asserted on the SDA pin at the end of a
receive/transmit by setting the Stop Sequence Enable
bit, PEN bit of the SSPCON2 register. At the end of a
receive/transmit, the SCL line is held low after the
falling edge of the ninth clock. When the PEN bit is set,
the master will assert the SDA line low. When the SDA
line is sampled low, the Baud Rate Generator is
reloaded and counts down to ?0?. When the Baud Rate
Generator times out, the SCL pin will be brought high
and one TBRG (Baud Rate Generator rollover count)
later, the SDA pin will be deasserted. When the SDA
pin is sampled high while SCL is high, the P bit of the
SSPSTAT register is set. A TBRG later, the PEN bit is
cleared and the SSPIF bit is set (Figure 22-31).*/
#include "config.h"
#include "i2cCheckBusIdle.h"
void i2cStop(void)
{
    SSPCON2bits.PEN = HI;// if PEN is set it will hold SDA low while SCL is high = STOP condition
    while(SSPCON2bits.PEN == HI); // wait until PEN is low
    PIR1bits.SSP1IF = LO;
    i2cCheckBusIdle();
}
