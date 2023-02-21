/*
 * USART.h
 * Author: YOUSSEF ELBANDRAWY
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include "stdtypes.h"

#ifndef USART_H_
#define USART_H_

void USART_Init(uint16);
void USART_Transmit(uint8 data);
uint8 USART_Receive(void);
void USART_Transmit_String(uint8 *str);


#endif /* USART_H_ */