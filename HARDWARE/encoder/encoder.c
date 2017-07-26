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
	
	TIM2->CCMR1 |= 3<<4; //	IC1F='1000' ���벶��1�˲���
	TIM2->SMCR |= 3<<0;	 //SMS='011' ���е�������������غ��½�����Ч
	TIM2->CNT = 10000;   //THIS is the start num for you
	TIM2->CR1 |= 0x01;    //enable the tim2
}
/**************************************************************************
�������ܣ���TIM4��ʼ��Ϊ�������ӿ�ģʽ
��ڲ�������
����  ֵ����
**************************************************************************/
void Encoder_Init_TIM4(void)
{
	RCC->APB1ENR|=1<<2;     //TIM4ʱ��ʹ��
	RCC->APB2ENR|=1<<3;     //ʹ��PORTBʱ��
	GPIOB->CRL&=0X00FFFFFF; //PB6 PB7
	GPIOB->CRL|=0X44000000; //��������
//	/* �Ѷ�ʱ����ʼ��Ϊ������ģʽ */ 
//	TIM4->PSC = 0x0;//Ԥ��Ƶ��
//	TIM4->ARR = ENCODER_TIM_PERIOD-1;//�趨�������Զ���װֵ 
//  TIM4->CCMR1 |= 1<<0;          //����ģʽ��IC1FP1ӳ�䵽TI1��
//  TIM4->CCMR1 |= 1<<8;          //����ģʽ��IC2FP2ӳ�䵽TI2��
//  TIM4->CCER |= 0<<1;           //IC1������
//  TIM4->CCER |= 0<<5;           //IC2������
//	TIM4->SMCR |= 3<<0;	          //SMS='011' ���е�������������غ��½�����Ч
//	TIM4->CNT=10000;
//	TIM4->CR1 |= 0x01;            //CEN=1��ʹ�ܶ�ʱ��
	
		/* Enable the TIM3 Update Interrupt */
	//����������Ҫͬʱ���òſ���ʹ���ж�
	TIM4->DIER|=1<<0;   //��������ж�				
	TIM4->DIER|=1<<6;   //�������ж�
	//MY_NVIC_Init(1,3,TIM4_IRQn,1);

	/* Timer configuration in Encoder mode */ 
	TIM4->PSC = 0x0;//Ԥ��Ƶ��
	TIM4->ARR = ENCODER_TIM_PERIOD;//�趨�������Զ���װֵ 
	TIM4->CR1 &=~(3<<8);// ѡ��ʱ�ӷ�Ƶ������Ƶ
	TIM4->CR1 &=~(3<<5);// ѡ�����ģʽ:���ض���ģʽ
		
	TIM4->CCMR1 |= 1<<0; //CC1S='01' IC1FP1ӳ�䵽TI1
	TIM4->CCMR1 |= 1<<8; //CC2S='01' IC2FP2ӳ�䵽TI2
	TIM4->CCER &= ~(1<<1);	 //CC1P='0'	 IC1FP1�����࣬IC1FP1=TI1
	TIM4->CCER &= ~(1<<5);	 //CC2P='0'	 IC2FP2�����࣬IC2FP2=TI2
	TIM4->CCMR1 |= 3<<4; //	IC1F='1000' ���벶��1�˲���
	TIM4->SMCR |= 3<<0;	 //SMS='011' ���е�������������غ��½�����Ч
	TIM4->CNT = 10000;
	TIM4->CR1 |= 0x01;    //CEN=1��ʹ�ܶ�ʱ��
}
/**************************************************************************
�������ܣ���λʱ���ȡ����������
��ڲ�������ʱ��
����  ֵ���ٶ�ֵ
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
	if(TIM4->SR&0X0001)//����ж�
	{
			    				   				     	    	
	}				   
	TIM4->SR&=~(1<<0);//����жϱ�־λ 	    
}
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//����ж�
	{
			    				   				     	    	
	}				   
	TIM2->SR&=~(1<<0);//����жϱ�־λ 	    
}
