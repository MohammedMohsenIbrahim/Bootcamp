/*
 * LED.c
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-069
 */


/*********************************************** Includes ***************************************************************/
#include "../Headers/LED.h"

/**************************************** Functions Definitions ********************************************************/
/***********************************************************************************************************************

Function Name           : LED_init

Function Description    : Function Responsible for init the LED module in TIVA C Board

Function Parameters     :
                          u32_LED_SYS_CTRL_POR : address of the control port of LED
                          u32_LED_PORT_BASE    : address of base port of LED
                          u8_LED_PIN_NUM       : led pin NUM

Function Return         : N/A

************************************************************************************************************************/

void LED_init(uint32_t u32_LED_SYS_CTRL_PORT,uint32_t u32_LED_PORT_BASE,uint8_t u8_LED_PIN_NUM){

    SysCtlPeripheralEnable(u32_LED_SYS_CTRL_PORT);

    while(SysCtlPeripheralReady(u32_LED_SYS_CTRL_PORT) == ZERO){}

    GPIOPinTypeGPIOOutput(u32_LED_PORT_BASE, u8_LED_PIN_NUM);


}

/***********************************************************************************************************************

Function Name           : LED_write

Function Description    : Function Responsible for writing on led to enable or disable it

Function Parameters     :
                          u32_LED_PORT      : LED PORT
                          u8_LED_PIN_NUM    : Pin NUM
                          u8_LED_VAL        : High -> the same pin num , LOW -> ZERO

Function Return         : N/A

************************************************************************************************************************/

void LED_write(uint32_t u32_LED_PORT,uint8_t u8_LED_PIN_NUM,uint8_t u8_LED_VAL){
    GPIOPinWrite(u32_LED_PORT,u8_LED_PIN_NUM,u8_LED_VAL);
}

