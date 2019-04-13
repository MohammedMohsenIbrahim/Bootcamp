/*
 * Push_Button.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-069
 */


/********************************************* Includes ***************************************************/
#include "../Headers/Push_Button.h"

/**************************************** Functions Definitions ********************************************************/
/***********************************************************************************************************************

Function Name           : Push_Button_init

Function Description    : Function Responsible for init Push Button in TIVA C Board

Function Parameters     :
                          Push_Button_ID : ID of push button ID

Function Return         : N/A

************************************************************************************************************************/
void Push_Button_init(uint8_t Push_Button_ID)
 {

    switch(Push_Button_ID){
        case PUSH_BUTTON1_PIN_NUM :

        SysCtlPeripheralEnable(PUSH_BUTTON1_SYS_CTRL_PORT);
        while(!SysCtlPeripheralReady(PUSH_BUTTON1_SYS_CTRL_PORT)) {}
        GPIOPinTypeGPIOInput(PUSH_BUTTON1_PORT_BASE ,PUSH_BUTTON1_PIN_NUM);
        HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
        HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;
        GPIOPadConfigSet(PUSH_BUTTON1_PORT_BASE,PUSH_BUTTON1_PIN_NUM, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU );


        break ;
        case PUSH_BUTTON2_PIN_NUM :

            SysCtlPeripheralEnable(PUSH_BUTTON2_SYS_CTRL_PORT);
            while(!SysCtlPeripheralReady(PUSH_BUTTON2_SYS_CTRL_PORT)){}
            GPIOPinTypeGPIOInput(PUSH_BUTTON2_PORT_BASE,PUSH_BUTTON2_PIN_NUM);
            HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
            HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;

            GPIOPadConfigSet(PUSH_BUTTON2_PORT_BASE,PUSH_BUTTON2_PIN_NUM,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU );



        break ;
        default :
        break ;

    }




#if 0
    SysCtlPeripheralEnable(PUSH_BUTTON1_SYS_CTRL_PORT);
    while(!SysCtlPeripheralReady(PUSH_BUTTON1_SYS_CTRL_PORT)) {}
    GPIOPinTypeGPIOInput(PUSH_BUTTON1_PORT_BASE ,PUSH_BUTTON1_PIN_NUM);
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;
    GPIOPadConfigSet(PUSH_BUTTON1_PORT_BASE,PUSH_BUTTON1_PIN_NUM, GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU );


    SysCtlPeripheralEnable(PUSH_BUTTON2_SYS_CTRL_PORT);
    while(!SysCtlPeripheralReady(PUSH_BUTTON2_SYS_CTRL_PORT)){}
    GPIOPinTypeGPIOInput(PUSH_BUTTON2_PORT_BASE,PUSH_BUTTON2_PIN_NUM);
    GPIOPadConfigSet(PUSH_BUTTON2_PORT_BASE,PUSH_BUTTON2_PIN_NUM,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU );

#endif


}


/***********************************************************************************************************************

Function Name           : Push_Button_Read

Function Description    : Function Responsible for reading the value of Push Button pressed in TIVAC BOARD

Function Parameters     :
                          Push_Button_ID : ID of push button ID

Function Return         : s32_pin_val

************************************************************************************************************************/

int32_t Push_Button_Read(uint8_t Push_Button_ID){
    uint8_t s32_pin_val = BUTTON_NOT_PRESSED ;

    switch(Push_Button_ID){
    case PUSH_BUTTON1_PIN_NUM  :
         if(GPIOPinRead(PUSH_BUTTON1_PORT_BASE,PUSH_BUTTON1_PIN_NUM) == BUTTON_PRESSED ){
             s32_pin_val = BUTTON_PRESSED ;
         }

    break;
    case PUSH_BUTTON2_PIN_NUM  :
        if(GPIOPinRead(PUSH_BUTTON2_PORT_BASE,PUSH_BUTTON2_PIN_NUM) == BUTTON_PRESSED ){
            s32_pin_val = BUTTON_PRESSED ;
        }

    break;
    default :
    break;
    }

    return s32_pin_val ;
}
