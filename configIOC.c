#include "constVar.h"
void configIOC(void)
{
  INTCONbits.GIE = 1;           // enable global interrupts
  INTCONbits.IOCIE = 0;         // disables IOC interrupt (master switch))
  UCONbits.USBEN = 0;           // disable USB module  
  INTCONbits.IOCIF = 0;         // clear IOC interrupt flag
  /********IR IOC pin setup RB5 pin 12********************/
  IOCBPbits.IOCBP5 = 0;         // disable detection of rising edges on RB5 pin 12
  IOCBNbits.IOCBN5 = 0;         // disable detection of falling edges on RB5 pin 12
  IOCBFbits.IOCBF5 = 0;         // clear IOC FLAG FOR RB5 pin 12
  
  /********CLK IOC pin setup RA1 pin 18********************/
  /*IOCAPbits.IOCAP1 = 0;         // disable rising edge detections on RA1 pin 18
  IOCANbits.IOCAN1 = 1;         // enable falling edge detections on RA1 pin 18
  IOCAFbits.IOCAF1 = 0;         // clear IOC FLAG FOR RA1 pin 18*/
}
