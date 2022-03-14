#include "config.h"
void configOsc(void)
{
    OSCCONbits.IRCF3 = HI;  // 16MHz int osc
    OSCCONbits.IRCF2 = HI;
    OSCCONbits.IRCF1 = HI;
    OSCCONbits.IRCF2 = HI;
    
    OSCCONbits.SCS1 = HI;   // interneal oscillator eselected
    OSCCONbits.SCS0 = HI;
    /*
     bit 5-2 IRCF<3:0>: Internal Oscillator Frequency Select bits
1111 = 16 MHz or 48 MHz HF (see Section 5.2.2.1 ?HFINTOSC?)
1110 = 8 MHz or 24 MHz HF (3x PLL) or 32 MHz HF (4x PLL) (see Section 5.2.2.1 ?HFINTOSC?)
1101 = 4MHz
1100 = 2MHz
1011 = 1MHz
1010 = 500 kHz(1)
1001 = 250 kHz(1)
1000 = 125 kHz(1)
0111 = 500 kHz (default upon Reset)
0110 = 250 kHz
0101 = 125 kHz
0100 = 62.5 kHz
001x = 31.25 kHz(1)
000x = 31 kHz LF
bit 1-0 SCS<1:0>: System Clock Select bits
1x = Internal oscillator block
01 = Secondary oscillator
00 = Clock determined by FOSC<2:0> in Configuration Words.*/
}