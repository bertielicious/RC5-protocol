/*
 * File:   main.c
 * Author: User
 *
 * Created on 08 February 2025, 12:30
 */


#include "constVar.h"
#include "deviceConfigBits.h"
#include "configOsc.h"
#include "configPins.h"
#include "putch.h"
#include "configEUSART.h"
#include "configIOC.h"
#include "resetRC5.h"
#include "stateMachine.h"
#include "LCD1602init.h"
#include "enablePulseLCD.h"
#include "byteToNib.h"
#include "nibToBin.h"

void main(void) 
{
    RW = LO;    //always write to LCD
    LED = LO;
    configOsc();
    configPins();
    configEUSART();
    configIOC();
    enablePulseLCD();
    LCD1602init();
    
    /*RW = LO;    // higher ASCII nibble R
    RS = HI;
    D7 = LO;
    D6 = HI;
    D5 = LO;
    D4 = HI;
    __delay_ms(5);
    enablePulseLCD();
    
    RW = LO;    // lower ASCII nibble R
    RS = HI;
    D7 = LO;
    D6 = LO;
    D5 = HI;
    D4 = LO;
    __delay_ms(5);
    enablePulseLCD();
    
    
    RW = LO;    // higher ASCII nibble C
    RS = HI;
    D7 = LO;
    D6 = HI;
    D5 = LO;
    D4 = LO;
    __delay_ms(5);
    enablePulseLCD();
    
   RW = LO;    // lower ASCII nibble C
    RS = HI;
    D7 = LO;
    D6 = LO;
    D5 = HI;
    D4 = HI;
    __delay_ms(5);
    enablePulseLCD();*/
    
    
    
    
    
    uint8_t D4L, D5L, D6L, D7L, D4H, D5H, D6H, D7H;
    
    //uint8_t string[13] = "RC5 protocol";// text to be displayed on LCD
    uint8_t string[13] = "RC5 protocol";
    uint8_t *ascii;
    ascii = string;
    uint8_t lowN, highN = 0;
     
    fourBit binary;
    fourBit *ptr;
    ptr = &binary;
    
    //send command to LCD to start printing at row 1 col 2
    // set DDRAM address to 0x08
        RS = LO;    // command mode 0x08
        D7 = HI;
        D6 = LO;
        D5 = LO;
        D4 = LO;
        __delay_ms(5);
        enablePulseLCD();
        
        // set column to column 2
        RS = LO;    // command mode 0x02
        D7 = LO;
        D6 = LO;
        D5 = HI;
        D4 = LO;
        __delay_ms(5);
        enablePulseLCD();
        
    while(*ascii != 0)
    
    {

       printf("ascii %d\n", *ascii);
       byteToNib(*ascii, &lowN, &highN);
       printf("in main lowNib %d  hiNib %d\n" , lowN, highN);

       //convert low and high nibbles to binary
        nibToBin(&binary, &lowN, &highN);
        printf("in main D4L %d  D5L %d D6L %d  D7L %d D4H %d  D5H %d D6H %d  D7H %d\n" , ptr->D4L, ptr->D5L, ptr->D6L, ptr->D7L, ptr->D4H, ptr->D5H, ptr->D6H, ptr->D7H);
        
        RW = LO;    //send higher nibble first
        RS = HI;
        D7 = ptr->D7H;
        D6 = ptr->D6H;
        D5 = ptr->D5H;
        D4 = ptr->D4H;
       
        enablePulseLCD();
        __delay_ms(5);
        ascii= ascii + 1;
        //use D4L-D7L to drive port pins D4 - D7
        RW = LO;    //send lower nibble second
        RS = HI;
        D7 = ptr->D7L;
        D6 = ptr->D6L;
        D5 = ptr->D5L;
        D4 = ptr->D4L;
        
        enablePulseLCD();
        __delay_ms(5);
        
        

    }
   
    printf("RC5 protocol\n");
    
    while(1)
    {
       while(IR == HI && has_run !=1)
           ;    // wait for first button press on RC5 handset
            while(IR == LO && has_run !=1)
                ;
            if(IR == HI && has_run !=1)
            {
                bits--;
                has_run = 1;                // this block only runs once until system is reset
                INTCONbits.IOCIE = 0;       // master switch disable for interrupt on change   
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S1 of 0x2000
                bits--;
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S2 of 0x1000
                bits--;                        // keep track of how many of the 14 RC5 bits have been consumed
                state = MID1;
                TMR1H = 0x00;
                TMR1L = 0x00;
                INTCONbits.IOCIE = 1;       // master switch enable for interrupt on change     
                IOCBPbits.IOCBP5 = 0;       // disable interrupt on rising edge
                IOCBNbits.IOCBN5 = 1;       // enable interrupt on falling edge
            }   
            
            else if(IOCIF !=1 && (bits + 1) == 0)  // if no interrupt and all 14 RC5 bits have been consumed by state machine
            {
                printf("RC5 code = %x\n", RC5_code);
               
                
                resetRC5();
              
                T1CONbits.TMR1ON = 0;
            
        }
       /*Test LCD IO all good
       LATAbits.LATA4 = ~LATAbits.LATA4;
       LATAbits.LATA5 = ~LATAbits.LATA5;
       LATBbits.LATB6 = ~LATBbits.LATB6;
       LATCbits.LATC3 = ~LATCbits.LATC3;
       LATCbits.LATC6 = ~LATCbits.LATC6;
       LATCbits.LATC2 = ~LATCbits.LATC2;
       LATBbits.LATB4 = ~LATBbits.LATB4;
       __delay_ms(1000);*/
       
        
    }
                
    return;
}
