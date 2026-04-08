#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include <stdint.h>

//AI MADE !!!!!!!!!!!!!!!!!


/* ==================================================================== */
/* =================== UART REGISTER DEFINITIONS ====================== */
/* ==================================================================== */
/* We cast the raw memory address to a volatile pointer, then dereference 
   it so we can assign values directly to the register name. */

// Bank 0 Registers
#define PIR1    *((volatile uint8_t*)0x0C)
#define RCSTA   *((volatile uint8_t*)0x18)
#define RCREG   *((volatile uint8_t*)0x1A)

// Bank 1 Registers
#define TRISC   *((volatile uint8_t*)0x87)
#define TXSTA   *((volatile uint8_t*)0x98)
#define SPBRG   *((volatile uint8_t*)0x99)


/* ==================================================================== */
/* ========================= BIT DEFINITIONS ========================== */
/* ==================================================================== */

// TXSTA Bits
#define TXSTA_TX9D  0
#define TXSTA_TRMT  1
#define TXSTA_BRGH  2
#define TXSTA_SYNC  4
#define TXSTA_TXEN  5
#define TXSTA_TX9   6
#define TXSTA_CSRC  7

// RCSTA Bits
#define RCSTA_RX9D  0
#define RCSTA_OERR  1
#define RCSTA_FERR  2
#define RCSTA_ADDEN 3
#define RCSTA_CREN  4
#define RCSTA_SREN  5
#define RCSTA_RX9   6
#define RCSTA_SPEN  7

// PIR1 Bits
#define PIR1_TXIF   4
#define PIR1_RCIF   5

// TRISC Bits
#define TRISC_TRISC6 6 // TX Pin
#define TRISC_TRISC7 7 // RX Pin


#define TXREG   *((volatile uint8_t*)0x19)

#endif /* UART_PRIVATE_H */