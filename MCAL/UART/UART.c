// 1. Include the standard types you are using
#include <stdint.h>

//AI MADE !!!!!!!!!!!!!!!!!!!!!!!!!!


// 2. Include your custom UART files
#include "UART_interface.h" // Your function prototypes (Init, Write, Read)
#include "UART_private.h"   // The registers we just defined above
#include "UART_config.h"    // The baud rate and clock settings

void UART_Init(void) {
    // Change from uint16_t to uint8_t
    uint8_t spbrg_value; 

    #if UART_SPEED_MODE == UART_HIGH_SPEED
        // Set BRGH bit to 1
        TXSTA |= (1 << TXSTA_BRGH);
        // Calculate SPBRG for High Speed and cast to uint8_t
        spbrg_value = (uint8_t)((UART_SYSTEM_CLOCK_FREQ / (16UL * UART_BAUD_RATE)) - 1);
    #else
        // Clear BRGH bit to 0
        TXSTA &= ~(1 << TXSTA_BRGH);
        // Calculate SPBRG for Low Speed and cast to uint8_t
        spbrg_value = (uint8_t)((UART_SYSTEM_CLOCK_FREQ / (64UL * UART_BAUD_RATE)) - 1);
    #endif
    
    SPBRG = spbrg_value; 

    // Enable Asynchronous mode (SYNC = 0)
    TXSTA &= ~(1 << TXSTA_SYNC);
    
    // Enable Serial Port (SPEN = 1)
    RCSTA |= (1 << RCSTA_SPEN);
    
    // Enable transmission (TXEN = 1)
    TXSTA |= (1 << TXSTA_TXEN);

    // Enable continuous reception (CREN = 1)
    RCSTA |= (1 << RCSTA_CREN);

    // Set RX (RC7) as input, TX (RC6) as output
    TRISC |= (1 << TRISC_TRISC7);  // Input
    TRISC &= ~(1 << TRISC_TRISC6); // Output
}

void UART_Write_Char(char data) {
    // Wait until the Transmit Shift Register is empty (TRMT bit goes to 1)
    while (!(TXSTA & (1 << TXSTA_TRMT)));
    
    // Load data into the transmit register to start transmission
    TXREG = data; 
}

void UART_Write_String(const char *text) {
    // Loop through the string array until the null terminator '\0' is reached
    while (*text != '\0') {
        UART_Write_Char(*text);
        text++;
    }
}

uint8_t UART_Data_Ready(void) {
    // Check the Receive Interrupt Flag (RCIF). 
    // Returns 1 if unread data is in the receive buffer, 0 if empty.
    if (PIR1 & (1 << PIR1_RCIF)) {
        return 1;
    } else {
        return 0;
    }
}

char UART_Read_Char(void) {
    // Wait until data is received (RCIF bit goes to 1)
    // Warning: This is a blocking function and will halt code execution 
    // until a character arrives!
    while (!(PIR1 & (1 << PIR1_RCIF)));
    
    // Check for Overrun Error (OERR bit is 1)
    if (RCSTA & (1 << RCSTA_OERR)) {
        // Clear the error by toggling Continuous Receive Enable (CREN)
        RCSTA &= ~(1 << RCSTA_CREN); // Turn off
        RCSTA |= (1 << RCSTA_CREN);  // Turn back on
    }
    
    // Read and return the received data from the buffer
    return RCREG; 
}