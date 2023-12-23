/*
 * EXT_INTERRUPT.h
 *
 *  Created on: Oct 14, 2023
 *      Author: SHAHB
 */

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "..\..\STD.h"


#define GICR ( *(uint8 *) 0x5B )
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define MCUCR ( *(uint8 *) 0x55 )
#define ISC01 1
#define ISC00 0
#define ISC11 3
#define ISC10 2

#define INT0 0
#define INT1 1
#define INT2 2

#define INT1_FALLING 10
#define INT1_RISING 11
#define INT1_ANYCHANGE 01

void INTERRUPT_MODE_SET(uint8 INT_NUM, uint8 CALL_MODE) ;
void setCallback( void (*FunPtr)() );

#endif /* EXT_INTERRUPT_H_ */
