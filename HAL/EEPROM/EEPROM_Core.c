/*
 * EEPROM_Core.c
 *
 * Created: 10/7/2023 7:12:38 PM
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
#include "EEPROM_Core.h"
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

void EEPROM_WriteByte (uint8 data , uint8 Page_Address , uint8 Byte_location)
{
	/* Start Condition*/
	I2C_Start_Condition();
	
	/* Send the address of the page */
	I2C_SendAddress_WriteOperation(Page_Address);
	
	/* send the location of byte */
	I2C_WriteByte(Byte_location);
	
	/* send the required data */
	I2C_WriteByte(data);
	
	/* stop condition */
	I2C_Stop_Condition();

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

void EEPROM_WriteMultipleByte (uint8 *data , uint8 data_size , uint8 Page_Address , uint8 Byte_location)
{
	/* array counter */
	uint8 counter=0;
	
	/* start condition */
	I2C_Start_Condition();
	
	/* send address of page */
	I2C_SendAddress_WriteOperation(Page_Address);
	
	/* send location of byte */
	I2C_WriteByte(Byte_location);
	
	/* send all data from array (EEPROM HAS INTERNAL COUNTER)*/
	while (counter < data_size)
	{
		I2C_WriteByte(data[counter]);
		counter ++;
	}
	
	/* stop condition */
	I2C_Stop_Condition();
	
	
	
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

uint8 EEPROM_ReadByte ( uint8 Page_Addr , uint8 Byte_location)
{
	/* variable to read the data*/
	uint8 data=0 ;
	
		/* start Condition*/
		I2C_Start_Condition();
		
		/* send address of page*/
		I2C_SendAddress_WriteOperation(Page_Addr);
		
		/* Send location of byte */ 
		I2C_WriteByte(Byte_location);
		
		/* Repeat start to read ( BECAUSE First operation is always write )*/				
		I2C_Repeating_Start();
		
		I2C_SendAddress_ReadOperation(Page_Addr);
		
		data = I2C_ReadByte();
		
		I2C_Stop_Condition();
		
		return data;
	
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
