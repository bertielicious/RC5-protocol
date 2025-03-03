#include "constVar.h"
void resetRC5(void)
{
    INTCONbits.IOCIE = 0;         // disables IOC interrupt (master switch))
    UCONbits.USBEN = 0;           // disable USB module  
    INTCONbits.IOCIF = 0;         // clear IOC interrupt flag
  
    IOCBPbits.IOCBP5 = 0;         // disable detection of rising edges on RB5 pin 12
    IOCBNbits.IOCBN5 = 0;         // disable detection of falling edges on RB5 pin 12
    IOCBFbits.IOCBF5 = 0;         // clear IOC FLAG FOR RB5 pin 12
    
    has_run = 0;                  // allows code block to run until has_run = 1
    pulse_type = SP;              //initialises first pulse type from IR
    state = MID1;                 // entry state into IR decoding finite state machine
    RC5_code = 0x0000;            // clear value held in IR code variable
    bits = 14;
    magic_num = 1;
    countRC5 = 0;
}
