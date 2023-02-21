/*
* dio.c
* Author: YOUSSEF ELBANDRAWY
*/

#include "dio.h"

void pinmode(uint8 portnum, uint8 pinnum,uint8 mod){
	/*
	mod =1 >>> output  
	mod =0 >>> input  */
	
	switch(portnum){
		case 'a':
		case 'A':
		if (mod == 1)
		{
		 DDRA |= (1<<pinnum);
		}
		else if (mod == 0)
		{
			DDRA &= (~(1<<pinnum));
		}
		break;
		
		case 'b':
		case 'B':
		if (mod == 1)
		{
			DDRB |= (1<<pinnum);
		}
		else if (mod == 0)
		{
			DDRB &= (~(1<<pinnum));
		}
		break;
		
		case 'c':
		case 'C':
		if (mod == 1)
		{
			DDRC |= (1<<pinnum);
		}
		else if (mod == 0)
		{
			DDRC &= (~(1<<pinnum));
		}
		break;
		
		case 'd':
		case 'D':
		if (mod == 1)
		{
			DDRD |= (1<<pinnum);
		}
		else if (mod == 0)
		{
			DDRD &= (~(1<<pinnum));
		}
		break;
		
		}
	
}

void portmode(uint8 portnum,uint8 mod){
	switch(portnum){
		case 'a':
		case 'A':
		if (mod == 1)
		{
			DDRA |= (0xff);
		}
		else if (mod == 0)
		{
			DDRA &= (0x00);
		}
		break;
		
		case 'b':
		case 'B':
		if (mod == 1)
		{
			DDRB |= (0xff);
		}
		else if (mod == 0)
		{
			DDRB &= (0x00);
		}
		break;
		
		case 'c':
		case 'C':
		if (mod == 1)
		{
			DDRC |= (0xff);
		}
		else if (mod == 0)
		{
			DDRC &= (0x00);
		}
		break;
		
		case 'd':
		case 'D':
		if (mod == 1)
		{
			DDRD |= (0xff);
		}
		else if (mod == 0)
		{
			DDRD &= (0x00);
		}
		break;
		
	}
	
}

void digitalwrite(uint8 portnum, uint8 pinnum,uint8 val){
	
	switch(portnum){
		case 'a':
		case 'A':
		if (val >= 1)
		{
			PORTA |= (1<<pinnum);
		}
		else if (val == 0)
		{
			PORTA &= (~(1<<pinnum));
		}
		break;
		
		case 'b':
		case 'B':
		if (val >= 1)
		{
			PORTB |= (1<<pinnum);
		}
		else if (val == 0)
		{
			PORTB &= (~(1<<pinnum));
		}
		break;
		
		case 'c':
		case 'C':
		if (val >= 1)
		{
			PORTC |= (1<<pinnum);
		}
		else if (val == 0)
		{
			PORTC &= (~(1<<pinnum));
		}
		break;
		
		case 'd':
		case 'D':
		if (val >= 1)
		{
			PORTD |= (1<<pinnum);
		}
		else if (val == 0)
		{
			PORTD &= (~(1<<pinnum));
		}
		break;
	}	
}

uint8 digitalread(uint8 portnum, uint8 pinnum){
	uint8 val;
	switch(portnum)
	{
		case 'a':
		case 'A':
		val = (PINA & (1<<pinnum)) >> pinnum;
		break;
		
		case 'b':
		case 'B':
		val = (PINB & (1<<pinnum))>>pinnum;
		break;
		
		case 'c':
		case 'C':
		val = (PINC & (1<<pinnum))>>pinnum;
		break;
		
		case 'd':
		case 'D':
		val = (PIND & (1<<pinnum))>>pinnum;
		break;
		
	}
	return val;
}

void lower_portmode(uint8 portnum,uint8 mod){
	switch(portnum){
		case 'a':
		case 'A':
		if (mod == 1)  //make the low pins output(0:3)
		{
			DDRA |= (0x0f);
		}
		else if (mod == 0)  //make the low pins input(0:3)
		{
			DDRA |= (0xf0);
		}
		
		break;
		
		case 'b':
		case 'B':
		if (mod == 1)  //make the low pins output(0:3)
		{
			DDRB |= (0x0f);
		}
		else if (mod == 0)  //make the low pins input(0:3)
		{
			DDRB |= (0xf0);
		}
		
		break;
		
		case 'c':
		case 'C':
		if (mod == 1)
		{
			DDRC |= (0x0f);
		}
		else if (mod == 0)
		{
			DDRC |= (0xf0);
		}
		
		break;
		
		case 'd':
		case 'D':
		if (mod == 1)
		{
			DDRD |= (0x0f);
		}
		else if (mod == 0)
		{
			DDRD |= (0xf0);
		}
		
		break;
		
	}
	
	
}


void upper_portmode(uint8 portnum,uint8 mod){
	switch(portnum){
		case 'a':
		case 'A':
		if (mod == 1)  //make the high pins output(4:7)
		{
			DDRA |= (0xf0);
		}
		else if (mod == 0)  //make the high pins input(4:7)
		{
			DDRA |= (0x0f);
		}
		break;
		
		case 'b':
		case 'B':
		if (mod == 1)  //make the low pins output(0:3)
		{
			DDRB |= (0xf0);
		}
		else if (mod == 0)  //make the low pins input(0:3)
		{
			DDRB |= (0x0f);
		}
		break;
		
		case 'c':
		case 'C':
		if (mod == 1)
		{
			DDRC |= (0xf0);
		}
		else if (mod == 0)
		{
			DDRC |= (0x0f);
		}
		break;
		
		case 'd':
		case 'D':
		if (mod == 1)
		{
			DDRD |= (0xf0);
		}
		else if (mod == 0)
		{
			DDRD |= (0x0f);
		}
		break;
		
	}
	
	
	
}

void activate_pullup(uint8 portname ,uint8 pinnumber, uint8 connect_pullup){
	switch(portname)
	{
		case 'A':
		case 'a':
		if(connect_pullup==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(connect_pullup==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if(connect_pullup==1)
		{
			SET_BIT(PORTC,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(connect_pullup==1)
		{
			SET_BIT(PORTD,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
	}
	
}

void port_write(uint8 portname,uint8 portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;
		default:
		break ;
	}
}

uint8 port_read(uint8 portname)
{
	uint8 return_val=0;
	switch(portname)
	{
		case 'A' :
		return_val=PINA; // read the value of port A
		break ;
		case 'B':
		return_val=PINB; // read the value of port B
		break ;
		case 'C' :
		return_val=PINC; // read the value of port C
		break ;
		case 'D':
		return_val=PIND; // read the value of port D
		break ;
		default:
		break ;
	}
	return return_val;
}

void write_low_nibble(uint8 portname,uint8 value)
{
	value&=0x0f;
	switch(portname)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		case 'C':
		PORTC&=0xf0;
		PORTC|=value;
		case 'D':
		PORTD&=0xf0;
		PORTD|=value;
	}
}

void write_high_nibble(uint8 portname,uint8 value)
{
	value<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		break;
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		break;
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		break;
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
		break;
	}
}