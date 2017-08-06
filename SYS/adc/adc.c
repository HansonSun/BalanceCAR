//ע�͵ĵط�ʱʹ�ö�ͨ���ɼ�����Ҫ�ı��
//ADC12_IN0:PA0  ADC12_IN1:PA1  ADC12_IN2:PA2  ADC12_IN3:PA3  ADC12_IN4:PA4  ADC12_IN5:PA5 ADC12_IN6:PA6 ADC12_IN7:PA7
//ADC12_IN8:PB0  ADC12_IN9:PB1  ADC12_IN10:PC0 ADC12_IN11:PC1 ADC12_IN13:PC3 ADC12_IN14:PC4  ADC12_IN15:PC5
 
#include"adc.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void Adc_Singlechannel_Gpio_Init(int ch){
  switch(ch){
		case(0):{
			GPIOA_CLK_EN
			GPIOA_0_IN_ANALOG();
			break;
		}
		case(1):{
			GPIOA_CLK_EN
			GPIOA_1_IN_ANALOG();
			break;
		}
		case(2):{
			GPIOA_CLK_EN
			GPIOA_2_IN_ANALOG();
			break;
		}
	  case(3):{
			GPIOA_CLK_EN
			GPIOA_3_IN_ANALOG();
			break;
		}
		case(4):{
			GPIOA_CLK_EN
			GPIOA_4_IN_ANALOG();
			break;
		}
		case(5):{
			GPIOA_CLK_EN
			GPIOA_5_IN_ANALOG();
			break;
		}
		case(6):{
			GPIOA_CLK_EN
			GPIOA_6_IN_ANALOG();
			break;
		}
		case(7):{
			GPIOA_CLK_EN
			GPIOA_7_IN_ANALOG();
			break;
		}
		case(8):{
			GPIOA_CLK_EN
			GPIOB_0_IN_ANALOG();
			break;
		}
	  case(9):{
			GPIOB_CLK_EN
			GPIOB_1_IN_ANALOG();
			break;
		}
		case(10):{
			GPIOC_CLK_EN
			GPIOC_0_IN_ANALOG();
			break;
		}
		case(11):{
			GPIOC_CLK_EN
			GPIOC_1_IN_ANALOG();
			break;
		}
		case(12):{
			GPIOC_CLK_EN
			GPIOC_2_IN_ANALOG();
			break;
		}
		case(13):{
			GPIOC_CLK_EN
			GPIOC_3_IN_ANALOG();
			break;
		}
		case(14):{
			GPIOC_CLK_EN
			GPIOC_4_IN_ANALOG();
			break;
		}
		case(15):{
			GPIOC_CLK_EN
			GPIOC_5_IN_ANALOG();
			break;
		}
	}
}




u16 Get_Adc(u8 ch)   
{

	ADC1->SQR3&=0XFFFFFFE0;//��������1 ͨ��ch
	ADC1->SQR3|=ch;		  			    
	ADC1->CR2|=1<<22;       //��������ת��ͨ�� 
	while(!(ADC1->SR&1<<1));//�ȴ�ת������	 	   
	return ADC1->DR;		//����adcֵ	
}

Adc1_Multichannel_repeat(int channel_cnt,...){
		va_list vaptr;
		int ad_ch;
		va_start(vaptr,channel_cnt);
	
		ADC1->SQR1&=~(0XF<<20);  //define the the conversion num
		ADC1->SQR1&=(channel_cnt-1)<<20;  
	
	
		RCC->APB2ENR|=1<<9;    //enable the ADC1 clk	  
		RCC->APB2RSTR|=1<<9;   //reset ADC1
		RCC->APB2RSTR&=~(1<<9);   
		RCC->CFGR&=~(3<<14);   //set  the adc freq  12M
		RCC->CFGR|=2<<14; 
	
	
	
		ADC1->CR1&=0XF0FFFF;   
		ADC1->CR1&=~(0xf<<16);      //set adc Independent mode 
		ADC1->CR1|=1<<8;    		//enable the scan  
			
		ADC1->CR2&=~(1<<1);    //Continuous conversion
		ADC1->CR2&=~(7<<17);	    
		ADC1->CR2|=7<<17;	   //SWSTART
		ADC1->CR2|=1<<20;      //Conversion on external event enabled
		ADC1->CR2&=~(1<<11);   //Right alignment of data 
	
	
		for(ad_ch=0; ad_ch<number;ad_ch++)
	  {
		    channel=va_arg(vaptr,int);
				Adc_Singlechannel_Gpio_Init(channel);
			
			

	if(ad_ch<10){
		unsigned int mask=~(0x7<<(3*ad_ch));
		ADC1->SMPR2&=mask;//clear the channel
		ADC1->SMPR2|=7<<21;     //set Sample time to  239.5 cycles
	}
	else{
		unsigned int mask=~(0x7<<(3*(ad_ch%10)));
		ADC1->SMPR1&=mask;//clear the channel
		ADC1->SMPR1|=7<<((ad_ch%10)*3);      //set Sample time to  239.5 cycles
	}
switch(){
case
}
	
	
		}
		va_end(vaptr);	
		
			ADC1->CR2|=1<<0;	    //����ADת����	 
	ADC1->CR2|=1<<3;        //ʹ�ܸ�λУ׼  
	while(ADC1->CR2&1<<3);  //�ȴ�У׼���� 			 
    //��λ��������ò���Ӳ���������У׼�Ĵ�������ʼ�����λ��������� 		 
	ADC1->CR2|=1<<2;        //����ADУ׼	   
	while(ADC1->CR2&1<<2);  //�ȴ�У׼����

	
		
}
Adc1_Multichannel_onece(int channel_cnt,...){
	
		va_list vaptr;
		int i;
		int channel;
		va_start(vaptr,channel_cnt);
		for(i=0; i<number;i++)
	  {
		    channel=va_arg(vaptr,int);
				Adc_Singlechannel_Gpio_Init(channel);
			
			
			RCC->APB2ENR|=1<<9;    //enable the adc1 clk	  
			RCC->APB2RSTR|=1<<9;   //reset ADC1
			RCC->APB2RSTR&=~(1<<9);   
			RCC->CFGR&=~(3<<14);   //set  the adc freq  12M
			RCC->CFGR|=2<<14;      	 

	ADC1->CR1&=0XF0FFFF;   //
	ADC1->CR1|=0<<16;      //Independent mode 
	ADC1->CR1&=~(1<<8);    //diaable the scan  
			
	ADC1->CR2&=~(1<<1);    //����ת��ģʽ
	ADC1->CR2&=~(7<<17);	   
	ADC1->CR2|=7<<17;	   //�������ת��  
	ADC1->CR2|=1<<20;      //ʹ�����ⲿ����(SWSTART)!!!	����ʹ��һ���¼�������
	ADC1->CR2&=~(1<<11);   //�Ҷ���	 
	ADC1->SQR1&=~(0XF<<20);
	ADC1->SQR1&=0<<20;     //1��ת���ڹ��������� Ҳ����ֻת����������1 			

	if(ad_ch<10){
		//����ͨ��7�Ĳ���ʱ��
		unsigned int mask=~(0x7<<(3*ad_ch));
		ADC1->SMPR2&=mask;//ͨ��7����ʱ�����	  
		ADC1->SMPR2|=7<<21;      //ͨ��7  239.5����,��߲���ʱ�������߾�ȷ��	
	}
	else{
		unsigned int mask=~(0x7<<(3*(ad_ch%10)));
		ADC1->SMPR1&=mask;//ͨ��7����ʱ�����	  
		ADC1->SMPR1|=7<<((ad_ch%10)*3);      //ͨ��7  239.5����,��߲���ʱ�������߾�ȷ��
	}
 

	ADC1->CR2|=1<<0;	    //����ADת����	 
	ADC1->CR2|=1<<3;        //ʹ�ܸ�λУ׼  
	while(ADC1->CR2&1<<3);  //�ȴ�У׼���� 			 
    //��λ��������ò���Ӳ���������У׼�Ĵ�������ʼ�����λ��������� 		 
	ADC1->CR2|=1<<2;        //����ADУ׼	   
	while(ADC1->CR2&1<<2);  //�ȴ�У׼����

	
	
		}
		va_end(vaptr);	
		

}
Adc1_Singlechannel_repeat(u8 ch){

}

Adc1_Singlechannel_onece(u8 ch){
  
	 		 
	RCC->APB2ENR|=1<<9;    //ADC1ʱ��ʹ��	  
	RCC->APB2RSTR|=1<<9;   //ADC1��λ
	RCC->APB2RSTR&=~(1<<9);//��λ����	    
	RCC->CFGR&=~(3<<14);   //��Ƶ��������	
	//SYSCLK/DIV2=12M ADCʱ������Ϊ12M,ADC���ʱ�Ӳ��ܳ���14M!
	//���򽫵���ADC׼ȷ���½�! 
	RCC->CFGR|=2<<14;      	 

	ADC1->CR1&=0XF0FFFF;   //����ģʽ����
	ADC1->CR1|=0<<16;      //��������ģʽ  
	ADC1->CR1&=~(1<<8);    //��ɨ��ģʽ	  
	ADC1->CR2&=~(1<<1);    //����ת��ģʽ
	ADC1->CR2&=~(7<<17);	   
	ADC1->CR2|=7<<17;	   //�������ת��  
	ADC1->CR2|=1<<20;      //ʹ�����ⲿ����(SWSTART)!!!	����ʹ��һ���¼�������
	ADC1->CR2&=~(1<<11);   //�Ҷ���	 
	ADC1->SQR1&=~(0XF<<20);
	ADC1->SQR1&=0<<20;     //1��ת���ڹ��������� Ҳ����ֻת����������1 			

	if(ad_ch<10){
		//����ͨ��7�Ĳ���ʱ��
		unsigned int mask=~(0x7<<(3*ad_ch));
		ADC1->SMPR2&=mask;//ͨ��7����ʱ�����	  
		ADC1->SMPR2|=7<<21;      //ͨ��7  239.5����,��߲���ʱ�������߾�ȷ��	
	}
	else{
		unsigned int mask=~(0x7<<(3*(ad_ch%10)));
		ADC1->SMPR1&=mask;//ͨ��7����ʱ�����	  
		ADC1->SMPR1|=7<<((ad_ch%10)*3);      //ͨ��7  239.5����,��߲���ʱ�������߾�ȷ��
	}
 

	ADC1->CR2|=1<<0;	    //����ADת����	 
	ADC1->CR2|=1<<3;        //ʹ�ܸ�λУ׼  
	while(ADC1->CR2&1<<3);  //�ȴ�У׼���� 			 
    //��λ��������ò���Ӳ���������У׼�Ĵ�������ʼ�����λ��������� 		 
	ADC1->CR2|=1<<2;        //����ADУ׼	   
	while(ADC1->CR2&1<<2);  //�ȴ�У׼����


}



u16 Get_Adc_Average(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
	//	delay_us(200);
	}
	return temp_val/times;
} 
	 


