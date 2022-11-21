/*
 * timer.h
 *
 * Created: 05/11/2022 01:48:16 م
 *  Author: mahmoud
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//1-Including the lower layer:
#include "../../MICROCONTROLLER/UTILITIES/register.h"
#include "../../MICROCONTROLLER/UTILITIES/macros.h"

//2-Defining:

//A)Enums
typedef enum timer_error{TIMER_ERROR, TIMER_OK} EN_TimerErrors_t;

//B)Prototypes

//initializing timer 0//
EN_TimerErrors_t IntializeTimer_0();

//starting timer 0//
EN_TimerErrors_t StartTimer_0();

//stopping timer 0//
EN_TimerErrors_t StopTimer_0();

//breaking the delay loop//
EN_TimerErrors_t BreakTimer();

//generating 5 seconds delay with timer 0//
EN_TimerErrors_t Timer_0_Delay_5_Seconds();

//generating 0.5 seconds delay with timer 0//
EN_TimerErrors_t Timer_0_Delay_quarter_Seconds();

#endif /* TIMER_H_ */