#include "config.h"
void configPorts(void)
{
    ANSELA = 0x00;                  // disable all analogue inputs
    ANSELB = 0x00;
    ANSELC = 0x00;
    
    CM1CON0 = 0x00;                 // all COMPARATORS off
    CM2CON0 = 0x00;
    CM1CON1 = 0x00;
    CM2CON1 = 0x00;
    TRISAbits.TRISA4 = HI;          // UP/ Y button pin 3
  //  WPUAbits.WPUA4 = HI;            // weak pullup applied to RA4
    TRISAbits.TRISA5 = HI;          // UP/ Y button pin 2
  //  WPUAbits.WPUA5 = HI;            // weak pullup applied to RA5
    TRISCbits.TRISC7 = LO;          // diagnostic LED output on pin 9 RC7
    TRISBbits.TRISB5 = HI;          // ENT button pin 12
   // WPUBbits.WPUB5 = HI;            // weak pullup applied to RB5
}
