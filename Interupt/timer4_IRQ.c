#include <stm32f10x.h>
#include "timer.h"

//#define TIM4_FOR_INPUTCAPTURE
//#define TIM4_FOR_ENCODER
//#define TIM4_FOR_TIMER

#ifdef TIM4_FOR_TIMER
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
#endif

#ifdef TIM4_FOR_ENCODER
void TIM4_IRQHandler(void){ 		    		  			    
	if(TIM4->SR&0X0001)//update interupt
	{
			    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//clear the update interupt flag  	    
}
#endif


