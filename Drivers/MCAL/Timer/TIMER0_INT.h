
#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "..\..\STD.h"
//change types

//include types

//include bitmath


/*Timer0 Registers*/
//Timer/Counter Control Register
#define TCCR0 		*((volatile uint8*)0x53)
#define FOC0		7
#define WGM00		6
#define COM01		5
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0

#define TOIE0       0
//Timer/Counter Register
#define TCNT0 		*((volatile uint8*)0x52)

//Output Compare Register
#define OCR0 		*((volatile uint8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile uint8*)0x59)
#define OCIE0		1
#define TOIE0		0




//Timer/Counter Mode of Operation
#define Normal   0
#define PWM      1
#define CTC      2
#define FastPWM  3

//OCR0_NON_PWM_MODE
#define TOGGLE  1
#define Clear   2
#define Set     3



/*<Clock Select Bit Description>*/
//Timer/Counter stopped
#define Stop    0

//clkI/O/ (No prescaling)
#define clk16M    1
//Prescaling
#define clk8               8
#define clk64              64
#define clk256             256
#define clk1024            1024

//External clock source on T0 pin
#define External_falling_edge   3
#define External_rising_edge    4


void OC0_MODE(uint8 mode) ;

void TIMER0_init_Mode(uint8 mode);

void TIMER0_Start(uint16 preScaler);

void TIMER0_Stop();

uint8 TIMER0_GetCounts();

void TIMER0_SetTimerPreload(uint8 Value);

void Set_Up_DUTY(uint8 Duty);

uint8 Get_Duty();
uint16 x_return();

#endif /* TIMER0_TIMER0_INT_H_ */
