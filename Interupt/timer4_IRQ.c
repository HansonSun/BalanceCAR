#include <stm32f10x.h>
#include "timer.h"

int theflag4=0;

void TIM4_IRQHandler(void)
{
	if(TIM4->SR&0X0001) {
		TIM4->SR&=~(1<<0);
	if(theflag4==0){
	PAout(0)=0;
		theflag4=1;
	}
	else{
		PAout(0)=1;
		theflag4=0;
	}
	
	}
	
}
