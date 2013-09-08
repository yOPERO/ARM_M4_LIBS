/*--------------------------------------------------*-
  main.c (v1.1)
  ---------------------------------------------------
  Example of clearing and setting pins 
    individually and also writing directly to the port
-*-------------------------------------------------*/
#include "main.h"
#include "ports.h"
#include "timer.h"
#include "PLL.h"

/* Private constants */
#define DELAY_MS 1000

int main(){
  PLL_Init(); // configure for 50 MHz clock
  SysTick_Init(); //Initialize timer
  IO_init(); //Initialize inputs/outputs
  
  PORTF_BIT[LED_BLUE] = LED_BLUE;
  PORTF_BIT[LED_RED] = 0;

  while(1){        
    /*Set a single pin*/
    PORTF_BIT[LED_RED] = LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*Clear a single pin*/
    PORTF_BIT[LED_RED] = 0;
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle a single pin*/
    PORTF_BIT[LED_RED] ^= LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle a single pin*/
    PORTF_BIT[LED_RED] ^= LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*set multiple pins at once*/
    PORTF_PORT |= (LED_RED | LED_BLUE);    
    SysTick_Wait1ms(DELAY_MS);
    
    /*clear multiple pins at once*/
    PORTF_PORT &= ~(LED_RED | LED_BLUE);
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle multiple pins at once*/
    PORTF_PORT ^= (LED_RED | LED_BLUE);
    SysTick_Wait1ms(DELAY_MS);
    
  }    
  
    return 0;
}
/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/




    
