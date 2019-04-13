/*
 * CAN.h
 *
 *  Created on: Apr 3, 2019
 *      Author: AVE-LAP-069
 */

#ifndef MCAL_HEADERS_CAN_H_
#define MCAL_HEADERS_CAN_H_

/***************************************************** Includes ************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/can.h"
#include "inc/hw_types.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "inc/hw_can.h"
#include "CAN_PreCompile_config.h"
/**************************************************** Definitions **********************************************/
#define CAN_DATA_BYTES_NO           8



/************************************************* Global Variables ********************************************/
tCANBitClkParms CANBitClk;
tCANMsgObject sMsgObjectRx;
tCANMsgObject sMsgObjectTx;
uint8_t pui8BufferIn[8];
uint8_t pui8BufferOut[8];





/**************************************************** Global Arrays *********************************************/
volatile uint8_t can_messages_tx_arr[CAN_DATA_BYTES_NO];
volatile uint8_t can_messages_rx_arr[CAN_DATA_BYTES_NO];

/******************************************************** Enums *************************************************/
enum can_messgae_ides{
    FIRST_msg_id = 0 ,

};

enum can_mailboxes{
    FIRST_mailbox = 1 ,
    Second_mailbox
};


#define RX_MAILBOX              FIRST_mailbox
#define TX_MAILBOX              Second_mailbox

/***********************************************************************************************************************

Function Name           : CAN0_init

Function Description    : Function Responsible for init CAN0 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_init();

/***********************************************************************************************************************

Function Name           : CAN1_init

Function Description    : Function Responsible for init CAN1 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN1_init();

/***********************************************************************************************************************

Function Name           : CAN0_Enable

Function Description    : Function Responsible for enabling CAN0 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_Enable();

/***********************************************************************************************************************

Function Name           : CAN1_Enable

Function Description    : Function Responsible for enabling CAN1 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN1_Enable();


/***********************************************************************************************************************

Function Name           : CAN0_msg_config

Function Description    : Function Responsible for msg configurations of the sent messages

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_config_TX(uint32_t msg_id);

/***********************************************************************************************************************

Function Name           : CAN0_msg_config

Function Description    : Function Responsible for msg configurations of the received messages

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_config_RX(uint32_t msg_id);


/***********************************************************************************************************************

Function Name           : CAN0_msg_send

Function Description    : Function Responsible for sending configured msg via CAN

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_send();

/***********************************************************************************************************************

Function Name           : CAN0_msg_receive

Function Description    : Function Responsible for receiving configured msg via CAN

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_receive();

#endif /* MCAL_HEADERS_CAN_H_ */
