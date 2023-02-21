/*
 * lcd_config.h
 * Author: YOUSSEF ELBANDRAWY
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define four_bits_mode
#define lcd_configport 'C' //attach the lcd's data pins {(pin0:pin7) in case eight bit and (pin4:pin7) in case four bits}
#define lcd_control_port 'B'  //attach EN,RS.RW pins to (pin0:pin2)



#endif /* LCD_CONFIG_H_ */