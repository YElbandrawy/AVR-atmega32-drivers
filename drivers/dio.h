/*
* dio.h
* Author: YOUSSEF ELBANDRAWY
*/

#ifndef DIO_H_
#define DIO_H_


#include <avr/io.h>
#include "stdtypes.h"
#include "std_macros.h"

void pinmode(uint8 portnum, uint8 pinnum,uint8 mod);
void portmode(uint8 portnum,uint8 mod);
void digitalwrite(uint8 portnum, uint8 pinnum,uint8 val);
uint8 digitalread(uint8 portnum, uint8 pinnum);
void upper_portmode(uint8 portnum,uint8 mod);
void lower_portmode(uint8 portnum,uint8 mod);
void activate_pullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup);
void port_write(uint8 portname,uint8 portvalue);
uint8 port_read(uint8 portnum);
void write_low_nibble(uint8 portname,uint8 value);
void write_high_nibble(uint8 portname,uint8 value);
#endif /* DIO_H_ */

/*
**pinmode is used to set the direction of a single pin on a given port (A, B, C, or D) as either an input or output.

**portmode sets the direction of all pins on a given port as either inputs or outputs.

**digitalwrite is used to set a single pin on a given port to either a high or low value, depending on the value of val.

**digitalwrite is used to read the state of a digital pin on the microcontroller. It returns either HIGH or LOW, indicating the presence or absence of a voltage at the pin.

**lower_portmode is a C function that configures the mode (input/output) of the lower 4 bits (bits 0 to 3) of a specific port.
	It takes two arguments, portnum and mod, where
		-portnum is the port number (a, b, c, or d) and
		-mod is the mode (input or output).
	Based on the value of mod, it sets the lower pins (bits 0-3) of the specified port to either input or output mode.
		-If the value of mod is 1, the low pins are set to output mode.
		-If the value of mod is 0, the low pins are set to input mode.


** upper_portmode sets the mode of the high pins of a specific port.
	 It takes two arguments, portnum and mod, where 
		-portnum is the port number (a, b, c, or d) and
		-mod is the mode (input or output). 
	 Based on the value of mod, it sets the high pins (bits 4-7) of the specified port to either input or output mode. 
		-If the value of mod is 1, the high pins are set to output mode.
		-If the value of mod is 0, the high pins are set to input mode. 

**activate_pullup is used to activate or deactivate the pull-up on a specified port pin. It takes three arguments:
	portname - the name of the port (e.g. 'A', 'B', 'C', 'D').
	pinnumber - the number of the pin on the port.
	connect_pullup - an integer value of either 0 or 1 to either deactivate or activate the pull-up.
	
**port_write(uint8 portname,uint8 portvalue): Writes the 'portvalue' to the specified I/O portname. 
	The function takes two inputs.
	portname and portvalue. portname can be 'A', 'B', 'C', or 'D',which correspond to the names of the I/O ports.

**port_read(uint8 portname): Reads the value of the specified I/O portname.
	The function takes one input, portname, which can be 'A', 'B', 'C', or 'D'.
	The function returns the value read from the specified port.

**write_low_nibble(uint8 portname,uint8 value): Writes the low-order 4 bits of value to the specified I/O portname.
	The function takes two inputs, portname and value. portname can be 'A', 'B', 'C', or 'D', which correspond to the names of the I/O ports.

**write_high_nibble(uint8 portname,uint8 value): Writes the high-order 4 bits of value to the specified I/O portname.
	The function takes two inputs, portname and value. portname can be 'A', 'B', 'C', or 'D', which correspond to the names of the I/O ports.
*/