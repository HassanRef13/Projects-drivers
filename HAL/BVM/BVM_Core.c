/*
 * BVM_Core.c
 *
 * Created: 9/13/2023 11:39:53 AM
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
#include "BVM_Core.h"
#define F_CPU  16000000
#include <util/delay.h>
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
void BVM_Init(void)
{
	ADC_Init();
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
uint16 BVM_Read(void)
{
	uint16 static arr[array_size];
 	uint8 i=0 ,j=0 ;
	uint16 median=0;
	uint8 str[]= "Volt= ";
	uint8 str2[]= " mV";
	
	ADC_Read();
	ADC_Vin_Value= (ADC_Vin_Value * (237.837))/100;

 	uint16 temp=0;
 	for (i=0 ; i <array_size ; i++)
 	{
 		arr[i]= ADC_Vin_Value;
 	}
 	
 	for (i=0 ; i < array_size ; i++)
 	{
 		for (j=1 ; j < array_size-1 ; j++)
 		{
 			if (arr[j] < arr[i])
 			{
 				temp =arr[i];
 				arr[i]=arr[j];
 				arr[j]=temp;
 			}
 		}
 	}
 	median = arr[array_size/2];

 	LCD_WriteClear();
	LCD_WriteString(str);
 	LCD_WriteInteger(median);
	LCD_WriteString(str2);
	LCD_GoTo(0,15);
	Custom_Char();
 	_delay_ms(100);

	return median;
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
