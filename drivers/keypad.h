/*
 * keypad.h
 *  Author: Youssef El-bandrawy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypad_config.h"
#include "stdtypes.h"
#include <util/delay.h>

void keypad_init(void);
unsigned char checkpress(void);

#endif

/*
**keypad_init function initializes a keypad connected to the microcontroller.

**checkpress function check which button is pressed and return 'n' if none is pressed.
*/