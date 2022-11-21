/*
 * button_test.c
 *
 * Created: 14/11/2022 12:18:51 ص
 *  Author: Mahmoud
 */ 
/*
//1-Including the lower layers:
#include "../LED/led.h"
#include "button.h"

PIN_Value_t Button_state;//variable to save pin 1 value

int main(void)
{
	//2- initializing the button in pin 2 port D
	ButtonInt(PORT_D, PIN_2);
	//3-initializing pin 0 port A
	LedInt(PORT_A, PIN_0);	
	while(1)
	{
		//4-getting the button value
		ButtonState(PORT_D, PIN_2, &Button_state);
		//5-turning led 0 port B on if it is pressed
		if(Button_state == High)
		LedOn(PORT_A, PIN_0);
		else
		LedOff(PORT_A, PIN_0);
	}
}
*/