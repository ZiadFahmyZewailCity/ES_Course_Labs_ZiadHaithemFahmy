#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/INT/INT_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"

#include "STD_TYPES.h"
#include "UTIL.h"


//Week 2 Timer_based blinking LED 
/*
void toggle_LED_1(void)
{
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(1);
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(1);
}
void toggle_LED_2(void)
{
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(2);
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(2);
}

void setup()
{
    //Intializes used port pins intial states
    GPIO_Init();
    //Enables interrupts 
    TIMR_INTR_ENABLE();
    //Initalize timer
    timer_intialize(); 
}

void main()
{
    setup();
    while(1)
    {
        toggle_LED_1();
        toggle_LED_2();

    }
}
*/

//Motor control task (week2)
volatile u8 button_pressed_flag = 0;

void Change_Motor_Speed_ISR(void)
{
    button_pressed_flag = 1;
}

void setup()
{
    MOTOR_Init();
    EXT_INTO_SetCallback(Change_Motor_Speed_ISR);
    EXT_INTO_Enable();
    EXT_INTO_Init();
    
}

void main()
{
    setup(); 
    
    u8 speed_state = 0; 
    
    while(1)
    {
        if (button_pressed_flag == 1)
        {
            speed_state++;
            if (speed_state > 3)
            {
                speed_state = 0;
            }

            switch (speed_state)
            {
                case 0: SET_MOTOR_dutyCycle(25); break;
                case 1: SET_MOTOR_dutyCycle(50); break;
                case 2: SET_MOTOR_dutyCycle(75); break;
                case 3: SET_MOTOR_dutyCycle(100); break;
            }
                button_pressed_flag = 0;
        }
    }
}


