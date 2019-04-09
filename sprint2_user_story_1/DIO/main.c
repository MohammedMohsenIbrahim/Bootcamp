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
	Schedular_Add_Task(Task_BLINK_LED1);
	Schedular_Add_Task(Task_BLINK_LED2);
	Schedular_Add_Task(Task_BLINK_LED3);
    while(1) 
    {
		Schedular_run_tasks();
			
	}
}

