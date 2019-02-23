_/*
 * DC.c
 *
 * Created: 2/21/2019 3:46:07 PM
 *  Author: AVE-LAP-069
 */ 


/********************************************** Includes ***************************************/
#include "../headers/DC_Motor.h"

/**************************** Functions Definitions ***************************/
/****************************************************************************

Function Name		 : DC_Motor_init

Function Description : Function responsible for init DC Motor

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void DC_Motor_init(){
	/* Make the Directions Pins of the Motor as Output pins */
	DIO_SetPinDirection(DC_MOTOR_DIRECTION_PIN0_NUM,OUTPUT);
	DIO_SetPinDirection(DC_MOTOR_DIRECTION_PIN1_NUM,OUTPUT); 
	
	/* Select the channel connected with interfacing */
	#if(DC_MOTOR1_CONNECTION == DC_MOTOR_TIMER1_CHA)
		TIMER1_FAST_PWM_init('A',TIMER1_FAST_PWM_CLAER_PIN_OCR);
	#elif(DC_MOTOR1_CONNECTION == DC_MOTOR_TIMER1_CHB)
		TIMER1_FAST_PWM_init('B',TIMER1_FAST_PWM_CLAER_PIN_OCR);
	#else
		#error " Check the Motor Connection with Timer Pins "	
	#endif
}

/****************************************************************************

Function Name		 : DC_Motor1_direction

Function Description : Function responsible for controlling the DC Motor direction

Function Parameters  : u8_DC_Motor_dir : to determine the direction of DC Motor ( CW,CCW,STOP)

Function Return      : N/A

*******************************************************************************/

void DC_Motor1_direction(uint8 u8_DC_Motor_dir){
	/* Select the direction of the pins */
	switch(u8_DC_Motor_dir){
		case DC_MOTOR_COUNTER_CW :
				DIO_WritePin(DC_MOTOR_DIRECTION_PIN0_NUM,HIGH);
				DIO_WritePin(DC_MOTOR_DIRECTION_PIN1_NUM,LOW);
		break;
		case DC_MOTOR_CW		 :
			DIO_WritePin(DC_MOTOR_DIRECTION_PIN0_NUM,LOW);
			DIO_WritePin(DC_MOTOR_DIRECTION_PIN1_NUM,HIGH);
		break;
		case DC_MOTOR_STOP		 :
			DIO_WritePin(DC_MOTOR_DIRECTION_PIN0_NUM,LOW);
			DIO_WritePin(DC_MOTOR_DIRECTION_PIN1_NUM,LOW);		
		break;
		
	}
}

/****************************************************************************

Function Name		 : DC_Motor1_control_Speed

Function Description : Function responsible for controlling the DC Motor speed

Function Parameters  : u8_duty_cycle : duty cycle signal to determine the speed of Motor

Function Return      : N/A

*******************************************************************************/

void DC_MOTOR1_Control_Speed(uint8 u8_duty_cycle){
	/* change the duty cycle of the TIMER to change the speed of the Motor */
	TIMER1_FAST_PWM_OCR_VALS_using_DC(u8_duty_cycle);
}
