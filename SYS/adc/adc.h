#ifndef _ADC_H
#define _ADC_H

#include<stm32f10x.h>
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "sys.h"

extern vu16 ADC1SingleConverted;
extern vu16 ADC1MultiConverted[3];

u16 Get_Adc_Average(u8 ch,u8 times);
void Adc1_channel_Init(u8 ad_ch);
u16 Get_Adc(u8 ch);

void Adc_Singlechannel_Gpio_Init(int ch);
void Adc1_Multichannel_repeat(int channel_cnt,...);
void adc_set_sequence(int ch);
void Adc1_Singlechannel_once(u8 ad_ch);
void Adc1_Singlechannel_repeat(u8 ad_ch);

void Adc_DMA_OneChannel_Config(  );
void Adc_DMA_MultiChannel_Config( );

#endif

