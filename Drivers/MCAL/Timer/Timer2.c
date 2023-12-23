/*
 * Timer2.c
 *
 *  Created on: Dec 15, 2023
 *      Author: SHAHB
 */
#include "Timer2.h"
#include "..\..\STD.h"
#include "../../BITMATH.h"
#include "..\..\MCAL\DIO\DIO_AD.h"

void (*PtrIntTimer2)() ;
void setCallbackTimer2( void (*FunPtr)() )
{
	PtrIntTimer2 = FunPtr ;
}
void TIMER2_init_Mode(uint8 timerMode)
{
	DIO_direction(DIO_D7, DIO_OUTPUT) ;
	//set_global_interrupt() ;
	if (timerMode == TIMER2_NORMAL)
	{
		CLEAR_BIT(TCCR2, WGM21) ;
		CLEAR_BIT(TCCR2, WGM20) ;
	}
	else if (timerMode == TIMER2_PWM)
	{
		CLEAR_BIT(TCCR2, WGM21) ;
		SET_BIT(TCCR2, WGM20) ;
	}
	else if (timerMode == TIMER2_CTC)
	{
		SET_BIT(TCCR2, WGM21) ;
		CLEAR_BIT(TCCR2, WGM20) ;
	}
	else if (timerMode == TIMER2_FAST)
	{
		SET_BIT(TCCR2, WGM21) ;
		SET_BIT(TCCR2, WGM20) ;
	}
	//SET_BIT(TIMSK, TOIE0) ;
}


void TIMER2_Start(uint16 preScaler)
{
	if (preScaler == 1024)
		{
			SET_BIT(TCCR2, CS20) ;
			SET_BIT(TCCR2, CS21) ;
			SET_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 256)
		{
			CLEAR_BIT(TCCR2, CS20) ;
			SET_BIT(TCCR2, CS21) ;
			SET_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 128)
		{
			SET_BIT(TCCR2, CS20) ;
			CLEAR_BIT(TCCR2, CS21) ;
			SET_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 64)
		{
			CLEAR_BIT(TCCR2, CS20) ;
			CLEAR_BIT(TCCR2, CS21) ;
			SET_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 32)
		{
			SET_BIT(TCCR2, CS20) ;
			SET_BIT(TCCR2, CS21) ;
			CLEAR_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 8)
		{
			CLEAR_BIT(TCCR2, CS20) ;
			SET_BIT(TCCR2, CS21) ;
			CLEAR_BIT(TCCR2, CS22) ;
		}
		else if (preScaler == 0)
		{
			SET_BIT(TCCR2, CS20) ;
			CLEAR_BIT(TCCR2, CS21) ;
			CLEAR_BIT(TCCR2, CS22) ;
		}

}
void Set_Up_DUTY_Timer2(uint8 Duty)
{
	OCR2 = (Duty*256-1)/100;
}
uint8 Get_Duty_Timer2()
{
	uint8 Duty = (OCR2+1)/256;
	return Duty;
}
void TIMER2_Stop()
{
	CLEAR_BIT(TCCR2, CS22) ;
	CLEAR_BIT(TCCR2, CS21) ;
	CLEAR_BIT(TCCR2, CS20) ;
}

uint8 TIMER2_GetCounts()
{
	return TCNT2;
}

void OC2_MODE(int mode)
{
	if( mode == OC2_Normal)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if( mode == OC2_TOGGLE)
	{
		SET_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if( mode == OC2_CLEAR)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;
	}
	else if( mode == OC2_SET)
	{
		SET_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;	}
}



void TIMER2_SetTimerPreload(uint8 Value)
{
	TCNT2 = Value ;
}


void __vector_5 (void)__attribute__((signal,used)) ;
void __vector_5 (void)
{
	(*PtrIntTimer2)() ;
}





/*void TIMER2_compare_nonePWM(uint8 mode)
{
	if(mode == TIMER2_0C2DISCONNECT)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if (mode == TIMER2_TOGGLE)
	{
		SET_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if (mode == TIMER2_CLEAR)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;
	}
	else if(mode == TIMER2_SET)
	{
		SET_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;
	}
}
void TIMER2_compare_fastPWM(ui8 mode)
{

	if(mode == TIMER2_0C2DISCONNECT)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if (mode == TIMER2_TOGGLE)
	{
		SET_BIT(TCCR2, COM20) ;
		CLEAR_BIT(TCCR2, COM21) ;
	}
	else if (mode == TIMER2_CLEAR)
	{
		CLEAR_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;
	}
	else if(mode == TIMER2_SET)
	{
		SET_BIT(TCCR2, COM20) ;
		SET_BIT(TCCR2, COM21) ;
	}
}*/

/*void TIMER2_set_OCR2(uint8 mode, fl desired_duty)
{
	desired_duty /= 100 ;
	if (mode == TIMER2_CLEAR)
	{
		OCR2 = ( (uint8) ((desired_duty * 256) - 1)) ;
	}
	else if(mode == TIMER2_SET)
	{
		OCR2 = ( (uint8) (((desired_duty * 256) + 256) * -1)) ;
	}
}*/
