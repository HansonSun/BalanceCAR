#ifndef __ENCODER_H
#define __ENCODER_H
#include <sys.h>	 


#define ENCODER_CNT_RANGE (u16)(60000) 

void Encoder_Init_TIM1(void);
void Encoder_Init_TIM2(void);
void Encoder_Init_TIM3(void);
void Encoder_Init_TIM4(void);

int Read_Encoder(u8 TIMX);

#endif
