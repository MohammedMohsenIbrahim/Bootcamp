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
#include "APP/TTC Schedular/TTC_Headers/TTC_Schedular.h"
#include "APP/TTC Schedular/TTC_Headers/Tasks.h"

int main(void)
{
	sei();
	Tasks_init();
	Schedular_init(Task_BLINK_LED1,1,1000);
	Schedular_init(Task_BLINK_LED2,2,2000);
	Schedular_init(Task_BLINK_LED3,0,3000);
    while(1) 
    {
		schedulerStart_according_periodicity_priority();
			
	}
}

