/*
 * USART.c
 * Author: YOUSSEF ELBANDRAWY
 */ 


#include "USART.h"

//Bit Masks for UCSRB
#define Enable_TX_and_RX ((1<<RXEN)|(1<<TXEN))
#define RX_Complete_Interrupt_Enable  (1<<RXCIE)
#define TX_Complete_Interrupt_Enable  (1<<TXCIE)  
//Bit Masks for UCSRC
#define Synchronous_Operation (1<<UMSEL)
#define Odd_Parity ((1<<UPM0)|(1<<UPM1))
#define Even_Parity (1<<UPM1)
#define Stop_bit_2  (1<<USBS)
#define Character_Size_6 (1<<UCSZ0)
#define Character_Size_7 (1<<UCSZ1)
#define Character_Size_8 ((1<<UCSZ0)|(1<<UCSZ1))



void USART_Init(uint16 baud)
{
	/* Set baud rate */
	uint16 ubrr = (F_CPU/(16*baud))-1;
	UBRRL = (uint8)ubrr;
	UBRRH = (uint8)(ubrr>>8);
	
	/* Enable receiver and transmitter */
	UCSRB = Enable_TX_and_RX;
	/* Set frame format: 8data, 1stop bit */
	UCSRC = ((1<<URSEL)|Character_Size_8);
}



void USART_Transmit( uint8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}


uint8 USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}

void USART_Transmit_String(uint8 *string)
{
	while(*string)
	{
		USART_Transmit(*string++);
	}
}
