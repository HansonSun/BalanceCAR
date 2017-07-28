//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11
//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9


#include"pwm.h"

//range[0.2HZ,24MHZ]
void TIM1_SET_FREQ(u8 ch,u32 freq){
    if(freq<=1000){
        u16 psc=7199;
        u16 arr=10000/freq;

       // TIM1_1_SET_CCR(arr/2);
        
        TIM1_PWM_INIT(arr,7199);

        TIM1_1_SET_CCR(arr/2 );
    }
    else if(freq<=10000){
        u16 psc=71;
        u16 arr=1000000/freq;
        TIM1->PSC=psc;
        TIM1->ARR=arr;
        TIM1_1_SET_CCR(arr/2);
    }
    else if(freq<=24000000){
        u16 psc=1;
        u16 arr=48000000/freq;
        TIM1->PSC=psc;
        TIM1->ARR=arr;
        TIM1_1_SET_CCR(arr/2);
    }
}

void TIM1_PWM_INIT(u16 arr,u16 psc){
    RCC->APB2ENR|=1<<11;  //Enable The Timer1 CLK
    TIM1->ARR=arr;		  //SET Timer1 ARR
    TIM1->PSC=psc;		  //SET Timer1 PSC	
    TIM1->BDTR|=1<<15;    //set break and dead-time register (timer1 and timer8 only)
    TIM1->CR1=0x0080;     //enable the reload buffer
    TIM1->CR1|=0x01;      //enable the counter 
}
void TIM2_PWM_INIT(u16 arr,u16 psc){		 					 
	RCC->APB1ENR|=1<<0;    //Enable The Timer2 clk
	TIM2->ARR=arr;		   //SET Timer2 ARR
	TIM2->PSC=psc;		   //SET Timer2 PSC	
	TIM2->CR1=0x0080;      //enable the reload buffer
	TIM2->CR1|=0x01;       //enable the counter    											  
} 

void TIM3_PWM_INIT(u16 arr,u16 psc){		 					 
	RCC->APB1ENR|=1<<1;     //Enable The Timer3 clk
	TIM3->ARR=arr;			//SET Timer3 ARR
	TIM3->PSC=psc;			//SET Timer3 PSC
	TIM3->CR1=0x0080;   	//enable the reload buffer
	TIM3->CR1|=0x01;        //enable the counter    											  
} 

void TIM4_PWM_INIT(u16 arr,u16 psc){		 					 
	RCC->APB1ENR|=1<<2;     //Enable The Timer4 clk
	TIM4->ARR=arr;			//SET Timer4 ARR
	TIM4->PSC=psc;			//SET Timer4 PSC
	TIM4->CR1=0x0080;   	//enable the reload buffer
	TIM4->CR1|=0x01;  		//enable the counter    											  
} 



void TIM1_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(time_ms*10.0);
	TIM1_PWM_INIT(set_arr-1,7199);
	
	if(ch1==1){
		TIM1_ENA_CH(1);
		TIM1_1_SET_CCR((u16)(set_arr*duty) );
	}
	if(ch2==1){
		TIM1_ENA_CH(2);
		TIM1_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM1_ENA_CH(3);
		TIM1_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM1_ENA_CH(4);
		TIM1_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM2_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(time_ms*10.0);
	TIM2_PWM_INIT(set_arr-1,7199);
	
	if(ch1==1){
		TIM2_ENA_CH(1);
		TIM2_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM2_ENA_CH(2);
		TIM2_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM2_ENA_CH(3);
		TIM2_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM2_ENA_CH(4);
		TIM2_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM3_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(time_ms*10.0);
	TIM3_PWM_INIT(set_arr-1,7199);
	
	if(ch1==1){
		TIM3_ENA_CH(1);
		TIM3_1_SET_CCR( (u16)(set_arr*duty) );
	}
	if(ch2==1){
		TIM3_ENA_CH(2);
		TIM3_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM3_ENA_CH(3);
		TIM3_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM3_ENA_CH(4);
		TIM3_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM4_PWM_INIT_MS(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(time_ms*10.0);
	TIM4_PWM_INIT(set_arr-1,7199);
	
	if(ch1==1){
		TIM4_ENA_CH(1);
		TIM4_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM4_ENA_CH(2);
		TIM4_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM4_ENA_CH(3);
		TIM4_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM4_ENA_CH(4);
		TIM4_4_SET_CCR((u16)(set_arr*duty));
	}
}


void TIM1_1_SET_DUTY(int ch,float duty){
	u16 arr=TIM1->ARR;
	TIM1_1_SET_CCR( (u16)((arr+1)*duty) );
}


void TIM3_1_SET_DUTY(float duty){
	u16 arr=TIM3->ARR;
	TIM3_1_SET_CCR( (u16)((arr+1)*duty));
}

void TIM3_2_SET_DUTY(float duty){
	u16 arr=TIM3->ARR;
	TIM3_2_SET_CCR( (u16)((arr+1)*duty));
}

void TIM3_3_SET_DUTY(float duty){
	u16 arr=TIM3->ARR;
	u16 set_num=(u16)((arr+1)*duty);
	TIM3_3_SET_CCR( set_num );
}

void TIM3_4_SET_DUTY(float duty){
	int arr=TIM3->ARR;
	TIM3_4_SET_CCR( (u16)((arr+1)*duty) );
	

}

void TIM1_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(100000/hz);
	TIM1_PWM_INIT(set_arr-1,719);
	
	if(ch1==1){
		TIM1_ENA_CH(1);
		TIM1_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM1_ENA_CH(2);
		TIM1_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM1_ENA_CH(3);
		TIM1_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM1_ENA_CH(4);
		TIM1_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM2_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(100000/hz);
	TIM2_PWM_INIT(set_arr-1,719);
	
	if(ch1==1){
		TIM2_ENA_CH(1);
		TIM2_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM2_ENA_CH(2);
		TIM2_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM2_ENA_CH(3);
		TIM2_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM2_ENA_CH(4);
		TIM2_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM3_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(100000/hz);
	TIM3_PWM_INIT(set_arr-1,719);
	
	if(ch1==1){
		TIM3_ENA_CH(1);
		TIM3_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM3_ENA_CH(2);
		TIM3_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM3_ENA_CH(3);
		TIM3_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM3_ENA_CH(4);
		TIM3_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM4_PWM_INIT_HZ(int hz,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 set_arr=(u16)(100000/hz);
	TIM4_PWM_INIT(set_arr-1,719);
	
	if(ch1==1){
		TIM4_ENA_CH(1);
		TIM4_1_SET_CCR((u16)(set_arr*duty));
	}
	if(ch2==1){
		TIM4_ENA_CH(2);
		TIM4_2_SET_CCR((u16)(set_arr*duty));
	}
	if(ch3==1){
		TIM4_ENA_CH(3);
		TIM4_3_SET_CCR((u16)(set_arr*duty));
	}
	if(ch4==1){
		TIM4_ENA_CH(4);
		TIM4_4_SET_CCR((u16)(set_arr*duty));
	}
}

void TIM1_ENA_CH(int ch){
	switch(ch){
		case(1):{
			GPIOA_CLK_ENA();
			GPIOA_8_OUT_AFPP();      //Set A8 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR1|=6<<4;  	 //Set pwm in mode 2	
			TIM1->CCMR1|=1<<3; 	 	 //preload mode enable
			TIM1->CCER|=1<<0;   	 //output mode enable 
		break;
		}
		case(2):{
			GPIOA_CLK_ENA();
			GPIOA_9_OUT_AFPP();	     //Set A9 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR1|=6<<12;  	 //Set pwm in mode 2	
			TIM1->CCMR1|=1<<11; 	 //preload mode enable
			TIM1->CCER|=1<<4;   	 //output mode enable  
		break;
		}
		case(3):{
			GPIOA_CLK_ENA();
            GPIOA_10_OUT_AFPP();    //Set A10 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR2|=6<<4;  	//Set pwm in mode 2	
			TIM1->CCMR2|=1<<3; 	 	//preload mode enable
			TIM1->CCER|=1<<8;       //output mode enable  
		break;
		}
		case(4):{
			GPIOA_CLK_ENA();
			GPIOA_11_OUT_AFPP();	//Set A11 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR2|=6<<12;  	//Set pwm in mode 2	
			TIM1->CCMR2|=1<<11; 	//preload mode enable
			TIM1->CCER|=1<<12;   	//output mode enable  
		break;
		}
	}
}


void TIM2_ENA_CH(int ch){
	switch(ch){
		case(1):{
			GPIOA_0_OUT_AFPP();     //Set A0 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR1|=6<<4;  	//Set pwm in mode 1
			TIM2->CCMR1|=1<<3; 	 	//preload mode enable
			TIM2->CCER|=1<<0;   	//output mode enable 
		break;
		}
		case(2):{
			GPIOA_1_OUT_AFPP();	    //Set A1 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR1|=6<<12;  	//Set pwm in mode 1	
			TIM2->CCMR1|=1<<11; 	//preload mode enable
			TIM2->CCER|=1<<4;   	//output mode enable  
		break;
		}
		case(3):{
	    GPIOA_2_OUT_AFPP();         //Set A2 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR2|=6<<4;  	//Set pwm in mode 1
			TIM2->CCMR2|=1<<3; 	 	//preload mode enable
			TIM2->CCER|=1<<8;       //output mode enable  
		break;
		}
		case(4):{
			GPIOA_3_OUT_AFPP();	    //Set A3 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR2|=6<<12;  	//Set pwm in mode 1	
			TIM2->CCMR2|=1<<11; 	//preload mode enable
			TIM2->CCER|=1<<12;      //output mode enable  
		break;
		}
	}
}

void TIM3_ENA_CH(int ch){
	switch(ch){
		case(1):{
			GPIOA_6_OUT_AFPP();    //Set A6 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR1|=6<<4;     //Set pwm in mode 1	
			TIM3->CCMR1|=1<<3; 	   //preload mode enable
			TIM3->CCER|=1<<0;      //output mode enable 
		break;
		}
		case(2):{
			GPIOA_7_OUT_AFPP();	   //Set A7 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR1|=6<<12;    //Set pwm in mode 1	
			TIM3->CCMR1|=1<<11;    //preload mode enable
			TIM3->CCER|=1<<4;      //output mode enable  
		break;
		}
		case(3):{
	    GPIOB_0_OUT_AFPP();         //Set B0 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR2|=6<<4;      //Set pwm in mode 1	
			TIM3->CCMR2|=1<<3; 	 	//preload mode enable
			TIM3->CCER|=1<<8;   	//output mode enable  
		break;
		}
		case(4):{
			GPIOB_1_OUT_AFPP();	    //Set B1 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR2|=6<<12;  	//Set pwm in mode 1	
			TIM3->CCMR2|=1<<11; 	//preload mode enable
			TIM3->CCER|=1<<12;      //output mode enable  
		break;
		}
	}
}




void TIM4_ENA_CH(int ch){
	switch(ch){
		case(1):{
			GPIOB_6_OUT_AFPP();  //Set B6 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR1|=6<<4;   //Set pwm in mode 1	
			TIM4->CCMR1|=1<<3; 	 //preload mode enable
			TIM4->CCER|=1<<0;    //output mode enable 
		break;
		}
		case(2):{
			GPIOB_7_OUT_AFPP();	 //Set B7 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR1|=6<<12;  //Set pwm in mode 1	
			TIM4->CCMR1|=1<<11;  //preload mode enable
			TIM4->CCER|=1<<4;    //output mode enable  
		break;
		}
		case(3):{
	    GPIOB_8_OUT_AFPP();       //Set B8 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR2|=6<<4;    //Set pwm in mode 1	
			TIM4->CCMR2|=1<<3; 	  //preload mode enable
			TIM4->CCER|=1<<8;     //output mode enable  
		break;
		}
		case(4):{
			GPIOB_9_OUT_AFPP();	  //Set B9 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR2|=6<<12;   //Set pwm in mode 1	
			TIM4->CCMR2|=1<<11;   //preload mode enable
			TIM4->CCER|=1<<12;    //output mode enable  
		break;
		}
	}
}








