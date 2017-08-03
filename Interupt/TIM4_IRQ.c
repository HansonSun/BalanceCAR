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
float p=80;
float d=-50;
int err=0;
int setspeed=0;
int last_err=0;
int err_sum=0;

void TIM4_IRQHandler(void)
{ 
	if(TIM4->SR&0X0001) {
		TIM4->SR&=~(1<<0);
		position=Get_Adc_Average(7,15);
		spinspeed=Read_Encoder(2);
		err=position-set_pos;
        err_sum+=err;
        
		if(err>800 || err<-800)
			TIM3_4_SET_DUTY(0)
		else{
			
			setspeed=p*err+d*(err-last_err);
			if(setspeed>=800)
				setspeed=800;
			else if(setspeed<=-800)
				setspeed=-800;
		
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


