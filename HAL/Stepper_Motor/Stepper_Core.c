/*
 * Stepper_Core.c
 *
 * Created: 10/16/2023 12:15:21 PM
 *  Author: Hassan
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Stepper_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Stepper_set(Step_Sequance_t Step, Step_Direction_t Direction)
{
	if (Step == Full_Step_Sequance)
	{
		if (Direction == StepCW)
		{
			DIO_WritePort(Channel_A , 9);	// AD High
			DIO_WritePort(Channel_A , 3);	// AB High
			DIO_WritePort(Channel_A , 6);	// BC High
			DIO_WritePort(Channel_A , 12);	// CD High
		}
		else if (Direction == StepCCW)
		{
			DIO_WritePort(Channel_A , 9);	// AD High
			DIO_WritePort(Channel_A , 12);	// CD High
			DIO_WritePort(Channel_A , 6);	// BC High
			DIO_WritePort(Channel_A , 3);	// AB High
		}
		
	}
	else if (Step == Half_Step_Sequance)
	{
		if (Direction == StepCW)
		{
			DIO_WritePort(Channel_A , 1);	//	A  HIGH
			DIO_WritePort(Channel_A , 3);	//	AB HIGH		 
			DIO_WritePort(Channel_A , 2);	//	B  HIGH 
			DIO_WritePort(Channel_A , 6);	//	BC HIGH
			
			DIO_WritePort(Channel_A , 4);	//	C  HIGH
			DIO_WritePort(Channel_A , 12);	//	CD HIGH
			DIO_WritePort(Channel_A , 8);	//	D  HIGH
			DIO_WritePort(Channel_A , 9);	//	DA HIGH
		}
		else if (Direction == StepCCW)
		{
			DIO_WritePort(Channel_A , 9);	//	DA HIGH
			DIO_WritePort(Channel_A , 8);	//	D  HIGH
			DIO_WritePort(Channel_A , 12);	//	CD HIGH
			DIO_WritePort(Channel_A , 4);	//	C  HIGH
			
			DIO_WritePort(Channel_A , 6);	//	BC HIGH
			DIO_WritePort(Channel_A , 2);	//	B  HIGH 
			DIO_WritePort(Channel_A , 3);	//	AB HIGH
			DIO_WritePort(Channel_A , 1);	//	A  HIGH
		}
	}

	
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
