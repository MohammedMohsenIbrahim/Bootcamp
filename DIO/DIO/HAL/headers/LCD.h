/*
 * LCD.h
 *
 * Created: 2/19/2019 10:19:51 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef LCD_H_
#define LCD_H_

/****************************** Includes ***********************************/
#include "LCD_config.h"


/**************************** Definitions **********************************/
#define CHAR_LCD_DATA_DDR					DDR_A
#define CHAR_LCD_CTRL_DDR					DDR_A

#define CHAR_LCD_DATA_PORT					PORT_A
#define CHAR_LCD_CTRL_PORT					PORT_A

#define CHAR_LCD_RS							1
#define CHAR_LCD_RW							2
#define CHAR_LCD_E							3

#define CHAR_LCD_DELAY_TIME					1
#define FIVE_SECONDS						5

#define UPPER_FOUR_BITS_HEX					0xF0
#define LOWER_FOUR_BITS_HEX					0x0F
#define EIGHT_BITS_HEX						0xFF

#define FOUR_BITS							4
#define CHAR_LCD_STARTING_ADDRESS			0x40

#define CHAR_LCD_FIRST_ROW					0
#define CHAR_LCD_SECOND_ROW					1

/**************************** Enumurators **********************************/
enum Character_LCD_Commands{
	char_LCD_Clear_display_screen_cmd	     = 0x01 ,
	char_LCD_return_home_cmd				 = 0x02 ,
	char_LCD_shift_cursor_to_left_cmd		 = 0x04 ,
	cahr_LCD_shift_cursor_to_right_cmd		 = 0x06 ,
	char_LCD_shift_display_right_cmd         = 0x05 ,
	char_LCD_shift_display_left_cmd          = 0x07 ,
	char_LCD_cursor_off_cmd			         = 0x08 ,
	char_LCD_cursor_on_cmd			         = 0x0A ,
	char_LCD_display_on_cursor_off_cmd       = 0x0C ,
	char_LCD_dsiplay_on_cursor_blink_cmd     = 0x0E ,
	char_LCD_shift_cursor_position_left_cmd  = 0x10 ,
	char_LCD_shift_cursor_position_right_cmd = 0x14 ,
	char_lcd_shift_init_display_left_cmd     = 0x18 ,
	char_lcd_shift_init_display_right_cmd    = 0x1C ,
	char_lcd_cursor_begin_at_1st_line_cmd	 = 0x80 ,
	char_lcd_cursor_begin_at_2st_line_cmd	 = 0xC0 ,
	char_lcd_four_bits_mode_cmd				 = 0x28 , 
	char_lcd_eight_bits_mode_cmd			 = 0x38 , 
	char_lcd_wake_up						 = 0x30 ,
};

/************************* Functions Declarations **************************/
void LCD_init();
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_display_string(uint8 *string);
void LCD_gotoRowColumn(uint8 row,uint8 col);
void LCD_sendString_RowCol(uint8 *string,uint8 row,uint8 col);
void LCD_clear();



#endif /* LCD_H_ */