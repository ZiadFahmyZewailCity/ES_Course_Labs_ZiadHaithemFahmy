#ifndef UART_CONFIG_H
#define UART_CONFIG_H

//AI MADE !!!!!!!!!!!!!!!!!



/* Set your system oscillator frequency here (e.g., 20MHz) */
#define UART_SYSTEM_CLOCK_FREQ    20000000UL 

/* Set your desired baud rate */
#define UART_BAUD_RATE            9600

/* Configuration Options:
   Options for UART_SPEED_MODE:
   1. UART_HIGH_SPEED (BRGH = 1)
   2. UART_LOW_SPEED  (BRGH = 0)
*/
#define UART_SPEED_MODE           UART_HIGH_SPEED

#define UART_HIGH_SPEED           1
#define UART_LOW_SPEED            0

#endif /* UART_CONFIG_H */