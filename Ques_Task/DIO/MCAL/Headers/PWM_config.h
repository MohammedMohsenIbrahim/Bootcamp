/*
 * PWM_config.h
 *
 * Created: 2/21/2019 11:35:27 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

/***************************************** Includes *********************************************/
#include "../../types.h"
#include "../../BitwiseOperations.h"
#include "../../Memory_Mapped_Registers.h"
#include "../../DIO.h"
#include "../../Timers.h"

/******************************* PWM Configurations Definitions **********************************/
#define TIMER1_PWM_CHA_PIN_NUM						29
#define TIMER1_PWM_CHB_PIN_NUM						28

#define TIMER1_FAST_PWM_NORMAL_PIN					0
#define TIMER1_FAST_PWM_TOGGLE_PIN_OCR				1
#define TIMER1_FAST_PWM_CLAER_PIN_OCR				2
#define TIMER1_FAST_PWM_SET_PIN_OCR					3			 

/******************************** PWM Configuration Selection ************************************/
#define TIMER1_TOP_VAL								1023


#endif /* PWM_CONFIG_H_ */