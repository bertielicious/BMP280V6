#include "config.h"
#include "oLedWrite.h"
void setColumnAddress(uchar columnAddr)
{
    uchar highOffset = 0x10;    // 10000
    uchar lowOffset = 0x00;     // 00000
    
    uchar lowNib, highNib;
    lowNib = lowOffset | (columnAddr & 0x0f);
    highNib = highOffset | ((columnAddr & 0xf0)>>4);
   
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, highNib);
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, lowNib);
}
