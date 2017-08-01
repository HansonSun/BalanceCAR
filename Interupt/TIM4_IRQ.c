#include <stm32f10x.h>
#include "timer.h"
#include "usart.h"
#include "daolibai.h"
#include "adc.h"

//#define TIM4_FOR_INPUTCAPTURE
//#define TIM4_FOR_ENCODER
#define TIM4_FOR_TIMER

#ifdef TIM4_FOR_TIMER
int set_pos=3125;
float p=12;
float d=4;
int err=0;
int setspeed=0;
int last_err=0;
int err_sum=0;

void TIM4_IRQHandler(void)
{ 
	if(TIM4->SR&0X0001) {
		TIM4->SR&=~(1<<0);
		position=Get_Adc_Average(7,10);
		err=position-set_pos;
        err_sum+=err;
        
		if(err>300 || err<-300)
			set_speed(0);
		else{
			
			setspeed=p*err+d*(err-last_err);
			if(setspeed>=1000)
				setspeed=1000;
			else if(setspeed<=-1000)
				setspeed=-1000;
		
			set_speed(setspeed);
		}
	last_err=err;
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


