#include "daolibai.h"
#include "pwm.h"

unsigned char Send_Count; //串口需要发送的数据个数
unsigned char i,temp;          //计数变量

u32 position=10;


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
	GPIOB_CLK_EN;
	GPIOB_12_OUT_PP();
	GPIOB_13_OUT_PP();
	TIM3_PWM_INIT_HZ(200,0.5,0,0,0,1);
	stop() 
}

//speed range[0:1000]
void set_speed(int speed){
		 int set_speed=0;
		float speed_duty=0;
		
	if(speed>=0){
			set_speed=speed;
			speed_duty=set_speed*1.0/1000.0;
			turn_right();
		}
		else{
			set_speed=-speed;
			speed_duty=set_speed*1.0/1000.0;
			turn_left();
			
		}
		
		motor_speed(speed_duty);

}


void daolibai_init(){
	motor_init();
	Adc1_channel_Init(7);
}
