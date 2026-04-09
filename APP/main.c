#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"


#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1  GPIO_PIN0
#define MOTOR_PIN2  GPIO_PIN2

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN1

//u8 USART_data = 0;
void Bluetooth_UART_Callback(u8 UART_data)
{
     
    LED_Init(GPIO_PORTB,GPIO_PIN0);


}

int main(void)
{

    while(1)
    {
        
    }

    return 0;
}
