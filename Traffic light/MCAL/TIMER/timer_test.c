/*
 * timer_test.c
 *
 * Created: 13/11/2022 11:38:25 م
 *  Author: Mahmoud
 */ 
/*
//1-Including the lower layer:
#include "../DIO/dio.h"
#include "timer.h"

 int main(void)
 {
	 //1- initializing pin 0,1 as outputs
	 InitializePin(PORT_A, PIN_0, Output);
	 InitializePin(PORT_A, PIN_1, Output);
	 
	 //2-initializing timer 0
	 IntializeTimer_0();
	 
	 while(1)
	 {
		 //3-writing 0 on pin 1 port A
		 ChangePinValue(PORT_A, PIN_1, Low);
		 //4-writing 1 on pin 0 port A
		 ChangePinValue(PORT_A, PIN_0, High);
		 //5-generating 5 seconds delay
		 Timer_0_Delay_5_Seconds();
		 //6-writing 0 on pin 0 port A
		 ChangePinValue(PORT_A, PIN_0, Low);
		 //7-writing 1 on pin 1 port A
		 ChangePinValue(PORT_A, PIN_1, High);
		 //8-generating 5 seconds delay
		 Timer_0_Delay_5_Seconds();
	 }
 }
*/