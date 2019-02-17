/*
 * ICU.c
 *
 * Created: 2/14/2019 11:41:27 AM
 *  Author: AVE-LAP-069
 */ 


/***************************************** Includes ***************************************/
#include "ICU.h"

/************************************ Functions Definitions ********************************/
/*******************************************************************************************
Function Name		 : Timer1_ICU_init

Function Description : Function responsible for initialization Input capture unit in Timer1

Function Parameters  : N/A

Function Return      : N/A
*********************************************************************************************/
void Timer1_ICU_init(){
	 TIMER1_PRE_COMPILE_CONFIGURATIONS();
	 DIO_SetPinDirection(TIMER1_ICU_PIN_NUM,0);
	 
	 Set_Bit(TCCR1B,7);		// Noise canceler 
	 Set_Bit(TCCR1B,6);     // detect the rising edge at first
	 Set_Bit(TIFR,ICF1);	// clear ICU flag
		
}

/*******************************************************************************************
Function Name		 : Timer1_ICU_calculate_duty_cycle

Function Description : Function responsible for calculating duty cycle using Input capture unit in Timer1

Function Parameters  : N/A

Function Return      : flt_duty_cycle : duty cycle of the signal 
*********************************************************************************************/
float Timer1_ICU_calculate_duty_cycle(){
	uint16 u16_high_time = 0 , u16_time = 0 ;
	float flt_duty_cycle ;
	
	while(Get_Bit(TIFR,ICF1) == 0);
	Set_Bit(TIFR,ICF1);  // clear ICU flag
	TCNT1H = 0 ;
	TCNT1L = 0 ;
	Clear_Bit(TCCR1B,6); // detect falling edge
	while(Get_Bit(TIFR,ICF1) == 0);
	Set_Bit(TIFR,ICF1);
	u16_high_time = ICR1H ;
	u16_high_time = u16_high_time << 8 ;
	u16_high_time = ICR1L ;
	
	Set_Bit(TCCR1B,6); // detect rising edge
	while(Get_Bit(TIFR,ICF1) == 0);
	Set_Bit(TIFR,ICF1);
	u16_time = ICR1H ;
	u16_time = u16_high_time << 8 ;
	u16_time = ICR1L ;
	
	flt_duty_cycle = (u16_time / u16_high_time ) ;
	
	return flt_duty_cycle ;
}  