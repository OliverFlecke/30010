#ifndef TIMER_H
#define TIMER_H

void initTimer0();
void initTimer1();

long getCounter0();
long getCounter1();

void isr_timer0();
void isr_timer1();

#endif