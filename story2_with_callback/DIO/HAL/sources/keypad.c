/*
 * keypad.c
 *
 * Created: 2/18/2019 11:21:03 AM
 *  Author: AVE-LAP-069
 */ 

/************************************ Includes *****************************/

#include "../headers/keypad.h"


/**************************** Functions Definitions ************************/
/****************************************************************************

Function Name		 : keypad_init

Function Description : Function responsible for initialization the keypad module

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Keypad_init(){
	uint8 keypad_pins_counter;
	for(keypad_pins_counter = NUM_ZERO; keypad_pins_counter < N_ROW;keypad_pins_counter++){
		DIO_SetPinDirection((KEYPAD_ROW_START_PIN_NUM + keypad_pins_counter),OUTPUT);
	}
	for(keypad_pins_counter = NUM_ZERO; keypad_pins_counter < N_COL;keypad_pins_counter++){
		DIO_SetPinDirection(KEYPAD_COL_START_PIN_NUM + keypad_pins_counter,INPUT);
		DIO_WritePin((KEYPAD_COL_START_PIN_NUM + keypad_pins_counter),HIGH);
	}
		
}

/****************************************************************************

Function Name		 : keypad_getPressedKey

Function Description : Function responsible for determine which key pressed in keypad module

Function Parameters  : N/A

Function Return      : 
						key_pressed_in_keypad (u8)

*******************************************************************************/
uint8 Keypad_getPressedKey(){
	uint8 rows , cols ;
			for(rows = NUM_ZERO ; rows < N_ROW ; rows++){
				KEYPAD_ROW_DATA_PORT |= EIGHT_BITS_MASKING ;
				DIO_WritePin(KEYPAD_ROW_START_PIN_NUM + rows,LOW);
				for(cols = NUM_ZERO;cols < N_COL ; cols++){
					if(DIO_ReadPin((KEYPAD_COL_START_PIN_NUM + cols)) == LOW){
							#if(keypad_pins_mul_col == KEYPAD_3_3_PIN_COUNT)
								return (((rows * N_COL) + cols + NUM_ONE));
							#elif(keypad_pins_mul_col == KEYPAD_4_4_PIN_COUNT)
								return Keypad_4_4(((rows * N_COL) + cols + NUM_ONE));
							#endif
				}
			}
		}
}


