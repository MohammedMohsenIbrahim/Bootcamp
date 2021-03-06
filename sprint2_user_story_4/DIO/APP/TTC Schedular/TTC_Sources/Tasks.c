/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:29:18 PM
 *  Author: AVE-LAP-069
 */ 

/******************************************* Includes ****************************************/
#include "../TTC_Headers/Tasks.h"


/**************************************** Functions Definitions *********************************/
/****************************************************************************

Function Name		 : Tasks_init

Function Description : Function responsible for initialization all tasks

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Tasks_init(){
	 DIO_SetPinDirection(LED1_PIN_NUM,OUTPUT);
	 DIO_SetPinDirection(LED2_PIN_NUM,OUTPUT);
	 DIO_SetPinDirection(LED3_PIN_NUM,OUTPUT);
	 DIO_SetPinDirection(REMOVE_TASK_BTN_NUM,INPUT);
	 DIO_WritePin(REMOVE_TASK_BTN_NUM,HIGH);
	 TIMER0_OCR_init(TICKS_FOR_1MS);
}

/****************************************************************************

Function Name		 : Task_BLINK_LED1

Function Description : Function responsible for Blinking the first task 

Function Parameters  : N/A 

Function Return      : N/A

*******************************************************************************/
void Task_BLINK_LED1(){
	if(Call_Back_Flag == TRUE){
		Toggle_Bit(LED1_PORT,5);
	}
}

/****************************************************************************

Function Name		 : Task_BLINK_LED2

Function Description : Function responsible for Blinking the second task

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void  Task_BLINK_LED2(){
	if(Call_Back_Flag == TRUE){	
		Toggle_Bit(LED2_PORT,6);
	}
}

/****************************************************************************

Function Name		 : Task_BLINK_LED3

Function Description : Function responsible for Blinking the third task

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Task_BLINK_LED3(){
  if(Call_Back_Flag == TRUE){	
	Toggle_Bit(LED3_PORT,7);
  }
}