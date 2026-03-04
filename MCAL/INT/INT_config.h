#ifndef INT_CONFIG_H
#define INT_CONFIG_H

#include "STD_TYPES.h"

//Port used for interupt
#define INT_PORT  GPIO_PORTB 
#define INT_PIN GPIO_PIN0


//This should all choice of which edge to trigger interrupt on through changing the INT_EDGE_CONTROL macro, Should satisfy bonus task ? 
#define RISINGEDGE 1
#define FALINGEDGE 0
#define INT_EDGE_CONTROL RISINGEDGE

#endif