/*
 * GLOBAL_INTERRUPT.c
 *
 *  Created on: Oct 14, 2023
 *      Author: SHAHB
 */
#include "..\..\STD.h"
#include "GLOBAL_INTERRUPT.h"
#include "..\..\BITMATH.h"

void set_global_interrupt()
{
	SET_BIT(SREG, SREG_GIENABLE) ;
}
void clear_global_interrupt()
{
	CLEAR_BIT(SREG, SREG_GIENABLE) ;
}
