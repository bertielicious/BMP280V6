#include "config.h"
#include "clearSH1106.h"
#include "writePCF8583.h"
#include "decToBcd.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "split0To99.h"
#include "oLedWrite.h"
#include "selectDigit.h"
#include "writeColon.h"

/********************User interface************************/
/*Overview: This function disables the clock counting, then allows the input of current time
Input: */

uint8_t UserInterface(uint8_t state)
{
    static uint8_t setSecs = 0;
    static uint8_t setMins = 0;
    static uint8_t setHours = 0;
    static uint8_t result;
    static uint8_t bcd;
    static splitData time;
    
   
    
    switch(state)
    {
    case 1:
        writePCF8583(0xa0, 0x00, 0x80); // stop counting
        writePCF8583(0xa0, 0x02, 0x00); // seconds reset to 0
        
        writeColon(2,0,'S', 8);// write 'Set time?' on page 0
        writeColon(10,0,'e', 8);
        writeColon(18,0,'t', 8);
        writeColon(34,0,'t', 5);
        writeColon(42,0,'i', 5);
        writeColon(50,0,'m', 8);
        writeColon(58,0,'e', 8);
        writeColon(66,0,'Q', 8);    //?
        
        if(UP == LO)
        {
            state = 2;
        }
        if(DOWN == LO)
        {
            state = 14;
        }
       
        break;
    
    case 2:
        writeColon(2,2,'h', 8);
        writeColon(10,2,'o', 8);
        writeColon(18,2,'u', 8);
        writeColon(26,2,'r', 8);
        writeColon(34,2,'s', 8);
        if(UP == 0 || DOWN == LO)
        {
            state = 3;
        }
        break;
        
    case 3:
        time = split0To99(setHours);
        writeColon(58, 2, time.units, 8);
        writeColon(50, 2, time.tens, 8);
        if(UP == LO)
        {
            state = 4;
        }
        else if(DOWN == LO)
        {
            state = 5;
        }
        else if(ENT == LO)
        {
            state = 6;
        }
        break;
            
        case 4:
            if(setHours >= 0 && setHours < 23)
            {
                setHours++;
                __delay_ms(100);
            }
            state = 3;
            break;
            
        case 5:
             if(setHours >= 1 && setHours< 24)
            {
                setHours--;
                __delay_ms(100);
            }
            state = 3;
            break;  
            
        case 6: 
            result = decToBcd(setHours);
            //printf("hours %d\n", result);
            state = 7;
            break;
            
        case 7:
            writePCF8583(0xa0, 0x04, result);
            state = 8;
            break;
        
        case 8:
            writeColon(2,4,'m', 8);
            writeColon(10,4,'i', 8);
            writeColon(18,4,'n', 8);
            writeColon(26,4,'u', 8);
            writeColon(34,4,'t', 8);
            writeColon(42,4,'e', 8);
            writeColon(50,4,'s', 8);
            
        if(UP == 0 || DOWN == LO)
        {
            state = 9;
        }
        break;
        
        case 9:
        time = split0To99(setMins);
        writeColon(74, 4, time.units, 8);
        writeColon(66, 4, time.tens, 8);
        if(UP == LO)
        {
            state = 10;
        }
        else if(DOWN == LO)
        {
            state = 11;
        }
        else if(ENT == LO)
        {
            state = 12;
        }
        break;
            
        case 10:
            if(setMins >= 0 && setMins < 58)
            {
                setMins++;
                __delay_ms(100);
            }
            state = 9;
            break;
            
            
        case 11:
             if(setMins >= 1 && setMins< 59)
            {
                setMins--;
                __delay_ms(100);
            }
            state = 9;
            break;  
            
        case 12:
            result = decToBcd(setMins);
            state = 13;
            break;
            
        case 13:
            writePCF8583(0xa0, 0x03, result);
            state = 14;
            break;
        case 14:
            writePCF8583(0xa0, 0x00, 0x00);
            state = 15;
            break;
            
        case 15:   
            clearSH1106();
            state = 16;
            break;
            
        case 16:
            break;
            
       
    
    }
   printf("%d\n", state);
   return state;
}