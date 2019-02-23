/*
 * keypad.h
 *
 * Created: 2/18/2019 11:21:21 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/****************************** Includes ***********************************/
#include "keypad_cfg.h"

/**************************** Definitions ***********************************/ 
#define NUM_ZERO							0
#define NUM_ONE								1
#define KEYPAD_3_3_PIN_COUNT				9
#define KEYPAD_4_4_PIN_COUNT				16
#define EIGHT_BITS_MASKING					0xFF

/********************** Function Declarations *******************************/
void Keypad_init();
uint8 Keypad_getPressedKey();
uint8 Keypad_3_3(uint8 number);

#endif /* KEYPAD_H_ */