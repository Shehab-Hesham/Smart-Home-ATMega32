/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: SHAHB
 */
#include "PROTOTYPES.h"
//#define MODE ADMIN

uint16 password_user  ; //= 21;
uint16 password_admin ; //= 123;
uint16 password_user2 ; //= 22;
uint8 current_password=0;
uint16 entered_password=0 ;
uint16 compare_password ;
uint8 password_counter = 0 ;
uint8 trial_num = 0 ;
uint16 timer0_counter = 0 ;
uint16 temp ;
uint8 key ;
uint8 light_level ;
uint8 command_recieve ;
uint8 *data;
uint8 admin_flag = 0;
void AC()
{
	control_AC(temp) ;
}
void DIMMER()
{
	control_dimmer(light_level) ;
}

int main ()
{

	EEPROM_Init() ;

//	Write_EEPROM(11,password_user) ;
//	_delay_ms(100) ;
//	Write_EEPROM(16,password_user2) ;
//	_delay_ms(100);
//	Write_EEPROM(13 ,password_admin) ;

	DIO_direction(LED_1, DIO_OUTPUT) ;
	DIO_direction(LED_2, DIO_OUTPUT) ;
	DIO_direction(LED_3, DIO_OUTPUT) ;
	DIO_direction(LED_4, DIO_OUTPUT) ;
	DIO_direction(LED_5, DIO_OUTPUT) ;

	DIO_direction(BUZZER, DIO_OUTPUT) ;

	DIO_direction(MOTOR_IN1, DIO_OUTPUT) ;
	DIO_direction(MOTOR_IN2, DIO_OUTPUT) ;

	DIO_set(MOTOR_IN2, DIO_LOW) ;

	LCD_void_init() ;
	KEYPAD_init();


	//Interrupt
	INTERRUPT_MODE_SET(INT1, INT1_RISING) ;
	setCallback(clearAfter) ;
	set_global_interrupt() ;

	//Timer2
	TIMER2_init_Mode(TIMER2_PWM);
	OC2_MODE(OC2_CLEAR);
	setCallbackTimer2(DIMMER) ;
	TIMER2_Start(clk1024) ;

	//Timer1
	TIMER1_initMode(fastPWM);
	SetFrequancyTimer1(50) ;
	SetOutputMode(NonInverting);
	SetFrequancyTimer1(50);
	TIMER1_Start(64);

	//Timer0
	TIMER0_init_Mode(FastPWM) ;
	OC0_MODE(Clear) ;
	Timer0_setCallback(AC) ;


	ADC_void_Init() ;
	UART_init() ;

	control_dimmer('6') ;

	//password_counter = 4 ;
	//compare_password = 1234 ;
	//command_recieve = '0' ;
	jump:
	LCD_void_sendString("Enter Password") ;
	_delay_ms(100);
	LCD_void_clear() ;

	while (1)
	{
		key = KEYPAD_read() ;
		control_AC(0) ;

		  if(key != UNPRESSED && key!='=')
			{
			  current_password = key - 48;
				LCD_void_sendNum( current_password);
				entered_password = current_password+ entered_password*10;
				TIMER0_SetTimerPreload(0) ;
				while (key== KEYPAD_read()){}
			}
			else if(key=='=')
		{
				LCD_void_clear();
				while (key== KEYPAD_read()){}
			LCD_void_clear() ;
             uint8 u = Read_EEPROM(11,data);
             uint8 a = Read_EEPROM(13,data);
             uint8 u2 = Read_EEPROM(16,data);

			if(entered_password == u || entered_password == a ||entered_password == u2)
			{
				if (entered_password == a)
				{
					LCD_void_sendString("Correct, Admin") ;
					//EEPROM_write(entered_password, 13) ;  //save password to EEPROM
					admin_flag = 1;
				}
				else if (entered_password == u)//user
				{
					LCD_void_sendString("Correct, User1") ;
					//EEPROM_write(entered_password, 11) ;  //save password to EEPROM
					admin_flag = 0;
				}
				else //if (entered_password == u2)//user
				{
					LCD_void_sendString("Correct, User2") ;
					//EEPROM_write(entered_password, 11) ;  //save password to EEPROM
					admin_flag = 0;
				}
				DIO_set(MOTOR_IN1, DIO_HIGH) ;
				password_counter =1 ;
				while (password_counter	)
				{
					temp = ADC_u16_read(ADC1) ;
					temp /= 2 ;
					temp -= 1 ;
					//control_AC(temp) ;
					//LCD_void_sendNum(temp) ;
					control_AC(temp) ;
					_delay_ms(500) ;
					LCD_void_clear() ;
					command_recieve = receiveData();
					if (command_recieve !='x')
					{
						//LCD_void_sendData(command_recieve) ;
						if (command_recieve == '0') //Log Out
						{
							current_password=0 ;
							entered_password = 0 ;
							control_LEDS(command_recieve) ;
							goto jump;
						}
						 if ((command_recieve >= '1' && command_recieve <=  '5') || (command_recieve >= 'C' && command_recieve <= 'G'))
						{
							control_LEDS(command_recieve) ;
						}
						if (command_recieve >= '6' && command_recieve <=  'A')
						{
							control_dimmer(command_recieve) ;
						}
						//#if MODE ADMIN
						if (admin_flag)
						{
							if (command_recieve == 'H' || command_recieve == 'I') //Log Out
							{
								control_door(command_recieve) ;
							}
						}
						//#endif
					}

				current_password = 0 ;
				entered_password = 0 ;
			}
		}
			else
			{
				entered_password = 0 ;
				trial_num++ ;
				LCD_void_sendString("Incorrect Password") ;
				_delay_ms(500) ;
				LCD_void_clear() ;
				compare_password = 0 ;
			}
			if (trial_num == 3)
			{
				LCD_void_clear() ;
				LCD_void_sendString("Blocked") ;
				control_alarm(ON) ;
				_delay_ms(500) ;

			}
		}

	}
}
