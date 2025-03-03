#include "constVar.h"
void configPins(void)
{
    // RC7 is an output (pin 9) to drive LED
    TRISCbits.TRISC7 = LO;
    
     //********TURN OFF ANALOGUE INPUTS**********************
    ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
    ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
    ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
    
    /* SET DATA DIRECTION FOR GENERAL I/O PINS************************/
    TRISBbits.TRISB5 = HI;           // IR IOC input pin 12
    
    
    TRISAbits.TRISA4 = LO;           // Enable output RS pin 3
    TRISAbits.TRISA5 = LO;           // Enable output RW pin 2
    TRISBbits.TRISB6 = LO;           // Enable output EN pin 11
    TRISCbits.TRISC3 = LO;           // Enable output D7 pin 7
    TRISCbits.TRISC6 = LO;           // Enable output D6 pin 8
    TRISCbits.TRISC2 = LO;           // Enable output D5 pin 14
    TRISBbits.TRISB4 = LO;           // Enable output D4 pin 13
}
