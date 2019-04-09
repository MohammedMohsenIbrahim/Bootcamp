/*
 * ICU.h
 *
 * Created: 2/14/2019 11:41:54 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef ICU_H_
#define ICU_H_

/******************************************** Includes ***********************************/
#include "BitwiseOperations.h"
#include "Memory_Mapped_Registers.h"
#include "types.h"
#include "Timers.h"
#include "DIO.h"

/****************************************** Definitions ***********************************/
#define TIMER1_ICU_PIN_NUM 30
#define ICF1				5

/************************************** Functions Declarations ****************************/
void Timer1_ICU_init();
float Timer1_ICU_calculate_duty_cycle();



#endif /* ICU_H_ */