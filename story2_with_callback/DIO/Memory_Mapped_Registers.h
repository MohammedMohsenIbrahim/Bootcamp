/*
 * Memory_Mapped_Registers.h
 *
 * Created: 2/13/2019 2:24:01 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef MEMORY_MAPPED_REGISTERS_H_
#define MEMORY_MAPPED_REGISTERS_H_

/******************************************** Includes ************************************/
#include "types.h"

/***************************************** Memory Mapped Registers ***********************************/

/************************************** DIO Memory Mapped Registers **********************************/
#define PORT_A (*(volatile uint8 *)0x3b)
#define DDR_A (*(volatile uint8 *)0x3a)
#define PIN_A (*(volatile uint8 *)0x39)

#define PORT_B (*(volatile uint8 *)0x38)
#define DDR_B (*(volatile uint8 *)0x37)
#define PIN_B (*(volatile uint8 *)0x36)

#define PORT_C (*(volatile uint8 *)0x35)
#define DDR_C (*(volatile uint8 *)0x34)
#define PIN_C (*(volatile uint8 *)0x33)

#define PORT_D (*(volatile uint8 *)0x32)
#define DDR_D (*(volatile uint8 *)0x31)
#define PIN_D (*(volatile uint8 *)0x30)

/************************************* Timers Memory Mapped Registers **********************************************/
// General
#define TIMSK (*(volatile uint8 *)0x59)
#define TIFR (*(volatile uint8 *)0x58)
//TIMER0
#define OCR0 (*(volatile uint8 *)0x5C)
#define TCCR0 (*(volatile uint8 *)0x53)
#define TCNT0 (*(volatile uint8 *)0x52)
// TIMER1
#define TCCR1A (*(volatile uint8 *)0x4F)
#define TCCR1B (*(volatile uint8 *)0x4E)
#define TCNT1H (*(volatile uint8 *)0x4D)
#define TCNT1L (*(volatile uint8 *)0x4C)
#define OCR1AH (*(volatile uint8 *)0x4B)
#define OCR1AL (*(volatile uint8 *)0x4A)
#define OCR1BH (*(volatile uint8 *)0x49)
#define OCR1BL (*(volatile uint8 *)0x48)

#define ICR1H (*(volatile uint8 *)0x47)
#define ICR1L (*(volatile uint8 *)0x46)
// TIMER2
#define TCCR2 (*(volatile uint8 *)0x45)
#define TCNT2 (*(volatile uint8 *)0x44)
#define OCR2 (*(volatile uint8 *)0x43)


/***************************************** Serialized Pins ****************************************************/





#endif /* MEMORY_MAPPED_REGISTERS_H_ */