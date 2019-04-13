/*
 * CAN.c
 *
 *  Created on: Apr 3, 2019
 *      Author: AVE-LAP-069
 */
/***************************************************** Includes ************************************************/
#include "CAN.h"






/***********************************************************************************************************************

Function Name           : CAN0_init

Function Description    : Function Responsible for init CAN0 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_init(){
    /*
        For this example CAN0 is used with RX and TX pins on port B4 and B5.
        The actual port and pins used may be different on your part, consult
        the data sheet for more information.
        GPIO port B needs to be enabled so these pins can be used.
        TODO: change this to whichever GPIO port you are using
       */
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

       /*
        Configure the GPIO pin muxing to select CAN0 functions for these pins.
        This step selects which alternate function is available for these pins.
        This is necessary if your part supports GPIO pin function muxing.
        Consult the data sheet to see which functions are allocated per pin.
        TODO: change this to select the port/pin you are using
       */
       GPIOPinConfigure(GPIO_PB4_CAN0RX);
       GPIOPinConfigure(GPIO_PB5_CAN0TX);

       /*
        Enable the alternate function on the GPIO pins.  The above step selects
        which alternate function is available.  This step actually enables the
        alternate function instead of GPIO for these pins.
        TODO: change this to match the port/pin you are using
       */
       GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);


    /* Enable the CAN0 module */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    /* Wait for the CAN0 module to be ready */

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_CAN0))
    {
    }



    /*   Reset the state of all the message objects and the state of the CAN
       module to a known state */

    CANInit(CAN0_BASE);

    /*
     Set up the bit rate for the CAN bus.  This function sets up the CAN
     bus timing for a nominal configuration.  You can achieve more control
     over the CAN bus timing by using the function CANBitTimingSet() instead
     of this one, if needed.
     In this example, the CAN bus is set to 500 kHz.  In the function below,
     the call to SysCtlClockGet() or ui32SysClock is used to determine the
     clock rate that is used for clocking the CAN peripheral.  This can be
     replaced with a  fixed value if you know the value of the system clock,
     saving the extra function call.  For some parts, the CAN peripheral is
     clocked by a fixed 8 MHz regardless of the system clock in which case
     the call to SysCtlClockGet() or ui32SysClock should be replaced with
     8000000.  Consult the data sheet for more information about CAN
     peripheral clocking.
    */
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
#else
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
#endif

    /*
     Enable interrupts on the CAN peripheral.  This example uses static
     allocation of interrupt handlers which means the name of the handler
     is in the vector table of startup code.  If you want to use dynamic
     allocation of the vector table, then you must also call CANIntRegister()
     here.

    // CANIntRegister(CAN0_BASE, CANIntHandler); // if using dynamic vectors
    */
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    /*
     Enable the CAN interrupt on the processor (NVIC).
    */
    IntEnable(INT_CAN0);

    CAN0_Enable();
}

/***********************************************************************************************************************

Function Name           : CAN1_init

Function Description    : Function Responsible for init CAN1 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN1_init(){

    /* Enable the CAN1 module */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN1);

    /* Wait for the CAN1 module to be ready */

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_CAN1))
    {
    }

    /*   Reset the state of all the message objects and the state of the CAN
       module to a known state */

    CANInit(CAN1_BASE);

    CAN1_Enable();
}


/***********************************************************************************************************************

Function Name           : CAN0_Enable

Function Description    : Function Responsible for enabling CAN0 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/

void CAN0_Enable(){
    CANEnable(CAN0_BASE);
}


/***********************************************************************************************************************

Function Name           : CAN1_Enable

Function Description    : Function Responsible for enabling CAN1 Module

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN1_Enable(){
    CANEnable(CAN1_BASE);
}



/***********************************************************************************************************************

Function Name           : CAN0_msg_config_TX

Function Description    : Function Responsible for msg configurations of the sent messages

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_config_TX(uint32_t msg_id){

    sMsgObjectTx.ui32MsgID = msg_id;
    sMsgObjectTx.ui32MsgIDMask = 0;
    sMsgObjectTx.ui32Flags =  MSG_OBJ_TX_INT_ENABLE ;
    sMsgObjectTx.ui32MsgLen = sizeof(can_messages_tx_arr);
    sMsgObjectTx.pui8MsgData = can_messages_tx_arr;
    CANMessageSet(CAN0_BASE,TX_MAILBOX, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}

/***********************************************************************************************************************

Function Name           : CAN0_msg_config

Function Description    : Function Responsible for msg configurations of the received messages

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_config_RX(uint32_t msg_id){
    sMsgObjectRx.ui32MsgID = msg_id;
    sMsgObjectRx.ui32MsgIDMask = 0;
    sMsgObjectRx.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sMsgObjectRx.ui32MsgLen = 8;
    sMsgObjectRx.pui8MsgData = can_messages_rx_arr;

    CANMessageSet(CAN0_BASE,RX_MAILBOX, &sMsgObjectRx, MSG_OBJ_TYPE_RX);
}

/***********************************************************************************************************************

Function Name           : CAN0_msg_send

Function Description    : Function Responsible for sending configured msg via CAN

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_send(){
    CANMessageSet(CAN0_BASE,TX_MAILBOX, &sMsgObjectTx, MSG_OBJ_TYPE_TX);
}


/***********************************************************************************************************************

Function Name           : CAN0_msg_receive

Function Description    : Function Responsible for receiving configured msg via CAN

Function Parameters     : N/A

Function Return         : N/A

************************************************************************************************************************/
void CAN0_msg_receive(){
    CANMessageGet(CAN0_BASE,RX_MAILBOX, &sMsgObjectRx, 0);

}
