#include "constVar.h"
void configEUSART(void)
{
    TXSTAbits.TXEN = HI;// enable the transmitter
    TXSTAbits.SYNC = LO;// Asynchronous mode
    RCSTAbits.SPEN = HI;// configures RB7 pin 10 as TX output
    SPBRG = 25; // 9600 baud rate
}
