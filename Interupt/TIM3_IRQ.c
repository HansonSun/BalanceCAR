#include <stm32f10x.h>
#include "timer.h"

//#define TIM3_FOR_INPUTCAPTURE
//#define TIM3_FOR_ENCODER
//#define TIM3_FOR_TIMER

#ifdef TIM3_FOR_TIMER

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
#endif 

#ifdef TIM3_FOR_ENCODER
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//update interupt
	{
			    				   				     	    	
	}				   
	TIM3->SR&=~(1<<0);//clear the update interupt flag       
}
#endif
