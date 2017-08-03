#include <stm32f10x.h>
#include "timer.h"
#include "delay.h"
#include "usart.h"
#include "gpio.h"

void EXTI0_IRQHandler(void ){
    EXTI->PR=1<<0;//clear the exti 0 interupt flag
}

void EXTI1_IRQHandler(void){
	EXTI->PR=1<<1;//clear the exti 1 interupt flag
}  

void EXTI2_IRQHandler(void ){
	EXTI->PR=1<<2;//clear the exti 2 interupt flag
}

void EXTI3_IRQHandler(void){
	EXTI->PR=1<<3;//clear the exti 3 interupt flag
}

void EXTI4_IRQHandler(void){
	EXTI->PR=1<<4;//clear the exti 4 interupt flag
}

void EXTI9_5_IRQHandler(void){
	EXTI->PR=1<<5;//clear the exti 4 interupt flag
}

void EXTI15_10_IRQHandler(void){  
	if( PDin(13)==0)	
	{
			delay_ms(200); 
			while( PDin(13)==0){ }	
			Uprintf(1,"hello");
	}
	EXTI->PR=1<<13; //clear the exti 13 interupt flag
}
