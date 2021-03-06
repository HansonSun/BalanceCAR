//Timer1 CH1:PA8  CH2:PA9  CH3:PA10 CH4:PA11
//Timer2 CH1:PA0  CH2:PA1  CH3:PA2  CH4:PA3
//Timer3 CH1:PA6  CH2:PA7  CH3:PB0  CH4:PB1
//Timer4 CH1:PB6  CH2:PB7  CH3:PB8  CH4:PB9


#include"pwm.h"


void Tim1_pwm_init(u16 arr,u16 psc){
    RCC->APB2ENR|=1<<11;  //Enable The Timer1 CLK
    TIM1->ARR=arr;		    //SET Timer1 ARR
    TIM1->PSC=psc;		    //SET Timer1 PSC	
    TIM1->BDTR|=1<<15;    //set break and dead-time register (timer1 and timer8 only)
    TIM1->CR1=0x0080;     //enable the reload buffer
    TIM1->CR1|=0x01;      //enable the counter 
}
void Tim2_pwm_init(u16 arr,u16 psc){		 					 
	  RCC->APB1ENR|=1<<0;    //Enable The Timer2 clk
	  TIM2->ARR=arr;		     //SET Timer2 ARR
	  TIM2->PSC=psc;		     //SET Timer2 PSC	
	  TIM2->CR1=0x0080;      //enable the reload buffer
	  TIM2->CR1|=0x01;       //enable the counter    											  
} 

void Tim3_pwm_init(u16 arr,u16 psc){		 					 
	 RCC->APB1ENR|=1<<1;     //Enable The Timer3 clk
	 TIM3->ARR=arr;			     //SET Timer3 ARR
	 TIM3->PSC=psc;			     //SET Timer3 PSC
	 TIM3->CR1=0x0080;   	   //enable the reload buffer
	 TIM3->CR1|=0x01;        //enable the counter    											  
} 

void Tim4_pwm_init(u16 arr,u16 psc){		 					 
	 RCC->APB1ENR|=1<<2;     //Enable The Timer4 clk
	 TIM4->ARR=arr;			     //SET Timer4 ARR
	 TIM4->PSC=psc;			     //SET Timer4 PSC
	 TIM4->CR1=0x0080;   	   //enable the reload buffer
	 TIM4->CR1|=0x01;  		   //enable the counter    											  
} 



void Tim1_pwm_set_ms(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	 u16 psc=0;
   u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
     
    Tim1_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM1_ENA_CH(1);
		TIM1_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM1_ENA_CH(2);
		TIM1_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM1_ENA_CH(3);
		TIM1_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM1_ENA_CH(4);
		TIM1_4_SET_CCR(arr*duty);
	}
}

void Tim2_pwm_set_ms(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 psc=0;
    u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
     
    Tim2_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM2_ENA_CH(1);
		TIM2_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM2_ENA_CH(2);
		TIM2_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM2_ENA_CH(3);
		TIM2_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM2_ENA_CH(4);
		TIM2_4_SET_CCR(arr*duty);
	}
}

void Tim3_pwm_set_ms(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 psc=0;
    u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
     
    Tim3_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM3_ENA_CH(1);
		TIM3_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM3_ENA_CH(2);
		TIM3_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM3_ENA_CH(3);
		TIM3_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM3_ENA_CH(4);
		TIM3_4_SET_CCR(arr*duty);
	}
}

void Tim4_pwm_set_ms(float time_ms,float duty,u8 ch1,u8 ch2 ,u8 ch3,u8 ch4){
	u16 psc=0;
    u16 arr=0;	
    
    if(time_ms>=100){
        psc=1999;
        arr=36*time_ms;
    }
    else if(time_ms>=10){
        psc=119;
        arr=600*time_ms;
    }
    else if(time_ms>=0.909){
        psc=11;
        arr=6000*time_ms;
    }
    else{
        psc=0;
        arr=72000*time_ms;
    }
     
    Tim4_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM4_ENA_CH(1);
		TIM4_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM4_ENA_CH(2);
		TIM4_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM4_ENA_CH(3);
		TIM4_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM4_ENA_CH(4);
		TIM4_4_SET_CCR(arr*duty);
	}
}


void Tim1_pwm_set_hz(u32 freqhz,float duty,u8 ch1,u8 ch2,u8 ch3,u8 ch4){
    u16 psc=0;
    u16 arr=0;	
    
    if(freqhz<=10){
        psc=1999;
        arr=36000/freqhz;
    }
    else if(freqhz<=100){
        psc=119;
        arr=600000/freqhz;
    }
    else if(freqhz<=1100){
        psc=11;
        arr=6000000/freqhz;
    }
    else{
        psc=0;
        arr=72000000/freqhz;
    }
     
    Tim1_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM1_ENA_CH(1);
		TIM1_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM1_ENA_CH(2);
		TIM1_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM1_ENA_CH(3);
		TIM1_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM1_ENA_CH(4);
		TIM1_4_SET_CCR(arr*duty);
	}
}

void Tim2_pwm_set_hz(u32 freqhz,float duty,u8 ch1,u8 ch2,u8 ch3,u8 ch4){
    u16 psc=0;
    u16 arr=0;	
    
    if(freqhz<=10){
        psc=1999;
        arr=36000/freqhz;
    }
    else if(freqhz<=100){
        psc=119;
        arr=600000/freqhz;
    }
    else if(freqhz<=1100){
        psc=11;
        arr=6000000/freqhz;
    }
    else{
        psc=0;
        arr=72000000/freqhz;
    }
     
    Tim2_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM2_ENA_CH(1);
		TIM2_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM2_ENA_CH(2);
		TIM2_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM2_ENA_CH(3);
		TIM2_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM2_ENA_CH(4);
		TIM2_4_SET_CCR(arr*duty);
	}
}


void Tim3_pwm_set_hz(u32 freqhz,float duty,u8 ch1,u8 ch2,u8 ch3,u8 ch4){
    u16 psc=0;
    u16 arr=0;	
    
    if(freqhz<=10){
        psc=1999;
        arr=36000/freqhz;
    }
    else if(freqhz<=100){
        psc=119;
        arr=600000/freqhz;
    }
    else if(freqhz<=1100){
        psc=11;
        arr=6000000/freqhz;
    }
    else{
        psc=0;
        arr=72000000/freqhz;
    }
     
    Tim3_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM3_ENA_CH(1);
		TIM3_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM3_ENA_CH(2);
		TIM3_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM3_ENA_CH(3);
		TIM3_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM3_ENA_CH(4);
		TIM3_4_SET_CCR(arr*duty);
	}
}


void Tim4_pwm_set_hz(u32 freqhz,float duty,u8 ch1,u8 ch2,u8 ch3,u8 ch4){
    u16 psc=0;
    u16 arr=0;	
    
    if(freqhz<=10){
        psc=1999;
        arr=36000/freqhz;
    }
    else if(freqhz<=100){
        psc=119;
        arr=600000/freqhz;
    }
    else if(freqhz<=1100){
        psc=11;
        arr=6000000/freqhz;
    }
    else{
        psc=0;
        arr=72000000/freqhz;
    }
     
    Tim4_pwm_init(arr-1,psc);
	if(ch1==1){
		TIM4_ENA_CH(1);
		TIM4_1_SET_CCR(arr*duty);
	}
	if(ch2==1){
		TIM4_ENA_CH(2);
		TIM4_2_SET_CCR(arr*duty);
	}
	if(ch3==1){
		TIM4_ENA_CH(3);
		TIM4_3_SET_CCR(arr*duty);
	}
	if(ch4==1){
		TIM4_ENA_CH(4);
		TIM4_4_SET_CCR(arr*duty);
	}
}



void TIM1_ENA_CH(int ch){
	switch(ch){
		case(1):{
			GPIOA_CLK_EN
			GPIOA_8_OUT_AFPP();      //Set A8 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR1|=6<<4;  	 //Set pwm in mode 2	
			TIM1->CCMR1|=1<<3; 	 	 //preload mode enable
			TIM1->CCER|=1<<0;   	 //output mode enable 
		break;
		}
		case(2):{
			GPIOA_CLK_EN
			GPIOA_9_OUT_AFPP();	     //Set A9 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR1|=6<<12;  	 //Set pwm in mode 2	
			TIM1->CCMR1|=1<<11; 	 //preload mode enable
			TIM1->CCER|=1<<4;   	 //output mode enable  
		break;
		}
		case(3):{
			GPIOA_CLK_EN
            GPIOA_10_OUT_AFPP();    //Set A10 speed:50Mhz mode:Alternate function output Push-pull
			TIM1->CCMR2|=6<<4;  	//Set pwm in mode 2	
			TIM1->CCMR2|=1<<3; 	 	//preload mode enable
			TIM1->CCER|=1<<8;       //output mode enable  
		break;
		}
		case(4):{
			GPIOA_CLK_EN
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
            GPIOA_CLK_EN
			GPIOA_0_OUT_AFPP();     //Set A0 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR1|=6<<4;  	//Set pwm in mode 1
			TIM2->CCMR1|=1<<3; 	 	//preload mode enable
			TIM2->CCER|=1<<0;   	//output mode enable 
		break;
		}
		case(2):{
            GPIOA_CLK_EN
			GPIOA_1_OUT_AFPP();	    //Set A1 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR1|=6<<12;  	//Set pwm in mode 1	
			TIM2->CCMR1|=1<<11; 	//preload mode enable
			TIM2->CCER|=1<<4;   	//output mode enable  
		break;
		}
		case(3):{
            GPIOA_CLK_EN
            GPIOA_2_OUT_AFPP();     //Set A2 speed:50Mhz mode:Alternate function output Push-pull
			TIM2->CCMR2|=6<<4;  	//Set pwm in mode 1
			TIM2->CCMR2|=1<<3; 	 	//preload mode enable
			TIM2->CCER|=1<<8;       //output mode enable  
		break;
		}
		case(4):{
            GPIOA_CLK_EN
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
            GPIOA_CLK_EN
			GPIOA_6_OUT_AFPP();    //Set A6 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR1|=6<<4;     //Set pwm in mode 1	
			TIM3->CCMR1|=1<<3; 	   //preload mode enable
			TIM3->CCER|=1<<0;      //output mode enable 
		break;
		}
		case(2):{
            GPIOA_CLK_EN
			GPIOA_7_OUT_AFPP();	   //Set A7 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR1|=6<<12;    //Set pwm in mode 1	
			TIM3->CCMR1|=1<<11;    //preload mode enable
			TIM3->CCER|=1<<4;      //output mode enable  
		break;
		}
		case(3):{
            GPIOB_CLK_EN
            GPIOB_0_OUT_AFPP();     //Set B0 speed:50Mhz mode:Alternate function output Push-pull
			TIM3->CCMR2|=6<<4;      //Set pwm in mode 1	
			TIM3->CCMR2|=1<<3; 	 	//preload mode enable
			TIM3->CCER|=1<<8;   	//output mode enable  
		break;
		}
		case(4):{
            GPIOB_CLK_EN
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
            GPIOB_CLK_EN
			GPIOB_6_OUT_AFPP();  //Set B6 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR1|=6<<4;   //Set pwm in mode 1	
			TIM4->CCMR1|=1<<3; 	 //preload mode enable
			TIM4->CCER|=1<<0;    //output mode enable 
		break;
		}
		case(2):{
            GPIOB_CLK_EN
			GPIOB_7_OUT_AFPP();	 //Set B7 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR1|=6<<12;  //Set pwm in mode 1	
			TIM4->CCMR1|=1<<11;  //preload mode enable
			TIM4->CCER|=1<<4;    //output mode enable  
		break;
		}
		case(3):{
            GPIOB_CLK_EN
            GPIOB_8_OUT_AFPP();       //Set B8 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR2|=6<<4;    //Set pwm in mode 1	
			TIM4->CCMR2|=1<<3; 	  //preload mode enable
			TIM4->CCER|=1<<8;     //output mode enable  
		break;
		}
		case(4):{
            GPIOB_CLK_EN
			GPIOB_9_OUT_AFPP();	  //Set B9 speed:50Mhz mode:Alternate function output Push-pull
			TIM4->CCMR2|=6<<12;   //Set pwm in mode 1	
			TIM4->CCMR2|=1<<11;   //preload mode enable
			TIM4->CCER|=1<<12;    //output mode enable  
		break;
		}
	}
}






