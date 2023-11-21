/*
 * LCD_Core.c
 *
 * Created: 8/23/2023 9:28:35 PM
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
#include "LCD_Core.h"
#define F_CPU  16000000
#include <util/delay.h>
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 Custom_Char_Arr[C_CHAR_NO][BYTES_NO]={
	/************** Volt *******************/
	{0x00,0x02,0x04,0x08,0x04,0x08,0x10,0x00},
};



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
void LCD_Init(void)
{
	#if (LCD_MODE==LCD_4BIT_MODE)
		LCD_WriteCommand(0X33);
		LCD_WriteCommand(0X32);
		LCD_WriteCommand(0X28);

		LCD_WriteCommand(0X0C);
		LCD_WriteCommand(0X01);
		
		LCD_WriteCommand(0X06);
		LCD_WriteCommand(0X02);
	
	#endif /*(LCD_MODE==LCD_4BIT_MODE)*/
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
void LCD_WriteCommand(uint8 cmd)
{
// 	uint8 old_value = 0 , New_value = 0;

	DIO_WriteChannel(LCD_RS_PIN,PIN_LOW);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);

	#if (LCD_MODE==LCD_4BIT_MODE)
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd,4));	
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd,5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd,6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd,7));
	
// 	DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
// 	New_value = ((cmd>>1) & DATA_MASK) | (old_value & DATA_PORT_MASK);
// 	DIO_WritePort(LCD_D4_PIN,New_value);*/
	
	
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd,0));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd,1));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd,2));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd,3));
	
	/*DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value = ((cmd<<3)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);*/
	
	
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	_delay_ms(5);
	
	#endif
	
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
void LCD_WriteChar(uint8 chr)
{
// 	uint8 old_value = 0 , New_value = 0;
	DIO_WriteChannel(LCD_RS_PIN,PIN_HIGH);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	#if (LCD_MODE==LCD_4BIT_MODE)
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr,4));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr,5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr,6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr,7));
	
	/*DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value= ((chr>>1)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);*/
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	
	/*DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value =((chr<<3)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);*/
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr,0));
 	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr,1));
 	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr,2));
 	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr,3));
	
	DIO_WriteChannel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN,PIN_LOW);
	_delay_ms(5);
	
	#endif
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
void LCD_WriteString(uint8* chr)
{
	uint8 cnt = 0;
	while (chr[cnt] != '\0')
	{
		LCD_WriteChar(chr[cnt]);
		cnt++;
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
void LCD_WriteInteger(sint32 num)
{
	uint32 temp=1;
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num*=-1;
	}
	while (num!=0)
	{
		temp =(temp *10)+(num%10);
		num/=10;
	}
	while(temp!=1)
	{
		LCD_WriteChar((temp%10)+48);
		temp/=10;
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
void LCD_WriteClear(void)
{
	LCD_WriteCommand(0X01);
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
void LCD_GoTo(uint8 Row,uint8 Col)
{
	uint8 arr[2]={0X80,0XC0};
	LCD_WriteCommand(arr[Row]+Col);	
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
void Custom_Char(void)
{
	uint8 Custom_Char_Count = 0 , Bytes = 0;
	for (Custom_Char_Count = 0 ; Custom_Char_Count < C_CHAR_NO ; Custom_Char_Count++)
	{
		LCD_WriteCommand(0X40+(Custom_Char_Count*8));
		for(Bytes = 0 ; Bytes < BYTES_NO ; Bytes++)
		{
			LCD_WriteChar(Custom_Char_Arr[Custom_Char_Count][Bytes]);
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
