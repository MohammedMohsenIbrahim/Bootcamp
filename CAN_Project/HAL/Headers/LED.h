
#ifndef HAL_HEADERS_LED_H_
#define HAL_HEADERS_LED_H_

/*************************************** Includes ********************************************/
#include "../../Service/Headers/types.h"
#include "../../Service/Headers/tm4c123gh6pm.h"
#include "../../Service/Headers/bitwise_operation.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"

/************************************* Definitions *******************************************/
#define LED1_SYS_CTRL_PORT              SYSCTL_PERIPH_GPIOF
#define LED2_SYS_CTRL_PORT              SYSCTL_PERIPH_GPIOF
#define LED3_SYS_CTRL_PORT              SYSCTL_PERIPH_GPIOF
#define LED1_PORT_BASE                  GPIO_PORTF_BASE
#define LED2_PORT_BASE                  GPIO_PORTF_BASE
#define LED3_PORT_BASE                  GPIO_PORTF_BASE
#define LED1_PIN_NUM                    GPIO_PIN_1
#define LED2_PIN_NUM                    GPIO_PIN_2
#define LED3_PIN_NUM                    GPIO_PIN_3
#define LED1_DATA_PORT                  GPIO_PORTF_BASE
#define LED2_DATA_PORT                  GPIO_PORTF_BASE
#define LED3_DATA_PORT                  GPIO_PORTF_BASE


#define ZERO                            0

/**************************************** Functions Declaration ********************************************************/
/***********************************************************************************************************************

Function Name           : LED_init

Function Description    : Function Responsible for init the LED module in TIVA C Board

Function Parameters     :
                          u32_LED_SYS_CTRL_POR : address of the control port of LED
                          u32_LED_PORT_BASE    : address of base port of LED
                          u8_LED_PIN_NUM       : pin led num

Function Return         : N/A

************************************************************************************************************************/
void LED_init(uint32_t u32_LED_SYS_CTRL_PORT,uint32_t u32_LED_PORT_BASE,uint8_t u8_LED_PIN_NUM);


/***********************************************************************************************************************

Function Name           : LED_write

Function Description    : Function Responsible for writing on led to enable or disable it

Function Parameters     :
                          u32_LED_PORT      : LED PORT
                          u8_LED_PIN_NUM    : Pin NUM
                          u8_LED_VAL        : High -> the same pin num , LOW -> ZERO

Function Return         : N/A

************************************************************************************************************************/
void LED_write(uint32_t u32_LED_PORT,uint8_t u8_LED_PIN_NUM,uint8_t u8_LED_VAL);


#endif /* HAL_HEADERS_LED_H_ */
