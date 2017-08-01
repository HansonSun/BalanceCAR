#include <stm32f10x.h>
#include "timer.h"
#include "delay_ms.h"

void EXTI0_IRQHandler(void ){
    delay_ms(10);  //anti-shake

    EXTI->PR=1<<0;

}

void EXTI1_IRQHandler(void){

}  

void EXTI2_IRQHandler(void ){

}

void EXTI3_IRQHandler(void){

}

void EXTI4_IRQHandler(void){


}

void EXTI9_5_IRQHandler(void){

}

void EXTI15_10_IRQHandler(void){

}
