/*
 * Timer2.h
 *
 *  Created on: Dec 15, 2023
 *      Author: SHAHB
 */

#ifndef DRIVERS_MCAL_TIMER_TIMER2_H_
#define DRIVERS_MCAL_TIMER_TIMER2_H_

#include "..\..\STD.h"
#define TCCR2 *((volatile uint8*) 0x45)
#define FOC2 7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22 2
#define CS21 1
#define CS20 0

#define TIMER2_NORMAL 0
#define TIMER2_PWM 1
#define TIMER2_CTC 2
#define TIMER2_FAST 3

#define OC2_Normal 0
#define OC2_TOGGLE 1
#define OC2_CLEAR 2
#define OC2_SET 3

#define TCNT2 *((volatile uint8*) 0x44)
#define OCR2 *((volatile uint8*) 0x43)


void TIMER2_SetTimerPreload(uint8 Value);

void OC2_MODE(int mode);

uint8 TIMER2_GetCounts();

void TIMER2_Stop();

uint8 Get_Duty_Timer2();

void Set_Up_DUTY_Timer2(uint8 Duty);

void TIMER2_Start(uint16 preScaler);

void TIMER2_init_Mode(uint8 timerMode);

void setCallbackTimer2( void (*FunPtr)() );


#endif /* DRIVERS_MCAL_TIMER_TIMER2_H_ */
