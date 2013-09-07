#ifndef __TIMER_H__
#define __TIMER_H__

void SysTick_Init(void);
void SysTick_Wait(unsigned long delay);
void SysTick_Wait1ms(unsigned long delay);
void SysTick_Wait10ms(unsigned long delay);

#endif