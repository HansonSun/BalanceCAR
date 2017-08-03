#include "exti.h"
#include "sys.h"

//detect the fall trigger
void exti_init_ft(u8 GPIOx,u8 BITx){
	u8 EXTADDR;
	u8 EXTOFFSET;
	EXTADDR=BITx/4;
	EXTOFFSET=(BITx%4)*4; 
	RCC->APB2ENR|=0x01;		 
	AFIO->EXTICR[EXTADDR]&=~(0x000F<<EXTOFFSET);
	AFIO->EXTICR[EXTADDR]|=GPIOx<<EXTOFFSET;
	EXTI->IMR|=1<<BITx;   //enable the bitx line
 	EXTI->FTSR|=1<<BITx; //enable the bitx for fall trigger
} 	

//detect the rise trigger
void exti_init_rt(u8 GPIOx,u8 BITx){
	u8 EXTADDR;
	u8 EXTOFFSET;
	EXTADDR=BITx/4;
	EXTOFFSET=(BITx%4)*4; 
	RCC->APB2ENR|=0x01;		 //enable the afio
	AFIO->EXTICR[EXTADDR]&=~(0x000F<<EXTOFFSET);
	AFIO->EXTICR[EXTADDR]|=GPIOx<<EXTOFFSET;
	EXTI->IMR|=1<<BITx;  //enable the bitx line
	EXTI->RTSR|=1<<BITx;  //enable the bitx for fall trigger
} 	





