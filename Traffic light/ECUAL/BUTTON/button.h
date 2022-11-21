/*
 * button.h
 *
 * Created: 05/11/2022 01:45:00 م
 *  Author: mahmoud
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//1-Including the lower layer:
	#include "../../MCAL/DIO/dio.h"
	#include "../../MCAL/INTERRUPT/interrupth.h"
	#include "../../MCAL/TIMER/timer.h"

//2-Defining:

//A)Enums
	typedef enum Button_Errors{BUTTON_ERROR, BUTTON_OK} EN_ButtonErrors_t; //Enum to save the error number

//B)Prototypes
	//initializing the button //
	EN_ButtonErrors_t ButtonInt(char PORT_N, uint8_t PIN_N);
	//checking the button state//
	EN_ButtonErrors_t ButtonState(char PORT_N, uint8_t PIN_N, PIN_Value_t* Pin_statue);

#endif /* BUTTON_H_ */