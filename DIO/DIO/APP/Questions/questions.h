/*
 * questions.h
 *
 * Created: 2/20/2019 10:42:49 AM
 *  Author: AVE-LAP-069
 */ 


#ifndef QUESTIONS_H_
#define QUESTIONS_H_

/********************************************* Includes *****************************************/
#include "../../HAL/headers/LCD.h"
#include "../../DIO.h"
#include "emoji.h"

/******************************************** Definitions ***************************************/
#define APP_QUESTIONS_YES_BTN_NUM			20
#define APP_QUESTIONS_NO_BTN_NUM			10

#define NUM_ZERO							0
#define CHAR_LCD_ROW_ONE					0
#define CHAR_LCD_ROW_TWO					1
#define NUM_OF_REPEAT_WELC_SCREEN			3
#define CHAR_LCD_THIRD_COL					2
#define WELCOME_SCREEN_DELAY				400
#define BTN_DEBOUNCING_DELAY				30
#define APP_QUESTIONS_NUM_OF_QUESTIONS		6
#define STARTING_SCORE						0
#define POINTS_FOR_EACH_QUESTION			1
#define HALF_SECOND_DELAY					500
#define YES									1
#define NO									0

/* Questions answers */
#define NO_ANSWER							2
#define VALID_ANSWER						1
#define WRONG_ANSWER						0

/* APPlication Stages */
#define PRESS_ANY_KEY_STAGE					0
#define QUESTION_ONE_STAGE					1
#define QUESTION_TWO_STAGE					2
#define QUESTION_THREE_STAGE				3
#define QUESTION_FOUR_STAGE					4
#define QUESTION_FIVE_STAGE					5 
#define SCORE_SCREEN_STAGE					6
/****************************************** Global Variables ************************************/
static volatile uint8 Global_u8_APP_questions_stages = PRESS_ANY_KEY_STAGE ; 
static volatile uint8 Global_u8_score = STARTING_SCORE	;

/******************************************** Global Arrays *************************************/
/* Array to define the questions */
static volatile uint8 *Global_arr_questions_ptr[APP_QUESTIONS_NUM_OF_QUESTIONS] = {
	""									,
	"South USA 1550"					,
	"hitlar was artist"					,
	"England 0 World Cup"			    ,
	"Australia sedny"					,
	"Mekka 10th year"		
};

/* Array to define the answer of each question */
static volatile uint8 Glocal_arr_questions_answer[APP_QUESTIONS_NUM_OF_QUESTIONS] = {
	NO_ANSWER,
	WRONG_ANSWER,
	VALID_ANSWER,
	WRONG_ANSWER,
	WRONG_ANSWER,
	WRONG_ANSWER
};
/************************************** Functions Declarations **********************************/
/****************************************************************************

Function Name		 : APP_questions_init

Function Description : Function responsible for initialization the modules needed in the questions application

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_init();


/****************************************************************************

Function Name		 : APP_questions_show_welcome_screen

Function Description : Function responsible for showing the starting screen before the questions

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_show_welcome_screen();

/****************************************************************************

Function Name		 : APP_questions_press_any_btn_to_start

Function Description : Function responsible for waiting the player to press to start questions

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_press_any_btn_to_start();

/****************************************************************************

Function Name		 : APP_questions_questions_stage

Function Description : Function responsible for waiting the questions stage

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_questions_stage();

/****************************************************************************

Function Name		 : APP_questions_wait_for_answer

Function Description : Function responsible for waiting the answers of each question

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_wait_for_answer();

/****************************************************************************

Function Name		 : APP_questions_show_score

Function Description : Function responsible for showing the score of the questions in LCD

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_show_score();

/****************************************************************************

Function Name		 : APP_questions_check_answer

Function Description : Function responsible for waiting the answers of each question

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_check_answer(uint8 u8_answer);




#endif /* QUESTIONS_H_ */