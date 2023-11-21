/*
 * Time_Core.c
 *
 * Created: 9/15/2023 3:44:26 PM
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
#include "Timer_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 Timer0_Total_num_ovf_g=0;
uint32 Time0_Init_value_g =0;
uint32 Time1_OVF_g = 0;

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
void GPT_Init(void)
{
	#if (Timer0_State == Timer_Enable)
		#if (Timer0_Mode == Normal_mode)
			CLR_BIT(TCCR0 , 3);
			CLR_BIT(TCCR0 , 6);
			  #if (Timer0_Interrupt_State == Timer_Interrupt_Enable)
			  SET_BIT(TIMSK,0);
			  #elif (Timer0_Interrupt_State == Timer_Interrupt_Disable)
			  CLR_BIT(TIMSK,0);
			  #endif /*#if (Timer_Interrupt == Timer_Interrupt_Enable)*/
		#elif (Timer0_Mode ==  CTC)
			CLR_BIT(TCCR0 , 3);
			SET_BIT(TCCR0 , 6);
		#endif /*#if (Timer0_Mode == Normal_mode)*/
		#if (Timer0_Prescaler ==  No_prescaling )
		TCCR0 |= 0x01;
		#elif (Timer0_Prescaler ==  prescaler_8)
		TCCR0 |= 0x02;
		#elif (Timer0_Prescaler ==  prescaler_64 )
		TCCR0 |= 0x03;
		#elif (Timer0_Prescaler ==  prescaler_256 )
		TCCR0 |= 0x04;
		#elif (Timer0_Prescaler ==  prescaler_1024 )
		TCCR0 |= 0x05;
		#elif (Timer0_Prescaler ==  EXT_CLk_Falling_Eadge )
		TCCR0 |= 0x06;
		#elif (Timer0_Prescaler ==  EXT_CLk_Rising_Eadge )
		TCCR0 |= 0x07;
		#endif  /*#if (Clock_Select ==  No_clock_source )*/
	#endif /*#if (Timer0_State == Timer_Enable)*/	
	
	#if (Timer1_State == Timer_Enable)
		#if (Timer1_Mode == CTC)
		CLR_BIT (TCCR1A , 0);
		CLR_BIT (TCCR1A , 1);
		SET_BIT (TCCR1B , 3);
		CLR_BIT (TCCR1B , 4);
			#if (Timer1_Interrupt_State == Timer_Interrupt_Enable)
			SET_BIT(TIMSK,4);
			#elif (Timer1_Interrupt_State == Timer_Interrupt_Disable)
			CLR_BIT(TIMSK,4);
			#endif /*#if (Timer_Interrupt == Timer_Interrupt_Enable)*/
			
		#elif (Timer1_Mode == Normal_mode)
		CLR_BIT (TCCR1A , 0);
		CLR_BIT (TCCR1A , 1);
		CLR_BIT (TCCR1B , 3);
		CLR_BIT (TCCR1B , 4);		
			#if (Timer1_Interrupt_State == Timer_Interrupt_Enable)
			SET_BIT(TIMSK,2);
			#elif (Timer1_Interrupt_State == Timer_Interrupt_Disable)
			CLR_BIT(TIMSK,2);
			#endif /*#if (Timer_Interrupt == Timer_Interrupt_Enable)*/
	#endif	/*(Timer1_State == Timer_Enable)*/
				
		#if (Timer1_Prescaler ==  No_prescaling )
		TCCR1B |= 0x01;
		#elif (Timer1_Prescaler ==  prescaler_8)
		TCCR1B |= 0x02;
		#elif (Timer1_Prescaler ==  prescaler_64 )
		TCCR1B |= 0x03;
		#elif (Timer1_Prescaler ==  prescaler_256 )
		TCCR1B |= 0x04;
		#elif (Timer1_Prescaler ==  prescaler_1024 )
		TCCR1B |= 0x05;
		#endif /*#if (Timer0_Prescaler ==  No_prescaling )*/

	#endif /*#if (Timer1_State == Timer_Enable)*/
		
		
	
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
void GPT_SetTime (void)
{
	uint32 MCU_CLK_us = 16000000 / 1000000;
	
	#if (Timer0_State == Timer_Enable)
		uint8 Tick_Time_T0 = Timer0_Prescaler /MCU_CLK_us;
		#if (Timer0_Mode == Normal_Mode)
			uint32 Time_ms_T0= Timer0_count_ms;
			uint32 Total_num_tick_T0 = Time_ms_T0 *1000 /Tick_Time_T0;
			Timer0_Total_num_ovf_g= (Total_num_tick_T0/256);
			Time0_Init_value_g = 256 - (Total_num_tick_T0 % 256 ) ;
			TCNT0 = Time0_Init_value_g;
			if (Total_num_tick_T0 % 256 )
			{
				Timer0_Total_num_ovf_g++;
			}
			
		#elif (Timer0_Mode == CTC)
		
			
		
		#endif	/*#if (Timer0_Mode == Normal_Mode)*/
	#endif /*#if (Timer0_State == Timer_Enable)*/
	
	#if (Timer1_State == Timer_Enable)
		uint8 Tick_Time_T1 = Timer1_Prescaler/MCU_CLK_us;
		#if (Timer1_Mode == CTC)
		uint32 Time1_ms= Timer1_count_ms;
		uint32 Total_num_tick1 = (Time1_ms *1000 /Tick_Time_T1);
		OCR1A = Total_num_tick1 - 1 ;
		
		#elif (Timer1_Mode == Normal_mode)
		
		#endif	/*#if (Timer1_Mode == CTC)*/
	#endif	/*#if (Timer1_State == Timer_Enable)*/
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
