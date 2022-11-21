/*
 * interrupth.h
 *
 * Created: 05/11/2022 01:48:01 م
 *  Author: mahmoud
 */ 

#ifndef INTERRUPTH_H_
#define INTERRUPTH_H_

//1-Including the lower layer:
#include "../../MICROCONTROLLER/UTILITIES/register.h"

//2-Defining:

//A) vectors
#define EXT_INT_0	__vector_1

//B)Interrupt Service Routine (ISR)
#define ISR(INT_VECT) \
void INT_VECT (void)__attribute__((signal,used)); \
void INT_VECT (void) 

//C)Enums
typedef enum interrupt_error{INTERRUPT_ERROR, INTERRUPT_OK} EN_InterruptError_t;

//D)Prototypes

//Enabling external interrupt 0//
EN_InterruptError_t EnableInterrupt_0();

#endif /* INTERRUPTH_H_ */