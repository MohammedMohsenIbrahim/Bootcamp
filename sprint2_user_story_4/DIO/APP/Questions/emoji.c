
/*
 * Emoji.c
 *
 * Created: 2/20/2019 12:11:48 PM
 *  Author: AVE-LAP-063
 */ 
#include "emoji.h"
#include "emoji_config.h "

/**************************************** Functions Definitions *********************************/
/****************************************************************************

Function Name		 : smile

Function Description : Function responsible for drawing smile face in the character LCD

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void smile(){
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_SEVENTEEN);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	// Set Cursor Address
	
}

/****************************************************************************

Function Name		 : Welcome_Emoji

Function Description : Function responsible for drawing a shape in the welcoming screen in the char LCDs

Function Parameters  : 
					   r : the row number of the shape
					   c : the column number of the shape 
					   *func : pointer to function of the shape wanted to be displayed

Function Return      : N/A

*******************************************************************************/

void Welcome_Emoji(uint8 r, uint8 c,void*func(void)){
	
	func();	
	LCD_gotoRowColumn(r,c);
	_delay_ms(NUM_FIVE);
	LCD_displayCharacter(NUM_ZERO);
}

/****************************************************************************

Function Name		 : sad

Function Description : Function responsible for drawing a sad face in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/

void sad (){
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_SEVENTEEN);
	LCD_displayCharacter(NUM_SEVENTEEN);
	LCD_displayCharacter(NUM_SEVENTEEN);
	// Set Cursor Address
	
}

/****************************************************************************

Function Name		 : True_Emoji

Function Description : Function responsible for drawing a smile emoji with true symbol in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/

void True_Emoji(){ 
	
LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_TWO);
LCD_displayCharacter(NUM_FOUR);
LCD_displayCharacter(NUM_EIGHT);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_sendCommand(second_address);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_TWELVE);
LCD_displayCharacter(NUM_TWELVE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);

LCD_sendCommand(third_address);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_TWELVE);
LCD_displayCharacter(NUM_TWELVE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_sendCommand(forth_address);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_EIGHT);
LCD_displayCharacter(NUM_FOUR);
LCD_displayCharacter(NUM_TWO);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_sendCommand(fifth_address);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_EIGHT);
LCD_displayCharacter(NUM_FOUR);
LCD_displayCharacter(NUM_TWO);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ZERO);
LCD_sendCommand(sixth_address );
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_sendCommand(seventh_address);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_THIRTY_ONE);
LCD_sendCommand(eighth_address);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_TWO);
LCD_displayCharacter(NUM_FOUR);
LCD_displayCharacter(NUM_EIGHT);
LCD_displayCharacter(NUM_SIXTEEN);
LCD_sendCommand(nitnth_address);
LCD_displayCharacter(NUM_ZERO);
LCD_displayCharacter(NUM_ONE);
LCD_displayCharacter(NUM_TWO);
LCD_displayCharacter(NUM_THREE);
LCD_gotoRowColumn(NUM_ONE,NUM_ZERO);
LCD_displayCharacter(NUM_FOUR);
LCD_displayCharacter(NUM_FIVE);
	
LCD_displayCharacter(NUM_SIX);
LCD_displayCharacter(NUM_SEVEN);
LCD_gotoRowColumn(NUM_ONE,NUM_EIGHT);
LCD_display_string("Shater");

}

/****************************************************************************

Function Name		 : False_Emoji

Function Description : Function responsible for drawing a sad emoji with false symbol in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/

void False_Emoji(){
	
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_TWO);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_EIGHT);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_sendCommand(second_address);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);

	LCD_sendCommand(third_address);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_sendCommand(forth_address);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_EIGHT);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_TWO);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_sendCommand(fifth_address);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_EIGHT);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_TWO);
	LCD_displayCharacter(NUM_TEN);
	LCD_displayCharacter(NUM_ZERO);
	LCD_sendCommand(sixth_address);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_sendCommand(seventh_address);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_THIRTY_ONE);
	LCD_sendCommand(eighth_address);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_TWO);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_EIGHT);
	LCD_displayCharacter(NUM_SIXTEEN);
	LCD_displayCharacter(NUM_ZERO);
	LCD_sendCommand(nitnth_address);
	LCD_displayCharacter(NUM_ZERO);
	LCD_displayCharacter(NUM_ONE);
	LCD_displayCharacter(NUM_TWO);
	LCD_displayCharacter(NUM_THREE);
	LCD_gotoRowColumn(NUM_ONE,NUM_ZERO);
	LCD_displayCharacter(NUM_FOUR);
	LCD_displayCharacter(NUM_FIVE);

	LCD_displayCharacter(NUM_SIX);
	LCD_displayCharacter(NUM_SEVEN);
	LCD_gotoRowColumn(NUM_ONE,NUM_EIGHT);
	LCD_display_string("bty5a");
}
