/*
 * ISR.h
 *
 * Created: 2/20/2019 4:41:34 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef ISR_H_
#define ISR_H_

/************************************************ Includes *******************************************/
#include <avr/interrupt.h>


/***************************************** Interrupt service rotuine *********************************/
/* TIMER0 OVF interrupt service routine */
ISR(TIMER0_OVF_vect){
		
}

/* TIMER0 OCR interrupt service routine */
ISR(TIMER0_COMP_vect){
	
}




#endif /* ISR_H_ */