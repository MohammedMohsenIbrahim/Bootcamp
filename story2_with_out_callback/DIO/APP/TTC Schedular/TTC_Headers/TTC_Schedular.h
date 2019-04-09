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
#define TTC_MAX_TASKS_NUM				100 
#define NUM_ZERO						0



/**************************** External Variables and Funs *********************************/
extern volatile void Task_BLINK_LED1();
extern volatile void Task_BLINK_LED2();
extern volatile void Task_BLINK_LED3();
/*************************************** Global Arrays ************************************/
volatile static uint8 Task_counter = 0 ;

static void (*Ready_Tasks_PTR_Array[TTC_MAX_TASKS_NUM])(void) = {Task_BLINK_LED1,Task_BLINK_LED2,Task_BLINK_LED3} ; /* Array of pointers to fun to determine tasks ready to run */

volatile void Call_Back_Fun();
void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void));
void schedulerInit_AndStart();


#endif /* TTC_SCHEDULAR_H_ */