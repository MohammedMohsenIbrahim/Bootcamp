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
#include <util/delay.h>

/**************************************** Definitions *************************************/
#define TTC_MAX_TASKS_NUM				2 
#define NUM_ZERO						0
#define TRUE							1
#define FALSE							0


/**************************** External Variables and Funs *********************************/
extern volatile void Task_BLINK_LED1();
extern volatile void Task_BLINK_LED2();
extern volatile void Task_BLINK_LED3();
extern volatile uint8 Call_Back_Flag ;
/*************************************** Global Arrays ************************************/
volatile static uint8 Task_counter = 0 ;
volatile uint8 Call_Back_Flag  ;



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




static void (*Ready_Tasks_PTR_Array[TTC_MAX_TASKS_NUM])(void)  ; /* Array of pointers to fun to determine tasks ready to run */
void Set_Call_Back_Flag();
void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void));
void schedulerInit_AndStart();


#endif /* TTC_SCHEDULAR_H_ */