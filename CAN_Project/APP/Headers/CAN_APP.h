/*
 * CAN_APP.h
 *
 *  Created on: Apr 3, 2019
 *      Author: AVE-LAP-069
 */

#ifndef APP_HEADERS_CAN_APP_H_
#define APP_HEADERS_CAN_APP_H_

/*********************************************** Includes *************************************************************/
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
#include "utils/uartstdio.h"
#include "LED.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "Push_Button.h"
#include "../../../Service/Headers/types.h"
#include "../../../Service/Headers/tm4c123gh6pm.h"
#include "../../../Service/Headers/bitwise_operation.h"
#include "driverlib/debug.h"
#include "CAN.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
#include "message_buffer.h"


/*********************************************** Definitions ********************************************************/


#define BIT_0   ( 1 << 0 )
#define LED_BIT_EVENT_FLAG  BIT_0

#define LOW                     0
#define STARTUP_NODE_VAL        1

#define SRC_INDEX               0
#define DEST_INDEX              1
#define TOKEN_INDEX             2
#define SWITCH_INDEX            3
#define STARTUP_NODE_INDEX      4

#ifdef NODE1

#define THIS_NODE_ID                FIRST_NODE_ID
#define NEXT_NODE_ID                SECOND_NODE_ID
#define PREV_NODE_ID                THIRD_NODE_ID
#define TOKEN_ID                    74

#define THIS_NODE_LED_PORT          LED1_PORT_BASE
#define THIS_NODE_LED_PIN           LED1_PIN_NUM

#endif

#ifdef NODE2
    #define THIS_NODE_ID            SECOND_NODE_ID
    #define NEXT_NODE_ID            THIRD_NODE_ID
    #define PREV_NODE_ID                FIRST_NODE_ID
    #define TOKEN_ID                74

    #define THIS_NODE_LED_PORT      LED2_PORT_BASE
    #define THIS_NODE_LED_PIN       LED2_PIN_NUM
#endif

#ifdef NODE3
    #define THIS_NODE_ID            THIRD_NODE_ID
    #define NEXT_NODE_ID            FIRST_NODE_ID
    #define PREV_NODE_ID            SECOND_NODE_ID
    #define TOKEN_ID                74
    #define THIS_NODE_LED_PORT      LED3_PORT_BASE
    #define THIS_NODE_LED_PIN       LED3_PIN_NUM

#endif




/************************************************* ENUMS ************************************************************/
enum CAN_APP_NODES_ID{
  FIRST_NODE_ID = 1 ,
  SECOND_NODE_ID    ,
  THIRD_NODE_ID
};

enum CAN_APP_MESSAGES_ID{
  TAKE_TOKEN_msg_id = 0 ,
};

/****************************************** Global Vars and arrs ****************************************************/
extern volatile uint8_t can_messages_tx_arr[CAN_DATA_BYTES_NO];
extern volatile uint8_t can_messages_rx_arr[CAN_DATA_BYTES_NO];
extern volatile bool g_bRXFlag1  ;
extern volatile bool g_bRXFlag2  ;
extern volatile bool g_bErrFlag ;

extern volatile uint8_t Switch_State  ;
extern volatile uint8_t Action_Switch_State ;

volatile EventGroupHandle_t led_event_gp;

extern void SimpleDelay();
/*********************************************************************************************************************

Function Name           : CAN_APP_sys_init

Function Description    : Function responsible for init the system in this APP

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_sys_init();
/*********************************************************************************************************************

Function Name           : CAN_APP_init_Fun

Function Description    : Function responsible for init the modules used in the Application

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_init_fun();

/*********************************************************************************************************************

Function Name           : CAN_APP_config_TX_msg

Function Description    : Function responsible for configuring TX message

Function Params         : TX_msg_id

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_config_TX_msg(uint32_t TX_msg_id);

/*********************************************************************************************************************

Function Name           : CAN_APP_config_RX_msg

Function Description    : Function responsible for configuring RX message

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_config_RX_msg(uint32_t RX_msg_id);

/*********************************************************************************************************************

Function Name           : CAN_APP_config_RX_msg

Function Description    : Function responsible for set the messages will be received

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_rec_set_message();


/*********************************************************************************************************************

Function Name           : CAN_APP_send_the_messages_according_to_state

Function Description    : Function responsible for set the messages will be received

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_send_the_messages_according_to_state();

/*********************************************************************************************************************

Function Name           : CAN_APP_receive_the_messages_according_to_state

Function Description    : Function responsible for receive the message from other node

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_receive_the_messages_according_to_state();

/*********************************************************************************************************************

Function Name           : CAN_APP_node_check_the_token

Function Description    : Function responsible for check the token of the node taken or not and take action

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_node_check_the_token();


/*********************************************************************************************************************

Function Name           : CAN_APP_SELECT_Node_DEST_ID_SEND

Function Description    : Function responsible for selecting the destination node in the send case

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_SELECT_Node_DEST_ID_SEND();


#endif /* APP_HEADERS_CAN_APP_H_ */
