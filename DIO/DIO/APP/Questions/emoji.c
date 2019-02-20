
/*
 * Emoji.c
 *
 * Created: 2/20/2019 12:11:48 PM
 *  Author: AVE-LAP-063
 */ 
#include "emoji.h"
#include "emoji_config.h "
void smile(){
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(ZERO);
	LCD_displayCharacter(10);
	LCD_displayCharacter(ZERO);
	LCD_displayCharacter(17);
	LCD_displayCharacter(10);
	LCD_displayCharacter(4);
	LCD_displayCharacter(ZERO);
	LCD_displayCharacter(ZERO);
	// Set Cursor Address
	
}
void Welcome_Emoji(uint8 r, uint8 c,void*func(void)){
	
	func();	
	LCD_gotoRowColumn(r,c);
	_delay_ms(5);
	LCD_displayCharacter(0);
}

void sad (){
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(ZERO);
	LCD_displayCharacter(10);
	LCD_displayCharacter(ZERO);
	LCD_displayCharacter(4);
	LCD_displayCharacter(10);
	LCD_displayCharacter(17);
	LCD_displayCharacter(17);
	LCD_displayCharacter(17);
	// Set Cursor Address
	
}
void True_Emoji(){ 
	
LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
LCD_displayCharacter(0);
LCD_displayCharacter(1);
LCD_displayCharacter(2);
LCD_displayCharacter(4);
LCD_displayCharacter(8);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_sendCommand(0x48);
LCD_displayCharacter(31);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(12);
LCD_displayCharacter(12);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(0);

LCD_sendCommand(0x50);
LCD_displayCharacter(31);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(12);
LCD_displayCharacter(12);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_sendCommand(0x58);
LCD_displayCharacter(0);
LCD_displayCharacter(16);
LCD_displayCharacter(8);
LCD_displayCharacter(4);
LCD_displayCharacter(2);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_sendCommand(0x60);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_displayCharacter(8);
LCD_displayCharacter(4);
LCD_displayCharacter(2);
LCD_displayCharacter(1);
LCD_displayCharacter(0);
LCD_sendCommand(0x68);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_displayCharacter(16);
LCD_displayCharacter(31);
LCD_displayCharacter(0);
LCD_displayCharacter(31);
LCD_sendCommand(0x70);
LCD_displayCharacter(0);
LCD_displayCharacter(0);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(31);
LCD_displayCharacter(0);
LCD_displayCharacter(31);
LCD_sendCommand(0x78);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(1);
LCD_displayCharacter(2);
LCD_displayCharacter(4);
LCD_displayCharacter(8);
LCD_displayCharacter(16);
LCD_sendCommand(0x80);
LCD_displayCharacter(0);
LCD_displayCharacter(1);
LCD_displayCharacter(2);
LCD_displayCharacter(3);
LCD_gotoRowColumn(1,0);
LCD_displayCharacter(4);
LCD_displayCharacter(5);
	
LCD_displayCharacter(6);
LCD_displayCharacter(7);
LCD_gotoRowColumn(1,8);
LCD_display_string("Shater");

}
void False_Emoji(){
	
	LCD_sendCommand(CGRAM_ADDRESS); // Set CGRAM Address
	LCD_displayCharacter(0);
	LCD_displayCharacter(1);
	LCD_displayCharacter(2);
	LCD_displayCharacter(4);
	LCD_displayCharacter(8);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_sendCommand(0x48);
	LCD_displayCharacter(31);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_displayCharacter(4);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);

	LCD_sendCommand(0x50);
	LCD_displayCharacter(31);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_displayCharacter(4);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_sendCommand(0x58);
	LCD_displayCharacter(0);
	LCD_displayCharacter(10);
	LCD_displayCharacter(8);
	LCD_displayCharacter(4);
	LCD_displayCharacter(2);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_sendCommand(0x60);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_displayCharacter(8);
	LCD_displayCharacter(4);
	LCD_displayCharacter(2);
	LCD_displayCharacter(10);
	LCD_displayCharacter(0);
	LCD_sendCommand(0x68);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_displayCharacter(16);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_sendCommand(0x70);
	LCD_displayCharacter(0);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_displayCharacter(0);
	LCD_displayCharacter(31);
	LCD_sendCommand(0x78);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_displayCharacter(1);
	LCD_displayCharacter(2);
	LCD_displayCharacter(4);
	LCD_displayCharacter(8);
	LCD_displayCharacter(16);
	LCD_displayCharacter(00);
	LCD_sendCommand(0x80);
	LCD_displayCharacter(0);
	LCD_displayCharacter(1);
	LCD_displayCharacter(2);
	LCD_displayCharacter(3);
	LCD_gotoRowColumn(1,0);
	LCD_displayCharacter(4);
	LCD_displayCharacter(5);
	
	LCD_displayCharacter(6);
	LCD_displayCharacter(7);
	LCD_gotoRowColumn(1,8);
	LCD_display_string("bty5a");

}
