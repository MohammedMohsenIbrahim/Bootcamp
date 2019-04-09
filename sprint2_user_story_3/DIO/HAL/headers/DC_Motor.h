/*
 * DC_Motor.h
 *
 * Created: 2/21/2019 3:45:36 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*************************************** Includes ************************************/
#include "DC_Motor_config.h"

/************************************** Definitions **********************************/
#define DC_MOTOR_DIRECTION_PIN0_NUM			26
#define DC_MOTOR_DIRECTION_PIN1_NUM			27

/**************************** Functions Declarations ***************************/
/****************************************************************************

Function Name		 : DC_Motor_init

Function Description : Function responsible for init DC Motor

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/	
void DC_Motor_init();


/****************************************************************************

Function Name		 : DC_Motor1_direction

Function Description : Function responsible for controlling the DC Motor direction

Function Parameters  : u8_DC_Motor_dir : to determine the direction of DC Motor ( CW,CCW,STOP)

Function Return      : N/A

*******************************************************************************/
void DC_Motor1_direction(uint8 u8_DC_Motor_dir);


/****************************************************************************

Function Name		 : DC_Motor1_control_Speed

Function Description : Function responsible for controlling the DC Motor speed

Function Parameters  : u8_duty_cycle : duty cycle signal to determine the speed of Motor

Function Return      : N/A

*******************************************************************************/
void DC_MOTOR1_Control_Speed(uint8 u8_duty_cycle);



#endif /* DC_MOTOR_H_ */