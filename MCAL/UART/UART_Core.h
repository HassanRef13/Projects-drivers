/*
 * UART_Core.h
 *
 * Created: 9/29/2023 2:15:55 PM
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
#ifndef UART_CORE_H_
#define UART_CORE_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"
#include "UART_CFG.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ENABLE   1
#define DISABLE  0

#define Parity_ODD  1
#define Parity_EVEN 0

#define	UART_DATA_BYTES_5  0
#define UART_DATA_BYTES_6  1
#define	UART_DATA_BYTES_7  2
#define UART_DATA_BYTES_8  3
#define UART_DATA_BYTES_9  4

#define UART_Asynchronous_mode	0
#define UART_synchronous_mode	1

#define UART_STOP_1Bit	1
#define UART_STOP_2Bit	2
		
/**********************************************************************************************************************
 *  GLOBUART_DATA_BYTES_8AL FUNCTION MACROS
 *********************************************************************************************************************/
		

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
uint8 TxData_Buffert[TxDATA_BUFFER_SIZE];



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern uint8 UART_RECIEVED_DATA[4];
extern uint8 UART_TRANSMITE_DATA[8];

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void UART_Init(void);

void UART_InitiateTX (void);

void UART_SendData(void);

void UART_ReceiveData(void);

uint8 UART_ReceiveStatus(void);


#endif /* UART_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
