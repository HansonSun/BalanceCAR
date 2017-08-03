#ifndef   __SYS_H
#define	  __SYS_H
 
#include "delay.h"
#include "usart.h"
#include <stdio.h>
#include <stdlib.h>
#include "pwm.h"

void NVIC_CONFIG(void);
void SYS_CONFIG(void);

//--------------------APB2ENR-------------------------------------------------//
#define USART1_CLK_EN   RCC->APB2ENR|=1<<14;
#define SPI1_CLK_EN     RCC->APB2ENR|=1<<12;
#define TIM1_CLK_EN     RCC->APB2ENR|=1<<11;
#define ADC2_CLK_EN     RCC->APB2ENR|=1<<10;
#define ADC1_CLK_EN     RCC->APB2ENR|=1<<9;
#define GPIOE_CLK_EN    RCC->APB2ENR|=1<<6;
#define GPIOD_CLK_EN    RCC->APB2ENR|=1<<5;
#define GPIOC_CLK_EN    RCC->APB2ENR|=1<<4;
#define GPIOB_CLK_EN    RCC->APB2ENR|=1<<3;
#define GPIOA_CLK_EN    RCC->APB2ENR|=1<<2;
#define AFIO_CLK_EN     RCC->APB2ENR|=1<<0;

//------------------APB1ENR----------------------------------------------------//
#define DAC_CLK_EN      RCC->APB1ENR|=1<<29;
#define PWR_CLK_EN      RCC->APB1ENR|=1<<28;
#define BKP_CLK_EN      RCC->APB1ENR|=1<<27;
#define CAN2_CLK_EN     RCC->APB1ENR|=1<<26;
#define CAN1_CLK_EN     RCC->APB1ENR|=1<<25;
#define I2C2_CLK_EN     RCC->APB1ENR|=1<<22;
#define I2C1_CLK_EN     RCC->APB1ENR|=1<<21;
#define UART5_CLK_EN    RCC->APB1ENR|=1<<20;
#define UART4_CLK_EN    RCC->APB1ENR|=1<<19;
#define USART3_CLK_EN   RCC->APB1ENR|=1<<18;
#define USART2_CLK_EN   RCC->APB1ENR|=1<<17;
#define SPI3_CLK_EN     RCC->APB1ENR|=1<<15;
#define SPI2_CLK_EN     RCC->APB1ENR|=1<<14;
#define WWDG_CLK_EN     RCC->APB1ENR|=1<<11;
#define TIM7_CLK_EN     RCC->APB1ENR|=1<<5;
#define TIM6_CLK_EN     RCC->APB1ENR|=1<<4;
#define TIM5_CLK_EN     RCC->APB1ENR|=1<<3;
#define TIM4_CLK_EN     RCC->APB1ENR|=1<<2;
#define TIM3_CLK_EN     RCC->APB1ENR|=1<<1;
#define TIM2_CLK_EN     RCC->APB1ENR|=1<<0;
//----------------------------------------------------------------------//

#define GPIO_A 0
#define GPIO_B 1
#define GPIO_C 2
#define GPIO_D 3
#define GPIO_E 4
#define GPIO_F 5



#endif

