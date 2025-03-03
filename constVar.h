/* 
 * File:   constVar.h
 * Author: User
 *
 * Created on 08 February 2025, 12:46
 */

#ifndef CONSTVAR_H
#define	CONSTVAR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include <xc.h>
#define _XTAL_FREQ 16000000      // Internal clock 4MHz
enum
{
    LO,
    HI
};

#define LED LATCbits.LATC7 // pin 9

/********States**********/
#define STARTIR 0
#define MID1 1
#define START1 2
#define MID0 3
#define START0 4

/******pulse_types****/
#define SP 0
#define LP 1
#define SS 2
#define LS 3
#define ERR 4
#define IR  PORTBbits.RB5

/************global variables for IR code********/
volatile bool has_run = 0;
//volatile unsigned int space_width, pulse_width,temp2, temp3, countRC5 = 0;
volatile uint16_t space_width, pulse_width,temp2, temp3, countRC5 = 0;
uint8_t pulse_type = SP;
uint8_t state = MID1;
volatile uint16_t RC5_code = 0x0000;      
volatile uint16_t bits = 14; // number of bits to be shifted left to form the RC5_code (14 bits)
volatile uint8_t magic_num = 1;

/***************LCD PINS**************************/
#define RS LATAbits.LATA4   // digital output pin 3 
#define RW LATAbits.LATA5  // digital output pin 2
#define D7 LATCbits.LATC3   // digital output pin 7
#define D6 LATCbits.LATC6   // digital output pin 8
#define D5 LATCbits.LATC2   // digital output pin 14
#define D4 LATBbits.LATB4   // digital output pin 13
#define EN LATBbits.LATB6   // digital output pin 11

/*struct allows us to pass all members by reference to function nibTobin
 which sets or clears the data PORT pins connects to LCD to enable text and  
 numbers to  be displayed */
typedef struct
{
    uint8_t D4L:1;  // loNib
    uint8_t D5L:1;
    uint8_t D6L:1;
    uint8_t D7L:1;

    uint8_t D4H:1;  // hiNib
    uint8_t D5H:1;
    uint8_t D6H:1;
    uint8_t D7H:1;

   // uint8_t lowNib;
   // uint8_t highNib;
}fourBit;

#endif	/* CONSTVAR_H */

