/*
 * timer.c
 *
 * Created: 05/11/2022 01:49:00 م
 *  Author: mahmoud
 */ 

#include "timer.h"

volatile int stop_timer0 = 0; //used in break delay

//initializing timer 0 function
EN_TimerErrors_t IntializeTimer_0()
{
	//1-choosing the mood
	TCCR0 = 0x00;
	//2-setting timer start value
	TCNT0 = 0x00;
	
	return TIMER_OK; //returning no error
}

//starting timer 0 function
EN_TimerErrors_t StartTimer_0()
{
	//3-setting the prescaler
	TCCR0 |= (1<<0);
	*(&stop_timer0) = 0;
	
	return TIMER_OK; //returning no error
}

//stopping timer 0 function
EN_TimerErrors_t StopTimer_0()
{
	//1-setting timer/counter control register to 0
	TCCR0 = 0x00;
	
	return TIMER_OK; //returning no error
}

//breaking the delay loop function
EN_TimerErrors_t BreakTimer()
{
	*(&stop_timer0) = 1;
	
	return TIMER_OK; //returning no error
}

//generating 5 seconds delay with timer 0 function
EN_TimerErrors_t Timer_0_Delay_5_Seconds()
{
	//1-starting timer 0
	StartTimer_0();
	
	long int Overflow_Counter = 0; //a variable to keep track of numbers of overflows
	
	//2-busy wait loop
	while (Overflow_Counter < 19531)
	{
		if (stop_timer0 == 1)
		break;
		
		while((TIFR & (1<<0) ) == 0); //busy wait for the overflow flag
		TIFR |= (1<<0);            //resetting the overflow flag
		Overflow_Counter++;        //increasing the overflow numbers by 1
	}
	
	//3-stopping the timer
	StopTimer_0();
	
	return TIMER_OK; //returning no error
}

//generating 0.25 seconds delay with timer 0 function
EN_TimerErrors_t Timer_0_Delay_quarter_Seconds()
{
	//1-starting timer 0
	StartTimer_0();
	
	long int Overflow_Counter = 0; //a variable to keep track of numbers of overflows
	
	//2-busy wait loop
	while (Overflow_Counter < 976)
	{
		if (stop_timer0 == 1)
		break;
		
		while((TIFR & (1<<0)) == 0); //busy wait for the overflow flag
		TIFR |= (1<<0);			   //resetting the overflow flag
		Overflow_Counter++;		   //increasing the overflow numbers by 1
	}
	
	//3-stopping the timer
	StopTimer_0();
	
	return TIMER_OK; //returning no error
}
