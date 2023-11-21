/*
 * KeyPad_Core.h
 *
 * Created: 8/26/2023 2:35:11 PM
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
#ifndef KEYPAD_CORE_H_
#define KEYPAD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "KeyPad_CFG.h"
#include "DIO_CORE.h"
#define F_CPU 16000000U
#include <util/delay.h>
#include "LCD_Core.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	KEYPAD_PRESSED = 0,
	KEYPAD_NOT_PRESSED,
	KEYPAD_NA
}BUTTON_STATUS;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 extern uint8 KEYPAD_Values [Row_num][Col_num];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void  KEYPAD_init ();

uint8  KeyPAD_GetValue ();
 
#endif /* KEYPAD_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/