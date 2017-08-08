//注释的地方时使用多通道采集是需要改变的
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


void adc_set_sequence(int ch){
		if(ch<=6 && ch >=1){
				ADC1->SQR1&=(0X1F)<<((ch%7)*5);
				ADC1->SQR1|=(ch)<<((ch%7)*5);
		}
		else if(ch<=12 && ch >=7){
				ADC1->SQR2&=(0X1F)<<((ch%7)*5);
				ADC1->SQR2|=(ch)<<((ch%7)*5);
		}
		else if(ch<=16 && ch>=13){
				ADC1->SQR1&=(0X1F)<<((ch%13)*5);
				ADC1->SQR1|=(ch)<<((ch%13)*5);
		}

} 

u16 Get_Adc(u8 ch)   
{

	ADC1->SQR3&=0XFFFFFFE0;//规则序列1 通道ch
	ADC1->SQR3|=ch;		  			    
//	ADC1->CR2|=1<<22;       //启动规则转换通道 
	while(!(ADC1->SR&1<<1));//等待转换结束	 	   
	return ADC1->DR;		//返回adc值	
}


void Adc1_Multichannel_repeat(int channel_cnt,...){
		va_list vaptr;
		int i;
		int ad_ch;
		va_start(vaptr,channel_cnt); //get ad channel num
	
		ADC1->SQR1&=~(0XF<<20);  
		ADC1->SQR1|=(channel_cnt-1)<<20;  //define the the conversion num
	
		RCC->APB2ENR|=1<<9;    //enable the ADC1 clk	
  
		RCC->APB2RSTR|=1<<9;   //reset ADC1
		RCC->APB2RSTR&=~(1<<9);   
	
		RCC->CFGR&=~(3<<14);   //set  the adc freq  12M
		RCC->CFGR|=2<<14; 
	
		ADC1->CR1&=0XF0FFFF;   
		ADC1->CR1&=~(0xf<<16);  //set adc Independent mode 
		ADC1->CR1|=1<<8;    		//enable the scan  
			
		ADC1->CR2|=(1<<1);    //Continuous conversion    
		ADC1->CR2|=7<<17;	   //SWSTART
		ADC1->CR2|=1<<20;      //Conversion on external event enabled
		ADC1->CR2&=~(1<<11);   //Right alignment of data 
	
		for(i=0; i<channel_cnt;i++)
	  {
		    ad_ch=va_arg(vaptr,int);
				Adc_Singlechannel_Gpio_Init(ad_ch); //init the ad channel gpio

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
				
				adc_set_sequence(ad_ch);
	
	
		}
		va_end(vaptr);	
		
		ADC1->CR2|=1<<0;	      //开启AD转换器	 
		ADC1->CR2|=1<<3;        //使能复位校准  
		while(ADC1->CR2&1<<3);  //等待校准结束 			 
		//该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
		ADC1->CR2|=1<<2;        //开启AD校准	   
		while(ADC1->CR2&1<<2);  //等待校准结束
}
//the multichannel must use the dma,because the cpu have no time to make conversion for adc
void Adc1_Multichannel_once(int channel_cnt,...){
		va_list vaptr;
		int i;
		int ad_ch;
		va_start(vaptr,channel_cnt); //get ad channel num
	
		ADC1->SQR1&=~(0XF<<20);  
		ADC1->SQR1|=(channel_cnt-1)<<20;  //define the the conversion num
	
		RCC->APB2ENR|=1<<9;    //enable the ADC1 clk	
  
		RCC->APB2RSTR|=1<<9;   //reset ADC1
		RCC->APB2RSTR&=~(1<<9);   
	
		RCC->CFGR&=~(3<<14);   //set  the adc freq  12M
		RCC->CFGR|=2<<14; 
	
		ADC1->CR1&=0XF0FFFF;   
		ADC1->CR1&=~(0xf<<16);  //set adc Independent mode 
		ADC1->CR1|=1<<8;    		//enable the scan  
			
		ADC1->CR2|=(1<<1);    //Continuous conversion    
		ADC1->CR2|=7<<17;	   //SWSTART
		ADC1->CR2|=1<<20;      //Conversion on external event enabled
		ADC1->CR2&=~(1<<11);   //Right alignment of data 
	
		for(i=0; i<channel_cnt;i++)
	  {
		    ad_ch=va_arg(vaptr,int);
				Adc_Singlechannel_Gpio_Init(ad_ch); //init the ad channel gpio

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
				
				adc_set_sequence(ad_ch);
	
	
		}
		va_end(vaptr);	
		
		ADC1->CR2|=1<<0;	      //开启AD转换器	 
		ADC1->CR2|=1<<3;        //使能复位校准  
		while(ADC1->CR2&1<<3);  //等待校准结束 			 
		//该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
		ADC1->CR2|=1<<2;        //开启AD校准	   
		while(ADC1->CR2&1<<2);  //等待校准结束
		
}

void Adc1_Singlechannel_repeat(u8 ad_ch){
	Adc_Singlechannel_Gpio_Init(ad_ch); //init the ad channel gpio		 
	RCC->APB2ENR|=1<<9;    		//Enable ADC1 clk	  
	RCC->APB2RSTR|=1<<9;   		//reset the adc1
	RCC->APB2RSTR&=~(1<<9);   
	RCC->CFGR&=~(3<<14);  		//set the adc freq
	RCC->CFGR|=2<<14;      	 

	ADC1->CR1&=0XF0FFFF;   //Independent mode  
	ADC1->CR1&=~(1<<8);    //disable the scan mode
	ADC1->CR2|=(1<<1);    //Continuous conversion mode   
	ADC1->CR2|=7<<17;	   //SWSTART 
	ADC1->CR2|=1<<20;      //Conversion on external event enabled
	ADC1->CR2&=~(1<<11);   //right align
	ADC1->SQR1&=~(0XF<<20);//1 conversion		

	if(ad_ch<10){
		//设置通道7的采样时间
		unsigned int mask=~(0x7<<(3*ad_ch));
		ADC1->SMPR2&=mask;//通道7采样时间清空	  
		ADC1->SMPR2|=7<<21;      //通道7  239.5周期,提高采样时间可以提高精确度	
	}
	else{
		unsigned int mask=~(0x7<<(3*(ad_ch%10)));
		ADC1->SMPR1&=mask;//通道7采样时间清空	  
		ADC1->SMPR1|=7<<((ad_ch%10)*3);      //通道7  239.5周期,提高采样时间可以提高精确度
	}
	
	ADC1->SQR3&=0XFFFFFFE0;//规则序列1 通道ch
	ADC1->SQR3|=ad_ch;		
 

	ADC1->CR2|=1<<0;	    //开启AD转换器	 
	ADC1->CR2|=1<<3;        //使能复位校准  
	while(ADC1->CR2&1<<3);  //等待校准结束 			 
    //该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
	ADC1->CR2|=1<<2;        //开启AD校准	   
	while(ADC1->CR2&1<<2);  //等待校准结束
}

void Adc1_Singlechannel_once(u8 ad_ch){
	
	Adc_Singlechannel_Gpio_Init(ad_ch); //init the ad channel gpio		 
	RCC->APB2ENR|=1<<9;    		//Enable ADC1 clk	  
	RCC->APB2RSTR|=1<<9;   		//ADC1 reset
	RCC->APB2RSTR&=~(1<<9);   
	RCC->CFGR&=~(3<<14);  
	RCC->CFGR|=2<<14;      	 

	ADC1->CR1&=0XF0FFFF;   //Independent mode  
	ADC1->CR1&=~(1<<8);    //disable the scan mode
	ADC1->CR2&=~(1<<1);    //Single conversion mode
	ADC1->CR2&=~(7<<17);	   
	ADC1->CR2|=7<<17;	   //SWSTART 
	ADC1->CR2|=1<<20;      //Conversion on external event enabled
	ADC1->CR2&=~(1<<11);   //right align
	ADC1->SQR1&=~(0XF<<20);//1 conversion		

	if(ad_ch<10){
		//设置通道7的采样时间
		unsigned int mask=~(0x7<<(3*ad_ch));
		ADC1->SMPR2&=mask;//通道7采样时间清空	  
		ADC1->SMPR2|=7<<21;      //通道7  239.5周期,提高采样时间可以提高精确度	
	}
	else{
		unsigned int mask=~(0x7<<(3*(ad_ch%10)));
		ADC1->SMPR1&=mask;//通道7采样时间清空	  
		ADC1->SMPR1|=7<<((ad_ch%10)*3);      //通道7  239.5周期,提高采样时间可以提高精确度
	}
 

	ADC1->CR2|=1<<0;	    //开启AD转换器	 
	ADC1->CR2|=1<<3;        //使能复位校准  
	while(ADC1->CR2&1<<3);  //等待校准结束 			 
    //该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
	ADC1->CR2|=1<<2;        //开启AD校准	   
	while(ADC1->CR2&1<<2);  //等待校准结束
}



u16 Get_Adc_Average(u8 ch,u8 times){
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++){
		temp_val+=Get_Adc(ch);
	}
	return temp_val/times;
} 
	 

void MYDMA_Config(DMA_Channel_TypeDef*DMA_CHx,u32 cpar,u32 cmar,u16 cndtr){
	RCC->AHBENR|=1<<0; 
	delay_ms(5);   					  //wait the dma to stable
	DMA_CHx->CPAR=cpar;   	  //peripheral address
	DMA_CHx->CMAR=(u32)cmar;  //memory address
	DMA1_MEM_LEN=cndtr; 
	DMA_CHx->CNDTR=cndtr; 
	DMA_CHx->CCR=0X00000000;  
	DMA_CHx->CCR|=1<<4;   // Read from peripheral
	DMA_CHx->CCR|=0<<5;   //Circular mode
	DMA_CHx->CCR|=0<<6; //Peripheral increment mode
	DMA_CHx->CCR|=1<<7;   //Memory increment mode
	DMA_CHx->CCR|=0<<8;   //Peripheral size::8-bits
	DMA_CHx->CCR|=0<<10;  //Memory size::8-bits
	DMA_CHx->CCR|=1<<12;  //Channel priority level -->Medium
	DMA_CHx->CCR&=~(1<<14);  //Memory to memory mode disabled
}

