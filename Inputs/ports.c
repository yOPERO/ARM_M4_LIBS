/*--------------------------------------------------*-
  ports.c (v1.1)
  ---------------------------------------------------
  Here all the pins are Enabled/initiliazed
-*-------------------------------------------------*/

#include "main.h" 
#include "ports.h"

/*--------------------------------------------------*-
  IO_init()
  All pins are Enabled/initiliazed
-*--------------------------------------------------*/
void IO_init(void){
  /*Enabling Ports*/
  SYSCTL_RCGCGPIO_R  |= ENABLE_PORTF | ENABLE_PORTD; //  clock gating enable port F(bit5), portD(bit3)
  SYSCTL_GPIOHBCTL_R |= ENABLE_PORTF | ENABLE_PORTD; // Enable AHB ON PORTF and PORTD
  
  /*Setting inputs*/
  GPIO_PORTF_AHB_DIR_R |= (LED_RED |LED_BLUE | LED_GREEN); // Set pin PF1,PF2.PF3 as output
  
  /*Enabling Digital*/
  GPIO_PORTF_AHB_DEN_R = (LED_RED |LED_BLUE | LED_GREEN); // Enable digital on pin PF1,PF2,PF3
  
  /*Setting Outputs*/
}

/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/
