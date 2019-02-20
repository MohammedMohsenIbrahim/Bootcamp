/*
 * Timers.h
 *
 * Created: 2/13/2019 3:59:32 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

/***************************************** Includes *********************************************/
#include "types.h"
#include "BitwiseOperations.h"
#include "Memory_Mapped_Registers.h"
#include "DIO.h"
/*************************************** Definitions ********************************************/
#define NUM_ZERO					0

#define TIMER0_PRESCALER_BIT0		0
#define TIMER0_PRESCALER_BIT1		1
#define TIMER0_PRESCALER_BIT2		2

#define TIMER1_PRESCALER_BIT0		0
#define TIMER1_PRESCALER_BIT1		1
#define TIMER1_PRESCALER_BIT2		2

/***************************** TIMER CONFIGURATIONS DEFINITIONS *********************************/
#define STOP_TIMER						   0
#define TIMER_NO_PRESCALER				   1
#define TIMER_PRESCLAER_8				   8
#define TIMER_PRESCALER_16				   16
#define TIMER_PRESCALER_32				   32
#define TIMER_PRESCALER_64				   64
#define TIMER_PRESCALER_128				   128	
#define TIMER_PRESCLAER_256				   256
#define TIMER_PRESCLAER_1024			   1024

#define TIMER_EXTERNAL_CLOCK_FALLING_EDGE  6
#define TIMER_EXTERNAL_CLOCK_RISING_EDGE   7

/***************************** TIMER CONFIGURATIONS SELECTIONS *********************************/
#define TIMER0_PRESCALER	64
#define TIMER0_OCR_PIN_NUM	11

#define TIMER1_PRESCALER	64

/******************************** Functions Declarations ***************************************/
void TIMER0_PRE_COMPILE_CONFIGURATIONS();
void TIMER0_OVF_init();
void TIMER0_OCR_init(uint8 no_of_ticks);
void TIMER0_Delay_OVF(uint32 delay_time);
void TIMER0_Delay_OCR(uint32 delay_time);

void TIMER1_PRE_COMPILE_CONFIGURATIONS();




#endif /* TIMERS_H_ */