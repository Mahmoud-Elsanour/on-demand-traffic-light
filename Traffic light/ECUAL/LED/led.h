/*
 * led.h
 *
 * Created: 05/11/2022 01:43:46 م
 *  Author: mahmoud
 */ 


#ifndef LED_H_
#define LED_H_

//1-Including the lower layer:
	#include "../../MCAL/DIO/dio.h"

//2-Defining:

//A)Enums
	typedef enum Led_Errors{LED_ERROR, LED_OK} EN_LedErrors_t; //Enum to save the error number

//B)Prototypes	

	//initializing the led//
	EN_LedErrors_t LedInt(char PORT_N, uint8_t PIN_N);
	
	//changing the led value to on//
	EN_LedErrors_t LedOn(char PORT_N, uint8_t PIN_N);
	
	//changing the led value to off//
	EN_LedErrors_t LedOff(char PORT_N, uint8_t PIN_N);
	
#endif /* LED_H_ */