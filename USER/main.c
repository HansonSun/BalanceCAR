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

    //TIM1_PWM_INIT(799,0);
    ///TIM1_ENA_CH(1);
    ///TIM1_1_SET_CCR(400);
    
    TIM1_PWM_INIT_MS(0.23,0.5,1,1,1,1);
    
    while(1);
}


