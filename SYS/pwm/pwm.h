//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9
//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11

#ifndef __PWM_H
#define __PWM_H


#include<stm32f10x.h>
#include "gpio.h"

#define TIM1_1_SET_CCR(x) TIM1->CCR1=x
#define TIM1_2_SET_CCR(x) TIM1->CCR2=x
#define TIM1_3_SET_CCR(x) TIM1->CCR3=x
#define TIM1_4_SET_CCR(x) TIM1->CCR4=x

#define TIM2_1_SET_CCR(x) TIM2->CCR1=x
#define TIM2_2_SET_CCR(x) TIM2->CCR2=x
#define TIM2_3_SET_CCR(x) TIM2->CCR3=x
#define TIM2_4_SET_CCR(x) TIM2->CCR4=x

#define TIM3_1_SET_CCR(x) TIM3->CCR1=x
#define TIM3_2_SET_CCR(x) TIM3->CCR2=x
#define TIM3_3_SET_CCR(x) TIM3->CCR3=x
#define TIM3_4_SET_CCR(x) TIM3->CCR4=x

#define TIM4_1_SET_CCR(x) TIM4->CCR1=x
#define TIM4_2_SET_CCR(x) TIM4->CCR2=x
#define TIM4_3_SET_CCR(x) TIM4->CCR3=x
#define TIM4_4_SET_CCR(x) TIM4->CCR4=x



void TIM1_PWM_INIT(u16 arr,u16 psc);
void TIM2_PWM_INIT(u16 arr,u16 psc);
void TIM3_PWM_INIT(u16 arr,u16 psc);
void TIM4_PWM_INIT(u16 arr,u16 psc);

void TIM1_ENABLE_CH(int ch);
void TIM2_ENABLE_CH(int ch);
void TIM3_ENABLE_CH(int ch);
void TIM4_ENABLE_CH(int ch);

void TIM1_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM2_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM3_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM4_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);

void TIM1_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM2_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM3_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
void TIM4_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4);
				
void TIM1_1_SET_DUTY(int ch,float duty);
void TIM3_1_SET_DUTY(float duty);
void TIM3_2_SET_DUTY(float duty);
void TIM3_3_SET_DUTY(float duty);
void TIM3_4_SET_DUTY(float duty);
#endif
