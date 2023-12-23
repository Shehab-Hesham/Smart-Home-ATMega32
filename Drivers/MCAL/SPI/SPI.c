/*
 * SPI.c
 *
 *  Created on: Nov 10, 2023
 *      Author: SHAHB
 */
#include "util/delay.h"
#include "..\..\STD.h"
#include "../../BITMATH.h"
#include "..\DIO/DIO_AD.h"
#include "SPI_HW.h"

void SPI_void_INIT(uint8 state)
{
	DIO_direction(DIO_B4, DIO_OUTPUT) ;//SS
	DIO_direction(DIO_B5, DIO_OUTPUT) ;//MOSI
	DIO_direction(DIO_B6, DIO_INPUT) ;//MISO
	DIO_direction(DIO_B7, DIO_OUTPUT) ;//clk
	DIO_set(DIO_B4, DIO_LOW) ;

	SET_BIT(SPCR, SPE) ;

	if (state == MASTER)
	{
		SET_BIT(SPCR, MSTR) ;

	}
	else
	{
		CLEAR_BIT(SPCR, MSTR) ;
	}

	CLEAR_BIT(SPCR, SPI2X) ;
	SET_BIT(SPCR, SPR1) ;
	SET_BIT(SPCR, SPR0) ;

}

uint8 SPI_uint8_RECIEVE()
{
	uint16 time = 10000 ;
	while ( !GET_BIT(SPSR, SPIF ) )
	{
		time-- ;
		if(time ==0)
		{
			return NOT_RECIEVED ;
		}
	}
	return SPDR ;
}

void SPI_void_SEND(uint8 data)
{
	//_delay_ms(250) ;
	DIO_set(DIO_B4, DIO_HIGH) ;
	_delay_ms(1) ;
	DIO_set(DIO_B4, DIO_LOW) ;

	SPDR = data ;
	while ( !GET_BIT(SPSR, SPIF ) ) ;
	//return SPDR;
}
