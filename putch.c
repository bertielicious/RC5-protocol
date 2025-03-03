#include "constVar.h"
void putch(char byte)
{
    while(! TXIF)
    continue;
    TXREG = byte;
}
