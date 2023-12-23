/*
 * DOI_FUNC.c
 *
 *  Created on: Oct 6, 2023
 *      Author: SHAHB
 */


#include "..\..\BITMATH.h"
#include "..\..\STD.h"
#include "DIO_AD.h"

void DIO_set(uint8 pinNUM, uint8 dir)
{
	if(pinNUM >= 0 && pinNUM <= 7)
	{

		if(dir)
		{
			SET_BIT(PORTA, pinNUM) ;
		}
		else
		{
			CLEAR_BIT(PORTA, pinNUM) ;
		}

	}

	else if(pinNUM >= 8 && pinNUM <= 15)
	{
		pinNUM -= 8 ;

		if(dir)
		{
			SET_BIT(PORTB, pinNUM) ;
		}
		else
		{
			CLEAR_BIT(PORTB, pinNUM) ;
		}

	}

	else if(pinNUM >= 16 && pinNUM <= 23)
	{
		pinNUM -= 16 ;

		if(dir)
		{
			SET_BIT(PORTC, pinNUM) ;
		}
		else
		{
			CLEAR_BIT(PORTC, pinNUM) ;
		}

	}

	else
	{
		pinNUM -= 24 ;

		if(dir)
		{
			SET_BIT(PORTD, pinNUM) ;
		}
		else
		{
			CLEAR_BIT(PORTD, pinNUM) ;
		}
	}

}

void DIO_direction (uint8 pinNUM, uint8 dir)
{
	if(pinNUM >= 0 && pinNUM <= 7)
			{
				if(dir)
				{
					SET_BIT(DDRA, pinNUM) ;
				}
				else
				{
					CLEAR_BIT(DDRA, pinNUM) ;
				}
			}

			else if(pinNUM >= 8 && pinNUM <= 15)
			{
				pinNUM -= 8 ;
				if(dir)
				{
					SET_BIT(DDRB, pinNUM) ;
				}
				else
				{
					CLEAR_BIT(DDRB, pinNUM) ;
				}

			}

			else if(pinNUM >= 16 && pinNUM <= 23)
			{
				pinNUM -= 16 ;
				if(dir)
				{
					SET_BIT(DDRC, pinNUM) ;
				}
				else
				{
					CLEAR_BIT(DDRC, pinNUM) ;
				}

			}

			else
			{
				pinNUM -= 24 ;
				if(dir)
				{
					SET_BIT(DDRD, pinNUM) ;
				}
				else
				{
					CLEAR_BIT(DDRD, pinNUM) ;
				}

			}
}


uint8 DIO_get (uint8 pinNUM)
{
	if(pinNUM >= 0 && pinNUM <= 7)
		{
			return GET_BIT(PINA, pinNUM) ;
		}

		else if(pinNUM >= 8 && pinNUM <= 15)
		{
			pinNUM -= 8 ;
			return GET_BIT(PINB, pinNUM) ;

		}

		else if(pinNUM >= 16 && pinNUM <= 23)
		{
			pinNUM -= 16 ;
			return GET_BIT(PINC, pinNUM) ;

		}

		else
		{
			pinNUM -= 24 ;
			return GET_BIT(PIND, pinNUM) ;
		}
}
void DIO_set_pull_up(uint8 pinNUM)
{
	DIO_set(pinNUM, DIO_HIGH) ;
}
