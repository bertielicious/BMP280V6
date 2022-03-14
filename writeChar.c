#include "config.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "oLedWrite.h"
void writeChar(uint8_t colAddr, uint8_t pageAddr, uint8_t zoomFactor, splitData yowi)
{
    uint8_t i;
    uint16_t *num;
    if(zoomFactor == 1)
        setColumnAddress(colAddr);
        setPageAddress(pageAddr);
        
//        num = selectDigit(woofer.tens); // seconds tens
        for (i = 0; i < 8; i++)     // write the selected 8x8 bit map array to the display, using pointer *number which contains the 1st element of the bit map array eg array[0]]
        {
            oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, *num);// write the first array element to the display
            num++; // write the 2nd - 8th element of the array to the display
        }
}


