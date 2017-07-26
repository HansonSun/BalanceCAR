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
    Uart1_init(72,115200);
		//daolibai_init();
   // JTAG_MODE_SET(JTAG_DISABLE_SWD_DISABLE);


		/*while(1){
			TIM3_4_SET_DUTY(0.2);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.4);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.6);
			delay_ms(1000);
			TIM3_4_SET_DUTY(0.8);
			delay_ms(1000);
		}*/
    
  //  TIM1_PWM_INIT(899,0);
    //TIM1_ENA_CH(1);
   // TIM1_1_SET_CCR(400);
   //    TIM1_1_SET_DUTY(1,50);
   // TIM1_SET_FREQ(1,1000);
	 Encoder_Init_TIM2( );
    while(1)
		{
			delay_ms(500);
			newprintf(1,"%d\n",TIM2->CNT);
		}
}


