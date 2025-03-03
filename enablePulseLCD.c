#include "constVar.h"
void enablePulseLCD(void)
{
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(5);
}
