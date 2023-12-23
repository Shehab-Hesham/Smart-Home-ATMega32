/*
 * I2C.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Mohamed_onga
 */
#include "I2C.h"


void I2C_init()
{
	TWBR =72;
}

void I2C_Start_Send()
{
	TWCR  = (1<<TWCR_TWINT_BIT)|(1<<TWCR_TWSTA_BIT)|
	(1<<TWCR_TWEN_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT)))
	{

	}

}
void I2C_Send(uint8 DATA)
{
	TWDR = DATA;
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
}
uint8  I2C_Recive_ACK()
{
	TWCR = (1<<TWCR_TWINT_BIT)|(1<<TWCR_TWEN_BIT)| (1<<TWCR_TWEA_BIT) ;
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0)
	{

	}
	return TWDR;
}
uint8 I2C_Recive_No_ACK()
{
	TWCR = (1<<TWCR_TWINT_BIT)|(1<<TWCR_TWEN_BIT);
	while(GET_BIT(TWCR,TWCR_TWINT_BIT)==0)
	{

	}
	return TWDR;
}
void I2C_Sent_Address(uint8 address,uint8 statues)
{
	TWDR = address<<1;

	if (statues== Read)
	{
		SET_BIT(TWCR,TWDR_TWD0_BIT);
	}
	else if(statues == Write)
	{
		CLEAR_BIT(TWCR,TWDR_TWD0_BIT);
	}
	TWCR = (1<<TWCR_TWINT_BIT) | (1<<TWCR_TWEN_BIT);
	while (!(TWCR & (1<<TWCR_TWINT_BIT))) ;
}
void I2C_Stop_Send()
{
	TWCR = (1<<TWCR_TWINT_BIT)|(1<<TWCR_TWEN_BIT)|
	(1<<TWCR_TWSTO_BIT);
}
