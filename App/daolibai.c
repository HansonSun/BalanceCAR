#include "daolibai.h"
#include "pwm.h"

unsigned char Send_Count; //������Ҫ���͵����ݸ���
unsigned char i,temp;          //��������

u32 position=10;

void DataScope(float num){   
		DataScope_Get_Channel_Data( num, 1 );      
		Send_Count = DataScope_Data_Generate(1);
		for( i = 0 ; i < Send_Count; i++) {
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


int myabs(int num){
    return num<0?-num:num;
}

//speed range[0:1000]  dead zone may be [400:1000]
int total_zone=1000;
int dead_zone=400;
int usefule_zone=600;

void set_speed(int speed){
    float speed_duty=0;
    int positive_speed=myabs(speed);
    
    float use_ratio=positive_speed*1.0/total_zone;
    int real_speed=dead_zone+usefule_zone*use_ratio;
   
	if(speed>=0){
			speed_duty=real_speed*1.0/1000.0;
			turn_right();
		}
		else{
			speed_duty=-real_speed*1.0/1000.0;
			turn_left();	
		}
		motor_speed(speed_duty);
}


void dead_time_voltage(){


}

void daolibai_init(){
	motor_init();
	Adc1_channel_Init(7);
}
