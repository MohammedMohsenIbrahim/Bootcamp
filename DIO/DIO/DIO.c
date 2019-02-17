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
	switch(PinValue){
		case LOW :
			if(PinNum >= 0 && PinNum <= 7){
				Clear_Bit(PORT_A,PinNum);
			}else if(PinNum >= 8 && PinNum <= 15){
				Clear_Bit(PORT_B,(PinNum - 8));
			}else if(PinNum >= 16 && PinNum <= 23){
				Clear_Bit(PORT_C,(PinNum - 16));
			}else if(PinNum >= 24 && PinNum <= 31){
				Clear_Bit(PORT_D,(PinNum - 24));
			}
		break;
		case HIGH :
			if(PinNum >= 0 && PinNum <= 7){
				Set_Bit(PORT_A,PinNum);
			}else if(PinNum >= 8 && PinNum <= 15){
				Set_Bit(PORT_B,(PinNum - 8));
			}else if(PinNum >= 16 && PinNum <= 23){
				Set_Bit(PORT_C,(PinNum - 16));
			}else if(PinNum >= 24 && PinNum <= 31){
				Set_Bit(PORT_D,(PinNum - 24));
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
	switch(PinDirection){
		case INPUT :
		if(PinNum >= 0 && PinNum <= 7){
			Clear_Bit(DDR_A,PinNum);
			}else if(PinNum >= 8 && PinNum <= 15){
			Clear_Bit(DDR_B,(PinNum - 8));
			}else if(PinNum >= 16 && PinNum <= 23){
			Clear_Bit(DDR_C,(PinNum - 16));
			}else if(PinNum >= 24 && PinNum <= 31){
			Clear_Bit(DDR_D,(PinNum - 24));
		}
		break;
		case OUTPUT :
		if(PinNum >= 0 && PinNum <= 7){
			Set_Bit(DDR_A,PinNum);
			}else if(PinNum >= 8 && PinNum <= 15){
			Set_Bit(DDR_B,(PinNum - 8));
			}else if(PinNum >= 16 && PinNum <= 23){
			Set_Bit(DDR_C,(PinNum - 16));
			}else if(PinNum >= 24 && PinNum <= 31){
			Set_Bit(DDR_D,(PinNum - 24));
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
		if(PinNum >= 0 && PinNum <= 7){
			Read_val =  Get_Bit(PIN_A,PinNum);
			}else if(PinNum >= 8 && PinNum <= 15){
			Read_val = Get_Bit(PIN_B,(PinNum - 8));
			}else if(PinNum >= 16 && PinNum <= 23){
			Read_val = Get_Bit(PIN_C,(PinNum - 16));
			}else if(PinNum >= 24 && PinNum <= 31){
			Read_val = Get_Bit(PIN_D,(PinNum - 24));
		 }	
		 return Read_val ;
}