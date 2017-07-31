//---------------------STM32F103x8--STM32F103xB----------------------------------------------//
//USART1     TX:PA9   RX:PA10
//USART2     TX:PA2   RX:PA3
//USART3     TX:PB10  RX:PB11
//---------------------STM32F103xC--STM32F103xD--STM32F103xE-----------------------------------------//
//UART4      TX:PC10  RX:C11
//UART5      TX:PC12  RX:PD2

#include "usart.h"
#include "gpio.h"

void print_ch(int uart_num,char ch){
    switch(uart_num){
        case (1):{
            while((USART1->SR&0X40)==0);
            USART1->DR = (u8) ch;  
            break;
        }
        case(2):{
            while((USART2->SR&0X40)==0);
            USART2->DR = (u8) ch;  
            break;
        } 
        case(3):{
            while((USART3->SR&0X40)==0);
            USART3->DR = (u8) ch;  
            break;
        }
        case(4):{
            while((UART4->SR&0X40)==0);
            UART4->DR = (u8) ch;  
            break;
        }
        case(5):{
            while((UART5->SR&0X40)==0);
            UART5->DR = (u8) ch;  
            break;
        }                        
    }
}

void print_int(int uart_num,int dec){
    if(dec==0){
        return;
    }
    print_int(uart_num,dec/10);
    print_ch(uart_num, (char)(dec%10 + '0'));
}



void print_str(int uart_num,char* str){
    while(*str){
        print_ch(uart_num,*str++);
    }
}



void print_hex(int uart_num,unsigned int hex){
    if(hex==0){
        print_str(uart_num,"0x");
        return;
    }
    print_hex(uart_num,hex/16);
    if(hex%16 < 10){
        print_ch(uart_num,(char)(hex%16 + '0'));
    }
    else{
         print_ch(uart_num,(char)(hex%16 -10+ 'a' ));
				//print_int(uart_num,(char)(hex%16 ));
    }
}


void print_float(int uart_num,double flt){
    int tmpint = 0;
    tmpint = (int)flt;
    print_int(uart_num,tmpint);
    print_ch(uart_num,'.');
    flt = flt - tmpint;
    tmpint = (int)(flt * 1000000);
    print_int(uart_num,tmpint);
}

void print_bin(int uart_num,int bin)
{
    if(bin == 0)
    {
        print_str(uart_num,"0b");
        return;
    }
    print_bin(uart_num,bin/2);
    print_ch(uart_num, (char)(bin%2 + '0'));
}



void Uprintf(int uart_num,char* fmt, ...){
    double vargflt = 0;
    int  vargint = 0;
    char* vargpch = NULL;
    char vargch = 0;
    char* pfmt = NULL;
    va_list vp;
    va_start(vp, fmt);
    pfmt = fmt;
    while(*pfmt){
        if(*pfmt == '%'){
            switch(*(++pfmt)){
                case 'c':
                    vargch = va_arg(vp, int); 
                    print_ch(uart_num,vargch);
                    break;
                case 'd':
                    vargint = va_arg(vp, int);
                    print_int(uart_num,vargint);
                    break;
                case 'f':
                    vargflt = va_arg(vp, double);
                    print_float(uart_num,vargflt);
                    break;
                case 's':
                    vargpch = va_arg(vp, char*);
                    print_str(uart_num,vargpch);
                    break;
                case 'b':
                case 'B':
                    vargint = va_arg(vp, int);
                    print_bin(uart_num,vargint);
                    break;
                case 'x':
                case 'X':
                    vargint = va_arg(vp, int);
                    print_hex(uart_num,vargint);
                    break;
                case '%':
                    print_ch(uart_num,'%');
                    break;
                default:
                    break;
            }
            pfmt++;
        }
        else
        {
            print_ch(uart_num,*pfmt++);
        }
    }
    va_end(vp);
}






void Usart1_init(u32 pclk2,u32 bound){
    float temp;
    u16 mantissa;
    u16 fraction;   
    temp=(float)(pclk2*1000000)/(bound*16);
    mantissa=temp;
    fraction=(temp-mantissa)*16;  
    mantissa<<=4;
    mantissa+=fraction; 
    RCC->APB2ENR|=1<<2;     //enable the gpioa clk
    RCC->APB2ENR|=1<<14;    //enable usart1 clk
    GPIOA_9_OUT_AFPP();
    GPIOA_10_IN_UP();
    RCC->APB2RSTR|=1<<14;   
    RCC->APB2RSTR&=~(1<<14);  //reset the usart1
    USART1->BRR=mantissa;
    USART1->CR1|=0X200C;   // 1 Start bit, 8 Data bits, n Stop bit
    USART1->CR1|=1<<5;//enable the usart 1 recv interupt
}


void Usart2_init(u32 pclk2,u32 bound){
    float temp;
    u16 mantissa;
    u16 fraction;   
    temp=(float)(pclk2*1000000)/(bound*16);
    mantissa=temp;
    fraction=(temp-mantissa)*16;  
    mantissa<<=4;
    mantissa+=fraction; 

    RCC->APB2ENR|=1<<2;     //enable the gpioa clk
    RCC->APB2ENR|=1<<17;    //enable usart1 clk
    GPIOA_2_OUT_AFPP();     //set A2 OUT_AFPP
    GPIOA_3_IN_UP();       //set A3 IN_UP
    RCC->APB1RSTR|=1<<17;   
    RCC->APB1RSTR&=~(1<<17);  //reset the usart1
    
    USART2->BRR=mantissa;
    USART2->CR1|=0X200C;   // 1 Start bit, 8 Data bits, n Stop bit
    USART2->CR1|=1<<5;//enable the usart 1 recv interupt
}


void Usart3_init(u32 pclk2,u32 bound){
    float temp;
    u16 mantissa;
    u16 fraction;   
    temp=(float)(pclk2*1000000)/(bound*16);
    mantissa=temp;
    fraction=(temp-mantissa)*16;  
    mantissa<<=4;
    mantissa+=fraction; 

    RCC->APB2ENR|=1<<3;     //enable the gpiob clk
    RCC->APB2ENR|=1<<18;    //enable usart1 clk
    GPIOB_10_OUT_AFPP();   //set B10 AFPP
    GPIOB_11_IN_UP();      //set B11 IN_UP
    RCC->APB2RSTR|=1<<18;   
    RCC->APB2RSTR&=~(1<<18);  //reset the usart1
    USART3->BRR=mantissa;
    USART3->CR1|=0X200C;   // 1 Start bit, 8 Data bits, n Stop bit
    USART3->CR1|=1<<5;//enable the usart 1 recv interupt
}


void Uart4_init(u32 pclk2,u32 bound){
    float temp;
    u16 mantissa;
    u16 fraction;   
    temp=(float)(pclk2*1000000)/(bound*16);
    mantissa=temp;
    fraction=(temp-mantissa)*16;  
    mantissa<<=4;
    mantissa+=fraction; 
    
    GPIOC_CLK_EN    //enable the gpioa clk

    RCC->APB2ENR|=1<<19;    //enable usart1 clk
    GPIOC_10_OUT_AFPP();
    GPIOC_11_IN_UP();
    RCC->APB2RSTR|=1<<19;   
    RCC->APB2RSTR&=~(1<<19);  //reset the usart1
    UART4->BRR=mantissa;
    UART4->CR1|=0X200C;   // 1 Start bit, 8 Data bits, n Stop bit
    UART4->CR1|=1<<5;//enable the usart 1 recv interupt
}


void Uart5_init(u32 pclk2,u32 bound){
    float temp;
    u16 mantissa;
    u16 fraction;   
    temp=(float)(pclk2*1000000)/(bound*16);
    mantissa=temp;
    fraction=(temp-mantissa)*16;  
    mantissa<<=4;
    mantissa+=fraction; 
    
    GPIOC_CLK_EN
    GPIOD_CLK_EN

    RCC->APB1ENR|=1<<20;    //enable uart5 clk
    GPIOC_12_OUT_AFPP();      //set C12 AFPP
    GPIOD_2_IN_UP();       //set D2 IN_UP
    RCC->APB1RSTR|=1<<20;   
    RCC->APB1RSTR&=~(1<<20);  //reset the usart1
    UART5->BRR=mantissa;
    UART5->CR1|=0X200C;   // 1 Start bit, 8 Data bits, n Stop bit
    UART5->CR1|=1<<5;//enable the usart 1 recv interupt
}










