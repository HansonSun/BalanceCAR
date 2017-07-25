#include <stm32f10x.h>
#include "timer.h"

#define USART3_REC_LEN    200
u8 USART3_RX_BUF[USART3_REC_LEN];  
u16 USART3_RX_STA=0;    
  
void USART3_IRQHandler(void)
{
	u8 res;
	if(USART1->SR&(1<<5))
	{	 
		res=USART1->DR; 
		if((USART3_RX_STA&0x8000)==0)
		{
			if(USART3_RX_STA&0x4000)
			{
				if(res!=0x0a)USART3_RX_STA=0;
				else USART3_RX_STA|=0x8000;
			}else 
			{
				if(res==0x0d)USART3_RX_STA|=0x4000;
				else
				{
					USART3_RX_BUF[USART3_RX_STA&0X3FFF]=res;
					USART3_RX_STA++;
					if(USART3_RX_STA>(USART3_REC_LEN-1))USART3_RX_STA=0;
				}
			}
		} 
	}

} 