
#include "ADC_INIT.h"
#include "../../BITMATH.h"
#include "..\..\STD.h"
void ADC_void_Init()
{
	SET_BIT(ADMUX, ADMUX_REFS0) ;
	CLEAR_BIT(ADMUX, ADMUX_REFS1) ;
	
	SET_BIT(ADCSRA, ADCSRA_ADEN) ;

	CLEAR_BIT(ADCSRA, ADCSRA_ADATE) ;
	CLEAR_BIT(ADCSRA, ADCSRA_ADIE) ;
	SET_BIT(ADCSRA, ADCSRA_ADPS2) ;
	SET_BIT(ADCSRA, ADCSRA_ADPS1) ;
	SET_BIT(ADCSRA, ADCSRA_ADPS0) ;


}

uint16 ADC_u16_read(uint8 ChannelNumber)
{
	if (ChannelNumber == ADC0)
	{
		CLEAR_BIT(ADMUX, ADMUX_MUX0) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX1) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX2) ;

	}
	else if (ChannelNumber == ADC1)
	{
		SET_BIT(ADMUX, ADMUX_MUX0) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX1) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC2)
	{
		CLEAR_BIT(ADMUX, ADMUX_MUX0) ;
		SET_BIT(ADMUX, ADMUX_MUX1) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC3)
	{
		SET_BIT(ADMUX, ADMUX_MUX0) ;
		SET_BIT(ADMUX, ADMUX_MUX1) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC4)
	{
		CLEAR_BIT(ADMUX, ADMUX_MUX0) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX1) ;
		SET_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC5)
	{
		SET_BIT(ADMUX, ADMUX_MUX0) ;
		CLEAR_BIT(ADMUX, ADMUX_MUX1) ;
		SET_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC6)
	{
		CLEAR_BIT(ADMUX, ADMUX_MUX0) ;
		SET_BIT(ADMUX, ADMUX_MUX1) ;
		SET_BIT(ADMUX, ADMUX_MUX2) ;
	}
	else if (ChannelNumber == ADC7)
	{
		SET_BIT(ADMUX, ADMUX_MUX0) ;
		SET_BIT(ADMUX, ADMUX_MUX1) ;
		SET_BIT(ADMUX, ADMUX_MUX2) ;
	}
	
	SET_BIT(ADCSRA, ADCSRA_ADSC) ;
	
	while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) ;
	SET_BIT(ADCSRA, ADCSRA_ADIF) ;
	return ADCLH ;
}
