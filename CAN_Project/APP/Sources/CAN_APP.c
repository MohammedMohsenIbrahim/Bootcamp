/*
 * CAN_APP.c
 *
 *  Created on: Apr 3, 2019
 *      Author: AVE-LAP-069
 */


/********************************************************* Includes **************************************************/
#include "../Headers/CAN_APP.h"
#include "FreeRtos.h"
#include "task.h"



static volatile uint8_t Token_Flag = 0 ;

extern volatile uint8_t APP_Regulator_ctr ;
/*********************************************************************************************************************

Function Name           : CAN_APP_sys_init

Function Description    : Function responsible for init the system in this APP

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_sys_init(){

#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    uint32_t ui32SysClock;
#endif

    /*
     Set the clocking to run directly from the external crystal/oscillator.
     TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
     crystal on your board.
    */
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                       SYSCTL_OSC_MAIN |
                                       SYSCTL_USE_OSC)
                                       25000000);
#else
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
#endif

}



/*********************************************************************************************************************

Function Name           : CAN_APP_init_Fun

Function Description    : Function responsible for init the modules used in the Application

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_init_fun(){

    LED_init(LED1_SYS_CTRL_PORT,LED1_PORT_BASE,LED1_PIN_NUM);
    LED_init(LED2_SYS_CTRL_PORT,LED2_PORT_BASE,LED2_PIN_NUM);
    LED_init(LED3_SYS_CTRL_PORT,LED3_PORT_BASE,LED3_PIN_NUM);
    Push_Button_init(PUSH_BUTTON1_PIN_NUM);

    CAN0_init();

    led_event_gp = xEventGroupCreate();


}

/*********************************************************************************************************************

Function Name           : CAN_APP_config_TX_msg

Function Description    : Function responsible for configuring TX message

Function Params         : TX_msg_id

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_config_TX_msg(uint32_t TX_msg_id){
    CAN0_msg_config_TX(TX_msg_id);
}

/*********************************************************************************************************************

Function Name           : CAN_APP_config_RX_msg

Function Description    : Function responsible for configuring RX message

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_config_RX_msg(uint32_t RX_msg_id){
    CAN0_msg_config_RX(RX_msg_id);

}

/*********************************************************************************************************************

Function Name           : CAN_APP_config_RX_msg

Function Description    : Function responsible for set the messages will be received

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_rec_set_message(){
    CANMessageSet(CAN0_BASE,RX_MAILBOX, &sMsgObjectRx, MSG_OBJ_TYPE_RX); // ????????????????????????????????????
}


/*********************************************************************************************************************

Function Name           : CAN_APP_send_the_messages_according_to_state

Function Description    : Function responsible for set the messages will be received

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_send_the_messages_according_to_state(){

    can_messages_tx_arr[SRC_INDEX]          = THIS_NODE_ID         ;
    can_messages_tx_arr[DEST_INDEX]         = NEXT_NODE_ID         ;
    can_messages_tx_arr[TOKEN_INDEX]        = TOKEN_ID             ;
    can_messages_tx_arr[SWITCH_INDEX]       = Switch_State         ;


    CAN_APP_SELECT_Node_DEST_ID_SEND();
    #ifdef NODE1
        can_messages_tx_arr[STARTUP_NODE_INDEX] = STARTUP_NODE_VAL     ;
    #endif
  //  if(Token_Flag == 1 && can_messages_tx_arr[STARTUP_NODE_INDEX] != STARTUP_NODE_VAL ){
   //     sMsgObjectTx.pui8MsgData = can_messages_tx_arr        ;
   //     CANMessageSet(CAN0_BASE,TX_MAILBOX,&sMsgObjectTx,MSG_OBJ_TYPE_TX);
   //     Token_Flag = 0 ;
  //  }else{
        sMsgObjectTx.pui8MsgData = can_messages_tx_arr        ;
        CANMessageSet(CAN0_BASE,TX_MAILBOX,&sMsgObjectTx,MSG_OBJ_TYPE_TX);
        can_messages_tx_arr[STARTUP_NODE_INDEX] = 0     ;
//    }



    if(sMsgObjectTx.ui32Flags & MSG_OBJ_DATA_LOST)
      {
             /* report message lost error */
            UARTprintf("CAN TX message loss detected\n");
      }else{
    int uIdx ;
    UARTprintf("sent messages = ");
    for(uIdx = 0; uIdx < sMsgObjectTx.ui32MsgLen; uIdx++)
           {
               UARTprintf("%02X ",sMsgObjectTx.pui8MsgData[uIdx]);
           }
    UARTprintf("\n");
      }
}

/*********************************************************************************************************************

Function Name           : CAN_APP_receive_the_messages_according_to_state

Function Description    : Function responsible for receive the message from other node

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_receive_the_messages_according_to_state(){
    if(g_bRXFlag1){
        sMsgObjectRx.pui8MsgData =  can_messages_rx_arr  ;
        CANMessageGet(CAN0_BASE,RX_MAILBOX, &sMsgObjectRx,0);




        if(sMsgObjectRx.ui32Flags & MSG_OBJ_DATA_LOST)
          {
                 /* report message lost error */
                UARTprintf("CAN message loss detected\n");
          }else{

            int uIdx ;
            UARTprintf("rec messages = ");
            for(uIdx = 0; uIdx < 8; uIdx++)
                   {
                       UARTprintf(" %02X ", sMsgObjectRx.pui8MsgData[uIdx]);
                   }
            UARTprintf("\n");

            CAN_APP_node_check_the_token();

            g_bRXFlag1 = 0 ;

            if(sMsgObjectRx.pui8MsgData[TOKEN_INDEX] == TOKEN_ID && sMsgObjectRx.pui8MsgData[DEST_INDEX] == THIS_NODE_ID && sMsgObjectRx.pui8MsgData[SRC_INDEX] == PREV_NODE_ID && APP_START == 1){
                 APP_Regulator_ctr = 1 ;
             }

          }


       }
}

/*********************************************************************************************************************

Function Name           : CAN_APP_node_check_the_token

Function Description    : Function responsible for check the token of the node taken or not and take action

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/
void CAN_APP_node_check_the_token(){

   if(can_messages_rx_arr[TOKEN_INDEX] == TOKEN_ID && can_messages_rx_arr[DEST_INDEX] == THIS_NODE_ID){
       xEventGroupSetBits(led_event_gp,LED_BIT_EVENT_FLAG);

       if(sMsgObjectRx.pui8MsgData[SWITCH_INDEX] == 0 && Action_Switch_State == 0  ){
           Switch_State   = 0 ;
       }else if(sMsgObjectRx.pui8MsgData[SWITCH_INDEX] == 0 && Action_Switch_State == 1){
           Switch_State   = 1 ;
       }else if(sMsgObjectRx.pui8MsgData[SWITCH_INDEX] == 1 && Action_Switch_State == 0){
           Switch_State   = 1 ;
       }else if(sMsgObjectRx.pui8MsgData[SWITCH_INDEX] == 1 && Action_Switch_State == 1){
           Switch_State   = 0 ;
       }

        Token_Flag = 1 ;

    }

}


/*********************************************************************************************************************

Function Name           : CAN_APP_SELECT_Node_DEST_ID_SEND

Function Description    : Function responsible for selecting the destination node in the send case

Function Params         : N/A

Function Return         : N/A

**********************************************************************************************************************/

void CAN_APP_SELECT_Node_DEST_ID_SEND(){
    if(Switch_State == 0){
        if(THIS_NODE_ID == NODES_NO_CONNECTED_TO_BUS){
            can_messages_tx_arr[DEST_INDEX] = FIRST_NODE_ID  ;
        }else{
            can_messages_tx_arr[DEST_INDEX] = can_messages_tx_arr[SRC_INDEX] + 1 ;
        }
    }else if(Switch_State == 1){
        if(THIS_NODE_ID == FIRST_NODE_ID){
            can_messages_tx_arr[DEST_INDEX] =  NODES_NO_CONNECTED_TO_BUS ;
        }else{
            can_messages_tx_arr[DEST_INDEX] = can_messages_tx_arr[SRC_INDEX] - 1 ;
        }
    }
}
