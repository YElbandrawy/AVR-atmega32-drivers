/*
* Timer.c
*  Author: YOUSSEF ELBANDRAWY
*/ 


#include "Timer.h"


void timer_CTC_init_interrupt(uint8  OCR0_load)
{
	TCCR0 = CTC_MODE | CLOCK_PRESCALER_1024;
	OCR0 = OCR0_load;
	TIMSK = INTERRUPT_ON_COMPARE_MATCH;
	sei();
}

void timer_wave_nonPWM(uint8 OCR0_load)
{
	DDRB |= OC0_AS_OUTPUT;
	TCCR0 = CTC_MODE | CLOCK_PRESCALER_1024 | TOGGLE_ON_COMPARE_MATCH;
	OCR0 = OCR0_load;
}

void timer_wave_fastPWM(uint8 OCR0_load)
{
	DDRB |= OC0_AS_OUTPUT;
	TCCR0 = FAST_PWM_MODE | CLOCK_PRESCALER_1024 | SET_ON_COMPARE_MATCH_CLEAR_ON_BOTTOM;
	OCR0 = OCR0_load;
}

void timer_wave_phasecorrectPWM(uint8 OCR0_load)
{
	DDRB |= OC0_AS_OUTPUT;
	TCCR0 = PHASE_CORRECT_PWM_MODE | CLOCK_PRESCALER_1024 | SET_ON_COMPARE_MATCH_CLEAR_ON_BOTTOM;
	OCR0 = OCR0_load;
}


