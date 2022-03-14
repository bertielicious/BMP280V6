#include "config.h"
#include "selectDigit.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "zoomChar.h"
#include "oLedWrite.h"
void writeZoomedDigit(uint8_t colAddr, uint8_t pageAddr, splitData woofer, uint8_t zoomFactor, zoomPix xonk)
{
    uint8_t i, j;                        // loop counter
    uint16_t *num;                      // pointer to array returned from selectDigit function
    setColumnAddress(colAddr);
    setPageAddress(pageAddr);
    num = selectDigit(woofer.units);    // get first element of array containing selected decimal number 0 - 9
    
    for(i = 0; i <8; i++)
   
    {
         
        
             if(zoomFactor == 1)
             {
                     oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, *num);
                     num++;
             }
             if(zoomFactor == 2)
             {
             //    xonk = zoomChar(*num, zoomFactor);  // calculate position of each pixel for zoomFactor x1, x2, x3, x4
              //   oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, xonk.zoomedByte0);
             }
             
            
    }
}
