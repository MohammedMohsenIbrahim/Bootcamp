/*
 * Timers.c
 *
 * Created: 2/13/2019 3:58:54 PM
 *  Author: AVE-LAP-069
 */ 

/******************************************** Includes ****************************************/
#include "Timers.h"
volatile void (*Call_Back_Notification)(void) = Set_Call_Back ;
volatile uint16 timer0_ticks = 0 ;
/***************************************** Interrupt service rotuine *********************************/
/* TIMER0 OCR interrupt service routine */
ISR(TIMER0_COMP_vect){
	Call_Back_Notification();
}


/***********************************************************************************************
Function Name		 : Call_Back

Function Description : Function Responsible for calling the function responsible for setting call back flag

Function Parameters  : void (*Set_Call_Back)(void) : Pointer to function can be called when call back set

Function Return      : N/A
************************************************************************************************/
void Call_Back(void (*Set_Call_Back)(void)){
		void (*Call_Back_Notification)() = Set_Call_Back ;
	
}
void Set_Call_Back_Flag(){
	Call_Back_Flag = TRUE ;
}

volatile void Set_Call_Back(){
	timer0_ticks++ ;
	Set_Call_Back_Flag();

}

/***********************************************************************************************
Function Name		 : TIMER0_PRE_COMPILE_CONFIGURATIONS

Function Description : Function Responsible for static configurations of TIMER0 according to TIMER0.h file

Function Parameters  : N/A

Function Return      : N/A
************************************************************************************************/

void TIMER0_PRE_COMPILE_CONFIGURATIONS(){
	#if(TIMER0_PRESCALER ==	STOP_TIMER)
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_NO_PRESCALER)
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_PRESCLAER_8)
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER ==  TIMER_PRESCALER_64)
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_PRESCLAER_256)
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_PRESCLAER_1024)
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_EXTERNAL_CLOCK_FALLING_EDGE)
		Clear_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#elif(TIMER0_PRESCALER == TIMER_EXTERNAL_CLOCK_RISING_EDGE)
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT0);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT1);
		Set_Bit(TCCR0,TIMER0_PRESCALER_BIT2);
	#endif
}
/***********************************************************************************************
Function Name		 : TIMER0_OVF_init

Function Description : Function Responsible for initialization timer0 in OVF mode 

Function Parameters  : N/A

Function Return      : N/A
************************************************************************************************/
void TIMER0_OVF_init(){
	TIMER0_PRE_COMPILE_CONFIGURATIONS();
	
	Set_Bit(TCCR0,7);   /* NON PWM MODE */
	Clear_Bit(TCCR0,6); /* Normal Mode  */
	Clear_Bit(TCCR0,3);
	Clear_Bit(TCCR0,4);	/* Normal Port Operation */
	Clear_Bit(TCCR0,5);

	
	TCNT0 = NUM_ZERO ;           
	
}

/***********************************************************************************************
Function Name		 : TIMER0_OCR_init

Function Description : Function Responsible for initialization timer0 in Output compare mode

Function Parameters  : no_of_ticks : number of ticks before clearing the output compare pin 

Function Return      : N/A
************************************************************************************************/
void TIMER0_OCR_init(uint8 no_of_ticks){
		TIMER0_PRE_COMPILE_CONFIGURATIONS();
		DIO_SetPinDirection(TIMER0_OCR_PIN_NUM,OUTPUT); /* make the compare mode pin as output pin */
	
		Set_Bit(TCCR0,7);   /* NON PWM MODE */
		Clear_Bit(TCCR0,6); /* OCR Mode     */
		Set_Bit(TCCR0,3);
		Clear_Bit(TCCR0,4);	/* Clear output compare pin in compare match */
 		Set_Bit(TCCR0,5);
	 
	 #ifdef TIMER0_OCR_INTERRUPTS
		Set_Bit(TIMSK,1);
	 #endif
	 
	 #ifdef TIMER1_OVF_INTERRUPTS
		Set_Bit(TIMSK,0);
	 #endif
	
	TCNT0 = NUM_ZERO ;
	OCR0  = no_of_ticks ;
}

/***********************************************************************************************
Function Name		 : TIMER0_Delay_OVF

Function Description : Function Responsible for delaying certain milliseconds using timer0 (Polling technique)

Function Parameters  : delay_time

Function Return      : N/A
************************************************************************************************/
void TIMER0_Delay_OVF(uint32 delay_time){

	while(delay_time > NUM_ZERO){
		if(Get_Bit(TIFR,0)){
			Set_Bit(TIFR,0);
			delay_time-- ;	
		}		
	}
}

/***********************************************************************************************
Function Name		 : TIMER0_Delay_OCR

Function Description : Function Responsible for delaying certain milliseconds using timer0 (Polling technique) in OCR mode

Function Parameters  : delay_time

Function Return      : N/A
************************************************************************************************/
void TIMER0_Delay_OCR(uint32 delay_time){

	while(delay_time > NUM_ZERO){
		if(Get_Bit(TIFR,1)){
			Set_Bit(TIFR,1);
			delay_time-- ;
		}
	}
}


/***********************************************************************************************
Function Name		 : TIMER0_Delay_OCR_using_interrupt

Function Description : Function Responsible for delaying certain milliseconds using timer0 (Polling technique) in OCR mode

Function Parameters  : delay_time

Function Return      : N/A
************************************************************************************************/
void TIMER0_Delay_OCR_using_interrupt(uint32 delay_time){
	
}


/***************************************************** Timer1 *****************************************************/
/***********************************************************************************************
Function Name		 : TIMER1_PRE_COMPILE_CONFIGURATIONS

Function Description : Function Responsible for static configurations of TIMER1 according to TIMERS.h file

Function Parameters  : N/A
Function Return      : N/A
************************************************************************************************/

void TIMER1_PRE_COMPILE_CONFIGURATIONS(){
	#if(TIMER1_PRESCALER ==	STOP_TIMER)
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_NO_PRESCALER)
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_PRESCLAER_8)
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_PRESCALER_64)
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_PRESCLAER_256)
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_PRESCLAER_1024)
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_EXTERNAL_CLOCK_FALLING_EDGE)
		Clear_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#elif(TIMER1_PRESCALER == TIMER_EXTERNAL_CLOCK_RISING_EDGE)
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT0);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT1);
		Set_Bit(TCCR1B,TIMER1_PRESCALER_BIT2);
	#endif
}