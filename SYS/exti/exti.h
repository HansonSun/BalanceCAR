
#ifndef   __EXTI_H
#define   __EXTI_H

#include<stm32f10x.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h> 
#include "sys.h"


void exti_init_ft(u8 GPIOx,u8 BITx) ;
void exti_init_rt(u8 GPIOx,u8 BITx) ;


#endif
