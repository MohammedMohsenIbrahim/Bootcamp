/*
 * TTC_Schedular.h
 *
 * Created: 2/23/2019 1:59:17 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef TTC_SCHEDULAR_H_
#define TTC_SCHEDULAR_H_


/***************************************** Includes ***************************************/
#include "../../../DIO.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "../../../Service/headers/Selection_Sort.h"
#include "Tasks.h"

/**************************************** Definitions *************************************/
#define TTC_MAX_TASKS_NUM				4
#define NUM_ZERO						0
#define TRUE							1
#define FALSE							0


/**************************** External Variables and Funs *********************************/
extern void Task_BLINK_LED1();
extern void Task_BLINK_LED2();
extern void Task_BLINK_LED3();
extern volatile uint8 Call_Back_Flag ;
extern volatile uint16 timer0_ticks ;
/*************************************** Global Arrays ************************************/
volatile static uint8 Task_counter = 0 ;
volatile uint8 Call_Back_Flag  ;
static void (*Ready_Tasks_PTR_Array[TTC_MAX_TASKS_NUM])(void)  ; /* Array of pointers to fun to determine tasks ready to run */ 

/**************************************** Structures **************************************/
struct Schedular_Struct{
		void (*Ready_Tasks_PTR)(void);
		uint8  se_u8_task_priodicity ;
		uint8  se_u8_rem_ticks_to_execute_task ;
		uint8  se_u8_task_priority ;
}Task_struct[TTC_MAX_TASKS_NUM];

/****************************************************************************

Function Name		 : Schedular_init

Function Description : Function responsible for filling the task structure including the task info


Function Parameters  : N/A 

Function Return      : N/A

*******************************************************************************/
void Schedular_init(void (*Added_Fun_Name)(void),uint8 fun_priority,uint16 task_priodicity);


/****************************************************************************

Function Name		 : scheduler_Remove_Task

Function Description : Function responsible for removing any task from the scheduler

Function Parameters  : Task_index : the index of the task wanted to be removed  					  
						
Function Return      : N/A

*******************************************************************************/
void scheduler_Remove_Task(uint8 Task_index);


/****************************************************************************

Function Name		 : schedulerStart_according_periodicity_priority

Function Description : Function responsible for running the tasks from tasks struct according to the periodicity and priority


Function Parameters  : N/A 
					  
						
Function Return      : N/A

*******************************************************************************/
 void schedulerStart_according_periodicity_priority();


/****************************************************************************

Function Name		 : schedulerStart

Function Description : Function responsible for running the tasks from tasks struct according to the periodicity


Function Parameters  : 
					   void (*Added_Fun_Name)(void) : pointer to function wanted to added to ready array 
					   fun_priority    : index of function in ready array 
					   task_priodicity : no of second of each task to run
						
Function Return      : N/A

*******************************************************************************/
void schedulerStart();


/****************************************************************************

Function Name		 : Schedular_Add_Task

Function Description : Function responsible for adding the the ready tasks to run to the task array 
					   at the first empty position if no empty position found the fun will return False

Function Parameters  : void (*Added_Fun_Name)(void) : fun wanted to be added into the array 

Function Return      : N/A

*******************************************************************************/
uint8 Schedular_Add_Task(void (*Added_Fun_Name)(void));

/****************************************************************************

Function Name		 : Schedular_run_tasks

Function Description : Function Responsible for running the ready tasks from ready tasks array

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Schedular_run_tasks();



void Set_Call_Back_Flag();
void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void));
void schedulerInit_AndStart();


#endif /* TTC_SCHEDULAR_H_ */