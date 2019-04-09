/*
 * LCD_config.h
 *
 * Created: 2/19/2019 10:20:09 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*********************************** Includes ****************************************/
#include "../../types.h"
#include "../../DIO.h"
#include "../../Timers.h"
#include "../../software_delay.h"
#include "../../Memory_Mapped_Registers.h"
#define  F_CPU 16000000
#include <util/delay.h>
/*************************** Configuration Definitions ******************************/
#define char_LCD_four_bits_mode				4
#define char_LCD_eight_bits_mode			8

#define char_lcd_four_bits_mode_upper_pins	0
#define char_lcd_four_bits_mode_lower_pins	1	

/*************************** Configuration Selections ******************************/
#define char_lcd_bits_mode			char_LCD_four_bits_mode
#define char_lcd_four_bits_pins		char_lcd_four_bits_mode_upper_pins	 

#endif /* LCD_CONFIG_H_ */