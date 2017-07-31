//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9
//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11

#include "input_capture.h"

void TIM1_1_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM1_2_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM1_3_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM1_4_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}


void TIM2_1_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM2_2_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM2_3_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM2_4_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}


void TIM3_1_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM3_2_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM3_3_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM3_4_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}


void TIM4_1_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM4_2_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM4_3_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}
void TIM4_4_Cap_Init(u16 arr,u16 psc){
    RCC->APB1ENR|=1<<0;      //enable the gpioa clk
    RCC->APB2ENR|=1<<2;      //enable the tim2 clk
    
    GPIOA_8_IN_DOWN();   //set A8 to input down
    
    TIM2->ARR=arr;    //set TIM2 arr
    TIM2->PSC=psc;  //set TIM2 psc
    
    TIM2->CCMR1|=1<<0; //set the ic1 to ti1

    TIM2->CCMR1|=1<<4;//set the sampling filter
    TIM2->CCMR1|=0<<10; 
    
    TIM2->CCER|=0<<1; 
    TIM2->CCER|=1<<0; //Capture enable
    
    TIM2->DIER|=1<<1;  //enable the CC1 interupt
    TIM2->DIER|=1<<0;   //enable the update interupt
    
    TIM2->CR1|=0x01; //enable the counter 
}



