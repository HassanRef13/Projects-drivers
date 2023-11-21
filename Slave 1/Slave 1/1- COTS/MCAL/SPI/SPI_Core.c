/*
 * SPI_Core.c
 *
 * Created: 10/3/2023 12:29:23 PM
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
#include "SPI_Core.h"
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
void SPI_Init (void)
{
	#if (SPI_INIT_STATUS == SPI_Master)
	SPI->SPCR |= 0x53;
		/*************** For Clock_Rate ********************/		
		#if	  (SPI_Master_Clock_Rate  == Master_Clock_Rate4)
			SPI->SPCR|= 0;
		#elif (SPI_Master_Clock_Rate  == Master_Clock_Rate16)
			SPI->SPCR|= 1;
		#elif (SPI_Master_Clock_Rate  == Master_Clock_Rate64)
			SPI->SPCR|= 2;
		#elif (SPI_Master_Clock_Rate  == Master_Clock_Rate128)
			SPI->SPCR|= 3;
		#endif /*#if (SPI_Master_Clock_Rate  == Master_Clock_Rate4) */
		
	#elif (SPI_INIT_STATUS == SPI_Slave)
	SPI->SPCR |= 0x40;
		/*************** For Clock_Rate ********************/
		/*SPI->SPSR|= 1
		#if	  (SPI_Slave_Clock_Rate  == Slave_Clock_Rate4)
			SPI->SPCR|= 0;
		#elif (SPI_Slave_Clock_Rate  == Slave_Clock_Rate16)
			SPI->SPCR|= 1;					
		#elif (SPI_Slave_Clock_Rate  == Slave_Clock_Rate64)
			SPI->SPCR|= 2;					
		#elif (SPI_Slave_Clock_Rate  == Slave_Clock_Rate128)
			SPI->SPCR|= 3;
		#endif / *(SPI_Slave_Clock_Rate  == Slave_Clock_Rate4)* /*/
		
	#endif /*#if (SPI_INIT_STATUS == SPI_Master)*/
	
	/********* Interrupt Mode ***********/
	#if (SPI_Interrupt_Mode == SPI_Interrupt_Disable)
		CLR_BIT(SPI->SPCR, 7);
	#elif (SPI_Interrupt_Mode == SPI_Interrupt_Enable)
		SET_BIT(SPI->SPCR, 7);
	#endif /*#if (SPI_Interrupt_Mode == SPI_Interrupt_Disable)*/
	
	/*********** Data Order *******/
	#if (SPI_Data_Order == SPI_LSB)
		SET_BIT(SPI->SPCR , 5);
	#elif (SPI_Data_Order == SPI_MSB)
		CLR_BIT(SPI->SPCR , 5);
	#endif /*#if (SPI_Data_Order == SPI_MSB)*/
	
	/************ CPOL *****************/
	#if (SPI_Clock_Polarity  ==  Leading_Rising)
	/*  Leading Edge -> Rising .. Trailing Edge -> Falling*/
		CLR_BIT(SPI->SPCR , 3);
	#elif (SPI_Clock_Polarity  ==  Leading_Falling)
	/*  Leading Edge -> Falling .. Trailing Edge -> Rising*/
		SET_BIT(SPI->SPCR , 3);
	#endif	/*#if (SPI_Clock_Polarity  ==  Leading_Rising)*/
	
	/************** CPHA  ******************/
	#if (SPI_Clock_Phase ==  Leading_Sample)
	/*  Leading Edge -> Sample .. Trailing Edge -> Setup*/
		CLR_BIT(SPI->SPCR , 2);	
	#elif (SPI_Clock_Phase ==  Leading_Setup)
	/*  Leading Edge -> Setup .. Trailing Edge -> Sample*/
		SET_BIT(SPI->SPCR , 2);
	#endif /*#if (SPI_Clock_Phase ==  Leading_Sample)*/
	
	
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
uint8 SPI_TranSiever (uint8 Trans_Data)
{
	uint8 Rec_Data=0;
	
	SPI->SPDR = Trans_Data;
	/* Break the loop when SPSR =1 / while return false*/
	while (GET_BIT(SPI->SPSR,7) ==0);
	
	Rec_Data= SPI->SPDR;
	
	return Rec_Data;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
