/*
 * keypad.c
 * Author: Youssef El-Bandrawy
 */
 
#include "keypad.h"


void keypad_init(){
	portmode(configport,0);  //to make sure that DDRD contain 0x00
	upper_portmode(configport,0); //the upper part of the port is input(pin4:pin7)
	lower_portmode(configport,1);  //the lower part of the port is output(pin0:pin3)
	write_low_nibble(configport,1);
	
}
uint8 checkpress(void){
	for (char i=row_start; i<=row_end; i++)
	{
		digitalwrite(configport,i-1,0);
		for(char j=column_start; j<=row_end; j++)
		{
			if (digitalread(configport,j+3)==0)
			{
				digitalwrite(configport,i-1,1);
				_delay_ms(50);
				return buttons_arr[i-1][j-1];
				break;
			}
	
		}
		digitalwrite(configport,i-1,1);
		_delay_ms(50);
		
	}
return 'n';	
}

