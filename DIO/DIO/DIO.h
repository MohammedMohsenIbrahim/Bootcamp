/*
 * DIO.h
 *
 * Created: 2/13/2019 2:24:27 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef DIO_H_
#define DIO_H_

/****************************************** Includes **********************************************/
#include "types.h"
#include "Memory_Mapped_Registers.h"
#include "BitwiseOperations.h"

/***************************************** Definitions ********************************************/
#define LOW	   0
#define HIGH   1

#define INPUT  0
#define OUTPUT 1


/************************************* Functions Declarations *************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);
uint8 DIO_ReadPin(uint8 PinNum);

#endif /* DIO_H_ */