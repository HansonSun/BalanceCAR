#include <stm32f10x.h>
#include "timer.h"

int theflag3=0;

void TIM3_IRQHandler(void)
{
	if(TIM3->SR&0X0001) {
		TIM3->SR&=~(1<<0);
	if(theflag3==0){
	PAout(0)=0;
		theflag3=1;
	}
	else{
		PAout(0)=1;
		theflag3=0;
	}
	
	}
	
}
