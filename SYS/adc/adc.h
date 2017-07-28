#ifndef _ADC_H
#define _ADC_H

#include<stm32f10x.h>
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "sys.h"

u16 Get_Adc_Average(u8 ch,u8 times);
void Adc1_channel_Init(u8 ad_ch);
u16 Get_Adc(u8 ch);
#endif

