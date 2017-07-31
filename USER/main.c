#include <stm32f10x.h>
#include "sys.h"
#include "gpio.h"
#include "timer.h"
#include "DataScope_DP.h"
#include "adc.h"
#include "daolibai.h"
#include "encoder.h"


int main()
{
    SYS_CONFIG();
	  JTAG_MODE_SET(JTAG_DISABLE_SWD_DISABLE);
		Usart1_init(72,115200); //A9 A10
    daolibai_init(); //B12  B13 B1
		Encoder_Init_TIM2(); //A0 A1
		open_timer4_ms(10);
		//set_speed(500);
    while(1){
			DataScope(position);
			delay_ms(10);
		}
}


