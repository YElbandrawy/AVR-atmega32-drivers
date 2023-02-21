/*
 * SPI.c
 * Author: YOUSSEF ELBANDRAWY
 */ 

#include "SPI.h"

void SPI_SetDataOrder(uint16 order) {
	if (order == "MSB") {
		SPCR &= ~(1 << DORD);
	} else if (order == "LSB") {
		SPCR |= (1 << DORD);
	} 
	
}

void SPI_Enable_Interrupts(void)
{
	SPCR |= (1 << SPIE);
	if (!(SREG & (1 << 7))) {
		SREG |= (1 << 7);
	}
}

void SPI_Disable_Interrupts(void)
{
	SPCR &= ~(1 << SPIE);
}



void SPI_MasterInit(void) {
	/* Set MOSI and SCK PINS as output which in my case PB5 and PB7 */
	DDRB &= ~(1 << DDB6);
	DDRB |= (1 << DDB5) | (1 << DDB7) |(1 << DDB4);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1 << SPE) | (1 << MSTR);

}

void SPI_MasterTransmit(int8 cData) {
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1 << SPIF)));
}

void SPI_TransimitString(const char *str){
	while((*str)!='\0')
	{
		SPI_MasterTransmit(*str++);
		_delay_ms(300);
	}
	
	
}

void SPI_SlaveInit(void) {
	/* Set MISO output, all others input */
	DDRB &= ~(1 << DDB6);
	DDRB |= (1 << DDB6);
	/* Enable SPI */
	SPCR = (1 << SPE);
}

int8 SPI_SlaveReceive(void) {
	/* Wait for reception complete */
	while(!(SPSR & (1 << SPIF)))
	;
	/* Return data register */
	return SPDR;
}
