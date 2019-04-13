
/******************************************** Includes ********************************************************/
#include "CAN_TASKS.h"

volatile uint8_t Switch_State = 0 ;
volatile uint8_t Action_Switch_State ;

volatile uint8_t APP_Regulator_ctr = 0 ;
volatile uint8_t APP_START = 0 ;
/******************************************* Tasks Definitions ************************************************/
void init_Task(){
    CAN_APP_sys_init();
    CAN_APP_init_fun();


#ifdef NODE1
    CAN_APP_config_TX_msg(THIS_NODE_ID);
    CAN_APP_config_RX_msg(RECEIVE_ALL_MESSAGES);
#endif
#ifdef NODE2
    CAN_APP_config_TX_msg(THIS_NODE_ID);
    CAN_APP_config_RX_msg(RECEIVE_ALL_MESSAGES);
#endif
#ifdef NODE3
    CAN_APP_config_TX_msg(THIS_NODE_ID);
    CAN_APP_config_RX_msg(RECEIVE_ALL_MESSAGES);
#endif


    vTaskSuspend(NULL);
}

#if 0
void CAN_STARTUP_MSG_TASK_Send(){

#ifdef NODE1
        while(1){
    can_messages_tx_arr[SRC_INDEX]              = THIS_NODE_ID             ;
        can_messages_tx_arr[DEST_INDEX]         = NEXT_NODE_ID             ;
        can_messages_tx_arr[TOKEN_INDEX]        = TOKEN_ID                 ;
        can_messages_tx_arr[SWITCH_INDEX]       = Switch_State             ;
        can_messages_tx_arr[STARTUP_NODE_INDEX ] = 13 ;

        CAN_APP_SELECT_Node_DEST_ID_SEND();

        sMsgObjectTx.pui8MsgData = can_messages_tx_arr        ;
          CANMessageSet(CAN0_BASE,TX_MAILBOX,&sMsgObjectTx,MSG_OBJ_TYPE_TX);

          if(sMsgObjectTx.ui32Flags & MSG_OBJ_DATA_LOST)
            {
                   /* report message lost error */
                  UARTprintf("CAN TX message loss detected\n");
            }
          int uIdx ;
          UARTprintf("sent messages = ");
          for(uIdx = 0; uIdx < sMsgObjectTx.ui32MsgLen; uIdx++)
                 {
                     UARTprintf("%02X ",sMsgObjectTx.pui8MsgData[uIdx]);
                 }
          UARTprintf("\n");

          CAN_APP_receive_the_messages_according_to_state();

          if(sMsgObjectRx.pui8MsgData[STARTUP_NODE_INDEX ] == 17){
              APP_START  = 1 ;
              vTaskSuspend(NULL);
          }

          vTaskDelay(20/portTICK_RATE_MS);
        }
#endif
#ifdef NODE2
while(1){
    CAN_APP_receive_the_messages_according_to_state();
    if(sMsgObjectRx.pui8MsgData[STARTUP_NODE_INDEX ] == 13){
        can_messages_tx_arr[SRC_INDEX]          = THIS_NODE_ID             ;
              can_messages_tx_arr[DEST_INDEX]         = FIRST_NODE_ID         ;
              can_messages_tx_arr[TOKEN_INDEX]        = TOKEN_ID             ;
              can_messages_tx_arr[SWITCH_INDEX]       = Switch_State         ;
              can_messages_tx_arr[STARTUP_NODE_INDEX ] = 17 ;
              APP_START  = 1 ;

               vTaskSuspend(NULL);
           }

    vTaskDelay(20/portTICK_RATE_MS);
}
#endif
#ifdef NODE3
can_messages_tx_arr[STARTUP_NODE_INDEX ] = 17 ;
APP_START  = 1 ;
vTaskSuspend(NULL);
#endif
}

void CAN_Tx_Task(){
    while(1){
        if(APP_Regulator_ctr == 3 && APP_START == 1 ){
        CAN_APP_send_the_messages_according_to_state();
        APP_Regulator_ctr = 0 ;
        }

            vTaskDelay(500/portTICK_RATE_MS);

    }
}

void CAN_Rx_Task(){
    while(1){
        if( APP_START == 1){
            CAN_APP_receive_the_messages_according_to_state();
        }
        vTaskDelay(50/portTICK_RATE_MS);

    }
}


void CAN_Led_Task()
{
    uint8_t LED_Periodicity_ctr = LED_INIT_STATE ;

    while(1){
        if( APP_START == 1){
        uxBits = xEventGroupWaitBits(led_event_gp, LED_BIT_EVENT_FLAG,pdTRUE,pdFALSE,4);
        if((uxBits & (LED_BIT_EVENT_FLAG) )){
            LED_Periodicity_ctr++ ;
                if(APP_Regulator_ctr == 1){
                LED_write(THIS_NODE_LED_PORT,THIS_NODE_LED_PIN,THIS_NODE_LED_PIN );
                    APP_Regulator_ctr = 2 ;
                }else if(APP_Regulator_ctr == 2 ){

                LED_write(THIS_NODE_LED_PORT,THIS_NODE_LED_PIN,LOW);
                LED_Periodicity_ctr = LED_INIT_STATE ;
                APP_Regulator_ctr = 3 ;
                }
            }

        }
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void CAN_Push_Button_Task(){

    while(1){
        if( APP_START == 1){
                if((uxBits & (LED_BIT_EVENT_FLAG) ) == ( LED_BIT_EVENT_FLAG )){
                    if(!Push_Button_Read(PUSH_BUTTON1_PIN_NUM)){

                            Action_Switch_State = 1 ;

                }else{
                            Action_Switch_State = 0 ;
                    }
                }
        }
        vTaskDelay(50/portTICK_RATE_MS);
    }
}

#endif

void CAN_STARTUP_MSG_TASK_Send(){
    while(1){
        #ifdef NODE1

            can_messages_tx_arr[SRC_INDEX]              = THIS_NODE_ID             ;
            can_messages_tx_arr[DEST_INDEX]             = NEXT_NODE_ID             ;
            can_messages_tx_arr[TOKEN_INDEX]            = TOKEN_ID                 ;
            can_messages_tx_arr[SWITCH_INDEX]           = Switch_State             ;
            can_messages_tx_arr[STARTUP_NODE_INDEX ]    = 13 ;

            CAN_APP_SELECT_Node_DEST_ID_SEND();

            sMsgObjectTx.pui8MsgData = can_messages_tx_arr        ;
                      CANMessageSet(CAN0_BASE,TX_MAILBOX,&sMsgObjectTx,MSG_OBJ_TYPE_TX);

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
                        }if(APP_START == 1){

                      vTaskSuspend(NULL);
                    }else{
                        vTaskDelay(50/portTICK_RATE_MS);
                    }

        #endif
       #ifndef NODE1
                      can_messages_tx_arr[STARTUP_NODE_INDEX ]    = 13 ;
                      vTaskSuspend(NULL);
       #endif
    }
}


void CAN_STARTUP_MSG_TASK_Rec(){
    while(1){
        CAN_APP_receive_the_messages_according_to_state();
        #ifdef NODE2
        if(sMsgObjectRx.pui8MsgData[STARTUP_NODE_INDEX]  == 13 && sMsgObjectRx.pui8MsgData[SRC_INDEX] == FIRST_NODE_ID){
            APP_START = 1 ;
            UARTprintf("APP_START NODE %d = %d\n",THIS_NODE_ID,APP_START);
             vTaskSuspend(NULL);
        }else{
            vTaskDelay(50/portTICK_RATE_MS);
        }
        #endif
        #ifdef NODE3
        if(sMsgObjectRx.pui8MsgData[STARTUP_NODE_INDEX ]    == 13 && sMsgObjectRx.pui8MsgData[SRC_INDEX] == SECOND_NODE_ID){
            APP_START = 1 ;
            UARTprintf("APP_START NODE %d = %d\n",THIS_NODE_ID,APP_START);
            vTaskSuspend(NULL);
    }else{
        vTaskDelay(50/portTICK_RATE_MS);
    }
        #endif
        #ifdef NODE1
              if(sMsgObjectRx.pui8MsgData[STARTUP_NODE_INDEX ]    == 13 && sMsgObjectRx.pui8MsgData[SRC_INDEX] == THIRD_NODE_ID){
                  APP_START = 1 ;
                  UARTprintf("APP_START NODE %d = %d\n",THIS_NODE_ID,APP_START);
                  vTaskSuspend(NULL);
          }else{
              vTaskDelay(50/portTICK_RATE_MS);
          }
        #endif
    }
}

void CAN_Tx_Task(){
    while(1){
        if(APP_START == 1 && APP_Regulator_ctr == 3){
            CAN_APP_send_the_messages_according_to_state();
            APP_Regulator_ctr = 0 ;
        }
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void CAN_Rx_Task(){
    while(1){
        if(APP_START == 1 && APP_Regulator_ctr == 0){
            CAN_APP_receive_the_messages_according_to_state();

        }
        vTaskDelay(500/portTICK_RATE_MS);
    }
}

void CAN_LED_Task(){
    while(1){
        if(APP_START == 1 && APP_Regulator_ctr == 1){
            LED_write(THIS_NODE_LED_PORT,THIS_NODE_LED_PIN,THIS_NODE_LED_PIN );
            APP_Regulator_ctr = 2 ;
        }else if(APP_START == 1 && APP_Regulator_ctr == 2){
            LED_write(THIS_NODE_LED_PORT,THIS_NODE_LED_PIN,LOW );
            APP_Regulator_ctr = 3 ;
        }
        vTaskDelay(1000/portTICK_RATE_MS);
    }

}
