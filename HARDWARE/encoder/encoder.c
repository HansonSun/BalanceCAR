//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9
//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11

#include "encoder.h"

void Encoder_Init_TIM2(void)
{
	RCC->APB1ENR|=1<<0;     //enable the tim1 clk
	RCC->APB2ENR|=1<<2;    //enable the gpioa clk
	GPIOA->CRL&=0XFFFFFF00;//PA0 PA1
	GPIOA->CRL|=0X00000044;//set a0 a1 to float in

	TIM2->DIER|=1<<0;   //enable the update interupt	
	TIM2->DIER|=1<<6;   //enable the trigger interupt
	
	/* Timer configuration in Encoder mode */ 
	TIM2->PSC = 0x0;	//set tim2 psc
	TIM2->ARR = ENCODER_TIM_PERIOD;//set tim2 arr
	TIM2->CR1 &=~(3<<8);// do not divide frequent
	TIM2->CR1 &=~(3<<5);// edge align mode
		
	TIM2->CCMR1 |= 1<<0; //IC1 is mapped on TI1.
	TIM2->CCMR1 |= 1<<8; //IC2 is mapped on TI2.
	
	TIM2->CCER &= ~(1<<1);	 //non-inverted
	TIM2->CCER &= ~(1<<5);	 //non-inverted
	
	TIM2->CCMR1 |= 3<<4; //	IC1F='1000' 输入捕获1滤波器
	TIM2->SMCR |= 3<<0;	 //SMS='011' 所有的输入均在上升沿和下降沿有效
	TIM2->CNT = 10000;   //THIS is the start num for you
	TIM2->CR1 |= 0x01;    //enable the tim2
}
/**************************************************************************
函数功能：把TIM4初始化为编码器接口模式
入口参数：无
返回  值：无
**************************************************************************/
void Encoder_Init_TIM4(void)
{
	RCC->APB1ENR|=1<<2;     //TIM4时钟使能
	RCC->APB2ENR|=1<<3;     //使能PORTB时钟
	GPIOB->CRL&=0X00FFFFFF; //PB6 PB7
	GPIOB->CRL|=0X44000000; //浮空输入
//	/* 把定时器初始化为编码器模式 */ 
//	TIM4->PSC = 0x0;//预分频器
//	TIM4->ARR = ENCODER_TIM_PERIOD-1;//设定计数器自动重装值 
//  TIM4->CCMR1 |= 1<<0;          //输入模式，IC1FP1映射到TI1上
//  TIM4->CCMR1 |= 1<<8;          //输入模式，IC2FP2映射到TI2上
//  TIM4->CCER |= 0<<1;           //IC1不反向
//  TIM4->CCER |= 0<<5;           //IC2不反向
//	TIM4->SMCR |= 3<<0;	          //SMS='011' 所有的输入均在上升沿和下降沿有效
//	TIM4->CNT=10000;
//	TIM4->CR1 |= 0x01;            //CEN=1，使能定时器
	
		/* Enable the TIM3 Update Interrupt */
	//这两个东东要同时设置才可以使用中断
	TIM4->DIER|=1<<0;   //允许更新中断				
	TIM4->DIER|=1<<6;   //允许触发中断
	//MY_NVIC_Init(1,3,TIM4_IRQn,1);

	/* Timer configuration in Encoder mode */ 
	TIM4->PSC = 0x0;//预分频器
	TIM4->ARR = ENCODER_TIM_PERIOD;//设定计数器自动重装值 
	TIM4->CR1 &=~(3<<8);// 选择时钟分频：不分频
	TIM4->CR1 &=~(3<<5);// 选择计数模式:边沿对齐模式
		
	TIM4->CCMR1 |= 1<<0; //CC1S='01' IC1FP1映射到TI1
	TIM4->CCMR1 |= 1<<8; //CC2S='01' IC2FP2映射到TI2
	TIM4->CCER &= ~(1<<1);	 //CC1P='0'	 IC1FP1不反相，IC1FP1=TI1
	TIM4->CCER &= ~(1<<5);	 //CC2P='0'	 IC2FP2不反相，IC2FP2=TI2
	TIM4->CCMR1 |= 3<<4; //	IC1F='1000' 输入捕获1滤波器
	TIM4->SMCR |= 3<<0;	 //SMS='011' 所有的输入均在上升沿和下降沿有效
	TIM4->CNT = 10000;
	TIM4->CR1 |= 0x01;    //CEN=1，使能定时器
}
/**************************************************************************
函数功能：单位时间读取编码器计数
入口参数：定时器
返回  值：速度值
**************************************************************************/
int Read_Encoder(u8 TIMX)
{
    int Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM= (short)TIM2 -> CNT; break;
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;	
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT; break;	
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}


void TIM4_IRQHandler(void)
{ 		    		  			    
	if(TIM4->SR&0X0001)//溢出中断
	{
			    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//清除中断标志位 	    
}
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//溢出中断
	{
			    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//清除中断标志位 	    
}
