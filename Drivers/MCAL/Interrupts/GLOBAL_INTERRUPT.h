/*
 * GLOBAL_INTERRUPT.h
 *
 *  Created on: Oct 14, 2023
 *      Author: SHAHB
 */

#ifndef GLOBAL_INTERRUPT_H_
#define GLOBAL_INTERRUPT_H_

#define SREG ( *(uint8 *) 0x5F )
#define SREG_GIENABLE 7


void set_global_interrupt() ;
void clear_global_interrupt() ;

#endif /* GLOBAL_INTERRUPT_H_ */
