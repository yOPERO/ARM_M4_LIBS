/*--------------------------------------------------*-
  switches_leds.c (v1.1)
  ----------------------------------------------------
  Simple example of lighting the color leds
  according to the input from buttons SW1 and SW2
-*--------------------------------------------------*/
#include "main.h"
#include "ports.h"
#include "switches_leds.h"

/* Private variables*/
volatile unsigned long status;

/*--------------------------------------------------*-
    switches_led()
    if SW1 is pressed light Blue led
    if SW2 is pressed light Green led
    if both switches are pressed light Red led
-*--------------------------------------------------*/
void switches_leds(void){ 

  while(1){        
    /*Read buttons*/
    status = PortF_Input((SW2 | SW1));//this can accept 1 or more parameters
    
    switch (status){
      /*Note logic inversed  0 = switch pressed*/
      case 0x00: PORTF_PORT = LED_RED;break;
      case 0x01: PORTF_PORT = LED_BLUE;break;
      case 0x10: PORTF_PORT = LED_GREEN;break;
      case 0x11: PORTF_PORT = 0x00;break;
    }
  }  
    
}
/*--------------------------------------------------*-
    PortF_Input()
    can accept and read more than one pin
    when ANDed with  the ORed parameters
    returns a 0 on the pin  if input is grounded(pressed)
    eg: 
    PortFInput( 0x01 | 0x10) // 0x01 | 0x10 = 0x11 
    will return 0x11 if non of both pins is grounded(pressed)
    will return 0x10 if pin 1 is grounded
    will return 0x01 if pin 4 is grounded
-*--------------------------------------------------*/
unsigned long PortF_Input(unsigned long port){     
  return (PORTF_PORT & (port));  // read PF4,PF0 inputs
}