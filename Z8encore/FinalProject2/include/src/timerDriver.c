#include "timerDriver.h"
#include <eZ8.h>

// Counter for timer 0
short timer0Counter = 0;

/*
	Interrupt function for timer 0
*/
#pragma interrupt 
void isr_timer0() {
	timer0Counter++;
}

/*
	Get the counter for timer 0
*/
short getTimer0() {
	return timer0Counter;
}

/*
	Reset timer 0, so it can recount
*/
void resetTimer0() {
	timer0Counter = 0;
}

/*
	Setup timer 0 to 10ms
*/
void initTimer0() {
	// Set interrupt rutine 
	SET_VECTOR(TIMER0, isr_timer0);

	T0CTL = 0;		// Disable timer		
	T0CTL |= 0x01;	// Set continues mode

	// Set start value
	T0L = 0;
	T0H = 0;

	// Set prescale value to divide by 1 (not really needed)
	T0CTL |= 0x00;

	// Set reload value to 18432d = 1 ms period 
	T0RH = 0x48;	// Set high nipple reload value
	T0RL = 0x00;	// Set low nipple reload value

	// Setup interrupt for timer 0	
	IRQCTL |= 0x80;		// Enable all interrupts
	IRQ0ENH |= 0x20;	// Set priority high
	IRQ0ENL |= 0x20;	// Set priority high
	
	// Enable timer
	T0CTL |= 0x80;	
}

/*
	Stop/disable timer 0
*/
void stopTimer0() {
	T0CTL = 0;
}