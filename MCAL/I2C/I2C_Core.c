/*
 * I2C_Core.c
 *
 * Created: 10/7/2023 11:10:44 AM
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
#include "I2C_Core.h"

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
void I2C_Master_init(void)
{
	/* init scl 400khz / TWBR = 0x0c*/
	/* init scl 100khz / TWBR = 0x28*/
	
	TWBR = 0x0C;
	/* for equation */
	 CLR_BIT(TWSR , 0);
	 CLR_BIT(TWSR , 1);
	
	/* Enable ACK*/
	SET_BIT(TWCR ,6);
	/* Enable I2c */
	SET_BIT(TWCR ,2);
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
void I2C_Start_Condition(void)
{
	/* TWI START Condition */
	SET_BIT(TWCR , 5);
	
	/* Trigger flag and Enable */
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while (GET_BIT(TWCR , 7 ) == 0);
	
	/*Check Operation Status*/	
  while((TWSR &0XF8) != START_ACK);
	
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
void I2C_Repeating_Start(void)
{
	/* Generate Start condition*/
	SET_BIT(TWCR , 5 ) ;
	
	/* Trigger flag and Enable I2C*/
	TWCR |= 0X84 ;
	
	/*Monitor Flag*/
	while (GET_BIT(TWCR , 7 ) == 0);
	
	/*Check Operation Status*/
  while((TWSR &0XF8) != REP_START_ACK);
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
void I2C_SendAddress_WriteOperation(uint8 addr)
{
	/*Send Slave Addr with Write Operation*/
	TWDR = (addr << 1 );
	
	/* Trigger flag and Enable */
	TWCR = 0X84 ;
	
	/*Monitor Flag*/
	while(GET_BIT(TWCR , 7) == 0);
	
	/*Check Operation Status*/	
	while((TWSR &0XF8) != SLAVE_ADD_AND_WR_ACK);
	
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
void I2C_SendAddress_ReadOperation(uint8 addr)
{
		/*Send Slave Addr with Read Operation*/
		TWDR = (addr << 1) | (0x01) ;
		
		/* Trigger flag and Enable */
		TWCR = 0X84 ;
		
		/*Monitor Flag*/		
		while(GET_BIT(TWCR , 7) == 0);
		
		/*Check Operation Status*/
	while((TWSR &0XF8) != SLAVE_ADD_AND_RD_ACK); 

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
void I2C_WriteByte(uint8 data)
{
	/*Send Data Operation*/
	TWDR = data;
	
	/* Trigger flag and Enable */
	TWCR = 0X84;
	
	/*Monitor Flag*/
	while (GET_BIT(TWCR , 7 ) == 0);
	
	/*Check Operation Status*/	
	while((TWSR &0XF8) != WR_BYTE_ACK);
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
uint8 I2C_ReadByte(void)
{
	/* Variable to be returned*/
	uint8 Data = 0 ;
	/* Trigger flag and Enable */
	TWCR = 0X84;
	
	/*Monitor Flag*/
	while (GET_BIT(TWCR , 7 ) == 0);
	
	/*Check Operation Status*/
	while((TWSR &0XF8) != RD_BYTE_WITH_ACK);

	/* Read byte */
	Data = TWDR;
	
	/* returned data */
	return Data;
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
void I2C_Stop_Condition(void)
{
	TWCR = 0X94;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
