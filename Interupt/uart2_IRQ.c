#include <stm32f10x.h>
#include "timer.h"

#define USART2_REC_LEN      200
u8 USART2_RX_BUF[USART2_REC_LEN];  
u16 USART2_RX_STA=0;    
  
void USART2_IRQHandler(void)
{
	u8 res;
	if(USART1->SR&(1<<5))
	{	 
		res=USART1->DR; 
		if((USART2_RX_STA&0x8000)==0)
		{
			if(USART2_RX_STA&0x4000)
			{
				if(res!=0x0a)USART2_RX_STA=0;
				else USART2_RX_STA|=0x8000;
			}else 
			{
				if(res==0x0d)USART2_RX_STA|=0x4000;
				else
				{
					USART2_RX_BUF[USART2_RX_STA&0X3FFF]=res;
					USART2_RX_STA++;
					if(USART2_RX_STA>(USART2_REC_LEN-1))USART2_RX_STA=0;
				}
			}
		} 
	}

} 

