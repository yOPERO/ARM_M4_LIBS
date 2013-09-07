#include "main.h" 
#include "ports.h"

void IO_init(void){
  /*Enabling Ports*/
  SYSCTL_RCGCGPIO_R  |= ENABLE_PORTF | ENABLE_PORTD; //  clock gating enable port F(bit5), portD(bit3)
  SYSCTL_GPIOHBCTL_R |= ENABLE_PORTF | ENABLE_PORTD; // Enable AHB ON PORTF and PORTD

  /*Setting inputs/outputs*/
  GPIO_PORTF_AHB_DIR_R |= (LED_RED |LED_BLUE | LED_GREEN); // Set pin PF1,PF2.PF3 as output
  GPIO_PORTD_AHB_DIR_R |= LED_EXTRA; // Set pin PD0 as output
  
  /*Enabling Digital*/
  GPIO_PORTF_AHB_DEN_R = (LED_RED |LED_BLUE | LED_GREEN); // Enable digital on pin PF1,PF2,PF3
  GPIO_PORTD_AHB_DEN_R = LED_EXTRA; // Enable digital on pin PD0
}
