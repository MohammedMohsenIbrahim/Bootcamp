/*
 * Traffic_light_int.h
 *
 * Created: 2/20/2019 5:06:01 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef TRAFFIC_LIGHT_INT_H_
#define TRAFFIC_LIGHT_INT_H_

/*************************************************** Includes **************************************************/ 
#include "../../DIO.h"
#include "../../Timers.h"
#include <avr/interrupt.h>


/************************************************** Definitions ************************************************/
#define TRAFFIC_STOP_STATE			0
#define TRAFFIC_WAIT_STATE			1
#define TRAFFIC_GO_STATE			2

#define TRAFFIC_STOP_LED_NUM		13
#define TRAFFIC_WAIT_LED_NUM		14
#define TRAFFIC_GO_LED_NUM			15
#define TRAFFIC_BTN_NUM				20
#define ONE_MS_TICKS				250
#define ONE_THOUSAND				1000

/*********************************************** Global Variables **********************************************/
static volatile uint16 Global_u16_delay_ticks = NUM_ZERO ;
static volatile uint8  Global_u8_traffic_states = TRAFFIC_STOP_STATE ;
/********************************************* Functions Declarations ******************************************/
/****************************************************************************

Function Name		 : Traffic_light_init

Function Description : Function responsible for initialization modules in the Traffic light app

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Traffic_light_init();

/****************************************************************************

Function Name		 : Traffic_light_delay_ISR

Function Description : Function responsible for increment the timer0 counter in each delay

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Traffic_light_delay_ISR();

/****************************************************************************

Function Name		 : Traffic_light_swap_states

Function Description : Function responsible for activate go , stop , wait states in order with delay between them

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void Traffic_light_swap_states();



#endif /* TRAFFIC_LIGHT_INT_H_ */