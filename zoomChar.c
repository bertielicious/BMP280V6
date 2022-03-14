#include "config.h"
#include "setColumnAddress.h"
/* Overview: function can zoom any 8 x 8 bitmap by 1, 2,3 or 4 times.
 * Input: uint8_t LSbyte, uint8_t MSbyte, uint8_t col, uint8_t zoomFactor
 * Output: struct zoomPix containing a.zoomedByte1, a.zoomedByte2, a.col
 *******************************************************************************************************************/
zoomPix zoomChar(uint8_t unzoomedByte, uint8_t zoomFactor)
{
    zoomPix a;
    uint8_t byteBit7, byteBit6, byteBit5, byteBit4, byteBit3, byteBit2, byteBit1, byteBit0;
   /* if(zoomFactor == 1)
    {
        byteBit0 = (unzoomedByte & 0b00000001); // calculates page 0 zoomed byte, a byte at a time with every function call
        byteBit1 = (unzoomedByte & 0b00000010);
        byteBit2 = (unzoomedByte & 0b00000100);
        byteBit3 = (unzoomedByte & 0b00001000);
        byteBit4 = (unzoomedByte & 0b00010000);
        byteBit5 = (unzoomedByte & 0b00100000);
        byteBit6 = (unzoomedByte & 0b01000000);
        byteBit7 = (unzoomedByte & 0b10000000);
        a.zoomedByte0 = byteBit7 | byteBit6 | byteBit5 |  byteBit4 | byteBit3 |  byteBit2 | byteBit1 | byteBit0;
    }*/
    if(zoomFactor == 2)
    {
        byteBit0 = (unzoomedByte & 0b00000001); // calculates page 0 zoomed byte, a byte at a time with every function call
        byteBit1 = byteBit0;
        byteBit2 = (unzoomedByte & 0b00000010);
        byteBit3 = byteBit2;
        byteBit4 = (unzoomedByte & 0b00000100);
        byteBit5 = byteBit4;
        byteBit6 = (unzoomedByte & 0b00001000);
        byteBit7 = byteBit6;
        a.zoomedByte0 = (byteBit7<<4) | (byteBit6<<3) | (byteBit5<<3) |  (byteBit4<<2) | (byteBit3<<2) |  (byteBit2<<1) | (byteBit1<<1) | byteBit0;

        byteBit0 = (unzoomedByte & 0b00010000)>>4;    // calculates page 1 zoomed byte, a byte at a time with every function call
        byteBit1 = byteBit0;
        byteBit2 = (unzoomedByte & 0b00100000)>>4;
        byteBit3 = byteBit2;
        byteBit4 = (unzoomedByte & 0b01000000)>>4;
        byteBit5 = byteBit4;
        byteBit6 = (unzoomedByte & 0b10000000)>>4;
        byteBit7 = byteBit6;
 
        a.zoomedByte1 = (byteBit7<<4) | (byteBit6<<3) | (byteBit5<<3) |  (byteBit4<<2) | (byteBit3<<2) |  (byteBit2<<1) | (byteBit1<<1) | byteBit0;
    }
    if(zoomFactor == 3)
    {
        /************PAGE 0*****************/
        byteBit0 = (unzoomedByte & 0b00000001); // check for a '1', keep result in low nibble
        byteBit1 = byteBit0<<1;
        byteBit2 = byteBit0<<2;
       
        byteBit3 = (unzoomedByte & 0b00000010)>>1; // check for a '2', keep result in mid nibble
        byteBit4 = byteBit3<<1;
        byteBit5 = byteBit3<<2;
        
        byteBit6 = (unzoomedByte & 0b00000100)>>2; // check for a '2', keep result in mid nibble
        byteBit7 = byteBit6<<1;
        byteBit5 = byteBit6<<2;
 
       // a.zoomedByte1 = 
    }
    if(zoomFactor == 4)
    {
       /**********PAGE 0************/
        byteBit0 = unzoomedByte & 0b00000001;   //check if the read byte from the number to be zoomed contains a '1', keep result in low nibble
        byteBit1 = byteBit0<<1;
        byteBit2 = byteBit0<<2;
        byteBit3 = byteBit0<<3;
        
        byteBit4 = (unzoomedByte & 0b00000010)<<3;// shift the result up to the high nibble - check for a '2'
        byteBit5 = byteBit4<<1;
        byteBit6 = byteBit4<<2;
        byteBit7 = byteBit4<<3;
        a.zoomedByte0 = byteBit7 | byteBit6 | byteBit5 |  byteBit4 |  byteBit3 |  byteBit2| byteBit1 | byteBit0;
        
         /**********PAGE 1************/
        byteBit0 = (unzoomedByte & 0b00000100)>>2;  //check for '4', shift the 1 down to LSB of the lower nibble, so that we can duplicate it 3 times
        byteBit1 = byteBit0<<1;
        byteBit2 = byteBit0<<2;
        byteBit3 = byteBit0<<3;
        
        byteBit4 = (unzoomedByte & 0b00001000)<<1;  //check for '8', shift the '1' up to the LSB of the high nibble, so that we can duplicate it 3 times
        byteBit5 = byteBit4<<1;
        byteBit6 = byteBit4<<2;
        byteBit7 = byteBit4<<3;
        a.zoomedByte1 = byteBit7 | byteBit6 | byteBit5 |  byteBit4 |  byteBit3 |  byteBit2| byteBit1 | byteBit0;
        
         /**********PAGE 2************/
        byteBit0 = (unzoomedByte & 0b00010000)>>4;
        byteBit1 = byteBit0<<1;
        byteBit2 = byteBit0<<2;
        byteBit3 = byteBit0<<3;
        
        byteBit4 = (unzoomedByte & 0b00100000)>>1;
        byteBit5 = byteBit4<<1;
        byteBit6 = byteBit4<<2;
        byteBit7 = byteBit4<<3;
        a.zoomedByte2 = byteBit7 | byteBit6 | byteBit5 |  byteBit4 |  byteBit3 |  byteBit2| byteBit1 | byteBit0;
        
        /**********PAGE 3************/
        byteBit0 = (unzoomedByte & 0b01000000)>>6;
        byteBit1 = byteBit0<<1;
        byteBit2 = byteBit0<<2;
        byteBit3 = byteBit0<<3;
        
        byteBit4 = (unzoomedByte & 0b10000000)>>3;
        byteBit5 = byteBit4<<1;
        byteBit6 = byteBit4<<2;
        byteBit7 = byteBit4<<3;
        a.zoomedByte3 = byteBit7 | byteBit6 | byteBit5 |  byteBit4 |  byteBit3 |  byteBit2| byteBit1 | byteBit0;
    }  
       return a;    // returns zoomedByte0 (page0) and zoomedByte1 (page1) and colP0, colP1 to the caller
       
}
