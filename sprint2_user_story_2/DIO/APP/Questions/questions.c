/*
 * questions.c
 *
 * Created: 2/20/2019 10:42:33 AM
 *  Author: AVE-LAP-069
 */ 

/********************************************* Includes *****************************************/
#include "questions.h"

/**************************************** Functions Definitions *********************************/
/****************************************************************************

Function Name		 : APP_questions_init

Function Description : Function responsible for initialization the modules needed in the questions application

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/

void APP_questions_init(){
	LCD_init();  /* Init LCD module */
	DIO_SetPinDirection(APP_QUESTIONS_YES_BTN_NUM,INPUT);	/* Define Yes btn pin as input pin */
	DIO_SetPinDirection(APP_QUESTIONS_NO_BTN_NUM,INPUT);	/* Define No btn pin as input pin  */
}

/****************************************************************************

Function Name		 : APP_questions_show_welcome_screen

Function Description : Function responsible for showing the starting screen before the questions

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_show_welcome_screen(){
	uint8 local_u8_screen_counter ;  /* Define counter to determine number of blinking of welcome screen */
	
	/* Display the welcoming screen in twice rows of char LCD certain times */
	
	for(local_u8_screen_counter = NUM_ZERO;local_u8_screen_counter < NUM_OF_REPEAT_WELC_SCREEN ;local_u8_screen_counter++){
		Welcome_Emoji(0,0,smile);
		LCD_sendString_RowCol("Welcome Nerds",CHAR_LCD_ROW_ONE,CHAR_LCD_THIRD_COL);
		_delay_ms(WELCOME_SCREEN_DELAY);
		LCD_clear();
		_delay_ms(WELCOME_SCREEN_DELAY);
		Welcome_Emoji(1,1,smile);
		LCD_sendString_RowCol("Welcome Nerds",CHAR_LCD_ROW_TWO,CHAR_LCD_THIRD_COL);
		_delay_ms(WELCOME_SCREEN_DELAY);
		LCD_clear();
		_delay_ms(WELCOME_SCREEN_DELAY);				
	}
}

/****************************************************************************

Function Name		 : APP_questions_press_any_btn_to_start

Function Description : Function responsible for waiting the player to press to start questions

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_press_any_btn_to_start(){
	/* check the stage ID */
	if(Global_u8_APP_questions_stages == PRESS_ANY_KEY_STAGE){
		LCD_sendString_RowCol("Press Any Key",1,2);
		/* If any button pressed move to the next stage (question 1) and clear the screen */ 
		if( DIO_ReadPin(APP_QUESTIONS_YES_BTN_NUM) == HIGH){
			_delay_ms(BTN_DEBOUNCING_DELAY);
			if( DIO_ReadPin(APP_QUESTIONS_YES_BTN_NUM) == HIGH){
				LCD_clear();
				Global_u8_APP_questions_stages++ ;
			}
		}
		else if( DIO_ReadPin(APP_QUESTIONS_NO_BTN_NUM) == HIGH){
			_delay_ms(BTN_DEBOUNCING_DELAY);
			if( DIO_ReadPin(APP_QUESTIONS_NO_BTN_NUM) == HIGH){
				LCD_clear();
				Global_u8_APP_questions_stages++ ;
			}
		}
		else{
	
		}
		
	}
}

/****************************************************************************

Function Name		 : APP_questions_questions_stage

Function Description : Function responsible for waiting the questions stage 

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_questions_stage(){
	
	switch(Global_u8_APP_questions_stages){
		case QUESTION_ONE_STAGE :
				LCD_sendString_RowCol(Global_arr_questions_ptr[QUESTION_ONE_STAGE],0,0);
		break;
		case QUESTION_TWO_STAGE :
				LCD_sendString_RowCol(Global_arr_questions_ptr[QUESTION_TWO_STAGE],0,0);
		break;
		case QUESTION_THREE_STAGE :
				LCD_sendString_RowCol(Global_arr_questions_ptr[QUESTION_THREE_STAGE],0,0);
		break;
		case QUESTION_FOUR_STAGE :
				LCD_sendString_RowCol(Global_arr_questions_ptr[QUESTION_FOUR_STAGE],0,0);
		break;
		case QUESTION_FIVE_STAGE :
				LCD_sendString_RowCol(Global_arr_questions_ptr[QUESTION_FIVE_STAGE],0,0);
		break;
		default:
		
		break;
	}
}

/****************************************************************************

Function Name		 : APP_questions_wait_for_answer

Function Description : Function responsible for waiting the answers of each question

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_wait_for_answer(){
	
	/* check whether the stage is any questions stage */
	if(Global_u8_APP_questions_stages >= QUESTION_ONE_STAGE && Global_u8_APP_questions_stages <= QUESTION_FIVE_STAGE){
		/* If any button pressed save score and move to the next question */
		if( DIO_ReadPin(APP_QUESTIONS_YES_BTN_NUM) == HIGH){
			_delay_ms(BTN_DEBOUNCING_DELAY);
			if( DIO_ReadPin(APP_QUESTIONS_YES_BTN_NUM) == HIGH){
				/* check the answer and calculate score */
					APP_questions_check_answer(YES);	
				}
		}else if( DIO_ReadPin(APP_QUESTIONS_NO_BTN_NUM) == HIGH){
			_delay_ms(BTN_DEBOUNCING_DELAY);
			if( DIO_ReadPin(APP_QUESTIONS_NO_BTN_NUM) == HIGH){
				/* check the answer and calculate score */
				APP_questions_check_answer(NO);
			}
		}else{
			
		}
	}
}

/****************************************************************************

Function Name		 : APP_questions_check_answer

Function Description : Function responsible for waiting the answers of each question

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_check_answer(uint8 u8_answer){
	/* check whether the stage is any questions stage */
	if(Global_u8_APP_questions_stages >= QUESTION_ONE_STAGE && Global_u8_APP_questions_stages <= QUESTION_FIVE_STAGE){
		/* In case of valid answer */
		if(Glocal_arr_questions_answer[Global_u8_APP_questions_stages] == u8_answer){
			/* increase score and move to the next question */
			_delay_ms(HALF_SECOND_DELAY);
			LCD_clear();
			LCD_gotoRowColumn(0,0);
			True_Emoji();
			_delay_ms(1000);
			LCD_clear();
			Global_u8_score += POINTS_FOR_EACH_QUESTION ;
			Global_u8_APP_questions_stages++ ;
		/* In case of wrong answer */
		}else if(Glocal_arr_questions_answer[Global_u8_APP_questions_stages] != u8_answer){
			/* Move to the next question */
			_delay_ms(HALF_SECOND_DELAY);
			LCD_clear();
			LCD_gotoRowColumn(0,0);
			False_Emoji();
			_delay_ms(1000);
			LCD_clear();
			Global_u8_APP_questions_stages++ ;
		}else{
			
		}	
	}
}

/****************************************************************************

Function Name		 : APP_questions_show_score

Function Description : Function responsible for showing the score of the questions in LCD

Function Parameters  : N/A

Function Return      : N/A

*******************************************************************************/
void APP_questions_show_score(){
	if(Global_u8_APP_questions_stages == SCORE_SCREEN_STAGE){
		LCD_clear();
		LCD_sendString_RowCol("Score = ",0,0);
		LCD_displayCharacter((Global_u8_score + 48));
		Global_u8_APP_questions_stages++ ;
		
	}
	
}