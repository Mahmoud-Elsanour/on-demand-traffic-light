/*
 * new_app.c
 *
 * Created: 13/11/2022 06:07:27 م
 *  Author: Mahmoud
 */ 

#include "App.h"

int case_detector = 0; //variable to choose in switch
volatile int NoInterrupt = 1; //variable to prevent double click
int renew_delay = 0; //to make a new delay
int interrupt_case_3 = 0; // to detect that we are in interrupt case 3

//app initializing function
void AppInit()
{
	//1- initializing:
	//button//
	ButtonInt(PORT_D,PIN_2);
	//led 0//
	LedInt(PORT_A,PIN_0);
	//led 1//
	LedInt(PORT_A,PIN_1);
	//led 2//
	LedInt(PORT_A,PIN_2);
	//led 3//
	LedInt(PORT_A,PIN_3);
	//led 4//
	LedInt(PORT_A,PIN_4);
	//led 5//
	LedInt(PORT_A,PIN_5);
	//timer 0//
	IntializeTimer_0();
	//interrupt//
	EnableInterrupt_0();
}
//app start function
void AppStart()
{
	while(1)
	{
		//2- select the mode
		switch(case_detector)
		{
//////////////////////////////////////////////// start of normal mode//////////////////////////////////////////////
			
///////////////////////////////////////// cars green on & pedestrian red on ///////////////////////////////////////
			case 0:
			//1- led 5(pedestrian red) on
			LedOn(PORT_A,PIN_5);
			
			//2- led 0(car green) on
			LedOn(PORT_A,PIN_0);
			
			//3- setting that theres no interrupt in process
			NoInterrupt = 1;
			
			//4- 5 seconds delay
			Timer_0_Delay_5_Seconds();
			
			//5- going to the next case
			case_detector++;
			break;
			
			
///////////////////////// cars yellow on (& pedestrian yellow on if there is an interrupt) ////////////////////////
			case 1:
			//1- led 1(car yellow) (and led 4(pedestrian yellow)  if there's an interrupt)  blinking each 0.5 seconds
			for (int i = 0; i < 10; i++ )
			{
				//led 1(car yellow) on
				LedOn(PORT_A,PIN_1);
				
				//interrupt case: led 4 (pedestrian yellow) on if there's an interrupt
				if(NoInterrupt == 0)
				LedOn(PORT_A,PIN_4);
				
				//0.5 second delay
				Timer_0_Delay_quarter_Seconds();
				
				//led 1(car yellow) off
				LedOff(PORT_A,PIN_1);
				
				//interrupt case: led 4 (pedestrian yellow) off if there's an interrupt
				if(NoInterrupt == 0)
				LedOff(PORT_A,PIN_4);
				
				//0.5 second delay
				Timer_0_Delay_quarter_Seconds();
			}
			
			//2- led 2(car green) off
			LedOff(PORT_A,PIN_0);
			
			//interrupt case: led 5 (pedestrian red) off 
			if(NoInterrupt == 0)
			LedOff(PORT_A,PIN_5);
			
			//3- going to the next case
			case_detector++;
			break;
			
			
/////////////////////////// cars red on (& pedestrian green on if there is an interrupt) //////////////////////////
			case 2:
			//interrupt case: led 5 (pedestrian red) off
			if(NoInterrupt == 0)
			LedOff(PORT_A,PIN_5);
			
			//1- led 2(car red) on
			LedOn(PORT_A,PIN_2);
			
			//interrupt case: led 3 (pedestrian green) on
			if(NoInterrupt == 0)
			LedOn(PORT_A,PIN_3);
			
			//2- 5 seconds delay
			Timer_0_Delay_5_Seconds();
			
			//interrupt case: making a new delay
			if(renew_delay == 1)
			{
				Timer_0_Delay_5_Seconds();
				renew_delay = 0;
			}
			
			
			//3- going to the next case
			case_detector++;
			break;
			
			
///////////////////////// cars yellow on (& pedestrian yellow on if there is an interrupt) ////////////////////////
			case 3:
			//1- led 1(car yellow) (and led 4(pedestrian yellow)  if there's an interrupt)  blinking each 0.5 seconds
			for (int i = 0; i < 10; i++ )
			{
				//led 1(car yellow) on
				LedOn(PORT_A,PIN_1);
				
				//interrupt case: led 4 (pedestrian yellow) on if there's an interrupt
				if(NoInterrupt == 0)
				LedOn(PORT_A,PIN_4);
				
				//0.5 second delay
				Timer_0_Delay_quarter_Seconds();
				
				//led 1(car yellow) off
				LedOff(PORT_A,PIN_1);
				
				//interrupt case: led 4 (pedestrian yellow) off if there's an interrupt
				if(NoInterrupt == 0)
				LedOff(PORT_A,PIN_4);
				
				//0.5 second delay
				Timer_0_Delay_quarter_Seconds();
			}
			
			//2- led 0 (car red) off
			LedOff(PORT_A,PIN_2);
			
			//interrupt case: led 3 (pedestrian green) off
			if(NoInterrupt == 0)
			LedOff(PORT_A,PIN_3);
			
			//interrupt case: go to case 2 (car red on & pedestrian green on)
			if(interrupt_case_3 == 1)
			{
				case_detector++;
				interrupt_case_3 = 0;
				break;
			}
			
			
			//3- go back to case 0 (normal mode)
			case_detector = 0;
			break;
		}
	}
}

ISR(EXT_INT_0)
{
	//1-when there is an external interrupt 0:
	
	//2-checking if there is no interrupt in process
	if (NoInterrupt == 1)
	{
		//3- setting that theres an interrupt in process
		NoInterrupt = 0;
		
		//4- checking the case we were in:
		
		//5- if case 0 (car green on)
		if(case_detector == 0)
		{
			//6- stopping the delay
			BreakTimer();
		}
		
		//5- if case 1 (car yellow on going to car red)
		else if(case_detector == 1)
		{
			//6- led 4 (pedestrian yellow) on
			LedOn(PORT_A,PIN_4);
		}
		
		//5- if case 3 (car yellow on going to car green)
		else if(case_detector == 3)
		{
			//6- led 4 (pedestrian yellow) on
			LedOn(PORT_A,PIN_4);
			//7- go to case 2 after finishing the current case
			case_detector = 1 ;//note: the current case will add one
			interrupt_case_3 = 1;//to enable going to case 2
		}
		
		//5- if case 2 (car red on)
		else if (case_detector == 2)
		{
			//6- stopping the delay
			BreakTimer();
			//7- led 5(pedestrian red) off
			LedOff(PORT_A,PIN_5);
			//8- led 3 (pedestrian green) on
			LedOn(PORT_A,PIN_3);
			//9- make a new delay
			renew_delay = 1;
		}
	}
}