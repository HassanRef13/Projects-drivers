/*
 * Smart_Door.c
 *
 * Created: 9/24/2023 1:03:34 PM
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
#include "Smart_Door.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 Saved_Password[4]= {'1' , '2' , '3' , '4'};
uint8 Smart_counter = 0 ;
uint8 Input_Password [4]={0};
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
void Smart_Door_init(void)
{
	PORT_Init();
 	KEYPAD_init();
	LCD_Init();
	Servo_Motor_init();
	
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
void Smart_Door_Inputs (uint8 num)
{	
	LCD_WriteChar('*');
	Input_Password[Smart_counter]= num ; 	
	Smart_counter++;
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
void Smart_Door_Set (void)
{
	uint8 j=0 ;
	uint8  flag=0;
	uint8 Verified_Str[]="Verified";
	uint8 Welcome_Str[]="Welcome Back";
	uint8 Door_Locked[]="Door Locked!";
	uint8 Wrong_Pass_Str[]="Wrong Password!";
	uint8 Str1[]="Password:";
	
	for (j=0 ; j <4; j++)
	{
		if (Input_Password[j] == Saved_Password[j]	/*|| UART_RECIEVED_DATA[j] == Saved_Password[j]*/)
		{
			flag++;
		}
		
	}
	
	if (flag == 4)
	{
		
		LCD_WriteClear();
		LCD_WriteString(Verified_Str);
		BUZZER_SET_VALUE(BUZZER_HIGH);
		_delay_ms(50);
		BUZZER_SET_VALUE(BUZZER_LOW);
		_delay_ms(50);
		
		LED_SetValue(LED_GREEN , LED_HIGH);
		_delay_ms(2000);
		LCD_WriteClear();
		LCD_WriteString(Welcome_Str);

		Servo_Motor_GENERATE(90);
		_delay_ms(2000);
		Servo_Motor_GENERATE(0);
		LED_SetValue(LED_GREEN , LED_LOW);
		
		LCD_WriteClear();
		Smart_Door_Reset();
		LCD_WriteString(Str1);
		
	}
	else if (flag != 4)
	{
		
		/* RED LED HIGH*/
		LED_SetValue(LED_RED , LED_HIGH);
		LCD_WriteClear();
		LCD_WriteString(Wrong_Pass_Str);
		
		/* Buzzer Toggle */
		/*BUZZER_SET_VALUE(BUZZER_HIGH);
		_delay_ms(500);
		BUZZER_SET_VALUE(BUZZER_LOW);
		_delay_ms(500);
		BUZZER_SET_VALUE(BUZZER_HIGH);
		_delay_ms(500);
		BUZZER_SET_VALUE(BUZZER_LOW);
		_delay_ms(500);	
		BUZZER_SET_VALUE(BUZZER_HIGH);
		_delay_ms(500);
		BUZZER_SET_VALUE(BUZZER_LOW);
		_delay_ms(500);*/
		
		
  		_delay_ms(1000);
		Smart_Door_Reset();

 		LCD_WriteClear();
		LCD_WriteString(Str1);
		LED_SetValue(LED_RED , LED_LOW);
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
void Smart_Door_Reset(void)
{
	uint8 i;
	Smart_counter =0;
	LCD_WriteClear();
	for (i=0 ; i<4 ; i++)
	{
 		/*UART_RECIEVED_DATA[i]=0;*/
		Input_Password[i]=0;
	}
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
