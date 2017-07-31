#include <stm32f10x.h>
#include "timer.h"
#include "adc.h"
#include "usart.h"
#include "daolibai.h"
//#define TIM5_FOR_INPUTCAPTURE
//#define TIM5_FOR_ENCODER
//#define TIM5_FOR_TIMER

#ifdef TIM5_FOR_TIMER

void TIM5_IRQHandler(void)
{
	if(TIM5->SR&0X0001) {
		

		TIM5->SR&=~(1<<0);
	}
	
}


#endif
