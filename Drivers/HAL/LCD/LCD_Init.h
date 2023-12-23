/*
 * LCD_Init.h
 *
 *  Created on: Oct 7, 2023
 *      Author: SHAHB
 */
#include "..\..\MCAL\DIO\DIO_AD.h"
#include "..\..\STD.h"

#ifndef LCD_INIT_H_
#define LCD_INIT_H_

#define LCD_MODE 4

#define FUNCTION_SET_8 0b00111000
#define DISPLAY_ON_CONTROL_8 0b00001111
#define DISPLAY_CLEAR_8 0b00000001
#define ENTRY_MODE_8 0b00000110
#define SHIFT_RIGHT_8 0b00010100
#define SHIFT_DISPLAY_8 0b00011100

#define FUNCTION_SET_4_A 0b0010
#define FUNCTION_SET_4_B 0b0010
#define FUNCTION_SET_4_C 0b1000
#define DISPLAY_ON_CONTROL_4_A 0b0000
#define DISPLAY_ON_CONTROL_4_B 0b1111
#define DISPLAY_CLEAR_4_A 0b0000
#define DISPLAY_CLEAR_4_B 0b0001
#define ENTRY_MODE_4_A 0b0000
#define ENTRY_MODE_4_B 0b0110
#define LCD_CLEAR_4_A 0b0000
#define LCD_CLEAR_4_B 0b0001
#define SHIFT_RIGHT_4_A 0b0001
#define SHIFT_RIGHT_4_B 0b0100
#define SHIFT_DISPLAY_4_A 0b0001
#define SHIFT_DISPLAY_4_B 0b1100

#define RS 9
#define RW 8
#define E 10
#define LCD_CLEAR 0b00000001
#define LCD_D0 0
#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

void LCD_void_init() ;
void LCD_void_sendData(int8 data) ;
void LCD_void_sendCmd(int8 cmd) ;
void LCD_void_clear() ;
void LCD_void_sendString(int8 * str) ;
void LCD_void_sendNum(int16 num) ;
void LCD_void_gotoX(int8 x) ;
void LCD_void_shiftDisplay(int8 x) ;

#endif /* LCD_INIT_H_ */
