#ifndef UART_H
#define UART_H

#include <stdint.h>


//AI MADE !!!!!!!!!!!!!!!!!

// Assuming your system frequency is defined somewhere (e.g., 20MHz). 
// Update this to match your actual crystal oscillator frequency!
#define _XTAL_FREQ 20000000  



// Initialization
void UART_Init(void);

// Transmission
void UART_Write_Char(char data);
void UART_Write_String(const char *text);

// Reception
char UART_Read_Char(void);
uint8_t UART_Data_Ready(void);

#endif /* UART_H */