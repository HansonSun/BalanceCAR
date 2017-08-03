#include <stm32f10x.h>
#include "sys.h"
#include "gpio.h"
#include "timer.h"
#include "DataScope_DP.h"
#include "adc.h"
#include "daolibai.h"
#include "encoder.h"
#include "exti.h"

int main()
{
    /*SYS_CONFIG();
    JTAG_MODE_SET(JTAG_DISABLE_SWD_DISABLE);
    Usart1_init(72,115200);  //A9 A10
    daolibai_init();         //B12 B13 B1
    Encoder_Init_TIM2();     //A0 A1
    open_timer4_ms(1);
    while(1){
        DataScope(position,spinspeed);
        delay_ms(10);
    }*/
		SYS_CONFIG();
		GPIOD_CLK_EN
	  GPIOD_13_IN_UP();
		Usart1_init(72,115200);  //A9 A10
		exti_init_ft(GPIO_D,13);

		while(1){
		}
}


