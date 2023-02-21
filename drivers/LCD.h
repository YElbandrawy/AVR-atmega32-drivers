/*
 * LCD.h
 *  Author: YOUSSEF ELBANDRAWY
 */ 


#ifndef LCD_H_
#define LCD_H_
 
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "dio.h"
#include "lcd_config.h"
#include "LCD.h"
#include "stdtypes.h"



#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#if defined four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28

#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif

void lcd_init(void);
void send_falling_edge(void);
void LCD_Send_cmd(uint8 cmd);
void LCD_Send_char(uint8 data);
void LCD_Send_string(uint8 *data);
void LCD_clearscreen();
void LCD_movecursor(uint8 row,uint8 coloumn);


#endif /* LCD_H_ */
/*
This code is for a driver for an LCD display. 
It supports either 8-bit mode or 4-bit mode, depending on the definition of the macros eight_bits_mode or four_bits_mode respectively. 

The functions are:

**lcd_init: This function initializes the LCD display by sending several commands to the display to set its mode, turn on the display, clear the screen, and set the entry mode.


**send_falling_edge: This function sends a falling edge signal to the EN pin of the LCD to trigger a command or data transfer.


**LCD_Send_cmd: This function sends a command to the LCD. 
	Depending on the mode of the LCD, either 8 bits or 4 bits are written to the display. 
	The RS pin is set to 0 to indicate a command transfer.


**LCD_Send_char: This function sends a character to the LCD.
	Depending on the mode of the LCD, either 8 bits or 4 bits are written to the display.
	The RS pin is set to 1 to indicate a data transfer.


**LCD_Send_string: This function sends a string of characters to the LCD.
	The string is passed as a pointer to the first character and the function loops through the string, sending each character to the display using the LCD_Send_char function.


**LCD_clearscreen: This function clears the screen of the LCD by sending the clear screen command to the display.


**LCD_movecursor: This function moves the cursor of the LCD to a specified row and column by sending a command to the display.
	If the row or column values are outside the valid range, the cursor is moved to the first position of the first line.

*/