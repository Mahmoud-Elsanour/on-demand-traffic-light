/*
 * register.h
 *
 * Created: 05/11/2022 01:49:28 PM
 *  Author: Mahmoud
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

//1-defining unsigned char to store registers values.
typedef unsigned char uint8_t;

//2-defining registers addresses:

//A) DIO(DDRN,PORTN and PINN) register.
	//DDRN:
	#define DDRA  (*((volatile uint8_t*)(0x3A)))
	#define DDRB  (*((volatile uint8_t*)(0x37)))
	#define DDRC  (*((volatile uint8_t*)(0x34)))
	#define DDRD  (*((volatile uint8_t*)(0x31)))
	//PORTN
	#define PORTA (*((volatile uint8_t*)(0x3B)))
	#define PORTB (*((volatile uint8_t*)(0x38)))
	#define PORTC (*((volatile uint8_t*)(0x35)))
	#define PORTD (*((volatile uint8_t*)(0x32)))
	//PINN
	#define PINA  (*((volatile uint8_t*)(0x39)))
	#define PINB  (*((volatile uint8_t*)(0x36)))
	#define PINC  (*((volatile uint8_t*)(0x33)))
	#define PIND  (*((volatile uint8_t*)(0x30)))

//B) Timer0(TCCR0,TCNT0,TIMSK0,OCR0 and TIFR) registers.
	#define TCCR0 (*((volatile uint8_t*)(0x53)))
	#define TIMSK (*((volatile uint8_t*)(0x59)))
	#define TCNT0 (*((volatile uint8_t*)(0x52)))
	#define OCR0  (*((volatile uint8_t*)(0x5C)))
	#define TIFR  (*((volatile uint8_t*)(0x58)))

//c) Interrupt(MCUCR,MCUCSR,GICR and GIFR) registers.
	#define MCUCR  (*((volatile uint8_t*)(0x55)))
	#define MCUCSR (*((volatile uint8_t*)(0x54)))
	#define GICR   (*((volatile uint8_t*)(0x5B)))
	#define GIFR   (*((volatile uint8_t*)(0x5A)))

//D) Status Register
	#define SREG (*((volatile uint8_t*)(0x5F)))

#endif /* REGISTER_H_ */