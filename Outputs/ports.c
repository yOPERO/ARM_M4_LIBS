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
  SYSCTL_RCGCGPIO_R  |= ENABLE_PORTF; //  clock gating enable port F(bit5))
  SYSCTL_GPIOHBCTL_R |= ENABLE_PORTF; // Enable AHB ON PORTF 

  /*Setting inputs*/
  GPIO_PORTF_AHB_DIR_R |= (LED_RED |LED_BLUE | LED_GREEN); // Set pin PF1,PF2.PF3 as output
  GPIO_PORTF_AHB_DEN_R |= (LED_RED |LED_BLUE | LED_GREEN); // Enable digital on pin PF1,PF2,PF3
  
  /*Setting Outputs*/
  /********************************************************-
  The below changes only when using PF0 PD7 PC[0:3]
  See GPIOCR on page 644 of the DS
  *********************************************************/
  GPIO_PORTF_AHB_LOCK_R = GPIO_LOCK_KEY;   // unlock GPIO Port F by writting 0x4C4F434B
  GPIO_PORTF_AHB_CR_R = SW2;           // Allow changes on PF0
  GPIO_PORTF_AHB_LOCK_R = GPIO_LOCK_UNLOCKED;         // lock GPIO Port F by writting 0x00
  /********************************************************/
  GPIO_PORTF_AHB_DIR_R &= ~(SW1 | SW2); // Set pin PF4 and PF0 as input
  GPIO_PORTF_AHB_PUR_R |= (SW1 | SW2);  // enable pull-up on PF4 and PF0
  
  /*Enabling Digital*/
  GPIO_PORTF_AHB_DEN_R |= (SW2 | SW1); // Enable digital on pin PF0 and PF4
 
}
/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/
