/*
 * EEPROM_Core.h
 *
 * Created: 10/7/2023 7:12:24 PM
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
#ifndef EEPROM_CORE_H_
#define EEPROM_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "I2C_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EEPROM_ADDRESS	0b01010000

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
void EEPROM_WriteByte (uint8 data , uint8 Page_Address , uint8 Byte_location);

void EEPROM_WriteMultipleByte (uint8 *data , uint8 data_size , uint8 Addr , uint8 Byte_location);

uint8 EEPROM_ReadByte ( uint8 Page_Addr , uint8 Byte_location);

 
#endif /* EEPROM_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/