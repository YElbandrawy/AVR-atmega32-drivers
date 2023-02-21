/*
 * I2C.c
 * Author: YOUSSEF ELBANDRAWY
 */ 

#include "I2C.h"

void I2C_Init(void) {
	TWBR = (((F_CPU / F_SCL) / Prescaler) - 16) / 2;
}

void I2C_Start(void) {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop(void) {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	_delay_us(10);
}

void I2C_Write(uint8 data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	_delay_ms(10);
}

uint8 I2C_Read_ACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

uint8 I2C_Read_NACK(void) {
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}


void I2C_WriteByte(uint8 EEPROM_address, uint8 byte_address, uint8 data) {
	I2C_Start();
	I2C_Write(EEPROM_address);
	I2C_Write(byte_address);
	I2C_Write(data);
	I2C_Stop();
	_delay_ms(60);
}



uint8 I2C_ReadByte(uint8 EEPROM_address, uint8 byte_address) {
	uint8 data;
	I2C_Start();
	I2C_Write(EEPROM_address);
	I2C_Write(byte_address);
	I2C_Start();
	I2C_Write((EEPROM_address) | 0x01);
	data = I2C_Read_NACK();
	_delay_ms(200);
	I2C_Stop();
	return data;
}

	
	