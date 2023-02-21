/*
 * EEPROM.h
 * Author: YOUSSEF ELBANDRAWY
 */


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "stdtypes.h"
#include "std_macros.h"

#define Ready_Interrupt_Enable (1<<EERIE)

void EEPROM_init(void);
void EEPROM_write(uint16 uiAddress, uint8 ucData);
uint8 EEPROM_read(uint16 uiAddress);



#endif /* EEPROM_H_ */