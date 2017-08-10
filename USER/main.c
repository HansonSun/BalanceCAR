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
    //JTAG_MODE_SET(JTAG_DISABLE_SWD_DISABLE);
    Usart1_init(72,115200);  //A9 A10
    daolibai_init();         //B12 B13 B1
    Encoder_Init_TIM2();     //A0 A1
    Tim4_timing_set_ms(1);
    while(1){
        DataScope(position,spinspeed);
        delay_ms(10);
    }*/
	SYS_CONFIG();
	Usart1_init(72,115200);  //A9 A10 

	Adc_DMA_MultiChannel_Config( );
		Adc1_Multichannel_repeat(3,0,1,2);
	while(1){
				Uprintf(1,"adc1:%x\n",ADC1MultiConverted[0]);
		Uprintf(1,"adc2:%x\n",ADC1MultiConverted[1]);
		Uprintf(1,"adc3:%x\n",ADC1MultiConverted[2]);
			delay_ms(1000);
	}
}


