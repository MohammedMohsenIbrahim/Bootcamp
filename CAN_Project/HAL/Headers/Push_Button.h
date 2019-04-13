/*
 * Push_Button.h
 *
 *  Created on: Mar 13, 2019
 *      Author: AVE-LAP-069
 */

#ifndef HAL_HEADERS_PUSH_BUTTON_H_
#define HAL_HEADERS_PUSH_BUTTON_H_

/*************************************** Includes ********************************************/
#include "../../Service/Headers/types.h"
#include "../../Service/Headers/tm4c123gh6pm.h"
#include "../../Service/Headers/bitwise_operation.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
//#include "OS/Includes/FreeRTOS.h"
//#include "OS/Includes/queue.h"
//#include "../OS/Includes/event_groups.h"
//#include "Includes/Buttons.h"


#define PUSH_BUTTON1_SYS_CTRL_PORT              SYSCTL_PERIPH_GPIOF
#define PUSH_BUTTON2_SYS_CTRL_PORT              SYSCTL_PERIPH_GPIOF
#define PUSH_BUTTON1_PORT_BASE                  GPIO_PORTF_BASE
#define PUSH_BUTTON2_PORT_BASE                  GPIO_PORTF_BASE
#define PUSH_BUTTON1_PIN_NUM                    GPIO_PIN_0
#define PUSH_BUTTON2_PIN_NUM                    GPIO_PIN_4


#define BUTTON_PRESSED                          1
#define BUTTON_NOT_PRESSED                      0



/**************************************** Functions Declarations ********************************************************/
/***********************************************************************************************************************

Function Name           : Push_Button_init

Function Description    : Function Responsible for init Push Button in TIVA C Board

Function Parameters     :
                          Push_Button_ID : ID of push button ID

Function Return         : N/A

************************************************************************************************************************/
void Push_Button_init(uint8_t Push_Button_ID);


/***********************************************************************************************************************

Function Name           : Push_Button_Read

Function Description    : Function Responsible for reading the value of Push Button pressed in TIVAC BOARD

Function Parameters     :
                          Push_Button_ID : ID of push button ID

Function Return         : uint32 The value of the pin

************************************************************************************************************************/
int32_t Push_Button_Read(uint8_t Push_Button_ID);



#endif /* HAL_HEADERS_PUSH_BUTTON_H_ */
