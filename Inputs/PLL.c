/*--------------------------------------------------*-
    PLL.c (v1.1)
    ----------------------------------------------------
    Phase Locked Loop (PLL)
    Configured in software, multiples the clock to higher
    frequencies for core and peripheral timing.
    -->To change the frecuency change the
    #define statement SYSDIV2 in PLL.h
-*--------------------------------------------------*/
#include "main.h" 
#include "PLL.h"

/*--------------------------------------------------*-
    PLL_Init()
    configure the system to get its clocks signal  
    from the PLL.

    The process below is taken from
    "Embedded Systems: Real Time Interfacing to 
    Arm Cortex M Microcontrollers" by Jonathan Valvano
-*--------------------------------------------------*/

void PLL_Init(void){   
  // 0) configure the system to use RCC2 for advanced features
  //    such as 400 MHz PLL and non-integer System Clock Divisor
  SYSCTL_RCC2_R |= SYSCTL_RCC2_USERCC2;
  
  // 1) bypass PLL while initializing
  SYSCTL_RCC2_R |= SYSCTL_RCC2_BYPASS2;
  
  // 2) select the crystal value and oscillator source
  SYSCTL_RCC_R &= ~SYSCTL_RCC_XTAL_M;   // clear XTAL field
  SYSCTL_RCC_R += SYSCTL_RCC_XTAL_16MHZ;// configure for 16 MHz crystal
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_OSCSRC2_M;// clear oscillator source field
  SYSCTL_RCC2_R += SYSCTL_RCC2_OSCSRC2_MO;// configure for main oscillator source
  
  // 3) activate PLL by clearing PWRDN
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_PWRDN2;
  
  // 4) set the desired system divider and the system divider least significant bit
  SYSCTL_RCC2_R |= SYSCTL_RCC2_DIV400;  // use 400 MHz PLL
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_SYSDIV2_M;  // clear system clock divider field
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_SYSDIV2LSB; // clear bit SYSDIV2LSB
  // set Divisor by writing 7-bit constant to bits 28-22
  SYSCTL_RCC2_R += (SYSDIV2<<22);       // divide by (SYSDIV2+1)
  
  // 5) wait for the PLL to lock by polling PLLLRIS
  while((SYSCTL_RIS_R&SYSCTL_RIS_PLLLRIS)==0){};
  
  // 6) enable use of PLL by clearing BYPASS
  SYSCTL_RCC2_R &= ~SYSCTL_RCC2_BYPASS2;
}

/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/
