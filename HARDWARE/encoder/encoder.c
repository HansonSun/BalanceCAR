//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11
//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9


#include "encoder.h"

void Encoder_Init_TIM1(void){
	RCC->APB2ENR|=1<<11;     //enable the Tim1 clk
	RCC->APB2ENR|=1<<2;      //enable the gpioa clk
    
	GPIOB->CRH&=0XFFFFFF00; //PA8 PA9
	GPIOB->CRH|=0XFF000044; //set A8 A9 to float in
    
	TIM1->DIER|=1<<0;   //enable the update interupt				
	TIM1->DIER|=1<<6;   //enable the trigger interupt

	TIM1->PSC = 0x0;
	TIM1->ARR = ENCODER_CNT_RANGE;////set the range for TIM2->CNT
	
    TIM1->CR1 &=~(3<<8);    // do not divide frequent
	TIM1->CR1 &=~(3<<5);    // edge align mode
		
	TIM1->CCMR1 |= 1<<0;   //IC1 is mapped on TI1.
	TIM1->CCMR1 |= 1<<8;   //IC2 is mapped on TI2.
	TIM1->CCER &= ~(1<<1);	 //NON-INVERTED
	TIM1->CCER &= ~(1<<5);   //NON-INVERTED
	TIM1->CCMR1 |= 3<<4; //	IC1F='1000' fSAMPLING=fCK_INT, N=8
	TIM1->SMCR |= 3<<0;	 //SMS='011'enable the encoder mode
	TIM1->CNT = 10000;  //THIS is the start num for you
	TIM1->CR1 |= 0x01;    //CEN=1 enable the tim1
}



void Encoder_Init_TIM2(void){
	RCC->APB1ENR|=1<<0;       //enable the Tim2 clk
	RCC->APB2ENR|=1<<2;       //enable the gpioa clk
	GPIOA->CRL&=0XFFFFFF00;   
	GPIOA->CRL|=0X00000044;   //set A0 A1 to float in

	TIM2->DIER|=1<<0;   //enable the update interupt	
	TIM2->DIER|=1<<6;   //enable the trigger interupt
	
	TIM2->PSC = 0x0;	   //set Tim2 psc
	TIM2->ARR = ENCODER_CNT_RANGE; //set the range for TIM2->CNT
	TIM2->CR1 &=~(3<<8);// do not divide frequent
	TIM2->CR1 &=~(3<<5);// edge align mode,The counter counts up or down depending on the direction bit
		
	TIM2->CCMR1 |= 1<<0; //IC1 is mapped on TI1.
	TIM2->CCMR1 |= 1<<8; //IC2 is mapped on TI2.
	
	TIM2->CCER &= ~(1<<1);	 //non-inverted£¬capture is done on a rising edge of IC1
	TIM2->CCER &= ~(1<<5);	 //non-inverted£¬capture is done on a rising edge of IC2
	
	TIM2->CCMR1 |= 3<<4; //fSAMPLING=fCK_INT, N=8
    
	TIM2->SMCR |= 3<<0;	 //enable the encoder mode, Counter counts up/down on both TI1FP1 and TI2FP2 edges
	TIM2->CNT = 10000;   //THIS is the start num for you
	TIM2->CR1 |= 0x01;    //enable the tim2
}

void Encoder_Init_TIM3(void){
	RCC->APB1ENR|=1<<1;       //enable the Tim3 clk
	RCC->APB2ENR|=1<<2;       //enable the gpioa clk
	GPIOA->CRL&=0XFFFFFFFF;   
	GPIOA->CRL|=0X44000000;   //set A6 A7 to float in

	TIM3->DIER|=1<<0;   //enable the update interupt	
	TIM3->DIER|=1<<6;   //enable the trigger interupt
	
	TIM3->PSC = 0x0;	   //set Tim2 psc
	TIM3->ARR = ENCODER_CNT_RANGE; //set the range for TIM2->CNT
	TIM3->CR1 &=~(3<<8);// do not divide frequent
	TIM3->CR1 &=~(3<<5);// edge align mode,The counter counts up or down depending on the direction bit
		
	TIM3->CCMR1 |= 1<<0; //IC1 is mapped on TI1.
	TIM3->CCMR1 |= 1<<8; //IC2 is mapped on TI2.
	
	TIM3->CCER &= ~(1<<1);	 //non-inverted£¬capture is done on a rising edge of IC1
	TIM3->CCER &= ~(1<<5);	 //non-inverted£¬capture is done on a rising edge of IC2
	
	TIM2->CCMR1 |= 3<<4; //fSAMPLING=fCK_INT, N=8
    
	TIM2->SMCR |= 3<<0;	 //enable the encoder mode, Counter counts up/down on both TI1FP1 and TI2FP2 edges
	TIM2->CNT = 10000;   //THIS is the start num for you
	TIM2->CR1 |= 0x01;    //enable the tim2
}




void Encoder_Init_TIM4(void){
	RCC->APB1ENR|=1<<2;       //enable the Tim2 clk
	RCC->APB2ENR|=1<<3;       //enable the gpioa clk
	GPIOB->CRL&=0XFFFFFFFF;   
	GPIOB->CRL|=0X44000000;   //set B6 B7 to float in

	TIM4->DIER|=1<<0;   //enable the update interupt	
	TIM4->DIER|=1<<6;   //enable the trigger interupt
	
	TIM4->PSC = 0x0;	   //set Tim4 psc
	TIM4->ARR = ENCODER_CNT_RANGE; //set the range for TIM4->CNT
	TIM4->CR1 &=~(3<<8);// do not divide frequent
	TIM4->CR1 &=~(3<<5);// edge align mode,The counter counts up or down depending on the direction bit
		
	TIM4->CCMR1 |= 1<<0; //IC1 is mapped on TI1.
	TIM4->CCMR1 |= 1<<8; //IC2 is mapped on TI2.
	
	TIM4->CCER &= ~(1<<1);	 //non-inverted£¬capture is done on a rising edge of IC1
	TIM4->CCER &= ~(1<<5);	 //non-inverted£¬capture is done on a rising edge of IC2
	
	TIM4->CCMR1 |= 3<<4; //fSAMPLING=fCK_INT, N=8
    
	TIM4->SMCR |= 3<<0;	 //enable the encoder mode, Counter counts up/down on both TI1FP1 and TI2FP2 edges
	TIM4->CNT = 10000;   //THIS is the start num for you
	TIM4->CR1 |= 0x01;    //enable the tim4
}






int Read_Encoder(u8 TIMX){
    int Encoder_TIM;    
    switch(TIMX){
        case 1:   Encoder_TIM= (short)TIM1 -> CNT; break;
        case 2:   Encoder_TIM= (short)TIM2 -> CNT; break;
        case 3:   Encoder_TIM= (short)TIM3 -> CNT; break;	
        case 4:   Encoder_TIM= (short)TIM4 -> CNT; break;	
        default:  Encoder_TIM=0;
    }
    return Encoder_TIM;
}








