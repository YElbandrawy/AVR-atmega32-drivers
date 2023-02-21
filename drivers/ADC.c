/*
 * ADC.c
 * Author: YOUSSEF ELBANDRAWY
 */ 


#include "ADC.h"

void vAdc_init(void){
SET_BIT(ADMUX,REFS0); //configure VREF
SET_BIT(ADMUX,REFS1);
SET_BIT(ADCSRA,ADEN); // enable ADC
/* adjust ADC clock*/
SET_BIT(ADCSRA,ADPS2);
SET_BIT(ADCSRA,ADPS1);
}

uint16 xAdc_read(void){
	uint16 read_val;
	SET_BIT(ADCSRA,ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
	
} 