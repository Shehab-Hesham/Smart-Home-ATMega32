/*
 * PROTOTYPES.h
 *
 *  Created on: Nov 4, 2023
 *      Author: SHAHB
 */

#ifndef DRIVERS_MCAL_UART_PROTOTYPES_H_
#define DRIVERS_MCAL_UART_PROTOTYPES_H_

#include "..\..\STD.h"


void UART_init () ;
uint8 receiveData () ;
void sendData (uint8 data) ;
void sendString(uint8 * string) ;
void receiveString(uint8 *buffer, uint8 bufferSize) ;
#endif /* DRIVERS_MCAL_UART_PROTOTYPES_H_ */
