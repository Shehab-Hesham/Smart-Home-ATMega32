/*
 * KEYPAD.c
 *
 *  Created on: Oct 13, 2023
 *      Author: SHAHB
 */
#include "..\..\STD.h"
#include "KEYPAD_INIT.h"
#include "..\..\MCAL\DIO\DIO_AD.h"

void KEYPAD_init()
{
	DIO_direction(KEYPAD_ROW0, DIO_INPUT) ;
	DIO_direction(KEYPAD_ROW1, DIO_INPUT) ;
	DIO_direction(KEYPAD_ROW2, DIO_INPUT) ;
	DIO_direction(KEYPAD_ROW3, DIO_INPUT) ;


	DIO_set_pull_up(KEYPAD_ROW0) ;
	DIO_set_pull_up(KEYPAD_ROW1) ;
	DIO_set_pull_up(KEYPAD_ROW2) ;
	DIO_set_pull_up(KEYPAD_ROW3) ;


	DIO_direction(KEYPAD_COL0, DIO_OUTPUT) ;
	DIO_direction(KEYPAD_COL1, DIO_OUTPUT) ;
	DIO_direction(KEYPAD_COL2, DIO_OUTPUT) ;
	DIO_direction(KEYPAD_COL3, DIO_OUTPUT) ;
}


int8 KEYPAD_read()
{
	DIO_set(KEYPAD_COL0, DIO_LOW) ;
	DIO_set(KEYPAD_COL1, DIO_HIGH) ;
	DIO_set(KEYPAD_COL2, DIO_HIGH) ;
	DIO_set(KEYPAD_COL3, DIO_HIGH) ;

	if (DIO_get(KEYPAD_ROW0) == 0)
	{
		return KEYPAD_ROW0COL0 ;
	}
	else if (DIO_get(KEYPAD_ROW1) == 0)
	{
		return KEYPAD_ROW1COL0 ;
	}
	else if (DIO_get(KEYPAD_ROW2) == 0)
	{
		return KEYPAD_ROW2COL0 ;
	}
	else if (DIO_get(KEYPAD_ROW3) == 0)
	{
		return KEYPAD_ROW3COL0 ;
	}

	DIO_set(KEYPAD_COL0, DIO_HIGH) ;
	DIO_set(KEYPAD_COL1, DIO_LOW) ;
	DIO_set(KEYPAD_COL2, DIO_HIGH) ;
	DIO_set(KEYPAD_COL3, DIO_HIGH) ;

	if (DIO_get(KEYPAD_ROW0) == 0)
	{
		return KEYPAD_ROW0COL1 ;
	}
	else if (DIO_get(KEYPAD_ROW1) == 0)
	{
		return KEYPAD_ROW1COL1 ;
	}
	else if (DIO_get(KEYPAD_ROW2) == 0)
	{
		return KEYPAD_ROW2COL1 ;
	}
	else if (DIO_get(KEYPAD_ROW3) == 0)
	{
		return KEYPAD_ROW3COL1 ;
	}

	DIO_set(KEYPAD_COL0, DIO_HIGH) ;
	DIO_set(KEYPAD_COL1, DIO_HIGH) ;
	DIO_set(KEYPAD_COL2, DIO_LOW) ;
	DIO_set(KEYPAD_COL3, DIO_HIGH) ;

	if (DIO_get(KEYPAD_ROW0) == 0)
	{
		return KEYPAD_ROW0COL2 ;
	}
	else if (DIO_get(KEYPAD_ROW1) == 0)
	{
		return KEYPAD_ROW1COL2 ;
	}
	else if (DIO_get(KEYPAD_ROW2) == 0)
	{
		return KEYPAD_ROW2COL2 ;
	}
	else if (DIO_get(KEYPAD_ROW3) == 0)
	{
		return KEYPAD_ROW3COL2 ;
	}


	DIO_set(KEYPAD_COL0, DIO_HIGH) ;
	DIO_set(KEYPAD_COL1, DIO_HIGH) ;
	DIO_set(KEYPAD_COL2, DIO_HIGH) ;
	DIO_set(KEYPAD_COL3, DIO_LOW) ;

	if (DIO_get(KEYPAD_ROW0) == 0)
	{
		return KEYPAD_ROW0COL3 ;
	}
	else if (DIO_get(KEYPAD_ROW1) == 0)
	{
		return KEYPAD_ROW1COL3 ;
	}
	else if (DIO_get(KEYPAD_ROW2) == 0)
	{
		return KEYPAD_ROW2COL3 ;
	}
	else if (DIO_get(KEYPAD_ROW3) == 0)
	{
		return KEYPAD_ROW3COL3 ;
	}
	return UNPRESSED ;

}
