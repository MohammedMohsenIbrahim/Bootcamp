/*
 * seven_seg.h
 *
 * Created: 2/18/2019 12:47:10 PM
 *  Author: AVE-LAP-069
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

/****************************** Includes ***********************************/
#include "seven_seg_config.h"

/**************************** Definitions ***********************************/
#define FIRST_SEVEN_SEG				1
#define SECOND_SEVEN_SEG			2
#define THIRD_SEVEN_SEG				3
#define FORTH_SEVEN_SEG				4

#define LEAST_CHAR_DISPLAYED_7SEG   0
#define MOST_CHAR_DISPLAYED_7SEG    9

#define MOST_FOUR_BITS_MASK			0xF0

/************************ Functions Declarations ****************************/
void BCDSevegments_init();
void BCDSevegments_enable(uint8 seven_seg_num);
void BCDSevegments_disable(uint8 seven_seg_num);
void BCDSevegments_displayNo(uint8 displayed_num);

#endif /* SEVEN_SEG_H_ */