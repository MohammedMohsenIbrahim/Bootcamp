/*
 * DC_Motor_config.h
 *
 * Created: 2/21/2019 3:45:51 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef DC_MOTOR_CONFIG_H_
#define DC_MOTOR_CONFIG_H_

/***************************************** Includes *********************************************/
#include "../../types.h"
#include "../../BitwiseOperations.h"
#include "../../Memory_Mapped_Registers.h"
#include "../../DIO.h"
#include "../../MCAL/Headers/PWM.h"

/******************************** DC Motor Config Definitions **********************************/
#define DC_MOTOR_TIMER1_CHA										0
#define DC_MOTOR_TIMER1_CHB										1

#define DC_MOTOR_COUNTER_CW										0
#define DC_MOTOR_CW												1
#define DC_MOTOR_STOP											2

/********************************* DC Motor Config Selections **********************************/
#define DC_MOTOR1_CONNECTION									DC_MOTOR_TIMER1_CHA



#endif /* DC_MOTOR_CONFIG_H_ */