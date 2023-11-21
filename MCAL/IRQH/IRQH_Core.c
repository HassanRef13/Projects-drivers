/*
 * IRQH_Core.c
 *
 * Created: 9/3/2023 10:49:03 AM
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
#include "IRQH_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
void (*CallBack_PtrFunc [20])(void) = {Null};
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
void IRQH_SetGlobalINT(uint8 Global_INT_Status )
{
	switch (Global_INT_Status)
	{
		case INT_ENABLE :
			SET_BIT(SREG,7);
			break;
			
		case INT_DISABLE :
			CLR_BIT(SREG,7);
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
void IRQG_Set_ExternalINT (void)
{
	#if (EXT_INT_0 == INT_ENABLE)
		SET_BIT(GICR, 6);
		
		#if (EXT_INT_0_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL)
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);

		#elif (EXT_INT_0_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
				
		#elif (EXT_INT_0_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);		
		
		#elif (EXT_INT_0_TRIGGER == EXT_INT_TRIGGER_RISING_EADGE)
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);			
		
		#endif /*(EXT_INT_0_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)*/
	
	#endif  /*(EXT_INT_0 == INT_ENABLE)*/
	
	#if (EXT_INT_1 == INT_ENABLE)
	
		SET_BIT(GICR, 7);
		
		#if (EXT_INT_1_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL)
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);

		#elif (EXT_INT_1_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
		
		#elif (EXT_INT_1_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
		
		#elif (EXT_INT_1_TRIGGER == EXT_INT_TRIGGER_RISING_EADGE)
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
		
		#endif /*(EXT_INT_1_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)*/
		
	#endif /*(EXT_INT_1 == INT_ENABLE)*/
	
	#if (EXT_INT_2 == INT_ENABLE)
		SET_BIT(GICR, 5);	
		
		#if (EXT_INT_2_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)
		CLR_BIT(MCUCSR,6);
		
		#elif (EXT_INT_2_TRIGGER == EXT_INT_TRIGGER_RISING_EADGE)
		SET_BIT(MCUCR,6);
		
		#endif /*(EXT_INT_2_TRIGGER == EXT_INT_TRIGGER_FALLING_EADGE)*/

	
	#endif /*(EXT_INT_2 == INT_ENABLE)*/
	
	
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
void IRQH_Set_callback (uint8 Interrupt_Vector_Index, void(*p)(void)   )
{
	CallBack_PtrFunc[Interrupt_Vector_Index] = p;
}

/********** external INT ************/
ISR(INT0_vect)
{
	if (CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX] != Null)
	{
		(*CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX])();
	}
}

/*********** ADC *****************/
ISR(ADC_vect)
{
		uint32 ADC_Digital_Value=0;
		ADC_Digital_Value=ADC_input_16bit_Access;
		ADC_Vin_Value= ((ADC_Digital_Value *5000) / 1023);
}

/************ Timer1 overflow flag********/
ISR(TIMER1_OVF_vect)
{
	Time1_OVF_g++;
}

/********* Timer0 overflow flag	********/
ISR(TIMER0_OVF_vect)
{
	static uint8 ctr =0;
	if (Timer0_Mode == CTC)
	{
		ctr ++;
		if (ctr == Timer0_Total_num_ovf_g)
		{	
			(*CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX])();
			ctr =0 ;
			TCNT0 = Time0_Init_value_g;
		}
	}
}

/******* Timer one CTC *******/
// ISR(TIMER1_COMPA_vect)
// {
// 	static uint8 Counter =0;
// 	Counter++;
// 	if (Counter == 1)
// 	{
// 		
// 		(*CallBack_PtrFunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX])();
// 		Counter =0 ;
// 	}
// }

ISR(TIMER1_CAPT_vect)
{	
	ICU_Cnt++;
	if(ICU_Cnt ==	1)
	{
		CAP1 = ICR1_16Bit_Access;
		Time1_OVF_g=0;
		/********* Falling eadge ******/
		CLR_BIT(TCCR1B, 6);
	}
	else if (ICU_Cnt ==	2)
	{
		CAP2= ICR1_16Bit_Access	+	(Time1_OVF_g * 65535);
		/********* Rising eadge ******/
		SET_BIT(TCCR1B, 6);
		
	}
	else if (ICU_Cnt ==	3)
	{
		Cap3 = ICR1_16Bit_Access + (Time1_OVF_g * 65535);
		
		/******** INT OFF ICU ***********/
		CLR_BIT(TIMSK,5);
	}
	
}


/************ UART ************/
ISR(USART_RXC_vect)
{
	if(CallBack_PtrFunc[USART_Rx_Complete_VECTOR_INDEX] != Null)
	{
		(*CallBack_PtrFunc[USART_Rx_Complete_VECTOR_INDEX])();
	}
}

ISR(USART_TXC_vect)
{
	
	TX_STATUS_FLAG =1;
	TX_CNT++;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
