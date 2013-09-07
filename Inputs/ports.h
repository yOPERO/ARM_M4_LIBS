#ifndef __PORTS_H__
/*Port definitions*/
#define ENABLE_PORTD (1U << 3)
#define ENABLE_PORTF (1U << 5)

/*Pin definitions*/
#define LED_RED   (1U << 1) // PF1
#define LED_BLUE  (1U << 2) // PF2
#define LED_GREEN (1U << 3) // PF3
#define LED_EXTRA (1U << 0) // PD0

/*Port Definitions*/
#define PORTF_IO (GPIO_PORTF_AHB_DATA_BITS_R)
#define PORTD_IO (GPIO_PORTD_AHB_DATA_BITS_R)
/*Function Definitions*/
void IO_init(void);


#endif