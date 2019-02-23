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

/*************************************** Global Arrays ************************************/
void (*Ready_Tasks_PTR_Array[TTC_MAX_TASKS_NUM])(void) ;



void TTC_Schedular_Select_Ready_Tasks(void (*u32_ready_fun_ptr)(void),uint8 u8_ready_fun_piriority);
void schedulerInit_AndStart();

#endif /* TTC_SCHEDULAR_H_ */