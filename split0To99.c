/*This fuction takes an integer from 0 to 99
 and splits it into two numbers, tens and units eg 37 would be split into
 num.tens = 3 and num.units = 7. It returns these two values using a data structure variable*/
#include "config.h"

splitData split0To99(uint16_t number)
{
    splitData num;         // create a local struct variable of custom type splitUchar (defined in config.h)
    num.tensThousands =  number/10000;
    num.thousands = (number/1000)%10;
    num.hundreds = (number/100)%10;
    num.tens = (number/10)%10;
    num.units = number%10;
    return num;             // return the customer struct variable num to the calling function, which will then display them on the oLed display
}
