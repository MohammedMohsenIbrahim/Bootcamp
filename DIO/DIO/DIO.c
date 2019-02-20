/*
 * DIO.c
 *
 * Created: 2/13/2019 2:24:41 PM
 *  Author: AVE-LAP-069
 */ 


/********************************************* Includes ***************************************/
#include "DIO.h"

/****************************************************** Functions Definitions ***********************************************/
/****************************************************************************************************************************
Function Name		 : DIO_WritePin

Function Description : Function Responsible for writing high or low value in any pin

Functions Parameters : PinValue (0,1) , PinNum (number of the pin to write into it from 0 to 31)

Functions Return     : N/A
*****************************************************************************************************************************/
void DIO_WritePin(uint8 PinNum,uint8 PinValue){
	switch(PinValue){								/* check the value of the written pin */
		case LOW :									/* case the pin has low value */
			if(PinNum >= PORTA_STARTING_PIN_NUM && PinNum <= PORTA_ENDING_PIN_NUM){	/* check porta pins */
				Clear_Bit(PORT_A,PinNum);				/* clear the pin wanted */
			}else if(PinNum >= PORTB_STARTING_PIN_NUM && PinNum <= PORTB_ENDING_PIN_NUM){ /* check portb pins */
				Clear_Bit(PORT_B,(PinNum - PORTB_STARTING_PIN_NUM));	/* clear the pin wanted */
			}else if(PinNum >= PORTC_STARTING_PIN_NUM && PinNum <= PORTC_ENDING_PIN_NUM){	/* check portc pins */
				Clear_Bit(PORT_C,(PinNum - PORTC_STARTING_PIN_NUM)); /* clear the pin wanted */
			}else if(PinNum >= PORTD_STARTING_PIN_NUM && PinNum <= PORTD_ENDING_PIN_NUM){ /* check portd pins */
				Clear_Bit(PORT_D,(PinNum - PORTD_STARTING_PIN_NUM));	/* clear the pin wanted */
			}
		break;
		case HIGH :		/* case the pin has high value */
			if(PinNum >= PORTA_STARTING_PIN_NUM && PinNum <= PORTA_ENDING_PIN_NUM){ /* check porta pins */
				Set_Bit(PORT_A,PinNum);	/* set the pin wanted */
			}else if(PinNum >= PORTB_STARTING_PIN_NUM && PinNum <= PORTB_ENDING_PIN_NUM){ /* check portb pins */
				Set_Bit(PORT_B,(PinNum - PORTB_STARTING_PIN_NUM)); /* set the pin wanted */
			}else if(PinNum >= PORTC_STARTING_PIN_NUM && PinNum <= PORTC_ENDING_PIN_NUM){ /* check potc pins */
				Set_Bit(PORT_C,(PinNum - PORTC_STARTING_PIN_NUM)); /* set the pin wanted */
			}else if(PinNum >= PORTD_STARTING_PIN_NUM && PinNum <= PORTD_ENDING_PIN_NUM){ /* check portd pins */
				Set_Bit(PORT_D,(PinNum - PORTD_STARTING_PIN_NUM)); /* set the pin wanted */
			}			
		break;
		default:
		break;
	}
}

/****************************************************************************************************************************
Function Name		 : DIO_SetPinDirection

Function Description : Function Responsible for determine the direction of any pin as input or output pin

Functions Parameters : PinDirection	 (Input or Output) , PinNum (number of the pin to write into it from 0 to 31)

Functions Return     : N/A
*****************************************************************************************************************************/
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection){
	switch(PinDirection){			/* check the direction of the pin wanted */
		case INPUT :				/* case input pin */
		if(PinNum >= PORTA_STARTING_PIN_NUM && PinNum <= PORTA_ENDING_PIN_NUM){		/* case porta */
			Clear_Bit(DDR_A,PinNum);
			}else if(PinNum >= PORTB_STARTING_PIN_NUM && PinNum <= PORTB_ENDING_PIN_NUM){
			Clear_Bit(DDR_B,(PinNum - PORTB_STARTING_PIN_NUM));
			}else if(PinNum >= PORTC_STARTING_PIN_NUM && PinNum <= PORTC_ENDING_PIN_NUM){
			Clear_Bit(DDR_C,(PinNum - PORTC_STARTING_PIN_NUM));
			}else if(PinNum >= PORTD_STARTING_PIN_NUM && PinNum <= PORTD_ENDING_PIN_NUM){
			Clear_Bit(DDR_D,(PinNum - PORTD_STARTING_PIN_NUM));
		}
		break;
		case OUTPUT :
		if(PinNum >= PORTA_STARTING_PIN_NUM && PinNum <= PORTA_ENDING_PIN_NUM){
			Set_Bit(DDR_A,PinNum);
			}else if(PinNum >= PORTB_STARTING_PIN_NUM && PinNum <= PORTB_ENDING_PIN_NUM){
			Set_Bit(DDR_B,(PinNum - PORTB_STARTING_PIN_NUM));
			}else if(PinNum >= PORTC_STARTING_PIN_NUM && PinNum <= PORTC_ENDING_PIN_NUM){
			Set_Bit(DDR_C,(PinNum - PORTC_STARTING_PIN_NUM));
			}else if(PinNum >= PORTD_STARTING_PIN_NUM && PinNum <= PORTD_ENDING_PIN_NUM){
			Set_Bit(DDR_D,(PinNum - PORTD_STARTING_PIN_NUM));
		}
		break;
		default:
		break;
	}
}

/****************************************************************************************************************************
Function Name		 : DIO_ReadPin

Function Description : Function Responsible for reading the value of any pin

Functions Parameters : PinNum (number of the pin to write into it from 0 to 31)

Functions Return     : the read value of the pin (HIGH , LOW)
*****************************************************************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum){
	uint8 Read_val ;
		if(PinNum >= PORTA_STARTING_PIN_NUM  && PinNum <= PORTA_ENDING_PIN_NUM){
				Read_val =  Get_Bit(PIN_A,PinNum);
			}else if(PinNum >= PORTB_STARTING_PIN_NUM && PinNum <= PORTB_ENDING_PIN_NUM){
				Read_val = Get_Bit(PIN_B,(PinNum - PORTB_STARTING_PIN_NUM));
			}else if(PinNum >= PORTC_STARTING_PIN_NUM && PinNum <= PORTC_ENDING_PIN_NUM){
				Read_val = Get_Bit(PIN_C,(PinNum - PORTC_STARTING_PIN_NUM));
			}else if(PinNum >= PORTD_STARTING_PIN_NUM && PinNum <= PORTD_ENDING_PIN_NUM){
				Read_val = Get_Bit(PIN_D,(PinNum - PORTD_STARTING_PIN_NUM));
		 }	
		 return Read_val ;
}