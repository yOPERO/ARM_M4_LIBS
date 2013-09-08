/*--------------------------------------------------*-
  main.c (v1.1)
  ----------------------------------------------------
  Simple example of lighting the color leds
  according to the input from buttons SW1 and SW2
-*--------------------------------------------------*/
#include "main.h"
#include "ports.h"
#include "switches_leds.h"

int main(){
    IO_init();    
    switches_leds();
    
    return 0;
}

/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/




    
