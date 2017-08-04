#include <stm32f10x.h>
#include "timer.h"


//#define TIM1_FOR_INPUTCAPTURE
//#define TIM1_FOR_ENCODER
#define TIM1_FOR_TIMING


#ifdef TIM1_FOR_TIMING
void TIM1_UP_IRQHandler(void)
{ 		  
     static int flag=0;
	if(TIM1->SR&0X0001)//update interupt
	{
			PAout(0)= flag%2;		
            flag++;        
	}				   
	TIM1->SR&=~(1<<0);//clear the update interupt flag       
}
#endif



#ifdef TIM1_FOR_ENCODER
void TIM1_IRQHandler(void)
{ 		    		  			    
	if(TIM1->SR&0X0001)//update interupt
	{
			    				   				     	    	
	}				   
	TIM1->SR&=~(1<<0);//clear the update interupt flag       
}
#endif


#ifdef TIM1_FOR_INPUTCAPTURE

u8 TIM2CH1_CAPTURE_STA=0;
u16 TIM2CH1_CAPTURE_VAL;

void TIM1_IRQHandler(void)
{
    u16 tsr;
    tsr=TIM1->SR;
    if((TIM1CH1_CAPTURE_STA&0X80)==0){
        if(tsr&0X01){
            if(TIM1CH1_CAPTURE_STA&0X40){
                if((TIM1CH1_CAPTURE_STA&0X3F)==0X3F){
                    TIM1CH1_CAPTURE_STA|=0X80;
                    TIM1CH1_CAPTURE_VAL=0XFFFF;
                }
                else 
                    TIM1CH1_CAPTURE_STA++;
            }
        }
        if(tsr&0x02){
            if(TIM1CH1_CAPTURE_STA&0X40) {
                TIM1CH1_CAPTURE_STA|=0X80; 
                TIM1CH1_CAPTURE_VAL=TIM2->CCR1;
                TIM1->CCER&=~(1<<1); 
            }
            else {
                TIM1CH1_CAPTURE_STA=0X40; 
                TIM1->CNT=0; 
                TIM1->CCER|=1<<1; 
            }
        }
    }
    TIM1->SR=0;
}

#endif
