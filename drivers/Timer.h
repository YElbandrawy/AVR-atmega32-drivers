/*
 * Timer.h
 *  Author: YOUSSEF ELBANDRAWY
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "stdtypes.h"
#include "std_macros.h"

// Bit Masks for TCCR0
#define CTC_MODE ((1<<WGM01))
#define FAST_PWM_MODE ((1<<WGM00)|(1<<WGM01))
#define PHASE_CORRECT_PWM_MODE ((1<<WGM00))

#define TOGGLE_ON_COMPARE_MATCH ((1<<COM00))
#define CLEAR_ON_COMPARE_MATCH_SET_ON_BOTTOM ((1<<COM01))
#define SET_ON_COMPARE_MATCH_CLEAR_ON_BOTTOM ((1<<COM01)|(1<<COM00))


#define CLOCK_NOPRESCALER ((1<<CS00))
#define CLOCK_PRESCALER_8 ((1<<CS01)
#define CLOCK_PRESCALER_64 ((1<<CS01)|(1<<CS00))
#define CLOCK_PRESCALER_256 ((1<<CS02))
#define CLOCK_PRESCALER_1024 ((1<<CS02)|(1<<CS00))
#define CLOCK_EXTERNAL_FALLING ((1<<CS02)|(1<<CS01)) //External clock source on T0 pin. Clock on falling edge.
#define CLOCK_EXTERNAL_RISING ((1<<CS02)|(1<<CS01)|(1<<CS00))  // External clock source on T0 pin. Clock on rising edge.


// Bit Mask for TIMSK
#define INTERRUPT_ON_COMPARE_MATCH (1<<OCIE0)

// Bit Mask for DDRB
#define OC0_AS_OUTPUT (1<<3)




void timer_CTC_init_interrupt(uint8 OCR0_load);

void timer_wave_nonPWM(uint8 OCR0_load);

void timer_wave_fastPWM(uint8 OCR0_load);

void timer_wave_phasecorrectPWM(uint8 OCR0_load);


#endif /* TIMER_H_ */


/*
    timer_CTC_init_interrupt(uint8 OCR0_load): This function initializes the timer peripheral in CTC (Clear Timer on Compare Match) mode 
	and sets up an interrupt service routine (ISR) that will be called whenever the value stored in the OCR0 register matches the timer's counter value. 
	It sets the value of OCR0 to OCR0_load, selects the timer clock prescaler (/1024), and enables the OCR0 interrupt.
	Finally, it enables global interrupts using the sei() function.

    timer_wave_nonPWM(uint8 OCR0_load): This function initializes the timer peripheral in CTC mode to generate a waveform (non-PWM) on the OC0 pin.
	It sets the OC0 pin as an output, sets the value of OCR0 to OCR0_load, selects the timer clock, and configures the timer to toggle the OC0 pin on compare match.

    timer_wave_fastPWM(uint8 OCR0_load): This function initializes the timer peripheral in Fast PWM mode to generate a PWM waveform on the OC0 pin.
	It sets the OC0 pin as an output, sets the value of OCR0 to OCR0_load, selects the timer clock, and configures the timer to set the OC0 pin on compare match and clear it at BOTTOM (inverting mode).

    timer_wave_phasecorrectPWM(uint8 OCR0_load): This function initializes the timer peripheral in Phase Correct PWM mode to generate a PWM waveform on the OC0 pin.
	It sets the OC0 pin as an output, sets the value of OCR0 to OCR0_load, selects the timer clock, and configures the timer to set the OC0 pin on compare match when up-counting and clear it on compare match when down-counting.

*/