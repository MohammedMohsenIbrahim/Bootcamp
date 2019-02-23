/*
 * PWM.h
 *
 * Created: 2/21/2019 11:34:57 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef PWM_H_
#define PWM_H_

/*************************************** Includes ************************************/
#include "PWM_config.h"

/************************************** Definitions ***********************************/
#define SHIFT_EIGHT_BITS					8

/******************************** Functions Declaration *******************************/
/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_Pre_Compile_Config

Function Description : Function responsible for static configurations in Fast PWM mode in timer1

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_Pre_Compile_Config();

/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_init

Function Description : Function responsible for initialization PWM mode in timer1

Function Parameters  : 
						
					   u8_PWM_channel : channel A or B of the Timer1
					   u8_OCR_action  : select the action of OCR pin in OCR match (normal operation - toggle - clear - set )
					   
					   
Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_init(uint8 u8_PWM_channel,uint8 u8_OCR_action);

/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_OCR_VALUES

Function Description : Function responsible for set the values of the OCR to change the duty cycle

Function Parameters  : u16_TIMER1_ocr_vals : the value of the compare in PWM mode

Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_OCR_VALUES(uint16 u16_TIMER1_ocr_vals);


/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_OCR_VALS_using_DC

Function Description : Function responsible for set the values of the OCR according to the duty cycle given

Function Parameters  : u8_duty_cycle : duty cycle of the PWM signal

Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_OCR_VALS_using_DC(uint8 u8_duty_cycle);


#endif /* PWM_H_ */