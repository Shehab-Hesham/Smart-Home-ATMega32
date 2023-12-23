

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

//change the types

//include std types

//include bit math

#include "..\..\STD.h"

/*ADC Registers*/
#define ADMUX 				*((volatile uint8*)0x27)
#define ADMUX_MUX0 0
#define ADMUX_MUX1 1
#define ADMUX_MUX2 2
#define ADMUX_MUX3 3
#define ADMUX_MUX4 4
#define ADMUX_ADLAR 5
#define ADMUX_REFS0 6
#define ADMUX_REFS1 7

#define ADCSRA 				*((volatile uint8*)0x26)
#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2
#define ADCSRA_ADIE 3
#define ADCSRA_ADIF 4
#define ADCSRA_ADATE 5
#define ADCSRA_ADSC 6
#define ADCSRA_ADEN 7

#define ADCH 				*((volatile uint8*)0x25)
#define ADCL 				*((volatile uint8*)0x24)
#define ADCLH				*((volatile uint16*)0x24)//important

#define SFIOR				*((volatile uint8*)0x50)
#define SFIOR_PSR10 0
#define SFIOR_PSR2 1
#define SFIOR_PUD 2
#define SFIOR_ACME 3
#define SFIOR_ADTS0 5
#define SFIOR_ADTS1 6
#define SFIOR_ADTS2 7


#define ADC0 00000
#define ADC1 00001
#define ADC2 00010
#define ADC3 00011
#define ADC4 00100
#define ADC5 00101
#define ADC6 00110
#define ADC7 00111

void ADC_void_Init();

uint16 ADC_u16_read(uint8 ChannelNumber);

#endif /* ADC_ADC_INT_H_ */
