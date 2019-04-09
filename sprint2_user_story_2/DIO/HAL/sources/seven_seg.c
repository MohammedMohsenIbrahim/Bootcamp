/*
 * seven_seg.c
 *
 * Created: 2/18/2019 12:47:24 PM
 *  Author: AVE-LAP-069
 */ 

/****************************** Includes ********************************/
#include "../headers/seven_seg.h"

/**************************** Functions Definitions ***************************/

/****************************************************************************

Function Name		 : BCDSevegments_init

Function Description : Function responsible for initialization the seven seg module module

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void BCDSevegments_init(){
		DIO_SetPinDirection(SEVEN_SEG_DB,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEG_PIN1,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEG_PIN2,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEG_PIN3,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEG_PIN4,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEGMENT1_ENABLE,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEGMENT2_ENABLE,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEGMENT3_ENABLE,OUTPUT);
		DIO_SetPinDirection(SEVEN_SEGMENT4_ENABLE,OUTPUT);
}

/****************************************************************************

Function Name		 : BCDSevegents_enable

Function Description : Function responsible for enable certain seven segment 

Function Parameters  : 
					   seven_seg_num : number of seven seg module wanted to be enabled

Function Return      : N/A

*******************************************************************************/

void BCDSevegments_enable(uint8 seven_seg_num){

	switch(seven_seg_num){
		case FIRST_SEVEN_SEG : 
			DIO_WritePin(SEVEN_SEGMENT1_ENABLE,HIGH);
		break;
		case SECOND_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT2_ENABLE,HIGH);	
		break;
		case THIRD_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT3_ENABLE,HIGH);				
		break;
		case FORTH_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT4_ENABLE,HIGH);				
		break ;
		default:
		break;	
	}
}

/****************************************************************************

Function Name		 : BCDSevegments_disable

Function Description : Function responsible for disable certain seven segment module

Function Parameters  :
					   seven_seg_num : number of seven seg wanted to be disabled 

Function Return      : N/A

*******************************************************************************/

void BCDSevegments_disable(uint8 seven_seg_num){
	switch(seven_seg_num){
		case FIRST_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT1_ENABLE,LOW);
		break;
		case SECOND_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT2_ENABLE,LOW);
		break;
		case THIRD_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT3_ENABLE,LOW);
		break;
		case FORTH_SEVEN_SEG :
			DIO_WritePin(SEVEN_SEGMENT4_ENABLE,LOW);
		break ;
		default:
		break;
	}
}

/****************************************************************************

Function Name		 : LCD_init

Function Description : Function responsible for initialization the LCD module

Function Parameters  : 
					   displayed_num : BCD number wanted to be displayed in the seven segment

Function Return      : N/A

*******************************************************************************/
void BCDSevegments_displayNo(uint8 displayed_num){
	if(displayed_num >= LEAST_CHAR_DISPLAYED_7SEG  && displayed_num <= MOST_CHAR_DISPLAYED_7SEG ){
		SEVEN_SEG_DATA_PORT &= MOST_FOUR_BITS_MASK ;
		SEVEN_SEG_DATA_PORT |= displayed_num ;
	}else if(displayed_num == '.'){
		DIO_WritePin(SEVEN_SEG_DB,HIGH);
	}else{
		
	}
}