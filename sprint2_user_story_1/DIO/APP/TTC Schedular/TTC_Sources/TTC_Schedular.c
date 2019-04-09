/*
 * TTC_Schedular.c
 *
 * Created: 2/23/2019 1:58:59 PM
 *  Author: AVE-LAP-069
 */ 


/***************************************** Includes ***************************************/
#include "../TTC_Headers/TTC_Schedular.h"

/**************************************** Functions Definitions *********************************/
/****************************************************************************

Function Name		 : Schedular_Add_Task

Function Description : Function responsible for adding the the ready tasks to run to the task array 
					   at the first empty position if no empty position found the fun will return False

Function Parameters  : void (*Added_Fun_Name)(void) : fun wanted to be added into the array 

Function Return      : N/A

*******************************************************************************/
uint8 Schedular_Add_Task(void (*Added_Fun_Name)(void)){
	static uint16 Local_u16_ready_tasks_array_counter = 0 ;
	if(NULL == Ready_Tasks_PTR_Array[Local_u16_ready_tasks_array_counter] && TTC_MAX_TASKS_NUM > Local_u16_ready_tasks_array_counter){
		Ready_Tasks_PTR_Array[Local_u16_ready_tasks_array_counter] = Added_Fun_Name ;
		Local_u16_ready_tasks_array_counter++ ;

		return TRUE ;
	}else{
		return FALSE ;
	}
}

/****************************************************************************

Function Name		 : Schedular_run_tasks

Function Description : Function Responsible for running the ready tasks from ready tasks array 

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Schedular_run_tasks(){
	static uint16 Local_u16_ready_tasks_array_index = 0 ;
	if(NULL != Ready_Tasks_PTR_Array[Local_u16_ready_tasks_array_index]){
		(*Ready_Tasks_PTR_Array[Local_u16_ready_tasks_array_index])();
		Local_u16_ready_tasks_array_index++ ;
	}
}

/****************************************************************************

Function Name		 : TTC_Schedular

Function Description : Function responsible for checking the ready flags to run and run the tasks 


Function Parameters  : N/A	

Function Return      : N/A

*******************************************************************************/
void TTC_Schedular(){
	if(TRUE == Call_Back_Flag){
		Call_Back_Flag = FALSE ;
		Task_BLINK_LED1();
		Task_BLINK_LED2();
		Task_BLINK_LED3();
	}	
}

/****************************************************************************

Function Name		 : TTC_Schedular_Select_Ready_Tasks

Function Description : Function responsible for Selecting the tasks ready to run and select the priority of it 
					   depends on it's position in TTC_Ready_Tasks_queue

Function Parameters  : 
					   *u32_ready_fun_ptr(void)(void) : pointer to fun responsible for determine which fun will be pushed
					   into the ready queue	

Function Return      : N/A

*******************************************************************************/
void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void)){
	if(Ready_Tasks_PTR_Array[Task_counter] != NUM_ZERO && Task_counter < TTC_MAX_TASKS_NUM){
		Ready_Tasks_PTR_Array[Task_counter] = u32_ready_fun_ptr ; 
		schedulerInit_AndStart();
		Task_counter++ ;
	}else{
		Task_counter++ ;
	}
} 


/****************************************************************************

Function Name		 : schedulerInit_AndStart

Function Description : Function responsible for running the ready tasks according their order in the u8_ready_fun_piriority

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void schedulerInit_AndStart(){

		if(Ready_Tasks_PTR_Array[Task_counter] != NUM_ZERO && Task_counter < TTC_MAX_TASKS_NUM){
			(*Ready_Tasks_PTR_Array[Task_counter])() ;
		}else{
		}
	
	
}