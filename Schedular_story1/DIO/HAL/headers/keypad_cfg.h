/*
 * keypad_cfg.h
 *
 * Created: 2/18/2019 11:22:00 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/*********************************** Includes ****************************************/
#include "../../BitwiseOperations.h"
#include "../../types.h"
#include "../../DIO.h"
#include "../../software_delay.h"
#include "../../Memory_Mapped_Registers.h"

/*************************** Configuration Definitions ******************************/

#define N_COL	3
#define N_ROW	3

#define  KEYPAD_ROW_DATA_PORT		PORT_C
#define KEYPAD_COL_DATA_PORT		PORT_C

#define KEYPAD_ROW_START_PIN_NUM	18	
#define KEYPAD_COL_START_PIN_NUM	21

#define keypad_pins_mul_col 9






#endif /* KEYPAD_CFG_H_ */