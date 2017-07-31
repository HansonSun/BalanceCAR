#include <stm32f10x.h>
#include "timer.h"

//#define TIM5_FOR_INPUTCAPTURE
//#define TIM5_FOR_ENCODER
//#define TIM5_FOR_TIMER

#ifndef TIM5_FOR_TIMER

int theflag5=0;
void TIM5_IRQHandler(void)
{
	if(TIM5->SR&0X0001) {
		TIM5->SR&=~(1<<0);
	if(theflag5==0){
	PAout(0)=0;
		theflag5=1;
	}
	else{
		PAout(0)=1;
		theflag5=0;
	}
	
	}
	
}

#endif
