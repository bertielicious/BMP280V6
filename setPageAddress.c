/*This function returns the page address to the caller
 * by accepting the required page number as a parameter */
#include "config.h"
#include "oLedWrite.h"
void setPageAddress(uchar page)
{
    uchar pageAddr;
    pageAddr = page | (0b10110000);// page takes a value from 0 to 7   
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddr);
    //printf(" in func pageAddr %d\n", pageAddr);
    //return pageAddr;
}