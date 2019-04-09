/*
 * LCD.c
 *
 * Created: 2/19/2019 10:20:28 AM
 *  Author: AVE-LAP-069
 */ 

/****************************** Includes ***********************************/
#include "../headers/LCD.h"

/************************* Functions Definitions ***************************/
/****************************************************************************

Function Name		 : LCD_init

Function Description : Function responsible for initialization the LCD module

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void LCD_init(){

	DIO_SetPinDirection(CHAR_LCD_RS,OUTPUT);
	DIO_SetPinDirection(CHAR_LCD_RW,OUTPUT);
	DIO_SetPinDirection(CHAR_LCD_E,OUTPUT);
	
	#if(char_lcd_bits_mode == char_LCD_four_bits_mode)
		LCD_sendCommand(char_lcd_four_bits_mode_cmd);
		#if(char_lcd_four_bits_pins == char_lcd_four_bits_mode_upper_pins)
			CHAR_LCD_DATA_DDR |= UPPER_FOUR_BITS_HEX ;
		#elif(char_lcd_four_bits_pins == char_lcd_four_bits_mode_lower_pins)
			CHAR_LCD_DATA_DDR |= LOWER_FOUR_BITS_HEX ;
		#endif	
	#elif(char_lcd_bits_mode == char_LCD_eight_bits_mode)
			CHAR_LCD_DATA_DDR  = EIGHT_BITS_HEX ;
			LCD_sendCommand(char_lcd_eight_bits_mode_cmd);
	#else
		#error "YOU MUST DEFINE THE LCD MODE EIGHT OR FOUR BITS "		
	#endif	
	

	LCD_sendCommand(char_lcd_four_bits_mode_cmd);
	LCD_sendCommand(char_LCD_dsiplay_on_cursor_blink_cmd);
	LCD_sendCommand(char_LCD_Clear_display_screen_cmd);

	LCD_sendCommand(char_lcd_cursor_begin_at_1st_line_cmd);
	_delay_ms(FIVE_SECONDS);
}

/****************************************************************************

Function Name		 : LCD_sendCommand

Function Description : Function responsible for sending a command to LCD from commands enum 
					   defined in .h file

Function Parameters  : 
						command : command wanted to sent to LCD from commands enum in .h file

Function Return      : N/A

*******************************************************************************/

void LCD_sendCommand(uint8 command){
	DIO_WritePin(CHAR_LCD_RS,LOW);
	DIO_WritePin(CHAR_LCD_RW,LOW);
	
	
	#if(char_lcd_bits_mode == char_LCD_four_bits_mode)
		#if(char_lcd_four_bits_pins == char_lcd_four_bits_mode_upper_pins)
			CHAR_LCD_DATA_PORT = (CHAR_LCD_DATA_PORT & LOWER_FOUR_BITS_HEX ) | (command & UPPER_FOUR_BITS_HEX);
		#elif(char_lcd_four_bits_pins == char_lcd_four_bits_mode_lower_pins)
			CHAR_LCD_DATA_PORT = ((command & UPPER_FOUR_BITS_HEX) >> FOUR_BITS ) | CHAR_LCD_DATA_PORT ;
		#endif
	#endif
	
	DIO_WritePin(CHAR_LCD_E,HIGH);
	_delay_ms(CHAR_LCD_DELAY_TIME);
	
	DIO_WritePin(CHAR_LCD_E,LOW);
	_delay_ms(CHAR_LCD_DELAY_TIME);

	#if(char_lcd_bits_mode == char_LCD_four_bits_mode)
		#if(char_lcd_four_bits_pins == char_lcd_four_bits_mode_upper_pins)
			CHAR_LCD_DATA_PORT = (CHAR_LCD_DATA_PORT & LOWER_FOUR_BITS_HEX ) | (command << FOUR_BITS);
		#elif(char_lcd_four_bits_pins == char_lcd_four_bits_mode_lower_pins)
			CHAR_LCD_DATA_PORT = (command & LOWER_FOUR_BITS_HEX) | CHAR_LCD_DATA_PORT ;
		#endif
		#elif(char_LCD_bits_mode == char_LCD_eight_bits_mode)
			CHAR_LCD_DATA_PORT = command ;
	#endif	

	DIO_WritePin(CHAR_LCD_E,HIGH);
	_delay_ms(CHAR_LCD_DELAY_TIME);
	
	DIO_WritePin(CHAR_LCD_E,LOW);
	_delay_ms(CHAR_LCD_DELAY_TIME);	
	
}

/****************************************************************************

Function Name		 : LCD_displayCharacter

Function Description : Function responsible for displaying the character sent in the LCD
					   

Function Parameters  : 
					   character : character wanted to be sent to CGRAM to be shown in LCD

Function Return      : N/A

*******************************************************************************/

void LCD_displayCharacter(uint8 character){
	DIO_WritePin(CHAR_LCD_RS,HIGH);
	DIO_WritePin(CHAR_LCD_RW,LOW);
	
	#if(char_lcd_bits_mode == char_LCD_four_bits_mode)
		#if(char_lcd_four_bits_pins == char_lcd_four_bits_mode_upper_pins)
	CHAR_LCD_DATA_PORT = (CHAR_LCD_DATA_PORT & LOWER_FOUR_BITS_HEX ) |(character & UPPER_FOUR_BITS_HEX);
		#elif(char_lcd_four_bits_pins == char_lcd_four_bits_mode_lower_pins)
			CHAR_LCD_DATA_PORT = ((character & UPPER_FOUR_BITS_HEX) >> FOUR_BITS ) | CHAR_LCD_DATA_PORT ;
		#endif
	#endif
		

	DIO_WritePin(CHAR_LCD_E,HIGH);
	_delay_ms(CHAR_LCD_DELAY_TIME);
	
	_delay_ms(CHAR_LCD_DELAY_TIME);
	DIO_WritePin(CHAR_LCD_E,LOW);
	_delay_ms(CHAR_LCD_DELAY_TIME);
	
	#if(char_lcd_bits_mode == char_LCD_four_bits_mode)
		#if(char_lcd_four_bits_pins == char_lcd_four_bits_mode_upper_pins)
			CHAR_LCD_DATA_PORT = (CHAR_LCD_DATA_PORT & LOWER_FOUR_BITS_HEX ) |(character << FOUR_BITS);
		#elif(char_lcd_four_bits_pins == char_lcd_four_bits_mode_lower_pins)
			CHAR_LCD_DATA_PORT = (character & LOWER_FOUR_BITS_HEX) | CHAR_LCD_DATA_PORT ;
		#endif
		#elif(char_LCD_bits_mode == char_LCD_eight_bits_mode)
			CHAR_LCD_DATA_PORT = character ;
	#endif
		

	DIO_WritePin(CHAR_LCD_E,HIGH);
	_delay_ms(CHAR_LCD_DELAY_TIME);
	
	_delay_ms(CHAR_LCD_DELAY_TIME);
	DIO_WritePin(CHAR_LCD_E,LOW);
	_delay_ms(CHAR_LCD_DELAY_TIME);	
}

/****************************************************************************

Function Name		 : LCD_display_string

Function Description : Function responsible for displaying string sent in the LCD
					   

Function Parameters  : 
					   string : string wanted to be sent to CGRAM to be shown in LCD

Function Return      : N/A

*******************************************************************************/

void LCD_display_string(uint8 *string){
	uint8 local_u8_char_counter = 0 ;
	while(string[local_u8_char_counter] != NULL){
		LCD_displayCharacter(string[local_u8_char_counter]);
		local_u8_char_counter++ ;
	}
}

/****************************************************************************

Function Name		 : LCD_gotoRowColumn

Function Description : Function responsible for moving the cursor into certain location in LCD
					   

Function Parameters  : 
					   row : row wanted to move the cursor to it
					   col : col wanted to move the cursor to it

Function Return      : N/A

*******************************************************************************/
void LCD_gotoRowColumn(uint8 row,uint8 col){
	uint8 local_u8_char_lcd_address ;
	switch(row){
		case CHAR_LCD_FIRST_ROW :
				local_u8_char_lcd_address = col ; 
		break;
		case CHAR_LCD_SECOND_ROW :
				local_u8_char_lcd_address = col + CHAR_LCD_STARTING_ADDRESS ;
		break;
		default:
		
		break;
	}
	
	LCD_sendCommand(local_u8_char_lcd_address | char_lcd_cursor_begin_at_1st_line_cmd);
}

/****************************************************************************

Function Name		 : LCD_sendString_RowCol

Function Description : Function responsible for moving the cursor into certain location in LCD
					   

Function Parameters  : 
					   string : string wanted to be sent to CGRAM to be shown in LCD						
					   row	  : row wanted to move the cursor to it
					   col	  : col wanted to move the cursor to it

Function Return      : N/A

*******************************************************************************/
void LCD_sendString_RowCol(uint8 *string,uint8 row,uint8 col){
	LCD_gotoRowColumn(row,col);
	LCD_display_string(string);
}

/****************************************************************************

Function Name		 : LCD_clear

Function Description : Function responsible for clearing the LCD
					   

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void LCD_clear(){
	LCD_sendCommand(char_LCD_Clear_display_screen_cmd);
}