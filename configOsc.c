#include "constVar.h"
void configOsc(void)
{
    OSCCONbits.IRCF3 = HI;  // 16MHz system clock (aka Fosc))
    OSCCONbits.IRCF2 = HI;  // instruction clock = Fosc/4 i.e 4MHz
    OSCCONbits.IRCF1 = HI;
    OSCCONbits.IRCF0 = HI;
    
    OSCCONbits.SCS1 = HI;   // select internal oscillator block
    
}