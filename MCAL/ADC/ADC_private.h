#ifndef ADC_PRIV_H
#define ADC_PRIV_H


#define ADRESH (*((volatile u8*)0x1E))
#define ADRESL (*((volatile u8*)0x9E))
#define ADCON0 (*((volatile u8*)0x1F))
#define ADCON1 (*((volatile u8*)0x9F))


#endif