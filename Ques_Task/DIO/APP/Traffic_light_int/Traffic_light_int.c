/*
 * Traffic_light_int.c
 *
 * Created: 2/20/2019 5:00:04 PM
 *  Author: AVE-LAP-069
 */ 

/**************************************** Includes ************************************/
#include "Traffic_light_int.h"
#include "../../ISR.h"

/************************* Functions Definitions ***************************/
/****************************************************************************

Function Name		 : Traffic_light_init

Function Description : Function responsible for initialization modules in the Traffic light app

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void Traffic_light_init(){
	sei();
	DIO_SetPinDirection(TRAFFIC_STOP_LED_NUM,OUTPUT);
	DIO_SetPinDirection(TRAFFIC_WAIT_LED_NUM,OUTPUT);
	DIO_SetPinDirection(TRAFFIC_GO_LED_NUM,OUTPUT);
	DIO_SetPinDirection(TRAFFIC_BTN_NUM,INPUT);
	TIMER0_OCR_init(ONE_MS_TICKS);
}

/****************************************************************************

Function Name		 : Traffic_light_delay_ISR

Function Description : Function responsible for increment the timer0 counter in each delay

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void Traffic_light_delay_ISR(){
	Global_u16_delay_ticks++ ;
	if(Global_u16_delay_ticks < ONE_THOUSAND){
		sei();
	}else{
		Global_u16_delay_ticks = 0 ;
	}
}


/****************************************************************************

Function Name		 : Traffic_light_swap_states

Function Description : Function responsible for activate go , stop , wait states in order with delay between them

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void Traffic_light_swap_states(){
	
	switch(Global_u8_traffic_states){
		case TRAFFIC_STOP_STATE :
			DIO_WritePin(TRAFFIC_STOP_LED_NUM,HIGH);
			DIO_WritePin(TRAFFIC_WAIT_LED_NUM,LOW);
			DIO_WritePin(TRAFFIC_GO_LED_NUM,LOW);
			Global_u8_traffic_states = TRAFFIC_WAIT_STATE ;
		break;
		case TRAFFIC_WAIT_STATE :
			DIO_WritePin(TRAFFIC_WAIT_LED_NUM,HIGH);
			DIO_WritePin(TRAFFIC_STOP_LED_NUM,LOW);
			DIO_WritePin(TRAFFIC_GO_LED_NUM,LOW);
			Global_u8_traffic_states = TRAFFIC_GO_STATE ;
		break;
		case TRAFFIC_GO_STATE   :
			DIO_WritePin(TRAFFIC_GO_LED_NUM,HIGH);
			DIO_WritePin(TRAFFIC_STOP_LED_NUM,LOW);
			DIO_WritePin(TRAFFIC_WAIT_LED_NUM,LOW);
			Global_u8_traffic_states = TRAFFIC_STOP_STATE ;
		break; 
	}

	
	
}