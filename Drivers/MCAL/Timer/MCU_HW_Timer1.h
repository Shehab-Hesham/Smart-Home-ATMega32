
#ifndef MCU_HW_H_
#define MCU_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "..\..\STD.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

////////////////////////////////////////////////////////////////////////

/*TIMER1 Registers*/
#define TCCR1A				*((volatile uint8*)0x4F)
#define TCCR1A_WGM10_BIT	0
#define TCCR1A_WGM11_BIT	1
#define TCCR1A_FOC1A_BIT	3
#define TCCR1A_FOC1B_BIT	2
#define TCCR1A_COM1B0_BIT	4
#define TCCR1A_COM1B1_BIT	5
#define TCCR1A_COM1A0_BIT	6
#define TCCR1A_COM1A1_BIT	7

#define TCCR1B				*((volatile uint8*)0x4E)
#define TCCR1B_CS10_BIT		0
#define TCCR1B_CS11_BIT		1
#define TCCR1B_CS12_BIT		2
#define TCCR1B_WGM12_BIT	3
#define TCCR1B_WGM13_BIT	4
#define TCCR1B_ICES1_BIT	6
#define TCCR1B_ICNC1_BIT	7

#define TCNT1				*((volatile uint16*)0x4C)

#define OCR1A				*((volatile uint16*)0x4A)

#define OCR1B				*((volatile uint16*)0x48)

#define ICR1				*((volatile uint16*)0x46)

#define TIMSK				*((volatile uint8*)0x59)
#define TIMSK_TOIE1_BIT			2
#define TIMSK_OCIE1B_BIT		3
#define TIMSK_OCIE1A_BIT		4
#define TIMSK_TICIE1_BIT		5

#define TIFR				*((volatile uint8*)0x58)
///////////////////////////////////////////////////////////////
#define fastPWM 14



#define NonInverting 2



/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
void TIMER1_initMode(uint8 Mode);

void TIMER1_Start(uint16 preScaler);

void SetOutputMode(uint8 Mode);

void SetTimer1Duty(uint8 Duty);

void SetFrequancyTimer1(uint16 Freq);



#endif /* MCU_HW_H_ */
