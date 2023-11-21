/*
 * UART_Core.c
 *
 * Created: 9/29/2023 2:17:07 PM
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
#include "UART_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 UART_RECIEVED_DATA[4];
uint8 UART_TRANSMITE_DATA[8];
uint8 Receive_Status_Flag=0;
uint8 TX_STATUS_FLAG =0;
uint8 TX_CNT=0;

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

void UART_Init(void)
{
	
	uint8 BaudRate_Value_l=0;
	/********** Parity **************/
	#if (UART_POLARITY_STATE == ENABLE)
	#if (UART_POLARITY_TYPE == POLARITY_ODD)
	UCSRC |= 0XD0;
	#elif (UART_POLARITY_TYPE == POLARITY_ODD)
	UCSRC |= 0XA0;
	#endif
	#endif /*(UART_POLARITY_STATE == ENABLE)*/
	
	/************ UART DATA BITS *********/
	#if (UART_DATA_BYTES == UART_DATA_BYTES_5)
	UCSRC |= 0X80;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_6)
	UCSRC |= 0X82;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_7)
	UCSRC |= 0X84;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_8)
	UCSRC |= 0X86;
	#endif /*#if (UART_DATA_BYTES == UART_DATA_BYTES_5)*/
	
	/********** UART INT *************/ 
	#if (UART_INTERRUPT_STATE == ENABLE)
		SET_BIT	(UCSRB , 6);	/*Tx INT Enable*/
		SET_BIT (UCSRB , 7);	/*Rx INT Enable*/
	#elif (UART_INTERRUPT_STATE == DISABLE)
		CLR_BIT	(UCSRB , 6);	/*Tx INT DISable*/
		CLR_BIT (UCSRB , 7);	/*Rx INT DISable*/
	#endif
	
		/* Enable UART Tx*/
		SET_BIT(UCSRB , 3);
		
		/* Enable UART RX*/
		SET_BIT(UCSRB , 4);
	
	/************ Sync mode ***************/
 	/*#if (UART_Sync_Mode == UART_Asynchronous_mode)
 			SET_BIT(UCSRC , 7);
 			CLR_BIT(UCSRC , 6);
 	#elif (UART_Sync_Mode == UART_Asynchronous_mode)
 			SET_BIT(UCSRC , 7);
 			SET_BIT(UCSRC , 6);
 	#endif / *#if (UART_Sync_Mode == UART_Asynchronous_mode)* /*/
	
	/********* UART STOP BIT ********/
	/*#if (UART_STOP_BITS == UART_STOP_1Bit)
		SET_BIT(UCSRC , 7);
		CLR_BIT(UCSRC , 3);
	#elif (UART_STOP_BITS == UART_STOP_2Bit)
		SET_BIT(UCSRC , 7);
		SET_BIT(UCSRC , 3);
	#endif / *#if (UART_STOP_BITS == UART_STOP_1Bit)* /*/
	
	
	
	/********** BaudRate ****************/
	BaudRate_Value_l = ((160000U) / (UART_BAUD_RATE * 16U)) - 1;
	UBRRL = BaudRate_Value_l;
	

	
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
void UART_InitiateTX (void)
{
	SET_BIT	(UCSRB , 6);	/*Tx INT Enable*/
	TX_STATUS_FLAG = 1 ;
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
void UART_SendData(void)
{
	
	if (TX_CNT == TxDATA_BUFFER_SIZE)
	{
		TX_CNT=0;
		CLR_BIT	(UCSRB , 6);	/*Tx INT DISable*/
		TX_STATUS_FLAG = 0;		
	}
	if (TX_STATUS_FLAG ==1 )
	{
		UDR= UART_TRANSMITE_DATA[TX_CNT];
		TX_STATUS_FLAG=0;
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
void UART_ReceiveData(void)
{
	static uint8 Receive_Counter=0;
	/******* Smart Dooor *********/
	/*static uint8 Count=0;*/

	
	UART_RECIEVED_DATA[Receive_Counter]= UDR;
	Receive_Counter++;
	
		if (UDR == '.' )
		{
			Receive_Counter=0;
			Receive_Status_Flag=1;
		}
	
	
	/****** Smart Door *******/
	/*Count++;
	if(Receive_Counter == 1)
	{	
		Receive_Counter=0;
		Receive_Status_Flag=1;
		
	}
	if (Count ==4)
	{
		Count=0;
	}*/
	

	
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
uint8 UART_ReceiveStatus(void)
{
	uint8 Rec_Status_l=0 ;
	
	if (Receive_Status_Flag == 1)
	{
		Receive_Status_Flag=0;
		Rec_Status_l=1;
	}
	
	return Rec_Status_l;
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
