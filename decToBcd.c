#include "config.h"

uint8_t decToBcd(uint8_t dec)
{
    uint8_t tens, units, bcd = 0;
    tens = (dec/10)<<4;
    units = dec%10;
    bcd = tens | units;
    return bcd;
}
