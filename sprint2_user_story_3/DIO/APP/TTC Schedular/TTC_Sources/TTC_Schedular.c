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

Function Name		 : Schedular_init

Function Description : Function responsible for filling the task structure including the task info


Function Parameters  : 
					   void (*Added_Fun_Name)(void) : pointer to function wanted to added to ready array 
					   fun_priority    : index of function in ready array 
					   task_priodicity : no of second of each task to run
						
Function Return      : N/A

*******************************************************************************/
void Schedular_init(void (*Added_Fun_Name)(void),uint8 fun_priority,uint16 task_periodicity){
	static uint8 Local_u8_task_struct_index = NUM_ZERO;
	Task_struct[Local_u8_task_struct_index].Ready_Tasks_PTR = Added_Fun_Name ; /* Add the function name of the task will run to the struct */
	Task_struct[Local_u8_task_struct_index].se_u8_task_priodicity = task_periodicity ; /* receive task periodicity from user */
	Task_struct[Local_u8_task_struct_index].se_u8_rem_ticks_to_execute_task = task_periodicity ; /* init periodicity with tick */
	Task_struct[Local_u8_task_struct_index].se_u8_task_priority = fun_priority ; /* set the priority of the task */
	Local_u8_task_struct_index++ ;
}

/****************************************************************************

Function Name		 : scheduler_Remove_Task

Function Description : Function responsible for removing any task from the scheduler


Function Parameters  : N/A 
					  
						
Function Return      : N/A

*******************************************************************************/


/****************************************************************************

Function Name		 : schedulerStart_according_periodicity_priority

Function Description : Function responsible for running the tasks from tasks struct according to the periodicity and priority


Function Parameters  : N/A 
					  
						
Function Return      : N/A

*******************************************************************************/
 void schedulerStart_according_periodicity_priority(){
	static uint8 Local_u8_task_counter = NUM_ZERO ;  /* Define counter to count the task ready to run */
	uint8 Local_u8_task_rem_time_counter ; /* Declare counter to loop on tasks to reduce the remaining time */
	uint8 Local_u8_arr_ready_task[TTC_MAX_TASKS_NUM] ; /* Declare array to save ready tasks to run */
	uint8 Local_u8_ready_tasks_index = NUM_ZERO ;
	
	
	for(Local_u8_task_rem_time_counter = NUM_ZERO ;Local_u8_task_rem_time_counter < TTC_MAX_TASKS_NUM;Local_u8_task_rem_time_counter++){
		if(NULL != Task_struct[Local_u8_task_counter].Ready_Tasks_PTR){ /* In case of valid task added to the tasks array of structure */
			Task_struct[Local_u8_task_rem_time_counter].se_u8_rem_ticks_to_execute_task-- ; /* Decrease the remaining  time each tick for all tasks */
			/* Check tasks to detect which on ready to be executed => rem time = 0 */
			if(NUM_ZERO == Task_struct[Local_u8_task_rem_time_counter].se_u8_rem_ticks_to_execute_task){
				Local_u8_arr_ready_task[Local_u8_ready_tasks_index] = 	Task_struct[Local_u8_task_rem_time_counter].se_u8_task_priority ; /* save the ready tasks in the ready tasks array */
				Local_u8_ready_tasks_index++ ; /* increment array counter for ready tasks */
			}
		}
	}
	/* sort the array to determine which task will run first */
	selectionSort(Local_u8_arr_ready_task,Local_u8_ready_tasks_index);
	/* Run the ready tasks */
	for(Local_u8_task_rem_time_counter = NUM_ZERO ;Local_u8_task_rem_time_counter < Local_u8_ready_tasks_index;Local_u8_task_rem_time_counter++){
		Task_struct[Local_u8_arr_ready_task[Local_u8_task_rem_time_counter]].Ready_Tasks_PTR(); /* call the function ready to run */
	}
	
	
}

/****************************************************************************

Function Name		 : schedulerStart

Function Description : Function responsible for running the tasks from tasks struct according to the periodicity


Function Parameters  : N/A
						
Function Return      : N/A

*******************************************************************************/
void schedulerStart(){
	static uint8 Local_u8_task_counter = 0 ;  /* Define counter to count the task ready to run */
	uint8 Local_u8_task_rem_time_counter ; /* Declare counter to loop on tasks to reduce the remaining time */
	for(Local_u8_task_rem_time_counter = 0 ;Local_u8_task_rem_time_counter < TTC_MAX_TASKS_NUM;Local_u8_task_rem_time_counter++){
		Task_struct[Local_u8_task_rem_time_counter].se_u8_rem_ticks_to_execute_task-- ; /* Decrease the remaining  time each tick for all tasks */
	}
	
	if(NUM_ZERO == Task_struct[Local_u8_task_counter].se_u8_rem_ticks_to_execute_task && NULL != Task_struct[Local_u8_task_counter].Ready_Tasks_PTR){ /* in case of no remaining time */
			Task_struct[Local_u8_task_counter].Ready_Tasks_PTR(); /* call the function ready to run */
			Local_u8_task_counter++ ; /* move to the next function in ready functions array */
			if(TTC_MAX_TASKS_NUM <= Local_u8_task_counter){ /* if the functions ready to run finished */
				Local_u8_task_counter = NUM_ZERO ; /* go the the first task again */
				timer0_ticks = NUM_ZERO ;
			}
	}
}

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