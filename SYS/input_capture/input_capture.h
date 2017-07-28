#ifndef  _INPUT_CAPTURE_H 
#define _INPUT_CAPTURE_H


#include "gpio.h"
#include <stm32f10x.h>


void TIM1_1_Cap_Init(u16 arr,u16 psc);
void TIM1_2_Cap_Init(u16 arr,u16 psc);
void TIM1_3_Cap_Init(u16 arr,u16 psc);
void TIM1_4_Cap_Init(u16 arr,u16 psc);


void TIM2_1_Cap_Init(u16 arr,u16 psc);
void TIM2_2_Cap_Init(u16 arr,u16 psc);
void TIM2_3_Cap_Init(u16 arr,u16 psc);
void TIM2_4_Cap_Init(u16 arr,u16 psc);


void TIM3_1_Cap_Init(u16 arr,u16 psc);
void TIM3_2_Cap_Init(u16 arr,u16 psc);
void TIM3_3_Cap_Init(u16 arr,u16 psc);
void TIM3_4_Cap_Init(u16 arr,u16 psc);


void TIM4_1_Cap_Init(u16 arr,u16 psc);
void TIM4_2_Cap_Init(u16 arr,u16 psc);
void TIM4_3_Cap_Init(u16 arr,u16 psc);
void TIM4_4_Cap_Init(u16 arr,u16 psc);


#endif
