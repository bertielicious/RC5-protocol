#include "constVar.h"
/*function accepts two variable addresses for the low nibble and high nibble of */
void byteToNib(uint8_t byte, uint8_t *low, uint8_t *high)
{
    uint8_t a,b;
    a = byte & 0x0f;
    b = (byte & 0xf0) >> 4;
    *low = a;
    *high = b;
}
