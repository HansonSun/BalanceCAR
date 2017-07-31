#include <stm32f10x.h>
#include "timer.h"


//#define TIM2_FOR_INPUTCAPTURE
#define TIM2_FOR_ENCODER
//#define TIM2_FOR_TIMER


#ifdef TIM2_FOR_TIMER
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//update interupt
	{
			    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//clear the update interupt flag       
}
#endif



#ifdef TIM2_FOR_ENCODER
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//update interupt
	{
			    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//clear the update interupt flag       
}
#endif


#ifdef TIM2_FOR_INPUTCAPTURE

u8 TIM2CH1_CAPTURE_STA=0;
u16 TIM2CH1_CAPTURE_VAL;

void TIM2_IRQHandler(void)
{
    u16 tsr;
    tsr=TIM2->SR;
    if((TIM2CH1_CAPTURE_STA&0X80)==0){
        if(tsr&0X01){
            if(TIM2CH1_CAPTURE_STA&0X40){
                if((TIM2CH1_CAPTURE_STA&0X3F)==0X3F){
                    TIM2CH1_CAPTURE_STA|=0X80;
                    TIM2CH1_CAPTURE_VAL=0XFFFF;
                }
                else 
                    TIM2CH1_CAPTURE_STA++;
            }
        }
        if(tsr&0x02){
            if(TIM2CH1_CAPTURE_STA&0X40) {
                TIM2CH1_CAPTURE_STA|=0X80; 
                TIM2CH1_CAPTURE_VAL=TIM2->CCR1;
                TIM2->CCER&=~(1<<1); 
            }
            else {
                TIM2CH1_CAPTURE_STA=0X40; 
                TIM2->CNT=0; 
                TIM2->CCER|=1<<1; 
            }
        }
    }
    TIM2->SR=0;
}

#endif
