/*
 * TempSensor_Core.h
 *
 * Created: 9/9/2023 5:32:31 PM
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
#ifndef TEMPSENSOR_CORE_H_
#define TEMPSENSOR_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ADC_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


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
void TempSensor_init(void);
uint16 TempSensor_Read(void);
 
#endif /* TEMPSENSOR_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
