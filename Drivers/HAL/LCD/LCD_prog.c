/*
 * LCD_prog.c
 *
 *  Created on: Oct 7, 2023
 *      Author: SHAHB
 */
#include "util/delay.h"
#include "..\..\MCAL\DIO\DIO_AD.h"
//#include "Drivers/MCAL/DIO/DIO_AD.h"
//#include "..\..\DIO_AD.h"
#include "LCD_Init.h"
#include "..\..\BITMATH.h"

void LCD_void_init()
{
	DIO_direction(DIO_B0,DIO_OUTPUT) ;
	DIO_direction(DIO_B1,DIO_OUTPUT) ;
	DIO_direction(DIO_B2,DIO_OUTPUT) ;
	#if (LCD_MODE == 8)

		DIO_direction(DIO_A0,DIO_OUTPUT) ;
		DIO_direction(DIO_A1,DIO_OUTPUT) ;
		DIO_direction(DIO_A2,DIO_OUTPUT) ;
		DIO_direction(DIO_A3,DIO_OUTPUT) ;
		DIO_direction(DIO_A4,DIO_OUTPUT) ;
		DIO_direction(DIO_A5,DIO_OUTPUT) ;
		DIO_direction(DIO_A6,DIO_OUTPUT) ;
		DIO_direction(DIO_A7,DIO_OUTPUT) ;


		_delay_ms(30) ;
		LCD_void_sendCmd(FUNCTION_SET_8) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(DISPLAY_ON_CONTROL_8) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(DISPLAY_CLEAR_8) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(ENTRY_MODE_8) ;

	#elif (LCD_MODE == 4)
		DIO_direction(DIO_A4,DIO_OUTPUT) ;
		DIO_direction(DIO_A5,DIO_OUTPUT) ;
		DIO_direction(DIO_A6,DIO_OUTPUT) ;
		DIO_direction(DIO_A7,DIO_OUTPUT) ;


		_delay_ms(30) ;
		LCD_void_sendCmd(FUNCTION_SET_4_A) ;
		_delay_us(40) ;
		LCD_void_sendCmd(FUNCTION_SET_4_B) ;
		_delay_us(40) ;
		LCD_void_sendCmd(FUNCTION_SET_4_C) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(DISPLAY_ON_CONTROL_4_A) ;
		_delay_us(40) ;
		LCD_void_sendCmd(DISPLAY_ON_CONTROL_4_B) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(DISPLAY_CLEAR_4_A) ;
		_delay_us(40) ;
		LCD_void_sendCmd(DISPLAY_CLEAR_4_B) ;
		_delay_ms(1) ;
		LCD_void_sendCmd(ENTRY_MODE_4_A) ;
		_delay_us(40) ;
		LCD_void_sendCmd(ENTRY_MODE_4_B) ;
	#endif
}
void LCD_void_sendData(int8 data)
{

	DIO_set(RS, DIO_HIGH) ;
	DIO_set(RW, DIO_LOW) ;
	DIO_set(E, DIO_HIGH) ;

	#if (LCD_MODE == 8)

		DIO_set(LCD_D0, GET_BIT(data,0)) ;
		DIO_set(LCD_D1, GET_BIT(data,1)) ;
		DIO_set(LCD_D2, GET_BIT(data,2)) ;
		DIO_set(LCD_D3, GET_BIT(data,3)) ;
		DIO_set(LCD_D4, GET_BIT(data,4)) ;
		DIO_set(LCD_D5, GET_BIT(data,5)) ;
		DIO_set(LCD_D6, GET_BIT(data,6)) ;
		DIO_set(LCD_D7, GET_BIT(data,7)) ;


		_delay_ms(10) ;
		DIO_set(E, DIO_LOW) ;
	#elif (LCD_MODE == 4)
	DIO_set(LCD_D4, GET_BIT(data,4)) ;
	DIO_set(LCD_D5, GET_BIT(data,5)) ;
	DIO_set(LCD_D6, GET_BIT(data,6)) ;
	DIO_set(LCD_D7, GET_BIT(data,7)) ;

	_delay_ms(10) ;
	DIO_set(E, DIO_LOW) ;
	//DIO_set(RS, DIO_HIGH) ;
	//DIO_set(RW, DIO_LOW) ;
	_delay_ms(1) ;
	DIO_set(E, DIO_HIGH) ;

	DIO_set(LCD_D4, GET_BIT(data,0)) ;
	DIO_set(LCD_D5, GET_BIT(data,1)) ;
	DIO_set(LCD_D6, GET_BIT(data,2)) ;
	DIO_set(LCD_D7, GET_BIT(data,3)) ;

	_delay_ms(10) ;
	DIO_set(E, DIO_LOW) ;
	#endif
}
void LCD_void_sendCmd(int8 cmd)
{
	DIO_set(RS, DIO_LOW) ;
	DIO_set(RW, DIO_LOW) ;
	#if (LCD_MODE == 8)

		DIO_set(LCD_D0, GET_BIT(cmd,0)) ;
		DIO_set(LCD_D1, GET_BIT(cmd,1)) ;
		DIO_set(LCD_D2, GET_BIT(cmd,2)) ;
		DIO_set(LCD_D3, GET_BIT(cmd,3)) ;
		DIO_set(LCD_D4, GET_BIT(cmd,4)) ;
		DIO_set(LCD_D5, GET_BIT(cmd,5)) ;
		DIO_set(LCD_D6, GET_BIT(cmd,6)) ;
		DIO_set(LCD_D7, GET_BIT(cmd,7)) ;

		DIO_set(E, DIO_HIGH) ;
		_delay_ms(10) ;
		DIO_set(E, DIO_LOW) ;
	#elif (LCD_MODE == 4)
		DIO_set(LCD_D4, GET_BIT(cmd,4)) ;
		DIO_set(LCD_D5, GET_BIT(cmd,5)) ;
		DIO_set(LCD_D6, GET_BIT(cmd,6)) ;
		DIO_set(LCD_D7, GET_BIT(cmd,7)) ;

		DIO_set(E, DIO_HIGH) ;
		_delay_ms(10) ;
		DIO_set(E, DIO_LOW) ;

		DIO_set(LCD_D4, GET_BIT(cmd,0)) ;
		DIO_set(LCD_D5, GET_BIT(cmd,1)) ;
		DIO_set(LCD_D6, GET_BIT(cmd,2)) ;
		DIO_set(LCD_D7, GET_BIT(cmd,3)) ;

		DIO_set(E, DIO_HIGH) ;
		_delay_ms(10) ;
		DIO_set(E, DIO_LOW) ;
	#endif
}
void LCD_void_clear()
{
	#if (LCD_MODE == 8)
		LCD_void_sendCmd(LCD_CLEAR) ;
	#elif (LCD_MODE == 4)
		LCD_void_sendCmd(LCD_CLEAR_4_A) ;
		_delay_us(40) ;
		LCD_void_sendCmd(LCD_CLEAR_4_B) ;
	#endif
}
void LCD_void_sendString(int8 * str)
{
	uint8 i ;
	#if (LCD_MODE == 8)
		for (i = 0 ; str[i] != '\0' ; i++)
			LCD_void_sendData(str[i]) ;
	#elif (LCD_MODE == 4)
		for (i = 0 ; str[i] != '\0' ; i++)
			LCD_void_sendData(str[i]) ;
	#endif
}
void LCD_void_sendNum(int16 num)
{
	char str[10] ;
	sprintf(str, "%d", num) ;
	#if (LCD_MODE == 8)
		LCD_void_sendString(str) ;
	#elif (LCD_MODE == 4)
		LCD_void_sendString(str) ;
	#endif
}
void LCD_void_gotoX(int8 x)
{
	uint8 iterate ;
	#if (LCD_MODE == 8)
		for(iterate = x ; iterate > 0 ; iterate--)
			LCD_void_sendCmd(SHIFT_RIGHT_8) ;
	#elif (LCD_MODE == 4)
		for(iterate = x ; iterate > 0 ; iterate--)
		{
			LCD_void_sendCmd(SHIFT_RIGHT_4_A) ;
			_delay_us(40) ;
			LCD_void_sendCmd(SHIFT_RIGHT_4_B) ;
		}
	#endif
}
void LCD_void_shiftDisplay(int8 x)
{
	uint8 iterate ;
	#if (LCD_MODE == 8)
		for(iterate = x ; iterate > 0 ; iterate--)
			LCD_void_sendCmd(SHIFT_DISPLAY_8) ;
	#elif (LCD_MODE == 4)
		for(iterate = x ; iterate > 0 ; iterate--)
		{
			LCD_void_sendCmd(SHIFT_DISPLAY_4_A) ;
			_delay_us(40) ;
			LCD_void_sendCmd(SHIFT_DISPLAY_4_B) ;
		}
	#endif
}
