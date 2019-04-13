/*
 * CAN_TASKS.h
 *
 *  Created on: Apr 4, 2019
 *      Author: AVE-LAP-069
 */

#ifndef OS_TASKS_HEADERS_CAN_TASKS_H_
#define OS_TASKS_HEADERS_CAN_TASKS_H_

/******************************************** Includes ********************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "message_buffer.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#include "CAN_APP.h"


#define RECEIVE_ALL_MESSAGES            0

#define NODE_LED_ON                     1
#define NODE_LED_OFF                    2
#define LED_INIT_STATE                  0

/******************************************************* Declarations ******************************************************/


EventBits_t uxBits;

void init_Task();
void CAN_Tx_Task();
void CAN_Rx_Task();
void CAN_Led_Task();
void CAN_Push_Button_Task();
void CAN_STARTUP_MSG_TASK_Send();
void CAN_STARTUP_MSG_TASK_Rec();
void CAN_LED_Task();


#endif /* OS_TASKS_HEADERS_CAN_TASKS_H_ */
