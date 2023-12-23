/*
 * KEYPAD_INIT.h
 *
 *  Created on: Oct 13, 2023
 *      Author: SHAHB
 */

#ifndef HAL_KEYPAD_INIT_H_
#define HAL_KEYPAD_INIT_H_

#include "..\..\STD.h"

#define KEYPAD_ROW0 DIO_B4
#define KEYPAD_ROW1 DIO_B5
#define KEYPAD_ROW2 DIO_B6
#define KEYPAD_ROW3 DIO_B7

#define KEYPAD_COL0 DIO_C2
#define KEYPAD_COL1 DIO_D2
#define KEYPAD_COL2 DIO_D4
#define KEYPAD_COL3 DIO_D6

#define UNPRESSED 'U'

#define KEYPAD_ROW0COL0 '7'
#define KEYPAD_ROW0COL1 '8'
#define KEYPAD_ROW0COL2 '9'
#define KEYPAD_ROW0COL3 '/'

#define KEYPAD_ROW1COL0 '4'
#define KEYPAD_ROW1COL1 '5'
#define KEYPAD_ROW1COL2 '6'
#define KEYPAD_ROW1COL3 '*'

#define KEYPAD_ROW2COL0 '1'
#define KEYPAD_ROW2COL1 '2'
#define KEYPAD_ROW2COL2 '3'
#define KEYPAD_ROW2COL3 '-'

#define KEYPAD_ROW3COL0 ' '
#define KEYPAD_ROW3COL1 '0'
#define KEYPAD_ROW3COL2 '='
#define KEYPAD_ROW3COL3 '+'

void KEYPAD_init() ;
int8 KEYPAD_read() ;

#endif /* HAL_KEYPAD_INIT_H_ */
