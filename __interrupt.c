#include "constVar.h"
#include "stateMachine.h"
void __interrupt() isr(void)
{
   if(IOCBFbits.IOCBF5 == 1)
     {
       LED = HI;
         if(magic_num%2 != 0)   // first rising edge of pulse detected
         {
             if(countRC5 == 0)                 // path A
             {
                T1CONbits.TMR1ON = 1;       // start TMR1
                magic_num++;               // make an even number so %evennum = 0
                countRC5 = 1;
                IOCBPbits.IOCBP5 = 1;       // enable interrupt on rising edge
                IOCBFbits.IOCBF5 = 0;      // clear relevant interrupt flags
                INTCONbits.IOCIF = 0;  
                
             }
             else if(countRC5 !=0)             // path C
             {
                 
                 temp3 = (uint16_t)TMR1H<<8 | (uint16_t)TMR1L;    // store TMR1 at start of next pulse 
                 space_width = temp3 - pulse_width;
                 
                 if(space_width >= 1776 && space_width <= 5332)
                 {
                     pulse_type = SS;
                 }
                 else if(space_width >= 5333 && space_width <= 8888)
                 {
                     pulse_type = LS;
                 }
                 stateMachine();
                 TMR1H = 0x00;
                 TMR1L = 0x00;
                 //temp1 = 0;
                 magic_num++;
                 IOCBFbits.IOCBF5 = 0;      // clear relevant interrupt flags
                 INTCONbits.IOCIF = 0;  
                 
             }
         }
         else           // path B
         {
            
             temp2 = (uint16_t)TMR1H<<8 | (uint16_t)TMR1L;    // store TMR1 at start of pulse
             pulse_width = temp2; //- temp1;
             magic_num = 1;
             
             if(pulse_width >= 1776 && pulse_width <= 5332)
                 {
                     pulse_type = SP;
                 }
             else if(pulse_width >= 5333 && pulse_width <= 8888)
                 {
                     pulse_type = LP;
                 }
             stateMachine(); 
            
             IOCBFbits.IOCBF5 = 0;      // clear relevant interrupt flags
             INTCONbits.IOCIF = 0;
         }
       LED = LO;
     }
}
