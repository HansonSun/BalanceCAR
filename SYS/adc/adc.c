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
		if(ch<=5 && ch >=0){
				ADC1->SQR3&=~((0X1F)<<( ch *5));
				ADC1->SQR3|=(ch)<<(ch*5);
		}
		else if(ch<=11 && ch >=6){
				ADC1->SQR2&=~((0X1F)<<((ch%6)*5));
				ADC1->SQR2|=(ch)<<((ch%6)*5);
		}
		else if(ch<=15 && ch>=12){
				ADC1->SQR1&=~((0X1F)<<((ch%12)*5));
				ADC1->SQR1|=(ch)<<((ch%12)*5);
		}

} 



void Adc1_Multichannel_repeat(int channel_cnt,...){
		va_list vaptr;
		int i;
		int ad_ch;
		va_start(vaptr,channel_cnt); //get ad channel num
	
		RCC->APB2ENR|=1<<9;    //enable the ADC1 clk	
  
		RCC->APB2RSTR|=1<<9;   //reset ADC1
		RCC->APB2RSTR&=~(1<<9);   
	
		RCC->CFGR&=~(3<<14);   //set  the adc freq  12M
		RCC->CFGR|=2<<14; 
	
		ADC1->CR1&=0XF0FFFF;   //set adc Independent mode 
		ADC1->CR1|=1<<8;    		//enable the scan  
			
		ADC1->CR2|=(1<<1);    //Continuous conversion    
		ADC1->CR2|=1<<20;      //Conversion on external event enabled!!!!!!!!!!!!!!!!!!
		ADC1->CR2|=7<<17;	   //SWSTART

		ADC1->CR2&=~(1<<11);   //Right alignment of data 
		
		ADC1->SQR1&=~(0XF<<20);  //THE SQ1 SET TIME IS VERY IMPORT 
	  ADC1->SQR1|=(channel_cnt-1)<<20;  //define the the conversion num

		for(i=0; i<channel_cnt;i++)
	  {	
		    ad_ch=va_arg(vaptr,int);
				Adc_Singlechannel_Gpio_Init(ad_ch); //init the ad channel gpio

				if(ad_ch<10){
						unsigned int mask=~(0x7<<(3*ad_ch));
						ADC1->SMPR2&=mask;//clear the channel
						ADC1->SMPR2|=7<<(ad_ch*3);     //set Sample time to  239.5 cycles
				}
				else{
						unsigned int mask=~(0x7<<(3*(ad_ch%10)));
						ADC1->SMPR1&=mask;//clear the channel
						ADC1->SMPR1|=7<<((ad_ch%10)*3);      //set Sample time to  239.5 cycles
				}
				
				adc_set_sequence(ad_ch);
	
	
		}
		va_end(vaptr);	
		
		ADC1->CR2|=1<<0;  //ENABLE THE ADC1 DMA
		ADC1->CR2|=1<<8;  //ENABLE THE ADC1 DMA

		 
		ADC1->CR2|=1<<3;        //使能复位校准  
		while(ADC1->CR2&1<<3);  //等待校准结束 			 
		//该位由软件设置并由硬件清除。在校准寄存器被初始化后该位将被清除。 		 
		ADC1->CR2|=1<<2;        //开启AD校准	   
		while(ADC1->CR2&1<<2);  //等待校准结束
		
		ADC1->CR2|=1<<22;       //启动规则转换通道
		ADC1->CR2|=1<<20;      //Conversion on external event enabled!!!!!!!!!!!!!!!!!!
 
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
 
		  ADC1->CR2|=1<<8;  //ENABLE THE ADC1 DMA

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
	 


#define ADC1_DR_Address    ((u32)0x4001244C)

vu16 ADC1SingleConverted=12;	   //存储多通道采集到的数据的数组

//ADC1 in Adc channel 1
void Adc_DMA_OneChannel_Config(  ){
		RCC->AHBENR|=1<<0;							//Enable the dma1  clk
		delay_ms(5);										//wait for stable
		DMA1_Channel1->CPAR=ADC1_DR_Address; 	 //set peripheral address register
		DMA1_Channel1->CMAR=(u32)(&ADC1SingleConverted); 				//set memory address register     	
		DMA1_Channel1->CNDTR=16;    		  //number of data
		DMA1_Channel1->CCR=0X00000000;		//reset the ccr
		DMA1_Channel1->CCR|=0<<4;  				//Read from peripheral
		DMA1_Channel1->CCR|=1<<5;  				//Circular mode enabled
		DMA1_Channel1->CCR|=0<<6; 				//Peripheral increment mode disabled
		DMA1_Channel1->CCR|=0<<7; 	 			//Memory increment mode disabled
		DMA1_Channel1->CCR|=0x1<<8; 	 			//16-bits Peripheral size
		DMA1_Channel1->CCR|=0x1<<10; 				//16-bits Memory size
		DMA1_Channel1->CCR|=1<<12; 				//Channel priority level
		DMA1_Channel1->CCR|=0<<14; 				//Memory to memory mode disabled  	
	


		DMA1_Channel1->CCR&=~(1<<0);    //Channel disabled  
		DMA1_Channel1->CNDTR=16; 
		DMA1_Channel1->CCR|=1<<0;         //Channel enabled 
}

vu16 ADC1MultiConverted[3]={0x31,0x31,0x31};	   //存储多通道采集到的数据的数组

void Adc_DMA_MultiChannel_Config( ){
		RCC->AHBENR|=1<<0;					//Enable the dma1  clk
		delay_ms(5);								//wait for stable
		DMA1_Channel1->CPAR=ADC1_DR_Address; 	 		//set peripheral address register
		DMA1_Channel1->CMAR=(u32)(ADC1MultiConverted); 	//set memory address register     	
		DMA1_Channel1->CNDTR=3;    	//number of data
		DMA1_Channel1->CCR=0X00000000;	//reset the ccr
		DMA1_Channel1->CCR|=0<<4;  			//Read from peripheral
		DMA1_Channel1->CCR|=1<<5;  			//Circular mode enabled
		DMA1_Channel1->CCR|=1<<6; 			//Peripheral increment mode enabled
		DMA1_Channel1->CCR|=1<<7; 	 		//Memory increment mode enabled
		DMA1_Channel1->CCR|=1<<8; 	 		//16-bits Peripheral size
		DMA1_Channel1->CCR|=1<<10; 			//16-bits Memory size
		DMA1_Channel1->CCR|=1<<12; 			//Channel priority level
		DMA1_Channel1->CCR|=0<<14; 			//Memory to memory mode disabled  

		DMA1_Channel1->CCR&=~(1<<0);    //Channel disabled  
		DMA1_Channel1->CNDTR=3; 
		DMA1_Channel1->CCR|=1<<0;         //Channel enabled 

	
} 




u16 Get_Adc(u8 ch)   
{

	ADC1->SQR3&=0XFFFFFFE0;//规则序列1 通道ch
	ADC1->SQR3|=ch;		  			    
//	ADC1->CR2|=1<<22;       //启动规则转换通道 
	while(!(ADC1->SR&1<<1));//等待转换结束	 	   
	return ADC1->DR;		//返回adc值	
}