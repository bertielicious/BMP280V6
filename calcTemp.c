#include "config.h"

/*******************************************************************************************************************
 * Function: calcTemp
 * Overview: function calculates temperature in degC taking into account trim parameters and adc value
 * Input: adc_T = temp_msb, lsb and xlsb in 20-bit form - typecast required to type BMP280_S32_t
 * Output: returns temperature in degrees C to the caller
 *******************************************************************************************************************/

int32_t calcTemp(int32_t adc_T, caliTemp num)
{
    int32_t t_fine;
    int32_t var1, var2, T;  
     
    var1 = ((((adc_T>>3) - (num.digT1<<1))) * (num.digT2)) >> 11;
    var2 = (((((adc_T>>4) - (num.digT1)) * ((adc_T>>4) - (num.digT1))) >>12) * (num.digT3)) >> 14;
    //printf("var1 %d   var2 %d\n", var1, var2);
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T; 
}

