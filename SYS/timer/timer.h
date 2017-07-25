#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f10x.h"
#include "gpio.h"
void open_timer2(u16 arr,u16 psc);
void open_timer2_ms(float time_ms);
void close_timer2(void);

void open_timer3(u16 arr,u16 psc);
void open_timer3_ms(float time_ms);
void close_timer3(void);

void open_timer4(u16 arr,u16 psc);
void open_timer4_ms(float time_ms);
void close_timer4(void);

void open_timer5(u16 arr,u16 psc);
void open_timer5_ms(float time_ms);
void close_timer5(void);


#endif




