/*
 * timer_test.c
 *
 * Created: 13/11/2022 11:38:25 م
 *  Author: Mahmoud
 */ 
/*
//1-Including the lower layer:
#include "../DIO/dio.h"
#include "interrupth.h"

int x = 0; //variable to use in switch

int main(void)
{
	//1- initializing pin 0,1 port A as outputs and 2 port D as input
	InitializePin(PORT_A, PIN_0, Output);
	InitializePin(PORT_A, PIN_1, Output);
	InitializePin(PORT_D, PIN_2, Input);
	 
	//2-Enabling external interrupt 0
	EnableInterrupt_0();
	
	while(1)
	{
		//checking x value
		switch(x)
		{
			case 0:
			//3-writing 1 on pin 0 port A
			ChangePinValue(PORT_A, PIN_0, High);
			//4-writing 0 on pin 1 port A
			ChangePinValue(PORT_A, PIN_1, Low);
			break;
			 
			case 1:
			//5-writing 0 on pin 0 port A
			ChangePinValue(PORT_A, PIN_0, Low);
			//6-writing 1 on pin 1 port A
			ChangePinValue(PORT_A, PIN_1, High);
			break; 
		}
	}
}

ISR(EXT_INT_0)
{
	if(x == 0)
	x = 1;
	else if(x == 1)
	x = 0;
}
*/
