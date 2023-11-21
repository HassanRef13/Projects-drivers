/*
 * PWM_Core.c
 *
 * Created: 9/21/2023 3:33:42 PM
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
#include "PWM_Core.h"

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
void PWM_init (void)
{
	#if (PWM0_STATE == PWM_ENABLE)
		#if (PWM0_TYPE ==  PWM_FAST)
			SET_BIT(TCCR0 , 3);
			SET_BIT(TCCR0 , 6);
				#if (PWM0_MODE == PWM_NON_INVERTING)
				CLR_BIT(TCCR0, 4);
				SET_BIT(TCCR0, 5);
				#elif (PWM0_MODE == PWM_INVERTING)
				SET_BIT(TCCR0, 4);
				SET_BIT(TCCR0, 5);
				#endif /*#if (PWM0_MODE == PWM_NON_INVERTING)*/	
		#endif /*		#if (PWM0_TYPE ==  Fast_PWM)*/
				
	#endif /*(PWM0 == PWM_ENABLE)*/ 
	
	#if (PWM1_STATE == PWM_ENABLE)
		#if (PWM1_TYPE == PWM_FAST)
			TCCR1A|=0X02;
			TCCR1B|=0X18;
	#elif (PWM1_TYPE == PWM_PHASE_CORRECT)
			TCCR1A|=0X02;
			TCCR1B|=0X10;
		#endif /*#if (PWM1_TYPE == Fast_PWM)*/
	
		#if (PWM1_MODE == PWM_NON_INVERTING)
		TCCR1A |= 0x80;
		#elif (PWM1_MODE == PWM_INVERTING)
		TCCR1A |= 0xC0;
		#endif /*#if (PWM1_MODE == PWM_NON_INVERTING)*/
	#endif /*(PWM1_STATE == PWM_ENABLE)*/
	#if (PWM2_STATE == PWM_ENABLE)
		#if (PWM2_TYPE ==  PWM_FAST)
			SET_BIT(TCCR2 , 3);
			SET_BIT(TCCR2 , 6);
				#if (PWM2_MODE == PWM_NON_INVERTING)
				CLR_BIT(TCCR2, 4);
				SET_BIT(TCCR2, 5);
				#elif (PWM2_MODE == PWM_INVERTING)
				SET_BIT(TCCR2, 4);
				SET_BIT(TCCR2, 5);
				#endif /*#if (PWM0_MODE == PWM_NON_INVERTING)*/	
		#endif /*#if (PWM0_TYPE ==  Fast_PWM)*/
	#endif /*(PWM2_STATE == PWM_ENABLE)*/
	
	

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
void PWM0_GENERATE (uint8 Duty_Cycle)
{
	#if ( PWM0_STATE == PWM_ENABLE)
		#if (PWM0_TYPE == PWM_FAST)
			#if (PWM0_MODE == PWM_NON_INVERTING)
				OCR0 = ( 256 * Duty_Cycle/100 ) -1;
			#elif (PWM0_MODE == PWM_INVERTING)
				OCR0 = 255 -((Duty_Cycle * 256 )/100);
			#endif /* #if (PWM0_MODE == PWM_NON_INVERTING)*/
		#elif (PWM0_TYPE == PWM_PHASE_CORRECT)
			#if (PWM0_MODE == PWM_NON_INVERTING)
				OCR0 = (Duty_Cycle * 255 /100 )-1;
			#elif (PWM0_MODE == PWM_INVERTING)
				OCR0 = 255 - ((Duty_Cycle * 255 )/100);
			#endif /* #if (PWM0_MODE == PWM_NON_INVERTING)*/
		#endif /*#if (PWM0_TYPE == Fast_PWM)*/
		#if (PWM0_PRESC ==  PWM_NO_PRESC )
		TCCR0 |= 0x01;
		#elif (PWM0_PRESC ==  PWM_PRESC8)
		TCCR0 |= 0x02;
		#elif (PWM0_PRESC ==  PWM_PRESC64 )
		TCCR0 |= 0x03;
		#elif (PWM0_PRESC ==  PWM_PRESC256 )
		TCCR0 |= 0x04;
		#elif (PWM0_PRESC ==  PWM_PRESC1024 )
		TCCR0 |= 0x05;
		#endif  /*#if (PWM0_PRESC ==  PWM_NO_PRESC )*/
		
	#endif /*( PWM0_STATE == PWM_ENABLE)*/
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
void PWM2_GENERATE (uint8 Duty_Cycle)
{
	#if ( PWM2_STATE == PWM_ENABLE)
		#if (PWM2_TYPE == PWM_FAST)
			#if (PWM2_MODE == PWM_NON_INVERTING)
			OCR2 = ( 256 * Duty_Cycle/100 ) -1;
			#elif (PWM2_MODE == PWM_INVERTING)
			OCR2 = 255 -((Duty_Cycle * 256 )/100);
			#endif /* #if (PWM2_TYPE == PWM_FAST)*/
		#elif (PWM2_TYPE == PWM_PHASE_CORRECT)
			#if (PWM2_MODE == PWM_NON_INVERTING)
			OCR2 = (Duty_Cycle * 255 /100 )-1;
			#elif (PWM2_MODE == PWM_INVERTING)
			OCR2 = 255 - ((Duty_Cycle * 255 )/100);
			#endif /* #if (PWM2_MODE == PWM_NON_INVERTING)*/
		#endif /*#if ( PWM2_STATE == PWM_ENABLE)*/
		
		#if (PWM2_PRESC ==  PWM_NO_PRESC )
		TCCR2 |= 0x01;
		#elif (PWM2_PRESC ==  PWM_PRESC8)
		TCCR2 |= 0x02;
		#elif (PWM2_PRESC ==  PWM_PRESC64 )
		TCCR2 |= 0x03;
		#elif (PWM2_PRESC ==  PWM_PRESC256 )
		TCCR2 |= 0x04;
		#elif (PWM2_PRESC ==  PWM_PRESC1024 )
		TCCR2 |= 0x05;
		#endif  /*#if (PWM2_PRESC ==  PWM_NO_PRESC )*/
	
	#endif /*( PWM0_STATE == PWM_ENABLE)*/
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
void PWM1_GENERATE (uint8 Duty_Cycle , uint16 Frequancy)
{
	#if ( PWM1_STATE == PWM_ENABLE)
		
		#if (PWM1_TYPE == PWM_FAST)	
		/* Timer counter */
		ICR1_16Bit_Access=(16000000/(PWM1_PRESC*Frequancy));
			  #if (PWM1_MODE == PWM_INVERTING)
			  OCR1A_16bit_Access= ICR1_16Bit_Access - ((Duty_Cycle* (ICR1_16Bit_Access+1))/100);  
			  #elif (PWM1_MODE == PWM_NON_INVERTING)
			  OCR1A_16bit_Access= (Duty_Cycle* (ICR1_16Bit_Access+1)/100)-1;
			  #endif /*#if (PWM1_MODE == PWM_INVERTING)*/
			  	
		#elif (PWM1_TYPE == PWM_PHASE_CORRECT)
				#if (PWM1_MODE == PWM_INVERTING)
				OCR1A_16bit_Access= ICR1_16Bit_Access - ((Duty_Cycle* (ICR1_16Bit_Access))/100);		
				#elif (PWM1_MODE == PWM_NON_INVERTING)
				OCR1A_16bit_Access= ((Duty_Cycle* (ICR1_16Bit_Access))/100);
				#endif /*#if (PWM1_MODE == PWM_INVERTING)*/
				/* Timer counter */
				ICR1_16Bit_Access=(16000000/(2* PWM1_PRESC*Frequancy))
		#endif /*#if (PWM1_TYPE == Fast_PWM)*/
		
		#if (PWM1_PRESC ==  PWM_PRESC8)
		TCCR1B |= 0x02;
		#elif (PWM1_PRESC ==  PWM_PRESC64 )
		TCCR1B |= 0x03;
		#elif (PWM1_PRESC ==  PWM_PRESC256 )
		TCCR1B |= 0x04;
		#elif (PWM1_PRESC ==  PWM_PRESC1024 )
		TCCR1B |= 0x05;
		#endif /*#if (PWM1_PRESC ==  PWM_PRESC8)*/
	#endif /*#if ( PWM1_STATE == PWM_ENABLE)*/
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
