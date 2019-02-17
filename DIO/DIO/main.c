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

int main(void)
{
    /* Replace with your application code */
	Timer1_ICU_init();
	
	float d_c ;
    while(1) 
    {
		d_c = Timer1_ICU_calculate_duty_cycle();
	}
}

