/*
 * DC_Motor_Core.c
 *
 * Created: 9/23/2023 8:54:50 AM
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
#include "DC_Motor_Core.h"

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
void DC_Motor_init()
{
	PWM_init();
}
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
void DC_Motor1(Direction_t Dir ,uint8 speed)
{
	
	PWM0_GENERATE(speed);
	
	switch (Dir)
	{
		case Clockwise:
			/****PORTC_PIN6  22 for in3  ********/
			DIO_WriteChannel(22 , PIN_HIGH);
			/****PORTC_PIN7  23  for in4 ********/
			DIO_WriteChannel(23 , PIN_LOW);
			break;
		case Anticlockwise:
			/****PORTC_PIN6  22 for in1  ********/
			DIO_WriteChannel(22 , PIN_LOW);
			/****PORTC_PIN7  23  for in3 ********/
			DIO_WriteChannel(23 , PIN_HIGH);
		break;
		
		default:
		break;
	}
	
	
}
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
void DC_Motor2(Direction_t Dir ,uint8 speed)
{
	
	PWM0_GENERATE(speed);
	
	switch (Dir)
	{
		case Clockwise:
			/****PORTC_PIN4   for in1  ********/
			DIO_WriteChannel(PORTC_PIN4 , PIN_HIGH);
			/****PORTC_PIN5    for in2 ********/
			DIO_WriteChannel(PORTC_PIN5 , PIN_LOW);
			break;
		case Anticlockwise:
			/****PORTC_PIN4   for in1  ********/
			DIO_WriteChannel(PORTC_PIN4 , PIN_LOW);
			/****PORTC_PIN5    for in2 ********/
			DIO_WriteChannel(PORTC_PIN5 , PIN_HIGH);
			break;
		
		default:
			break;
	}
	
	
}
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
void DC_Motor1_Stop(void)
{
	/****PORTC_PIN6  22 for in3  ********/
	DIO_WriteChannel(PORTC_PIN6 , PIN_HIGH);
	/****PORTC_PIN7  23 for in4  ********/
	DIO_WriteChannel(PORTC_PIN7 , PIN_HIGH);
	
}

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
void DC_Motor2_Stop(void)
{
	/****PORTC_PIN4   for in1  ********/
	DIO_WriteChannel(PORTC_PIN4 , PIN_HIGH);
	/****PORTC_PIN5   for in2  ********/
	DIO_WriteChannel(PORTC_PIN5 , PIN_HIGH);
	
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
