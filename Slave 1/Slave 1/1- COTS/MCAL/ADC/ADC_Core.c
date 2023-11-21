/*
 * ADC_Core.c
 *
 * Created: 9/8/2023 4:34:20 PM
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
#include "ADC_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 ADC_Vin_Value=0;

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
void ADC_Init(void)
{
	
	/************ Vref *************/
	#if (ADC_VOLTAGE_REFERENCE == ADC_VREF_VCC)
			SET_BIT(ADMUX,6);
			CLR_BIT(ADMUX,7);		
	#elif (ADC_VOLTAGE_REFERENCE == ADC_VREF_AREF)
			CLR_BIT(ADMUX,6);
			CLR_BIT(ADMUX,7);
	#elif (ADC_VOLTAGE_REFERENCE == ADC_VREF_INTERNAL)
			SET_BIT(ADMUX,6);
			SET_BIT(ADMUX,7);
	#endif /*(ADC_VOLTAGE_REFERENCE == ADC_VREF_VCC)*/

	
	/************* Right Adjust ************/
	#if (ADC_REG_ADJUST == ADC_RIGHT_ADJUST)
		CLR_BIT(ADMUX, 5);
	#elif (ADC_REG_ADJUST == ADC_LEFT_ADJUST)
		SET_BIT(ADMUX, 5);
	#endif	/*(ADC_REG_ADJUST == ADC_RIGHT_ADJUCT)*/
		
		
	/************* Channels ************/
	#if (ADC_CHANNEL == ADC_CHANNEL_0)	
		ADMUX |= 0x00;
	#elif (ADC_CHANNEL == ADC_CHANNEL_1)
		ADMUX |= 0x01;
	#elif (ADC_CHANNEL == ADC_CHANNEL_2)
		ADMUX |= 0x02;
	#elif (ADC_CHANNEL == ADC_CHANNEL_3)
		ADMUX |= 0x03;
	#elif (ADC_CHANNEL == ADC_CHANNEL_4)
		ADMUX |= 0x04;
	#elif (ADC_CHANNEL == ADC_CHANNEL_5)
		ADMUX |= 0x05;	
	#elif (ADC_CHANNEL == ADC_CHANNEL_6)
		ADMUX |= 0x06;
	#elif (ADC_CHANNEL == ADC_CHANNEL_7)
		ADMUX |= 0x07;
		
	#endif /*(ADC_CHANNEL == ADC_CHANNEL_0)*/

	/************ Conversion type *************/
	//auto
	#if (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_SINGLE_CONVERSION)
		CLR_BIT (ADCSRA, 5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_FREE_RUNNING)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x00<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Analog_Comparator)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x01<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_External_Interrupt_Request_0)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x02<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Timer_Counter0_Compare_Match)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x03<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Timer_Counter0_Overflow)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x04<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Timer_Counter_Compare_Match_B)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x05<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Timer_Counter1_Overflow)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x06<<5);
	#elif (ADC_CONVERSION_TRIGGER == ADC_CONVERSION_Timer_Counter1_Capture_Event)
		SET_BIT (ADCSRA, 5);
		SFIOR |= (0x07<<5);
	
	#endif	/*(ADC_CONVERSION_TRIGGER == ADC_CONVERSION_SINGLE_CONVERSION)*/
	
	/***************** INT **************/
	
	#if (ADC_INTERRUPT_STATES == ADC_INTERRUPT_DISABLED)
			CLR_BIT(ADCSRA, 3);
	#elif (ADC_INTERRUPT_STATES == ADC_INTERRUPT_ENABLED)
			SET_BIT(ADCSRA, 3);
	#endif	/*(ADC_INTERRUPT_STATES == ADC_INTERRUPT_DISABLED)*/

	/********** Prescaler ******************/
	#if (ADC_PRESCALER == ADC_PRESCALER_2)
		ADCSRA |= 0x01;
	#elif (ADC_PRESCALER == ADC_PRESCALER_4)
		ADCSRA |= 0x02;
	#elif (ADC_PRESCALER == ADC_PRESCALER_8)
		ADCSRA |= 0x03;
	#elif (ADC_PRESCALER == ADC_PRESCALER_16)
		ADCSRA |= 0x04;
	#elif (ADC_PRESCALER == ADC_PRESCALER_32)
		ADCSRA |= 0x05;
	#elif (ADC_PRESCALER == ADC_PRESCALER_64)
		ADCSRA |= 0x06;
	#elif (ADC_PRESCALER == ADC_PRESCALER_128)
		ADCSRA |= 0x07;
		
	#endif /*(ADC_PRESCALER == ADC_PRESCALER_2)*/
	

	/*********** Enable ADC ************/	
		SET_BIT(ADCSRA, 7);	
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
void ADC_Read (void)
{
	uint32 ADC_Digital_Value = 0;
	/*********** Start Conversion ************/
	SET_BIT(ADCSRA, 6);
	
	#if (ADC_INTERRUPT_STATES == ADC_INTERRUPT_DISABLED ) 
		while (GET_BIT (ADCSRA , 4) ==0);
		#if (ADC_REG_ADJUST == ADC_RIGHT_ADJUST)
		ADC_Digital_Value = ADC_input_16bit_Access;
		#elif (ADC_REG_ADJUST == ADC_LEFT_ADJUST)
		ADC_Digital_Value = (ADCH<<2) | (ADCL>>6);
		#endif 
		ADC_Vin_Value= ((ADC_Digital_Value *5000) / 1023);
	#endif /*(ADC_INTERRUPT_STATES == ADC_INTERRUPT_DISABLED )*/
	
	
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
