/*
 * ADC.h
 * Author: YOUSSEF ELBANDRAWY
 */ 


#ifndef ADC_H_
#define ADC_H_
 
 
#include <avr/io.h>
#include "stdtypes.h"
#include "std_macros.h"
 
void vAdc_init(void);
uint16 xAdc_read(void);
 
#endif

/*

vAdc_init(): This function initializes the ADC (Analog to Digital Converter) module.
	It sets the voltage reference of the ADC by setting bits REFS0 and REFS1 in the ADMUX register.
	It then enables the ADC module by setting the ADEN bit in the ADCSRA register.
	Finally, it adjusts the ADC clock by setting the ADPS2 and ADPS1 bits in the ADCSRA register.

xAdc_read(): This function reads the ADC value and returns the digital equivalent of an analog input.
	It starts the conversion process by setting the ADSC bit in the ADCSRA register.
	It then waits for the ADIF bit in the ADCSRA register to become 1, which indicates that the conversion is complete.
	After the conversion is complete, it clears the ADIF bit by setting it.
	and then retrieves the lower 8 bits of the ADC result from the ADCL register.
	It retrieves the higher 8 bits of the ADC result from the ADCH register,shifts it 8 bits to the left, and ORs it with the lower 8 bits.
    Finally, it returns the combined 16-bit value as read_val.

*/