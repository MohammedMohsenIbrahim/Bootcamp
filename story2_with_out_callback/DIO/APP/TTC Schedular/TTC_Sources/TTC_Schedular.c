/*
 * TTC_Schedular.c
 *
 * Created: 2/23/2019 1:58:59 PM
 *  Author: AVE-LAP-069
 */ 


/***************************************** Includes ***************************************/
#include "../TTC_Headers/TTC_Schedular.h"

/**************************************** Functions Definitions *********************************/
volatile void Call_Back_Fun(){
	TTC_Schedular_Select_Ready_Tasks((*Ready_Tasks_PTR_Array[Task_counter]));
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