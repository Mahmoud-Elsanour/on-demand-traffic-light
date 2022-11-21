/*
 * dio.c
 *
 * Created: 05/11/2022 01:46:51 م
 *  Author: mahmoud
 */ 
#include "dio.h"

//initializing the pin function
EN_DioErrors_t InitializePin(char PORT_N, uint8_t PIN_N, PIN_State_t Pin_statue)
{
	//1-checking whether the state is input or output:
	if(Pin_statue == Output)
	{
		//2-searching for the port
		switch(PORT_N)
		{
			case 'A': DDRA |= (1<<PIN_N); break; //3-changing the pin in port A value to 1
			case 'B': DDRB |= (1<<PIN_N); break; //3-changing the pin in port B value to 1
			case 'C': DDRC |= (1<<PIN_N); break; //3-changing the pin in port C value to 1
			case 'D': DDRD |= (1<<PIN_N); break; //3-changing the pin in port D value to 1
			default: return PORT_ERROR; //return with error if the port data is wrong
		}
	}
	
	else if(Pin_statue == Input)
	{
		//2-searching for the port
		switch(PORT_N)
		{
			case 'A': DDRA &= ~(1<<PIN_N); break; //3-changing the pin in port A value to 0
			case 'B': DDRB &= ~(1<<PIN_N); break; //3-changing the pin in port B value to 0
			case 'C': DDRC &= ~(1<<PIN_N); break; //3-changing the pin in port C value to 0
			case 'D': DDRD &= ~(1<<PIN_N); break; //3-changing the pin in port D value to 0
			default: return PORT_ERROR; //return with error if the port data is wrong
		}
	}
	
	else
	{
		return VALUE_ERROR;//return with error if the state data is wrong
	}
	
	return DIO_OK; //return ok after finishing
}

//setting the pin value function
EN_DioErrors_t ChangePinValue(char PORT_N, uint8_t PIN_N, PIN_Value_t Pin_value)
{
	//1-checking whether the state is high or low:
	if(Pin_value == High)
	{
		//2-searching for the port
		switch(PORT_N)
		{
			case 'A': PORTA |= (1<<PIN_N); break; //3-changing the pin in port A value to 1
			case 'B': PORTB |= (1<<PIN_N); break; //3-changing the pin in port B value to 1
			case 'C': PORTC |= (1<<PIN_N); break; //3-changing the pin in port C value to 1
			case 'D': PORTD |= (1<<PIN_N); break; //3-changing the pin in port D value to 1
			default: return PORT_ERROR;//return with error if the port data is wrong
		}
	}
	else if(Pin_value == Low)
	{
		//2-searching for the port
		switch(PORT_N)
		{
			case 'A': PORTA &= ~(1<<PIN_N); break; //3-changing the pin in port A value to 0
			case 'B': PORTB &= ~(1<<PIN_N); break; //3-changing the pin in port B value to 0
			case 'C': PORTC &= ~(1<<PIN_N); break; //3-changing the pin in port C value to 0
			case 'D': PORTD &= ~(1<<PIN_N); break; //3-changing the pin in port D value to 0
			default: return PORT_ERROR;//return with error if the port data is wrong
		}
	}
	else
	{
		return VALUE_ERROR;//return with error if the value data is wrong
	}
	
	return DIO_OK; //return ok after finishing
}

//reading the pin statue function
EN_DioErrors_t ReadPin(char PORT_N, uint8_t PIN_N, PIN_Value_t* Pin_statue)
{
	//2-searching for the port
	switch(PORT_N)
	{
		case 'A': *Pin_statue = ((PINA & (1<<PIN_N))>>PIN_N); break; //saving the pin statue from port A
		case 'B': *Pin_statue = ((PINB & (1<<PIN_N))>>PIN_N); break; //saving the pin statue from port B
		case 'C': *Pin_statue = ((PINC & (1<<PIN_N))>>PIN_N); break; //saving the pin statue from port C
		case 'D': *Pin_statue = ((PIND & (1<<PIN_N))>>PIN_N); break; //saving the pin statue from port D
		default: return PORT_ERROR;//return with error if the port data is wrong
	}
	
	return DIO_OK; //return ok after finishing
}
