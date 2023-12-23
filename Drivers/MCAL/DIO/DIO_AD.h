/*
 * DIO_AD.h
 *
 *  Created on: Oct 6, 2023
 *      Author: SHAHB
 */

#ifndef MCAL_DIO_DIO_AD_H_
#define MCAL_DIO_DIO_AD_H_

#include "..\..\STD.h"

#define DDRA *(uint8*)0x3A
#define PORTA *(uint8*)0x3B
#define PINA *(uint8*) 0x39

#define DDRB *(uint8*)0x37
#define PORTB *(uint8*)0x38
#define PINB *(uint8*) 0x36

#define DDRC *(uint8*)0x34
#define PORTC *(uint8*)0x35
#define PINC *(uint8*) 0x33

#define DDRD *(uint8*)0x31
#define PORTD *(uint8*)0x32
#define PIND *(uint8*) 0x30


#define DIO_HIGH 1
#define DIO_LOW  0

#define DIO_OUTPUT 1
#define DIO_INPUT  0

#define DIO_A0 0
#define DIO_A1 1
#define DIO_A2 2
#define DIO_A3 3
#define DIO_A4 4
#define DIO_A5 5
#define DIO_A6 6
#define DIO_A7 7

#define DIO_B0 8
#define DIO_B1 9
#define DIO_B2 10
#define DIO_B3 11
#define DIO_B4 12
#define DIO_B5 13
#define DIO_B6 14
#define DIO_B7 15

#define DIO_C0 16
#define DIO_C1 17
#define DIO_C2 18
#define DIO_C3 19
#define DIO_C4 20
#define DIO_C5 21
#define DIO_C6 22
#define DIO_C7 23

#define DIO_D0 24
#define DIO_D1 25
#define DIO_D2 26
#define DIO_D3 27
#define DIO_D4 28
#define DIO_D5 29
#define DIO_D6 30
#define DIO_D7 31

uint8 DIO_get (uint8 pinNUM) ;
void DIO_direction (uint8 pinNUM, uint8 dir) ;
void DIO_set(uint8 pinNUM, uint8 dir) ;
void DIO_set_pull_up(uint8 pinNUM) ;
#endif /* MCAL_DIO_DIO_AD_H_ */
