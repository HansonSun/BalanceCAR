#include "timer.h"
#include "delay.h"

void Tim1_timging_set_ms(float time_ms){
	u16 psc=0;
	u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
	Tim1_timing_init(arr-1,psc);
}

void Tim1_timing_init(u16 arr,u16 psc){
	RCC->APB2ENR|=1<<11;    //enable the tim1 clk
	TIM1->PSC=psc;          //set tim1 psc
	TIM1->ARR=arr;          //set tim1 arr
 //   TIM1->DIER|=1<<6;   
	TIM1->DIER|=1<<0;       //enable the tim1 update interupt
    TIM1->BDTR|=1<<15;      //set break and dead-time register (timer1 and timer8 only)
	TIM1->CR1=0x0080;     //enable the reload buffer
    TIM1->CR1|=1<<0;        //enable the counter
}

void Tim1_timing_close(){
	TIM1->DIER&=0xfffe;
	TIM1->CR1&=0xfffe;
}

void Tim2_timging_set_ms(float time_ms){
	u16 psc=0;
	u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
	Tim2_timing_init(arr-1,psc);
}

void Tim2_timing_init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<0;
	TIM2->PSC=psc;
	TIM2->ARR=arr;
	TIM2->DIER|=1<<0;
	TIM2->CR1|=1<<0;
}

void Tim2_timing_close(){
	TIM2->DIER&=0xfffe;
	TIM2->CR1&=0xfffe;
}

void Tim3_timging_set_ms(float time_ms){
	u16 psc=0;
	u16 arr=0;	
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
	Tim3_timing_init(arr-1,psc);
}

void Tim3_timing_init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<1;
	TIM3->PSC=psc;
	TIM3->ARR=arr;
	TIM3->DIER|=1<<0;
	TIM3->CR1|=1<<0;
}

void Tim3_timing_close(){
	TIM3->DIER&=0xfffe;
	TIM3->CR1&=0xfffe;
}

void Tim4_timing_set_ms(float time_ms){
	u16 psc=0;
	u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
	Tim4_timing_init(arr-1,psc);
}

void Tim4_timing_init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<2;
	TIM4->PSC=psc;
	TIM4->ARR=arr;
	TIM4->DIER|=1<<0;
	TIM4->CR1|=1<<0;
}

void Tim4_timing_close(){
	TIM4->DIER&=0xfffe;
	TIM4->CR1&=0xfffe;
}


void Tim5_timing_set_ms(float time_ms){
	u16 psc=0;
	u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
     
	Tim5_timing_init(arr-1,psc);
}

void Tim5_timing_init(u16 arr,u16 psc){
	RCC->APB1ENR|=1<<3;
	TIM5->PSC=psc;
	TIM5->ARR=arr;
	TIM5->DIER|=1<<0;
	TIM5->CR1|=1<<7;
	TIM5->CR1|=1<<0;
	
}

void Tim5_timing_close(){
	TIM5->DIER&=0xfffe;
	TIM5->CR1&=0xfffe;
}




