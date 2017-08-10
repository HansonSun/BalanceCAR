//嵌入式家园stm32串口通信代码库函数版1.0版本 希望同学们可以多多修改，是程序更加完善。
//作者 孙浩 2013.4.1
/*
USART1   TX:PA9  RX:PA10
USART2	 TX:PA2  RX:PA3
USART3	 TX:PB10  RX:PB11
UART4	 TX:PC10  RX:C11
UART5	 TX:PC12  RX:PD2
*/
#ifndef   __USART_H
#define   __USART_H

#include<stm32f10x.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h> 
#include "sys.h"


void Uprintf(int uart_num,char* fmt, ...);
void print_ch(int uart_num,char ch);
void print_int(int uart_num,int dec);
void print_float(int uart_num,double flt);
void print_bin(int uart_num,int bin);
void print_hex(int uart_num,unsigned int hex); 
void print_str(int uart_num,char* str); 

void Usart1_init(u32 pclk2,u32 bound);
void Usart2_init(u32 pclk2,u32 bound);
void Usart3_init(u32 pclk2,u32 bound);
void Uart4_init(u32 pclk2,u32 bound);
void Uart5_init(u32 pclk2,u32 bound);

void usart_MYDMA_Config(  u32 cpar,u32 cmar,u16 cndtr);
void usart_MYDMA_Enable(  );

#endif
