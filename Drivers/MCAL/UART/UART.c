/*
 * UART.c
 *
 *  Created on: Nov 4, 2023
 *      Author: SHAHB
 */

#include "..\..\STD.h"
#include "../../BITMATH.h"
#include "..\DIO/DIO_AD.h"
#include "PROTOTYPES.h"
#include "UART_PRIV.h"
#include "UART_CINFIG.h"


void UART_init ()
{
	CLEAR_BIT(UCSRB, RXCIE) ;
	CLEAR_BIT(UCSRB, TXCIE) ;
	CLEAR_BIT(UCSRB, UDRIE) ;
	SET_BIT(UCSRB, RXEN) ;
	SET_BIT(UCSRB, TXEN) ;

	uint8 dummy = 0x00 ;
	dummy = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) ;
	UCSRC_UBRRH = dummy ;

	UCSRC_UBRRH = 0x00 ;
	UBRRL = 103 ;

}
uint8 receiveData ()
{
	uint32 dummyTime = 0xFFFFFFFF ;
	while(!GET_BIT(UCSRA, RXC))
	{
		dummyTime-- ;
		if (dummyTime == 0)
			return 'x'  ;
	}
	return UDR ;
}
void sendData (uint8 data)
{
	while (!GET_BIT(UCSRA, UDRE)) ;
	UDR = data ;
}
void sendString(uint8 * string)
{
	int count = 0;
	while (string[count] != '\0')
	{
		sendData(string[count]) ;
		count ++ ;
	}
}
void receiveString(uint8 *buffer, uint8 bufferSize)
{
    uint8 receivedChar;
    uint8 index = 0;

    do
    {
        receivedChar = receiveData();
        buffer[index++] = receivedChar;

        if (index >= (bufferSize - 1) || receivedChar == '\n' || receivedChar == '\r')
        {
            buffer[index] = '\0';
            return;
        }

    } while (receivedChar != 'x');
}
