#ifndef _TIMER_H_
#define _TIMER_H_

#include "stm32f10x.h"
#include "gpio.h"

void Tim1_timing_init(u16 arr,u16 psc);
void Tim1_timing_set_ms(float time_ms);
void Tim1_timing_close(void);


void Tim2_timing_init(u16 arr,u16 psc);
void Tim2_timing_set_ms(float time_ms);
void Tim2_timing_close(void);

void Tim3_timing_init(u16 arr,u16 psc);
void Tim3_timing_set_ms(float time_ms);
void Tim2_timing_close(void);

void Tim4_timing_init(u16 arr,u16 psc);
void Tim4_timing_set_ms(float time_ms);
void Tim2_timing_close(void);

void Tim5_timing_init(u16 arr,u16 psc);
void Tim5_timing_set_ms(float time_ms);
void Tim5_timing_close(void);


#endif




