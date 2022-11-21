/*
 * interrupt.c
 *
 * Created: 05/11/2022 01:47:41 م
 *  Author: mahmoud
 */ 
#include "interrupth.h"

//Enabling external interrupt 0 function
EN_InterruptError_t EnableInterrupt_0()
{
	//1-Enabling interrupts
	SREG |= (1<<7);
	
	//2-setting the interrupt type(falling edge)
	MCUCR |= (0<<0) | (1<<1);
	
	//3-Enabling External interrupt 0
	GICR |= (1<<6);
	
	return INTERRUPT_OK;
}