#include "constVar.h"
#include "enablePulseLCD.h"
void LCD1602init(void)
{
     __delay_ms(110);         // wait while VDD establishes itself        
    RW = 0;    
    RS = 0;                 // Function set interface 8 bits  0x30          2
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
     __delay_ms(5);
    enablePulseLCD();
    
    
    RW = 0;   
    RS = 0;                 // Function set interface 8 bits  0x30          3
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
    __delay_ms(1);
    enablePulseLCD();
    
    
    RW = 0;   
    RS = 0;                 // Function set interface 8 bits 0x30           4
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 1;
     __delay_ms(1);
    enablePulseLCD();
    
    
    RW = 0;   
    RS = 0;                     // function set 4 bit mode 0x20        5
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 0;
    __delay_ms(1);
    enablePulseLCD();
    
    
    RW = 0;   
    RS = 0;                 // function set: 4bit, 2 line, 5x8 font          6a
    D7 = 0;
    D6 = 0;
    D5 = 1;
    D4 = 0; 
    __delay_ms(1);
    enablePulseLCD();
    
    
    RW = 0;   
    RS = 0;                 // display off     6b
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
     
    RW = 0;   
    RS = 0;                 // display clear           7a
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
     
    RW = 0;   
    RS = 0;                 // entry mode set          7b
    D7 = 1;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
     
     
    RW = 0;   
    RS = 0;                 // display on           8a
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    __delay_ms(5);
     enablePulseLCD();
     
     
    RW = 0;   
    RS = 0;                 // display on           8b
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 1;
    __delay_ms(5);
     enablePulseLCD();
     
     
     
    RW = 0;   
    RS = 0;                 // display on           9a
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
     
    RW = 0;   
    RS = 0;                 // display on           9b
    D7 = 0;
    D6 = 1;
    D5 = 1;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
     
     
    RW = 0;   
    RS = 0;                 // display on          11a
    D7 = 0;
    D6 = 0;
    D5 = 0;
    D4 = 0;
     __delay_ms(1);
     enablePulseLCD();
    
     
    RW = 0;   
    RS = 0;                 // display on           9a
    D7 = 1;
    D6 = 1;
    D5 = 0;
    D4 = 0;
    __delay_ms(1);
     enablePulseLCD();
     
        
}
