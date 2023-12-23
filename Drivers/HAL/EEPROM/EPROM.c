/*
 * EEPROM.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Mohamed_onga
 */


#include "PROTOTYPES.h"
#include "..\..\MCAL\DIO\DIO_AD.h"
#include "..\..\STD.h"
#include "../../MCAL/I2C/I2C_HW.h"
void EEPROM_Init()
{
	 I2C_init();
}
void Write_EEPROM( uint16 loc , uint8 data)
{
	uint8 x;
	x = loc>>7;
	x  = x |(0b1010<<4);
	CLEAR_BIT(x,0);
	I2C_Start_Send();
	I2C_Send(x);
	I2C_Send((uint8)loc);
	I2C_Send(data);
	I2C_Stop_Send();

}
uint8* Read_EEPROM(uint16 loc,uint8* DATA)
{
	uint8 x;
	x = loc>>7;
	x = x |(0b1010<<4);
	CLEAR_BIT(x,0);
	//Dumy Write
	I2C_Start_Send();
	I2C_Send(x);
	I2C_Send((uint8)loc);
	SET_BIT(x,0);
	//Read
	I2C_Start_Send();
	I2C_Send(x);
	*DATA= I2C_Recive_No_ACK();
	I2C_Stop_Send();
	return *DATA;

}
void Write_Buffer_EEPROM(uint8 *Buffer, uint16 loc,uint8 count )
{
	uint8 x;
	x = loc>>7;
	x  = x |(0b1010<<4);
	CLEAR_BIT(x,0);
	I2C_Start_Send();
	I2C_Send(x);
	I2C_Send((uint8)loc);

	for(uint16 i = 0 ; i < count ; i++)
	{
		I2C_Send(Buffer[i]);
	}
	I2C_Stop_Send();

}
void Read_Buffer_EEPROM(uint8* Buffer,uint16 loc,uint16 count )
{
	uint8 x;
	x = loc>>7;
	x = x |(0b1010<<4);
	CLEAR_BIT(x,0);
	//Dumy Write
	I2C_Start_Send();
	I2C_Send(x);
	I2C_Send((uint8)loc);
	SET_BIT(x,0);
	//Read
	I2C_Start_Send();
	I2C_Send(x);
	for(uint16 i = 0 ; i < count ; i++)
	{
	     Buffer[i]=I2C_Recive_No_ACK();
	}
	 Buffer[count-1]=I2C_Recive_No_ACK();
	I2C_Stop_Send();


}
