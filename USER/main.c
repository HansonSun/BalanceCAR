#include <stm32f10x.h>
#include "sys.h"
#include "gpio.h"
#include "timer.h"
#include "DataScope_DP.h"
#include "adc.h"
#include "daolibai.h"


int main()
{
    SYS_CONFIG();
 //   uart1_init(72,115200);
		daolibai_init();
   // JTAG_MODE_SET(JTAG_DISABLE_SWD_DISABLE);


		while(1){
			TIM3_4_SET_DUTY(0.2);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.4);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.6);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.8);
			delay_ms(1000);
		}
}

