#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "../MCAL/PWM/PWM_interface.h"

#include "MOTOR_config.h"
#include "MOTOR_private.h"
#include "MOTOR_interface.h"


#include "STD_TYPES.h"

void MOTOR_Init(void)
{
    //This was a recomendation from that AI to keep the pin input until the intialziation process is done, i liked the idea so i used ti
    GPIO_SetPinDirection(PWM_PORT, PWM_PIN, GPIO_INPUT);
    
    PWM_initi();    
    PWM_setFrequency(DEFAULT_MOTOR_FREQ); 
    PWM_setDutyCycle(DEFAULT_DUTY_CYCLE);
    
    GPIO_SetPinDirection(PWM_PORT, PWM_PIN, GPIO_OUTPUT);
}

void SET_MOTOR_frequency(u8 desired_freq)
{
    PWM_setFrequency(desired_freq);
}
void SET_MOTOR_dutyCycle(u8 desired_dutyCycle)
{
    PWM_setDutyCycle(desired_dutyCycle);
}