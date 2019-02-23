/*
 * PWM.c
 *
 * Created: 2/21/2019 11:35:41 AM
 *  Author: AVE-LAP-069
 */ 


/*************************************** Includes ************************************/
#include "../headers/PWM.h"

/**************************** Functions Definitions ***************************/
/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_Pre_Compile_Config

Function Description : Function responsible for static configurations in Fast PWM mode in timer1

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_Pre_Compile_Config(){
	TIMER1_PRE_COMPILE_CONFIGURATIONS();
}

/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_init

Function Description : Function responsible for initialization PWM mode in timer1

Function Parameters  : 
						
					   u8_PWM_channel : channel A or B of the Timer1
					   u8_OCR_action  : select the action of OCR pin in OCR match (normal operation - toggle - clear - set )
					   
					   
Function Return      : N/A

*******************************************************************************/
void TIMER1_FAST_PWM_init(uint8 u8_PWM_channel,uint8 u8_OCR_action){
	TIMER1_FAST_PWM_Pre_Compile_Config();
	/* Select Fast PWM mode 10 bits */
	Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_WAVEFORM_GENERATION_MODE_BIT1);
	Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_WAVEFORM_GENERATION_MODE_BIT0);
	Set_Bit(TIMER1_CONTROL_REG_1B,TIMER1_WAVEFORM_GENERATION_MODE_BIT2);
	/* Make the TIMER1 counter register start from Zero */
	TIMER1_COUNT_DATA_REG_HIGH = NUM_ZERO ;
	TIMER1_COUNT_DATA_REG_LOW = NUM_ZERO ;
	
	switch(u8_PWM_channel){
		/* Channel A */
		case 'A' :
				DIO_SetPinDirection(TIMER1_PWM_CHA_PIN_NUM,OUTPUT); /* Channel A pin output pin */
				Set_Bit(TIMER1_INTERRUPT_MASK_REG,TIMER1_OCR_CHA_INTERRUPT_ENABLE_BIT); /* Enable OCR CHA interrupt */
				
				/* Determine the Action of OCR pin in OCR match */
					if(u8_OCR_action == TIMER1_FAST_PWM_NORMAL_PIN){
						Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT1);
						Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT0);
					}else if(u8_OCR_action == TIMER1_FAST_PWM_TOGGLE_PIN_OCR){
						Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT1);
						Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT0);						
					}else if(u8_OCR_action == TIMER1_FAST_PWM_CLAER_PIN_OCR){
						Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT1);
						Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT0);						
					}else if(u8_OCR_action == TIMER1_FAST_PWM_SET_PIN_OCR){
						Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT1);
						Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT0);						
					}else{
						
					}
		break;
		case 'B' :
					DIO_SetPinDirection(TIMER1_PWM_CHB_PIN_NUM,OUTPUT);	/* Channel B pin output pin */
					Set_Bit(TIMER1_INTERRUPT_MASK_REG,TIMER1_OCR_CHB_INTERRUPT_ENABLE_BIT); /* Enable OCR CHB interrupt */
					/* Determine the Action of OCR pin in OCR match */
					if(u8_OCR_action == TIMER1_FAST_PWM_NORMAL_PIN){
							Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT1);
							Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT0);
						}else if(u8_OCR_action == TIMER1_FAST_PWM_TOGGLE_PIN_OCR){
							Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT1);
							Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT0);
						}else if(u8_OCR_action == TIMER1_FAST_PWM_CLAER_PIN_OCR){
							Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT1);
							Clear_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT0);
						}else if(u8_OCR_action == TIMER1_FAST_PWM_SET_PIN_OCR){
							Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT1);
							Set_Bit(TIMER1_CONTROL_REG_1A,TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT0);
						}else{
						
					}						
		break;
		default:
		
		break ;
	}
}

/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_OCR_VALUES

Function Description : Function responsible for set the values of the OCR to change the duty cycle

Function Parameters  : u16_TIMER1_ocr_vals : the value of the compare in PWM mode

Function Return      : N/A

*******************************************************************************/

void TIMER1_FAST_PWM_OCR_VALUES(uint16 u16_TIMER1_ocr_vals){
	/* Set the values in out put compare register to control the duty cycle */
	TIMER1_OCR_DATA_REG_HIGH = (uint8)(u16_TIMER1_ocr_vals >> SHIFT_EIGHT_BITS) ;
	TIMER1_OCR_DATA_REG_LOW  = (uint8)u16_TIMER1_ocr_vals ;
}


/****************************************************************************

Function Name		 : TIMER1_FAST_PWM_OCR_VALS_using_DC

Function Description : Function responsible for set the values of the OCR according to the duty cycle given

Function Parameters  : u8_duty_cycle : duty cycle of the PWM signal

Function Return      : N/A

*******************************************************************************/

void TIMER1_FAST_PWM_OCR_VALS_using_DC(uint8 u8_duty_cycle){
	uint16 u16_TIMER1_OCR_vals ;
	/* The value of output compare register is calculated by the equation 
	Duty cycle = percentage of ones (OCR VAL) / percentage of zeros 
			   = OCRVAL / TOP 
	*/
	
	u16_TIMER1_OCR_vals = (u8_duty_cycle * (TIMER1_TOP_VAL + 1));
	TIMER1_FAST_PWM_OCR_VALUES(u16_TIMER1_OCR_vals);
}

