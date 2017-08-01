#include <stm32f10x.h>
#include "timer.h"

#define USART1_REC_LEN              200
u8 USART1_RX_BUF[USART1_REC_LEN];  
u16 USART1_RX_STA=0;    
  
void USART1_IRQHandler(void)
{
	u8 res;
	if(USART1->SR&(1<<5))
	{	 
		res=USART1->DR; 
		if((USART1_RX_STA&0x8000)==0)
		{
			if(USART1_RX_STA&0x4000)
			{
				if(res!=0x0a)USART1_RX_STA=0;
				else USART1_RX_STA|=0x8000;
			}else 
			{
				if(res==0x0d)USART1_RX_STA|=0x4000;
				else
				{
					USART1_RX_BUF[USART1_RX_STA&0X3FFF]=res;
					USART1_RX_STA++;
					if(USART1_RX_STA>(USART1_REC_LEN-1))USART1_RX_STA=0;
				}
			}
		} 
	}

} 
