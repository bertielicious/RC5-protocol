#include "constVar.h"

void nibToBin(fourBit *ptr, uint8_t *low, uint8_t *high)
{
    char quotient, dividend, divisor, remainder = 0;
    divisor = 2;    // binary conversion

    /*get D4L*/
    dividend = *low;
    quotient = dividend/ (char)divisor;
    remainder = dividend%divisor;
    ptr->D4L = remainder;
    printf("in function D4L %d\n", ptr->D4L);


    /*get D5L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D5L = remainder;
    printf("in function D5L %d\n", ptr->D5L);

    /*get D6L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D6L = remainder;
    printf("in function D6L %d\n", ptr->D6L);

    /*get D7L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D7L = remainder;
    printf("in function D7L %d\n", ptr->D7L);

    /*get D4H*/
    dividend = *high;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D4H = remainder;
    printf("in function D4H %d\n", ptr->D4H);


    /*get D5L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D5H = remainder;
    printf("in function D5H %d\n", ptr->D5H);

    /*get D6L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D6H = remainder;
    printf("in function D6H %d\n", ptr->D6H);

    /*get D7L*/
    dividend = quotient;
    quotient = dividend/ divisor;
    remainder = dividend%divisor;
    ptr->D7H = remainder;
    printf("in function D7H %d\n", ptr->D7H);
}

