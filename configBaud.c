#include "config.h"
void configBaud(void)
{
    TXSTAbits.BRGH = LO;
    BAUDCONbits.BRG16 = LO;
    SPBRG = 25;
}
