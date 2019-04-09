/*
 * seven_seg_config.h
 *
 * Created: 2/18/2019 12:46:58 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

/****************************** Includes ***********************************/
#include "../../BitwiseOperations.h"
#include "../../types.h"
#include "../../DIO.h"
#include "../../software_delay.h"
#include "../../Memory_Mapped_Registers.h"

#define SEVEN_SEG_DATA_PORT PORT_B

#define SEVEN_SEGMENT1_ENABLE	26	
#define SEVEN_SEGMENT2_ENABLE	27
#define SEVEN_SEGMENT3_ENABLE	30
#define SEVEN_SEGMENT4_ENABLE	31

#define SEVEN_SEG_DB		28

#define SEVEN_SEG_PIN1		8
#define SEVEN_SEG_PIN2		9
#define SEVEN_SEG_PIN3		10
#define SEVEN_SEG_PIN4		11






#endif /* SEVEN_SEG_CONFIG_H_ */