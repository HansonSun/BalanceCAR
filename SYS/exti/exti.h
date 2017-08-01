
#ifndef   __EXTI_H
#define   __EXTI_H

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
#endif
