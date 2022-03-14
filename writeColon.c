#include "config.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "selectDigit.h"
#include "oLedWrite.h"
void writeColon(uint8_t colAddr, uint8_t pageAddr, uint8_t symbol, uint8_t repeat)
{
    uint16_t *number;
    uint8_t i;
    setColumnAddress(colAddr);
    setPageAddress(pageAddr);
    number = selectDigit(symbol);
    for(i = 0; i < repeat; i++)
    {
        oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW,*number);
        number++;
    }
    
}
