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
#include <avr/io.h>

/******************************** TIMER1 REG Definitions ********************************/
#define TIMER1_CONTROL_REG_1A						TCCR1A
#define TIMER1_CONTROL_REG_1B						TCCR1B
#define TIMER1_COUNT_DATA_REG_HIGH					TCNT1H
#define TIMER1_COUNT_DATA_REG_LOW					TCNT1L
#define TIMER1_OCR_DATA_REG_HIGH					OCR1AH
#define TIMER1_OCR_DATA_REG_LOW						OCR1AL
#define TIMER1_ICU_DATA_REG_HIGH					ICR1H
#define TIMER1_ICU_DATA_REG_LOW						ICR1L
#define TIMER1_INTERRUPT_MASK_REG					TIMSK
#define TIMER1_INTERRUPT_FLAG_REG					TIFR

/******************************** TIMER1 BITS Definitions *******************************/
/* TIMER1_CONTROL_REG_1A */
#define TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT1		COM1A1
#define TIMER1_COMPARE_OUTPUT_ACTION_CHA_BIT0		COM1A0
#define TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT1		COM1B1
#define TIMER1_COMPARE_OUTPUT_ACTION_CHB_BIT0		COM1B0
#define TIMER1_NON_PWM_MODE_CHA						FOC1A
#define TIMER1_NON_PWM_MODE_CHB						FOC1B
#define TIMER1_WAVEFORM_GENERATION_MODE_BIT1		WGM11
#define TIMER1_WAVEFORM_GENERATION_MODE_BIT0		WGM10
/* TIMER1_CONTROL_REG_1B */
#define ICU1_NOISE_CANCELLER_BIT					ICNC1
#define ICU1_EDGE_SELECT_BIT						ICES1
#define TIMER1_WAVEFORM_GENERATION_MODE_BIT3		WGM13
#define TIMER1_WAVEFORM_GENERATION_MODE_BIT2		WGM12
#define TIMER1_CLOCK_SELECT_BIT2					CS12
#define TIMER1_CLOCK_SELECT_BIT1					CS11
#define TIMER1_CLOCK_SELECT_BIT0					CS10
/* TIMER1_INTERRUPT_MASK_REG */
#define TIMER1_ICU_INTERRUPT_ENABLE_BIT				TICIE1
#define	TIMER1_OCR_CHA_INTERRUPT_ENABLE_BIT			OCIE1A
#define TIMER1_OCR_CHB_INTERRUPT_ENABLE_BIT			OCIE1B
#define TIMER1_OVF_INTERRUPT_ENABLE_BIT				TOIE1
/* TIMER1_INTERRUPT_FLAG_REG */
#define TIMER1_ICU_INTERRUPT_ENABLE_FLAG			ICF1
#define	TIMER1_OCR_CHA_INTERRUPT_ENABLE_FLAG		OCF1A
#define TIMER1_OCR_CHB_INTERRUPT_ENABLE_FLAG		OCF1B
#define TIMER1_OVF_INTERRUPT_ENABLE_FLAG			TOV1

/*************************************** Definitions ********************************************/

#define NUM_ZERO					0

#define TIMER0_PRESCALER_BIT0		0
#define TIMER0_PRESCALER_BIT1		1
#define TIMER0_PRESCALER_BIT2		2

#define TIMER1_PRESCALER_BIT0		0
#define TIMER1_PRESCALER_BIT1		1
#define TIMER1_PRESCALER_BIT2		2

/************************************ Global Variables ******************************************/
static uint8 TIMER0_tick_counter = NUM_ZERO ;

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
#define TIMER0_PRESCALER			TIMER_PRESCALER_64
#define TIMER0_OCR_PIN_NUM			11
#define TIMER0_OCR_INTERRUPTS

#define TIMER1_PRESCALER	TIMER_PRESCALER_64

/******************************** Functions Declarations ***************************************/
void TIMER0_PRE_COMPILE_CONFIGURATIONS();
void TIMER0_OVF_init();
void TIMER0_OCR_init(uint8 no_of_ticks);
void TIMER0_Delay_OVF(uint32 delay_time);
void TIMER0_Delay_OCR(uint32 delay_time);

void TIMER1_PRE_COMPILE_CONFIGURATIONS();




#endif /* TIMERS_H_ */