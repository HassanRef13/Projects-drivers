/*
 * Timer_CFG.h
 *
 * Created: 9/15/2023 3:45:16 PM
 *  Author: Hassan
 */ 
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define Timer0_State			Timer_Disable
#define Timer1_State			Timer_Enable
#define Timer2_State			Timer_Disable

#define Timer0_Mode				Normal_mode
#define Timer1_Mode				Normal_mode
#define Timer2_Mode				Normal_mode

#define Timer0_count_ms			1000U
#define Timer1_count_ms			1000U
#define Timer2_count_ms			1000U


#define Timer0_Prescaler		prescaler_8
#define Timer1_Prescaler		prescaler_1024
#define Timer2_Prescaler		prescaler_1024

#define Timer0_Interrupt_State	Timer_Interrupt_Disable
#define Timer1_Interrupt_State	Timer_Interrupt_Enable
#define Timer2_Interrupt_State	Timer_Interrupt_Disable

#define Timer_Interrupt_Enable	0U
#define Timer_Interrupt_Disable 1U

#define Timer0_OutPut_Compare	PWM_NON_INVERTING
#define Timer1_OutPut_Compare	PWM_NON_INVERTING
#define Timer2_OutPut_Compare	PWM_NON_INVERTING




/*********** Timer state *********/
#define Timer_Enable		0U
#define Timer_Disable		1U

/********* modes **********/
#define Normal_mode			0U
#define CTC					2U

#define No_clock_source			0U
#define No_prescaling			1U
#define prescaler_8				8U
#define prescaler_64			64U
#define prescaler_256			256U
#define prescaler_1024			1024U
#define EXT_CLk_Falling_Eadge	6U
#define EXT_CLk_Rising_Eadge	7U


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* TIMER_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
