/*
 * LCD.c
 * Author: YOUSSEF ELBANDRAWY
 */ 

#include "LCD.h"

void lcd_init(){
	_delay_ms(200);
	#if defined eight_bits_mode
	portmode(lcd_configport,1);
	pinmode(lcd_control_port,EN,1);
	pinmode(lcd_control_port,RW,1);
	pinmode(lcd_control_port,RS,1);
	digitalwrite(lcd_control_port,RW,0);
	LCD_Send_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_Send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	
	#elif defined four_bits_mode
	upper_portmode(lcd_configport,1);
	pinmode(lcd_control_port,EN,1);
	pinmode(lcd_control_port,RW,1);
	pinmode(lcd_control_port,RS,1);
	digitalwrite(lcd_control_port,RW,0);
	LCD_Send_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_Send_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_Send_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}

void send_falling_edge(void)
{
	digitalwrite(lcd_control_port,EN,1);
	_delay_ms(2);
	digitalwrite(lcd_control_port,EN,0);
	_delay_ms(2);
}

void LCD_Send_cmd(uint8 cmd)
{
	#if defined eight_bits_mode
	port_write(lcd_configport,cmd);
	digitalwrite(lcd_control_port,RS,0);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(lcd_configport,cmd>>4);
	digitalwrite(lcd_control_port,RS,0);
	send_falling_edge();
	write_high_nibble(lcd_configport,cmd);
	digitalwrite(lcd_control_port,RS,0);
	send_falling_edge();
	#endif
	_delay_ms(1);
}

void LCD_Send_char(uint8 data)
{
	#if defined eight_bits_mode
	port_write(lcd_configport,data);
	digitalwrite(lcd_control_port,RS,1);
	send_falling_edge();
	
	#elif defined four_bits_mode
	write_high_nibble(lcd_configport,data>>4);
	digitalwrite(lcd_control_port,RS,1);
	send_falling_edge();
	write_high_nibble(lcd_configport,data);
	digitalwrite(lcd_control_port,RS,1);
	send_falling_edge();
	#endif
	_delay_ms(1);
}

void LCD_Send_string(uint8 *data)
{
	while((*data)!='\0')
	{
		LCD_Send_char(*data);
		data++;
	}
}

void LCD_clearscreen()
{
	LCD_Send_cmd(CLR_SCREEN);
	_delay_ms(2);
}

void LCD_movecursor(uint8 row,uint8 coloumn)
{
	uint8 data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_Send_cmd(data);
	_delay_ms(1);
}
