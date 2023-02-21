/*
 * I2C.h
 * Author: YOUSSEF ELBANDRAWY
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <util/delay.h>
#include "stdtypes.h"

/* Define clock frequency and I2C bit rate */
#define F_CPU 8000000UL
#define F_SCL 100000UL
#define Prescaler 1

/* Define BAUD rate for serial communication */
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)


void I2C_Init(void);
/*
Description:
Initializes the I2C communication by setting the TWBR register with a value calculated using the system clock frequency and desired I2C clock frequency.
*/


/* Function to start I2C communication */
void I2C_Start(void);
/*
Description: 
Sends a start condition on the I2C bus by setting the TWSTA and TWEN bits in the TWCR register.
*/


/* Function to stop I2C communication */
void I2C_Stop(void);
/*
Description:
Sends a stop condition on the I2C bus by setting the TWSTO and TWEN bits in the TWCR register.
*/

/* Function to write data on I2C bus */
void I2C_Write(uint8 data);
/*
Description:
Writes a byte of data on the I2C bus by setting the TWDR register with the data and setting the TWEN bit in the TWCR register.
*/

/* Function to read data with ACK from I2C bus */
uint8 I2C_Read_ACK(void);
// This function reads data from the I2C bus with acknowledgement (ACK) from the receiver.


/* Function to read data with NACK from I2C bus */
uint8 I2C_Read_NACK(void);
/*
Description:
Reads a byte of data from the I2C bus and sends a NACK signal to the I2C slave device by setting the TWEN bit in the TWCR register.
*/




/* Function to write data to EEPROM */
void I2C_WriteByte(uint8 EEPROM_address, uint8 byte_address, uint8 data);
/*
Description:
Writes a byte of data to a specific byte in an I2C slave device with the specified EEPROM address 
by sending a start condition, followed by the EEPROM address, byte address, and data byte, and then sending a stop condition.
*/




/* Function to read data from EEPROM */
uint8 I2C_ReadByte(uint8 EEPROM_address, uint8 register_address);
/*
Description:
Reads a byte of data from a specific byte in an I2C slave device with the specified EEPROM address 
by sending a start condition, followed by the EEPROM address and register address, then sending another start condition and sending the EEPROM address with the read bit set,
and finally reading the data byte from the I2C bus and sending a stop condition.
*/

#endif /* I2C_H_ */