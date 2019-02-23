/*
 * DIO.c
 *
 * Created: 2/13/2019 10:26:51 AM
 * Author : AVE-LAP-069
 */ 

#include <avr/io.h>
#include "types.h"
#include "BitwiseOperations.h"
#include "DIO.h"
#include "software_delay.h"
#include "Timers.h"
#include "ICU.h"
#include "HAL/headers/seven_seg.h"
#include "HAL/headers/keypad.h"
#define  F_CPU 16000000
#include "util/delay.h"
#include "MCAL/Headers/PWM.h"
#include "HAL/headers/LCD.h"
#include "APP/Questions/questions.h"
#include "APP/Traffic_light_int/Traffic_light_int.h"
#include "HAL/headers/DC_Motor.h"

int main(void)
{
	uint8 i = 1 ;
    /* Replace with your application code */
	DC_Motor_init();
	DC_Motor1_direction(DC_MOTOR_CW);
	//DC_MOTOR1_Control_Speed(100);
    while(1) 
    {
	//	for(i=1;i<10;i++){
			DC_MOTOR1_Control_Speed(i*0);
			_delay_ms(2000);
	//	}

	}
}

