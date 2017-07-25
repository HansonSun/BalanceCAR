#include "daolibai.h"
#include "pwm.h"

unsigned char Send_Count; //串口需要发送的数据个数
unsigned char i,temp;          //计数变量


void DataScope(float num)
{   
		DataScope_Get_Channel_Data( num, 1 );      
		Send_Count = DataScope_Data_Generate(1);
		for( i = 0 ; i < Send_Count; i++) 
		{
			while((USART1->SR&0X40)==0);  
			USART1->DR = DataScope_OutPut_Buffer[i]; 
		}
}

void motor_init(){
	GPIOB_CLK_ENA();
	GPIOB_12_OUT_PP();//init gpio AIN1 PA12
	GPIOB_13_OUT_PP();//init gpio AIN2 PA13
	TIM3_PWM_INIT_HZ(200,0.2,0,0,1,0);//init pwma
	
	GPIOB_14_OUT_PP();//init gpio BIN1 PA14 
	GPIOB_15_OUT_PP();//init gpio BIN2 PA15
	TIM3_PWM_INIT_HZ(200,0.5,0,0,0,1);//init pwmb
}
void daolibai_init(){
	motor_init();
	PBout(12)=0;
	PBout(13)=1;
	PBout(14)=0;
	PBout(15)=1;
	Adc1_channel_Init(7);

}
