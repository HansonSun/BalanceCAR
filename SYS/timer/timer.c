#include "timer.h"
#include "delay.h"

void open_timer2_ms(float time_ms){
	u16 set_arr=(u16)(time_ms*10.0)-1;
	open_timer2(set_arr,7199);
}

void open_timer2(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<0;
	TIM2->PSC=psc;
	TIM2->ARR=arr;
	TIM2->DIER|=1<<0;
	TIM2->CR1|=1<<0;
}

void close_timer2(){
	TIM2->DIER&=0xfffe;
	TIM2->CR1&=0xfffe;
}

void open_timer3_ms(float time_ms){
	u16 set_arr=(u16)(time_ms*10.0)-1;
	open_timer3(set_arr,7199);
}

void open_timer3(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<1;
	TIM3->PSC=psc;
	TIM3->ARR=arr;
	TIM3->DIER|=1<<0;
	TIM3->CR1|=1<<0;
}

void close_timer3(){
	TIM3->DIER&=0xfffe;
	TIM3->CR1&=0xfffe;
}

void open_timer4_ms(float time_ms){
	u16 set_arr=(u16)(time_ms*10.0)-1;
	open_timer4(set_arr,7199);
}

void open_timer4(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<2;
	TIM4->PSC=psc;
	TIM4->ARR=arr;
	TIM4->DIER|=1<<0;
	TIM4->CR1|=1<<0;
}

void close_timer4(){
	TIM4->DIER&=0xfffe;
	TIM4->CR1&=0xfffe;
}


void open_timer5_ms(float time_ms){
	u16 set_arr=(u16)(time_ms*10.0)-1;
	open_timer5(set_arr,7199);
}

void open_timer5(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<3;
	TIM5->PSC=psc;
	TIM5->ARR=arr;
	TIM5->DIER|=1<<0;
	TIM5->CR1|=1<<7;
	TIM5->CR1|=1<<0;
	
}

void close_timer5(){
	TIM5->DIER&=0xfffe;
	TIM5->CR1&=0xfffe;
}




