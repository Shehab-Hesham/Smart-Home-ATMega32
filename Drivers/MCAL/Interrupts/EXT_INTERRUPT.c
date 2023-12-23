/*
 * EXT_INTERRUPT.c
 *
 *  Created on: Oct 14, 2023
 *      Author: SHAHB
 */

#include "..\..\STD.h"
#include "EXT_INTERRUPT.h"
#include "../../BITMATH.h"
#include "../../MCAL/DIO/DIO_AD.h"
#include "util/delay.h"

//create pointer to function
void (*PtrInt1)() ;

void setCallback( void (*FuncPtr)() )
{
	PtrInt1 = FuncPtr ;
}

void INTERRUPT_MODE_SET(uint8 INT_NUM, uint8 CALL_MODE)
{
	if (INT_NUM == INT0)
	{
		SET_BIT(GICR, GICR_INT0) ;
	}
	else if (INT_NUM ==  INT1)
	{
		//DIO_direction(DIO_D3, DIO_INPUT) ;
		//DIO_set(DIO_A7, DIO_HIGH) ;
		SET_BIT(GICR, GICR_INT1) ;
		if (CALL_MODE == INT1_FALLING)
		{
			SET_BIT(MCUCR, ISC11) ;
			CLEAR_BIT(MCUCR, ISC10) ;
		}
		else if (CALL_MODE == INT1_RISING)
		{
			SET_BIT(MCUCR, ISC11) ;
			SET_BIT(MCUCR, ISC10) ;
		}
		else if (CALL_MODE == INT1_ANYCHANGE)
		{
			SET_BIT(MCUCR, ISC10) ;
			CLEAR_BIT(MCUCR, ISC11) ;
		}
	}
	else if (INT_NUM == INT2)
	{
		SET_BIT(GICR, GICR_INT2) ;
	}

}

void __vector_2 (void)__attribute__((signal,used)) ;
void __vector_2(void)
{
	//DIO_set(DIO_C3,DIO_LOW);
	PtrInt1();
}
