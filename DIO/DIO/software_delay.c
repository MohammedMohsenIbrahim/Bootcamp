/*
 * software_delay.c
 *
 * Created: 2/13/2019 2:14:35 PM
 *  Author: AVE-LAP-069
 */ 

/********************************************* Includes ***************************************/
#include "software_delay.h" 

/**************************************** Functions Definitions *******************************/
/**********************************************************************************************
Function Name		 : function_delay

Function Description : function responsible for delaying the CPU for certain number of clock cycles

Function Parameters  : delay_time : no of clock cycles delayed

Function Return      : N/A 
***********************************************************************************************/

void function_delay(uint32 delay_time){
	uint32 counter = NUM_ZERO ;
	while(counter != delay_time){
		counter++ ;
	}
}
