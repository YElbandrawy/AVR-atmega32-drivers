/*
* keypad_config.h
* Author: Youssef El-Bandrawy
*/

#ifndef keypad_config_H_
#define keypad_config_H_
					 
#define configport 'D' //configure the keypad on port D
#define column_start 1
#define column_end 4  //number of columns
#define row_start 1
#define row_end 4   //number of rows
char buttons_arr[row_end][column_end]={{'7','8','9','/'},
									   {'4','5','6','*'},
									   {'1','2','3','-'},
									   {'A','0','=','+'}};
/*
char buttons_arr[row_end][column_end]={{'*','0','#'},
									   {'7','8','9'},
									   {'4','5','6'},
									   {'1','2','3'}};
*/

#endif 