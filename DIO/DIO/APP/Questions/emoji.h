
/*
 * Smile1.h
 *
 * Created: 2/20/2019 12:07:47 PM
 *  Author: AVE-LAP-063
 */ 


#ifndef SMILE1_H_
#define SMILE1_H_
#include "../../Types.h"
#include "../../HAL/headers/LCD.h"

/*********************************************************** Magic Numbers ********************************************************/
#define NUM_ZERO							0
#define NUM_ONE								1
#define NUM_TWO								2
#define NUM_THREE							3
#define NUM_FIVE							5
#define NUM_SEVEN							7
#define NUM_SIX								6
#define NUM_EIGHT							8
#define NUM_TEN								10
#define NUM_TWELVE							12
#define NUM_SIXTEEN							16
#define NUM_SEVENTEEN						17
#define NUM_FOUR							4
#define NUM_THIRTY_ONE						31
#define second_address                     0x48
#define third_address                      0x50
#define forth_address                       0x58
#define fifth_address                       0x60       
#define sixth_address                       0x68
#define seventh_address                      0x70
#define eighth_address                       0x78
#define nitnth_address                       0x80


/****************************************************************************

Function Name		 : Welcome_Emoji

Function Description : Function responsible for drawing a shape in the welcoming screen in the char LCDs

Function Parameters  : 
					   r : the row number of the shape
					   c : the column number of the shape 
					   *func : pointer to function of the shape wanted to be displayed

Function Return      : N/A

*******************************************************************************/
void Welcome_Emoji(uint8 r, uint8 c,void*func(void));

/****************************************************************************

Function Name		 : True_Emoji

Function Description : Function responsible for drawing a smile emoji with true symbol in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/
void True_Emoji();

/****************************************************************************

Function Name		 : False_Emoji

Function Description : Function responsible for drawing a sad emoji with false symbol in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/
void False_Emoji();

/****************************************************************************

Function Name		 : smile

Function Description : Function responsible for drawing smile face in the character LCD

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void smile();

/****************************************************************************

Function Name		 : sad

Function Description : Function responsible for drawing a sad face in the character LCD

Function Parameters  : N/A 
					  
Function Return      : N/A

*******************************************************************************/
void sad();






#endif /* SMILE1_H_ */