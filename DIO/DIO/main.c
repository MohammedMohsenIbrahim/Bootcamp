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
#include "HAL/headers/LCD.h"
#include "APP/Questions/questions.h"

int main(void)
{
    /* Replace with your application code */
	APP_questions_init();
	APP_questions_show_welcome_screen();
    while(1) 
    {
		APP_questions_press_any_btn_to_start();
		APP_questions_questions_stage();
		APP_questions_wait_for_answer();
		APP_questions_show_score();
		
	}
}

