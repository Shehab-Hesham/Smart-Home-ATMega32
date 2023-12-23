
#ifndef SPI_HW_H_
#define SPI_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "..\..\STD.h"

//////////////////////////////////////////////////////////////
#define NOT_RECIEVED 255
/*SPI Registers*/
//SPI Control Register
#define SPCR   	(*((volatile uint8 *)0x2D))
#define SPIE 	7  //SPI Interrupt Enable
#define SPE  	6  //SPI Enable
#define MSTR    4 //Master or slave
#define MASTER  1
#define SLAVE   0

#define SPR1 	1  //SPI Clock Rate Select
#define SPR0	0  //SPI Clock Rate Select

//SPI Status Register
#define SPSR   		(*((volatile uint8 *)0x2E))
#define SPIF	    7  //SPI Interrupt Flag
#define SPI2X	 	0  //Double SPI Speed Bit and used with SPR1 and SPR0 to select clock rate

//SPI Data Register
#define SPDR  (*((volatile uint8 *)0x2F))
///////////////////////////////////////////////////////////////

void SPI_void_INIT(uint8 state) ;
uint8 SPI_uint8_RECIEVE() ;
void SPI_void_SEND(uint8 data) ;

#endif /* SPI_HW_H_ */
