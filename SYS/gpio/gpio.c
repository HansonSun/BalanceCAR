#include "gpio.h"


void GPIO_Config(u8 Pin_Group,u8 Pin_Num,u8 Pin_Mode )
{
    RCC->APB2ENR|=1<<Pin_Group;  //enable the gpio clk
    switch(Pin_Group){
        case(_PORTA_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOA->CRL&=mask;
                GPIOA->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {        
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOA->CRH&=mask;
                GPIOA->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }

        case(_PORTB_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOB->CRL&=mask;
                GPIOB->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOB->CRH&=mask;
                GPIOB->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }
        case(_PORTC_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOC->CRL&=mask;
                GPIOC->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOC->CRH&=mask;
                GPIOC->CRH|=Pin_Mode<<(move_num*4);
            }
        break;
        }
        case(_PORTD_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOD->CRL&=mask;
                GPIOD->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOD->CRH&=mask;
                GPIOD->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }
        case(_PORTE_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOE->CRL&=mask;
                GPIOE->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOE->CRH&=mask;
                GPIOE->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }
        case(_PORTF_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOF->CRL&=mask;
                GPIOF->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOF->CRH&=mask;
                GPIOF->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }
        case(_PORTG_):{
            if(Pin_Num<=7){
                unsigned int mask=~(0xF<<(4*Pin_Num));
                GPIOG->CRL&=mask;
                GPIOG->CRL|=Pin_Mode<<(Pin_Num*4);
            }
            else {
                unsigned char move_num=(Pin_Num%8);
                unsigned int mask=~(0xF<<(4*move_num));
                GPIOG->CRH&=mask;
                GPIOG->CRH|=Pin_Mode<<(move_num*4);
            }
            break;
        }
    }
}



void JTAG_MODE_SET(u8 mode)
{
    RCC->APB2ENR|=1<<0;       //turn on the AFIO CLK 
    AFIO->MAPR&=0XF8FFFFFF;   //clear MAPR[26:24]
    AFIO->MAPR|=(mode<<24);   //set JTAG MODE
} 
