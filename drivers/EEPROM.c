/*
 * EEPROM.c
 * Author: YOUSSEF ELBANDRAWY
 */

#include "EEPROM.h"

void EEPROM_init(void){
	EECR |= Ready_Interrupt_Enable;
	SREG |= ACTIVE_GLOBAL_INTERUPT;
}
 
void EEPROM_write(uint16 uiAddress, uint8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

uint8 EEPROM_read(uint16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}
