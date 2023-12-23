/*
 * TIMER!_PROG.c
 *
 *  Created on: Oct 28, 2023
 *      Author: lenovo
 */


#include "MCU_HW_Timer1.h"
#include "..\..\MCAL\DIO\DIO_AD.h"
#include "..\..\BITMATH.h"
#include "..\..\STD.h"



void TIMER1_initMode(uint8 Mode)
{
	DIO_direction(DIO_D5, DIO_OUTPUT) ;

	if(Mode ==14)
	{
	 SET_BIT(TCCR1A,TCCR1A_WGM11_BIT);
	 SET_BIT(TCCR1B,TCCR1B_WGM12_BIT);
	 SET_BIT(TCCR1B,TCCR1B_WGM13_BIT);
	 CLEAR_BIT(TCCR1A,TCCR1A_WGM10_BIT);

	}


}

void TIMER1_Start(uint16 preScaler)
{

	if (preScaler==64)
	{
		SET_BIT(TCCR1B,TCCR1B_CS10_BIT);
		SET_BIT(TCCR1B,TCCR1B_CS11_BIT);
		CLEAR_BIT(TCCR1B,TCCR1B_CS12_BIT);
	}

}


void SetOutputMode(uint8 Mode)

{
	if (Mode == 2)
		SET_BIT(TCCR1A,TCCR1A_COM1A1_BIT);
		CLEAR_BIT(TCCR1A,TCCR1A_COM1A0_BIT);
}



void SetTimer1Duty(uint8 Duty)
{
	OCR1A = (Duty*ICR1)/100;
}

void SetFrequancyTimer1(uint16 Freq)
{
   ICR1=(16000000/(Freq*64))-1;

}
