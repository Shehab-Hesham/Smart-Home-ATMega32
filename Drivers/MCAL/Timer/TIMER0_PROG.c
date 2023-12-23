
#include "TIMER0_INT.h"
#include "..\..\BITMATH.h"
#include "..\DIO/DIO_AD.h"


void TIMER0_init_Mode(uint8 mode)
{
	DIO_direction(DIO_B3, DIO_OUTPUT) ;
	// Force -> Set
	SET_BIT(TCCR0,FOC0);
	//Enable
	SET_BIT(TIMSK,TOIE0);
	// Select Mode
	if (mode == Normal)
	{
		// Force -> Set
		SET_BIT(TCCR0,FOC0);
		CLEAR_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
	}
	else if (mode == PWM)
	{
		// Force -> CLEAR
		CLEAR_BIT(TCCR0,FOC0);
		CLEAR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
	}
	else if (mode == CTC)
	{
		CLEAR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM01);
	}
	else if (mode == FastPWM)
	{
		// Force -> CLEAR
		CLEAR_BIT(TCCR0,FOC0);
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
	}
	
}

void TIMER0_Start(uint16 preScaler)
{
	if(preScaler == 1024)
	{
		SET_BIT(TCCR0,CS02);
		CLEAR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS00);
	}
	else if(preScaler == 256)
	{
		SET_BIT(TCCR0,CS02);
		CLEAR_BIT(TCCR0,CS01);
		CLEAR_BIT(TCCR0,CS00);
	}
	else if(preScaler == 64)
		{
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}
	else if(preScaler == 8)
		{
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
			CLEAR_BIT(TCCR0,CS00);
		}
	else if(preScaler == 0)
		{
			CLEAR_BIT(TCCR0,CS02);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS00);
		}
	else if(preScaler == 1)
		{
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}

}
void Set_Up_DUTY(uint8 Duty)
{
	OCR0 = (Duty*256-1)/100;
}
uint8 Get_Duty()
{
	uint8 Duty = (OCR0+1)/256;
	return Duty;
}
void TIMER0_Stop()
{
	CLEAR_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);
}

uint8 TIMER0_GetCounts()
{
	return TCNT0;
}


void OC0_MODE(uint8 mode)
{
	if( mode == Normal)
	{
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
	}
	else if( mode == TOGGLE)
	{
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
	}
	else if( mode == Clear)
	{
		SET_BIT(TCCR0,COM01);
		CLEAR_BIT(TCCR0,COM00);
	}
	else if( mode == Set)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
}

void TIMER0_SetTimerPreload(uint8 Value)
{
	TCNT0 = Value;
}
// Pointer to Function
void (*funTIMER0)();
void Timer0_setCallback(void (*ptrFunc))
{
	funTIMER0 = ptrFunc;
}



void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	(*funTIMER0)();
}
