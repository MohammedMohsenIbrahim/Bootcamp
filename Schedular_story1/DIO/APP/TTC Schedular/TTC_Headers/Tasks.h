/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:29:39 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef TASKS_H_
#define TASKS_H_

/******************************************* Includes ****************************************/
#include "../../../Memory_Mapped_Registers.h"
#include "../../../DIO.h"

/***************************************** Definitions ***************************************/
#define LED1_PORT							PORT_B
#define LED2_PORT							PORT_B
#define LED3_PORT							PORT_B

#define LED1_PIN_NUM						13
#define LED2_PIN_NUM						14
#define LED3_PIN_NUM						15

#define TICKS_FOR_1MS						1


void Tasks_init();
void Task_BLINK_LED1();
void Task_BLINK_LED2();
void Task_BLINK_LED3();

#endif /* TASKS_H_ */