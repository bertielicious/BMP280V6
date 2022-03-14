#include "config.h"

uint8_t  bcdToDecimal(uint8_t byte)
{
    return((byte>>4)*10 + (byte & 0x0f));
   
}
