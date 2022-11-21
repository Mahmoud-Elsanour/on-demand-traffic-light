/*
 * led.c
 *
 * Created: 05/11/2022 01:43:59 م
 *  Author: mahmoud
 */ 

#include "led.h"

//initializing the led function
EN_LedErrors_t LedInt(char PORT_N, uint8_t PIN_N)
{
	// initializing pin N port N as output and checking for error
	if(	InitializePin(PORT_N, PIN_N, Output) != DIO_OK)
	{
		return LED_ERROR;
	}
	return LED_OK;
}

//changing the led value to on function
EN_LedErrors_t LedOn(char PORT_N, uint8_t PIN_N)
{
	//writing 1 on pin N port N and checking for error
	if(ChangePinValue(PORT_N, PIN_N, High) != DIO_OK)
	{
		return LED_ERROR;
	}
	return LED_OK;
}

//changing the led value to off function
EN_LedErrors_t LedOff(char PORT_N, uint8_t PIN_N)
{
	//writing 0 on pin N port N and checking for error
	if(ChangePinValue(PORT_N, PIN_N, Low) != DIO_OK)
	{
		return LED_ERROR;
	}
	return LED_OK;
}