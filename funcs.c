/*
 * funcs.c
 *
 *  Created on: Dec 16, 2023
 *      Author: SHAHB
 */
#include "PROTOTYPES.h"

extern uint8 password_admin ;
extern uint8 password_user ;
extern uint8 current_password ;
extern uint16 compare_password ;
extern uint16 entered_password ;
extern uint8 password_counter  ;
extern uint8 trial_num ;
extern uint16 timer0_counter  ;
extern uint16 temp ;
extern uint8 key ;
extern uint8 light_level ;

void clearAfter() //Interrupt
{
	LCD_void_clear() ;
	LCD_void_sendString("Reseting") ;
	_delay_ms(250) ;
	LCD_void_clear() ;
	trial_num = 0 ;
	timer0_counter = 0 ;
	password_counter = 0 ;
	compare_password = 0 ;
	entered_password = 0 ;
	current_password = 0 ;
	control_door('I') ;
	DIO_set(BUZZER, DIO_LOW) ;
	DIO_set(DIO_C3,DIO_LOW) ;
	DIO_set(DIO_C4,DIO_LOW) ;
	DIO_set(DIO_C5,DIO_LOW) ;
	DIO_set(DIO_C6,DIO_LOW) ;
	DIO_set(DIO_C7,DIO_LOW) ;
	control_AC(40) ;
	control_dimmer(6) ;// close AC with dummy high temperature
	//sendString("SYSTEM RESET");
	//sendData('\r');

}

void control_LEDS(uint8 led_num)
{
	switch(led_num)
	{
	   case '0':
				LCD_void_sendString("LOG OUT") ;
				sendString("LOG OUT");
				sendData('\r');
				_delay_ms(250) ;
				LCD_void_clear() ;
				LCD_void_sendString("LOG IN") ;
				sendString("LOG IN");
				sendData('\r');
				_delay_ms(250) ;
				LCD_void_clear() ;
				control_door('I') ;
				control_AC(40) ;
				control_dimmer(6) ;
				trial_num = 0 ;
				timer0_counter = 0 ;
				password_counter = 0 ;
				compare_password = 0 ;
				entered_password = 0 ;
				current_password = 0 ;
				DIO_set(BUZZER, DIO_LOW) ;
				DIO_set(MOTOR_IN1, DIO_LOW) ;
				DIO_set(LED_1, OFF) ;
				DIO_set(LED_2, OFF) ;
				DIO_set(LED_3, OFF) ;
				DIO_set(LED_4, OFF) ;
				DIO_set(LED_5, OFF) ;


				break ;
		case '1':
			DIO_set(LED_1, ON) ;
			LCD_void_sendString("LED 1 on") ;
			sendString("LED1 ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '2':
			DIO_set(LED_2, ON) ;
			LCD_void_sendString("LED 2 on") ;
			sendString("LED2 ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '3':
			DIO_set(LED_3, ON) ;
			LCD_void_sendString("LED 3 on") ;
			sendString("LED3 ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '4':
			DIO_set(LED_4, ON) ;
			LCD_void_sendString("LED 4 on") ;
			sendString("LED4 ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '5':
			DIO_set(LED_5, ON) ;
			LCD_void_sendString("LED 5 on") ;
			sendString("LED5 ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'C':
			DIO_set(LED_1, OFF) ;
			LCD_void_sendString("LED 1 off") ;
			sendString("LED1 OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'D':
			DIO_set(LED_2, OFF) ;
			LCD_void_sendString("LED 2 off") ;
			sendString("LED2 OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'E':
			DIO_set(LED_3, OFF) ;
			LCD_void_sendString("LED 3 off") ;
			sendString("LED3 OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'F':
			DIO_set(LED_4, OFF) ;
			LCD_void_sendString("LED 4 off") ;
			sendString("LED4 OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'G':
			DIO_set(LED_5, OFF) ;
			LCD_void_sendString("LED 5 off") ;
			sendString("LED5 OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
	}
}

void control_alarm(uint8 on_off)
{
	DIO_set(BUZZER, on_off) ;
	if (on_off)
	{
		sendString("INTRUDER!!");
		sendData('\r');
	}
}

void control_dimmer(uint8 level)
{
	switch(level)
	{
		case '6':
			level = DIMMER_1 ;
			sendString("Dimmer OFF");
			LCD_void_sendString("Dimmer OFF") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '7':
			level = DIMMER_2 ;
			sendString("Dimmer 25%");
			LCD_void_sendString("Dimmer 25%") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '8':
			level = DIMMER_3 ;
			sendString("Dimmer 50%");
			LCD_void_sendString("Dimmer 50%") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case '9':
			level = DIMMER_4 ;
			sendString("Dimmer 75%");
			LCD_void_sendString("Dimmer 75%") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'A':
			level = DIMMER_5 ;
			sendString("Dimmer MAX");
			LCD_void_sendString("Dimmer MAX") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
	}
	Set_Up_DUTY_Timer2(level) ; //set duty according to light level
}

void control_AC(uint8 temperature)
{
	static uint8 on_count = 0 ;
	static uint8 off_count = 0 ;
	TIMER0_Start(clk64) ;
	if (temperature <=28)
	{
		//off_count = 1 ;
		Set_Up_DUTY(AC_OFF);
		/*if (off_count == 1)
		{
			LCD_void_sendString("AC OFF") ;
			sendString("AC OFF");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
		}
		on_count = 0 ;*/
	}
	else
	{

		//on_count = 1 ;
		Set_Up_DUTY(AC_ON);
		/*if (on_count  == 1)
		{
			LCD_void_sendString("AC ON") ;
			sendString("AC ON");
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
		}*/
	}

}

void control_door(uint8 command)
{
	fl duty ;
	switch(command)
	{
		case 'H':
			duty = DOOR_OPEN ;
			sendString("Door is Open");
			LCD_void_sendString("Door is Open") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
		case 'I':
			duty = DOOR_CLOSE ;
			sendString("Door is Closed");
			LCD_void_sendString("Door is Closed") ;
			sendData('\r');
			_delay_ms(250) ;
			LCD_void_clear() ;
			break ;
	}
	SetTimer1Duty(duty) ;
}
