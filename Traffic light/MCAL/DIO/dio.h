/*
 * dio.h
 *
 * Created: 05/11/2022 01:45:17 م
 *  Author: mahmoud
 */ 


#ifndef DIO_H_
#define DIO_H_

//1-Including the lower layer:
	#include "../../MICROCONTROLLER/UTILITIES/macros.h"
	#include "../../MICROCONTROLLER/UTILITIES/register.h"

//2-Defining:

//A)Enums
	typedef enum value{Low = 0, High} PIN_Value_t; //Enum to save the the pin value
	typedef enum statue{Input = 0, Output} PIN_State_t;  //Enum to save the the pin statue
	typedef enum Dio_Errors{PORT_ERROR,VALUE_ERROR, DIO_OK} EN_DioErrors_t; //Enum to save the error number
	
//B)Prototypes
	//initializing the pin//
	EN_DioErrors_t InitializePin(char PORT_N, uint8_t PIN_N, PIN_State_t Pin_statue);	
	//changing the pin value//
	EN_DioErrors_t ChangePinValue(char PORT_N, uint8_t PIN_N, PIN_Value_t Pin_value);
	//reading the pin statue//
	EN_DioErrors_t ReadPin(char PORT_N, uint8_t PIN_N, PIN_Value_t* Pin_statue);

#endif /* DIO_H_ */