/*
 * SPI.h
 * Author: YOUSSEF ELBANDRAWY
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <avr/delay.h>
#include "stdtypes.h"


/**
 * @brief Sets the data order for the SPI interface.
 * 
 * @param order The desired data order, either "MSB" or "LSB".
 */
void SPI_SetDataOrder(uint16 order);


/**
 * @brief Enables interrupts for the SPI interface.
 */
void SPI_EnableInterrupts(void);


/**
 * @brief Disables interrupts for the SPI interface.
 */
void SPI_DisableInterrupts(void);


/**
 * @brief Initializes the SPI module as master.
 *
 * This function initializes the SPI module as master and sets the MOSI and SCK pins as output.
 * The SPI module is enabled, set to master mode, and the clock rate is set to fck/16.
 */
void SPI_MasterInit(void);



/**
 * @brief Sends data to an SPI slave device.
 *
 * This function sends a byte of data to an SPI slave device.
 * The byte is written to the data register and the function waits until the transfer is complete before returning.
 *
 * @param cData The data byte to send.
 */
void SPI_MasterTransmit(int8 cData);



/**
 * @brief Transmits a null-terminated string over the SPI interface.
 * 
 * @param str The string to be transmitted.
 */
void SPI_TransmitString(const char* str);




/**
 * @brief Initializes the SPI module as slave.
 *
 * This function initializes the SPI module as slave and sets the MISO pin as output and all other pins as input.
 * The SPI module is enabled.
 */
void SPI_SlaveInit(void);

  
  

/**
 * @brief Receives data from the SPI master device.
 *
 * This function waits for data to be received from the SPI master device.
 * The data is read from the data register and returned to the calling function.
 *
 * @return The received data byte.
 */
int8 SPI_SlaveReceive(void);



#endif /* SPI_H_ */