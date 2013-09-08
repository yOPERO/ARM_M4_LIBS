/*--------------------------------------------------*-
  port.h (v1.1)
  ----------------------------------------------------
  Port header for ARM M4 LX4F120XL -->Texas Instruments
-*--------------------------------------------------*/
#ifndef __PORTS_H__
#define __PORTS_H__

/*Custom Pin Definitions*/

/*LED definitions*/
#define LED_RED   (1U << 1) // PF1
#define LED_BLUE  (1U << 2) // PF2
#define LED_GREEN (1U << 3) // PF3

/*Switch definitions*/
#define SW2       (1U << 0) // on the left side of the Launchpad board
#define SW1       (1U << 4) // on the right side of the Launchpad board

/*Port definitions*/
#define ENABLE_PORTA (1U << 0)
#define ENABLE_PORTB (1U << 1)
#define ENABLE_PORTC (1U << 2)
#define ENABLE_PORTD (1U << 3)
#define ENABLE_PORTE (1U << 4)
#define ENABLE_PORTF (1U << 5)

/*Data bits access Definitions*/
#define PORTA_BIT (GPIO_PORTA_AHB_DATA_BITS_R)
#define PORTB_BIT (GPIO_PORTB_AHB_DATA_BITS_R)
#define PORTC_BIT (GPIO_PORTC_AHB_DATA_BITS_R)
#define PORTD_BIT (GPIO_PORTD_AHB_DATA_BITS_R)
#define PORTE_BIT (GPIO_PORTE_AHB_DATA_BITS_R)
#define PORTF_BIT (GPIO_PORTF_AHB_DATA_BITS_R)

/*Data Port access Definitions*/
#define PORTA_PORT (GPIO_PORTA_AHB_DATA_R)
#define PORTB_PORT (GPIO_PORTB_AHB_DATA_R)
#define PORTC_PORT (GPIO_PORTC_AHB_DATA_R)
#define PORTD_PORT (GPIO_PORTD_AHB_DATA_R)
#define PORTE_PORT (GPIO_PORTE_AHB_DATA_R)
#define PORTF_PORT (GPIO_PORTF_AHB_DATA_R)


/*Public Function Prototypes*/

void IO_init(void);

#endif

/*--------------------------------------------------*-
-----  END OF FILE  ----------------------------------
-*--------------------------------------------------*/