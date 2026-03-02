/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "LED_interface.h"
#include "INT_interface.h"
#include "STD_TYPES.h"

void toggle_LED(void)
{
    LED_Toggle(GPIO_PORTC,GPIO_PIN0);
}

void setup()
{
    GPIO_Init();
    EXT_INTO_Init();
    EXT_INTO_SetEdge(1);
    EXT_INTO_SetCallback(toggle_LED);
    EXT_INTO_Enable(); 
    SWITCH_Init(0);


}

void main()
{
    setup();
    while(1)
    {

    }
}