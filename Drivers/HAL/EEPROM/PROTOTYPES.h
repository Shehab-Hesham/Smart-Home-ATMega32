/*
 * EPROM.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Mohamed_onga
 */

#ifndef HAL_EPROM_EPROM_H_
#define HAL_EPROM_EPROM_H_

#include "../../MCAL/I2C/I2C_HW.h"
#include "..\..\STD.h"
#include "..\..\BITMATH.h"

uint8* Read_EEPROM(uint16 loc,uint8* DATA);
void Write_EEPROM(uint16 loc ,uint8 data);
void EEPROM_Init();
void Read_Buffer_EEPROM(uint8* Buffer,uint16 loc,uint16 count );
void Write_Buffer_EEPROM(uint8 *Buffer, uint16 loc,uint8 count );
#endif /* HAL_EPROM_EPROM_H_ */
