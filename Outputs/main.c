#include "main.h"
#include "ports.h"
#include "timer.h"
#include "PLL.h"

#define DELAY_MS 1000

int main(){
  PLL_Init();                  // configure for 50 MHz clock
  SysTick_Init();
  IO_init();
  
  PORTF_IO[LED_BLUE] = LED_BLUE;
  PORTF_IO[LED_RED] = 0;

  while(1){        
    /*Set a single pin*/
    PORTF_IO[LED_RED] = LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*Clear a single pin*/
    PORTF_IO[LED_RED] = 0;
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle a single pin*/
    PORTF_IO[LED_RED] ^= LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle a single pin*/
    PORTF_IO[LED_RED] ^= LED_RED;
    SysTick_Wait1ms(DELAY_MS);
    
    /*set multiple pins at once*/
    GPIO_PORTF_AHB_DATA_R |= (LED_RED | LED_BLUE);    
    SysTick_Wait1ms(DELAY_MS);
    
    /*clear multiple pins at once*/
    GPIO_PORTF_AHB_DATA_R &= ~(LED_RED | LED_BLUE);
    SysTick_Wait1ms(DELAY_MS);
    
    /*toogle multiple pins at once*/
    GPIO_PORTF_AHB_DATA_R ^= (LED_RED | LED_BLUE);
    SysTick_Wait1ms(DELAY_MS);
    
  }    
  
    return 0;
}




    
