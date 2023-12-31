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
uint8 current_password=0; //current password is the number that you enter each time )entered key but in integer)
uint16 entered_password=0 ; //entered password is the full password that is being compared with set password
uint16 compare_password ;
uint8 password_counter = 0 ; //flag raised when password entered correctly, enables control over house
uint8 trial_num = 0 ; //trial tp track when to block
uint16 timer0_counter = 0 ;
uint16 temp ; //ADC reading representing temperature
uint8 key ; //char input of keypadd
uint8 light_level ;
uint8 command_recieve ; //UART user input
uint8 *data;
uint8 admin_flag = 0; //admin flag
uint8 flag = 0 ; //blocking flag

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

	//set all LEDs as outputs
	DIO_direction(LED_1, DIO_OUTPUT) ;
	DIO_direction(LED_2, DIO_OUTPUT) ;
	DIO_direction(LED_3, DIO_OUTPUT) ;
	DIO_direction(LED_4, DIO_OUTPUT) ;
	DIO_direction(LED_5, DIO_OUTPUT) ;

	//set buzzer as output
	DIO_direction(BUZZER, DIO_OUTPUT) ;

	//set motor pins connected to H-Brideg as output
	DIO_direction(MOTOR_IN1, DIO_OUTPUT) ;
	DIO_direction(MOTOR_IN2, DIO_OUTPUT) ;

	DIO_set(MOTOR_IN2, DIO_LOW) ;

	//Initialize LCD and KEYPAD
	LCD_void_init() ;
	KEYPAD_init();


	//Interrupt
	INTERRUPT_MODE_SET(INT1, INT1_RISING) ; //sensitive to rising edge
	setCallback(clearAfter) ; //ISR calls function to reset system by setting a pointer to function
	set_global_interrupt() ; //raise global interrupt to initialize

	//Timer2
	TIMER2_init_Mode(TIMER2_PWM);
	OC2_MODE(OC2_CLEAR);
	setCallbackTimer2(DIMMER) ; //ISR Timer2 to control Dimmer LED
	TIMER2_Start(clk1024) ; //prescaler set last thing to start timer after correct configuration

	//Timer1
	TIMER1_initMode(fastPWM);
	SetOutputMode(NonInverting); //operating mode
	SetFrequancyTimer1(50); //operating frequency suitable for servo motor
	TIMER1_Start(64); //prescaler set last thing to start timer after correct configuration

	//Timer0
	TIMER0_init_Mode(FastPWM) ;
	OC0_MODE(Clear) ;
	Timer0_setCallback(AC) ;


	//Initialize ADC and UART
	ADC_void_Init() ;
	UART_init() ;

	control_dimmer('6') ; //ensure dimmer is closed

	//password_counter = 4 ;
	//compare_password = 1234 ;
	//command_recieve = '0' ;
	jump:
	LCD_void_sendString("Enter Password") ;
	_delay_ms(100);
	LCD_void_clear() ;

	while (1)
	{
		if (trial_num == 3) //if password was entered incorrectly 3 times
		{ //nothing can be done until reset button is pressed
			if (flag == 0) //in order not to print blocked many times
			{
				flag = 1 ;
				LCD_void_clear() ;
				LCD_void_sendString("Blocked") ;
				DIO_set(MOTOR_IN1, DIO_LOW) ;
				control_alarm(ON) ;
				_delay_ms(500) ;
			}
		}
		else
		{
		    key = KEYPAD_read() ; //user input as char
		    control_AC(0) ; //AC off
		  	if(key != UNPRESSED && key!='=')
			{
			  current_password = key - 48; //char to int
				LCD_void_sendNum( current_password);
				entered_password = current_password+ entered_password*10;
				TIMER0_SetTimerPreload(0) ; //turn off AC by setting TCNT0 to 0
				while (key== KEYPAD_read()){} //for debouncing avoidance
		    }
			else if(key=='=') //user finished entering password
			{
				LCD_void_clear();
				while (key== KEYPAD_read()){} //debouncing
				LCD_void_clear() ;

				//Read from EEPROM passwords for admin and users
				uint8 u = Read_EEPROM(11,data);
				uint8 a = Read_EEPROM(13,data);
				uint8 u2 = Read_EEPROM(16,data);

				if(entered_password == u || entered_password == a ||entered_password == u2)
				{
					if (entered_password == a)
					{
						LCD_void_sendString("Correct, Admin") ;
						//EEPROM_write(entered_password, 13) ;  //save password to EEPROM
						admin_flag = 1; //admin
					}
					else if (entered_password == u)//user
					{
						LCD_void_sendString("Correct, User1") ;
						//EEPROM_write(entered_password, 11) ;  //save password to EEPROM
						admin_flag = 0; //entered passsword for user 2
					}
					else //if (entered_password == u2)//user
					{
						LCD_void_sendString("Correct, User2") ;
						//EEPROM_write(entered_password, 11) ;  //save password to EEPROM
						admin_flag = 0; //entered password for user 2
					}
					DIO_set(MOTOR_IN1, DIO_HIGH) ; //enable one of H-Bridge pins to enable AC
					password_counter =1 ; //flag of correct password set
					while (password_counter	)
					{
						//calculate measured temperature from ADc
						temp = ADC_u16_read(ADC1) ;
						temp /= 2 ;
						temp -= 1 ;
						control_AC(temp) ;
						_delay_ms(500) ;
						LCD_void_clear() ;
						command_recieve = receiveData(); //receive commands from UART to control House features
						if (command_recieve !='x') //'x' is equivalent to nothing sent
						{
							//LCD_void_sendData(command_recieve) ;
							if (command_recieve == '0') //Log Out
							{
								current_password=0 ;
								entered_password = 0 ;
								clearAll() ; //logout system
								goto jump; //start over
							}
							//ranges to turn LEDs on/off
							 if ((command_recieve >= '1' && command_recieve <=  '5') || (command_recieve >= 'C' && command_recieve <= 'G'))
							{
								control_LEDS(command_recieve) ;
							}
							//range to turn dimmer on/off
							if (command_recieve >= '6' && command_recieve <=  'A')
							{
								control_dimmer(command_recieve) ;
							}
							//#if MODE ADMIN
							if (admin_flag)
							{ //control door only accessible to admin
								if (command_recieve == 'H' || command_recieve == 'I') //Log Out
								{
									control_door(command_recieve) ;
								}
							}
							//#endif
						}

					//reset password variables
					current_password = 0 ;
					entered_password = 0 ;
					}
				}
				else //entered each time password entered incorrectly
				{
					entered_password = 0 ;
					trial_num++ ; //increase number of trials in order to block (at 3)
					LCD_void_sendString("Wrong Password") ;
					_delay_ms(500) ;
					LCD_void_clear() ;
					compare_password = 0 ; //start over password calculation
				}

			}

		}
	}
}
