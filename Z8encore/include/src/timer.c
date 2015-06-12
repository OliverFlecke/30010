#include <eZ8.h>
#include "timer.h"

long counter0 = 0;
long counter1 = 0;

long getCounter0() {
	return counter0;
}

long getCounter1() {
	return counter1;
}

#pragma interrupt
void isr_timer0() {
//	IRQCTL &= ~0x80;
	
	counter0++;
	
//	IRQCTL |= 0x80;
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

	// Set prescale value to divide by 4 
	T0CTL |= 0x10;

	// Set reload value to 46080d = 10 ms period 
	T0RH = 0xB4;	// Set high nipple reload value
	T0RL = 0x00;	// Set low nipple reload value

	// Setup interrupt for timer 0	
	IRQCTL |= 0x80;		// Enable all interrupts
	IRQ0ENH |= 0x20;	// Set priority high
	IRQ0ENL |= 0x20;	// Set priority high
	
	// Enable timer
	T0CTL |= 0x80;	
}

#pragma interrupt
void isr_timer1() {
	counter1++;
}

void initTimer1() {
	// Set interrupt rutine 
	SET_VECTOR(TIMER1, isr_timer1);

	T1CTL = 0;		// Disable timer		
	T1CTL |= 0x01;	// Set continues mode

	// Set start value
	T1L = 0;
	T1H = 0;

	// Set prescale value to divide by 1
	T1CTL |= 0x08;

	// Set reload value to 18432d = 1 ms period 
	T1RH = 0x48;	// Set high nipple reload value
	T1RL = 0x00;	// Set low nipple reload value

	// Setup interrupt for timer 0	
	IRQCTL |= 0x80;		// Enable all interrupts
	IRQ1ENH |= 0x20;	// Set priority high
	IRQ1ENL |= 0x20;	// Set priority high
	
	// Enable timer
	T1CTL |= 0x80;	
}