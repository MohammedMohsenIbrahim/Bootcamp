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

Function Name		 : TTC_Schedular_Select_Ready_Tasks

Function Description : Function responsible for Selecting the tasks ready to run and select the priority of it 
					   depends on it's position in TTC_Ready_Tasks_queue

Function Parameters  : 
					   *u32_ready_fun_ptr(void)(void) : pointer to fun responsible for determine which fun will be pushed
					   into the ready queue	
					   
					  u8_ready_fun_piriority : the position of the function in the ready tasks queue which determine the 
					  priority of the function (0 => the highest priority) 

Function Return      : N/A

*******************************************************************************/
void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void),uint8 u8_ready_fun_piriority){
	Ready_Tasks_PTR_Array[u8_ready_fun_piriority] = u32_ready_fun_ptr ; 
} 


/****************************************************************************

Function Name		 : schedulerInit_AndStart

Function Description : Function responsible for running the ready tasks according their order in the u8_ready_fun_piriority

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void schedulerInit_AndStart(){
	uint8 Local_u8_ready_taks_counter = NUM_ZERO ;
	for(Local_u8_ready_taks_counter = NUM_ZERO;Local_u8_ready_taks_counter < TTC_MAX_TASKS_NUM;Local_u8_ready_taks_counter++){
		if(Ready_Tasks_PTR_Array[Local_u8_ready_taks_counter] != NUM_ZERO){
			(*Ready_Tasks_PTR_Array[Local_u8_ready_taks_counter])() ;
		}
	}
	
}