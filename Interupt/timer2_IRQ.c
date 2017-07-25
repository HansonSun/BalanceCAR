#include <stm32f10x.h>
#include "timer.h"

int theflag2=0;

void TIM2_IRQHandler(void)
{
	if(TIM2->SR&0X0001) {
		TIM2->SR&=~(1<<0);
	if(theflag2==0){
	PAout(0)=0;
		theflag2=1;
	}
	else{
		PAout(0)=1;
		theflag2=0;
	}
	
	}
	
}

