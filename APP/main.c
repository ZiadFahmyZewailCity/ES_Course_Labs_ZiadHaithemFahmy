#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/INT/INT_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"

#include "STD_TYPES.h"
#include "UTIL.h"


//Week 2 Timer_based blinking LED
void setup()
{
    //Setting Up individual pins
    GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN4,GPIO_INPUT);
    //Enables interrupts 
    TIMR_INTR_ENABLE();
    EXT_INTO_Init();
    EXT_INTO_Enable();
    //Initalize timer
    timer_0_intialize(); 
}

void main()
{
    setup();

    //Changes these to the necssary values for timers
    float next_trigger_led1 = 2.5; 
    //u32 next_trigger_led2 = 2; 
    while(1)
    {
        float currentTime = time_timer_0_elapsed();
        
        if (currentTime >= next_trigger_led1)
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
            next_trigger_led1 = currentTime + 2; 
        }
    }
}
