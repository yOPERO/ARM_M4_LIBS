/*--------------------------------------------------*-
    timer.c (v1.1)
    ----------------------------------------------------
    Once the PLL is configured 
    timer.c generates delays in function of units
    of the Clock source(eg 50Mhz == 20ns)
-*--------------------------------------------------*/
#include "timer.h"
#include "main.h"

void SysTick_Init(void){
   NVIC_ST_CTRL_R = 0; // 1) disable SysTick during setup 
   NVIC_ST_RELOAD_R = 0x00FFFFFF; // 2) maximum reload value 
   NVIC_ST_CURRENT_R = 0; // 3) any write to current clears it 
   NVIC_ST_CTRL_R = 0x00000005; // 4) enable SysTick with core clock
  } 
/*--------------------------------------------------*-
    Systick_Wait()
    The delay parameter is in units of 
    the 50 MHz core clock(20 ns) 
-*--------------------------------------------------*/
void SysTick_Wait(unsigned long delay){
    NVIC_ST_RELOAD_R = delay - 1;
    NVIC_ST_CURRENT_R = 0;
    /*Checks if bit 16 of NVIC_ST_CTRL_R is 1
    when overflow happens*/    
    while((NVIC_ST_CTRL_R & 0x00010000)== 0x00){};
}
/*--------------------------------------------------*-
    Systick_Wait10ms()
    Call this routine to wait for delay*10ms 
-*--------------------------------------------------*/

void SysTick_Wait10ms(unsigned long delay){
   unsigned long i; 
   for(i=0; i<delay; i++){
     SysTick_Wait(500000); // wait 10ms
    }
}
/*--------------------------------------------------*-
    Systick_Wait1ms()
    Call this routine to wait for delay*1ms 
-*--------------------------------------------------*/
void SysTick_Wait1ms(unsigned long delay){
   unsigned long i; 
   for(i=0; i<delay; i++){
     SysTick_Wait(50000); // wait 10ms
    }
}
/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/
