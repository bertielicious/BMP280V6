#include "config.h"
#include "readBMP280.h"
 /*******************************************************************************************************************
 * Function: readTrimParam
 * Overview: function reads temperature or pressure trim parameters into struct and returns whole struct to caller
 * Input: none
 * Output: struct containing Trim Parameters digT1, digT2, digT3
 *******************************************************************************************************************/
    
caliTemp readTrimParam(void)
{
    caliTemp word;
 
    uint8_t numLsb, numMsb;
    numLsb = readBMP280(0x88); // read contents of lsbT1
    numMsb = readBMP280(0x89); // read contents of msbT1
    word.digT1 = (numMsb<<8) | numLsb;
    
    numLsb = readBMP280(0x8a); // read contents of lsbT2
    numMsb = readBMP280(0x8b); // read contents of msbT2
    word.digT2 = (numMsb<<8) | numLsb;
    
    numLsb = readBMP280(0x8c); // read contents of lsbT3
    numMsb = readBMP280(0x8d); // read contents of msbT3
    word.digT3 = (numMsb<<8) | numLsb;
    
    return word;                // return struct containing members word.digT1, word.digT2, word.digT3
}
