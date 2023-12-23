/*
 * PROTOTYPES.h
 *
 *  Created on: Dec 16, 2023
 *      Author: SHAHB
 */

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include "util/delay.h"
#include "Drivers/STD.h"
#include "Drivers/BITMATH.h"
#include "Drivers/MCAL/DIO/DIO_AD.h"
#include "Drivers/MCAL/Interrupts/GLOBAL_INTERRUPT.h"
#include "Drivers/MCAL/Interrupts/EXT_INTERRUPT.h"
#include "Drivers/MCAL/ADC/ADC_INIT.h"
#include "Drivers/MCAL/Timer/TIMER0_INT.h"
#include "Drivers/MCAL/Timer/MCU_HW_Timer1.h"
#include "Drivers/MCAL/Timer/Timer2.h"
#include "Drivers/MCAL/UART/UART_CINFIG.h"
#include "Drivers/MCAL/UART/UART_PRIV.h"
#include "Drivers/MCAL/UART/PROTOTYPES.h"
#include "Drivers/MCAL/SPI/SPI_HW.h"
#include "Drivers/MCAL/I2C/I2C_HW.h"
#include "Drivers/HAL/EEPROM/PROTOTYPES.h"
#include "Drivers/HAL/Keypad/KEYPAD_INIT.h"
#include "Drivers/HAL/LCD/LCD_Init.h"

//Motor
#define MOTOR_IN1 DIO_A2
#define MOTOR_IN2 DIO_A3

//LEDs
#define LED_1 DIO_C3
#define LED_2 DIO_C4
#define LED_3 DIO_C5
#define LED_4 DIO_C6
#define LED_5 DIO_C7

//Buzzer
#define BUZZER DIO_A0

#define ON DIO_HIGH
#define OFF DIO_LOW

#define OPEN_DOOR 15
#define CLOSE_DOOR 7.5

#define AC_ON 100
#define AC_OFF 0

#define ADMIN 1
#define USER 0

#define DIMMER_5 100
#define DIMMER_4 75
#define DIMMER_3 50
#define DIMMER_2 25
#define DIMMER_1 0

#define DOOR_CLOSE 15
#define DOOR_OPEN 7.5

#define EXIT 0

#define size_command 2


void clearAll() ;
void clearAfter() ;
void control_LEDS(uint8 led_nun) ;
void control_alarm(uint8 on_off) ;
void control_dimmer(uint8 level) ;
void control_AC(uint8 temperature) ;
void control_door(uint8 command) ;


#endif /* PROTOTYPES_H_ */
