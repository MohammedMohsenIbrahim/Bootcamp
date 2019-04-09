/*********************************************************************************
 *
 *  Selection_Sort.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * As per explained algorithm, complete the below code to implement a fully
 * functional selection sort code
 *
 ********************************************************************************/
#include "../headers/Selection_Sort.h"


void selectionSort(int arr[], int arr_size)
{
	/* Your code goes here */
	int arr_counter , arr_counter2 , temp;
		for(arr_counter = 0 ; arr_counter < arr_size ; arr_counter++){
			for(arr_counter2 = arr_counter ; arr_counter2 < arr_size;arr_counter2++){
				if(arr[arr_counter] > arr[arr_counter2]){
					temp = arr[arr_counter];
					arr[arr_counter] = arr[arr_counter2];
					arr[arr_counter2] = temp ;
				}
		}
	}
}

