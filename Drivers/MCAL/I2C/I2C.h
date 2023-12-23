/*
 * I2C.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Mohamed_onga
 */

#ifndef MC_AL_I2C_I2C_H_
#define MC_AL_I2C_I2C_H_

#include "I2C_HW.h"
void I2C_init();
void I2C_Start_Send();
void I2C_Send(uint8 DATA);
uint8  I2C_Recive_ACK();
uint8 I2C_Recive_No_ACK();
void I2C_Sent_Address(uint8 address,uint8 statues);
void I2C_Stop_Send();

#endif /* MC_AL_I2C_I2C_H_ */
