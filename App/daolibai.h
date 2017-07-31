#ifndef _DAOLIBAI_H
#define _DAOLIBAI_H
#include "gpio.h"
#include "DataScope_DP.h"
#include "adc.h"

extern u32 position;

#define turn_left() {	PBout(12)=0;PBout(13)=1;}
#define turn_right()  {	PBout(12)=1;PBout(13)=0;}
#define stop()       {	PBout(12)=0;PBout(13)=0;}
#define motor_speed(x) TIM3_4_SET_DUTY(x)
void daolibai_init(void);
void DataScope(float num);
void set_speed(int speed);


#endif
