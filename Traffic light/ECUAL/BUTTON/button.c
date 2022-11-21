/*
 * button.c
 *
 * Created: 05/11/2022 01:44:16 م
 *  Author: mahmoud
 */ 

#include "button.h"

//initializing the button function
EN_ButtonErrors_t ButtonInt(char PORT_N, uint8_t PIN_N)
{
	// initializing pin N port N as intput and checking for error
	if(InitializePin(PORT_N, PIN_N, Input) != DIO_OK)
	{
		return BUTTON_ERROR;
	}
	return BUTTON_OK;
}

//checking the button state function
EN_ButtonErrors_t ButtonState(char PORT_N, uint8_t PIN_N, PIN_Value_t* Pin_statue)
{
	//1-reading pin N port N value and checking for error
	if(ReadPin(PORT_N, PIN_N, Pin_statue) != DIO_OK)
	{
		return BUTTON_ERROR;
	}
	return BUTTON_OK;
}
