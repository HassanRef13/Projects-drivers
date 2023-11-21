/*
 * MCU.h
 *
 * Created: 8/16/2023 6:21:50 PM
 *  Author: Ali
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

#ifndef MCU_H_
#define MCU_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*************************************** GPIO Registers ************************************************/
#define PHYSICAL_GPIO_ACCESS(addr)      (*(volatile uint8*)(addr))
#define GPIOA_BASE_ADDRRESS             (0X39)
#define GPIOB_BASE_ADDRRESS             (0X36)
#define GPIOC_BASE_ADDRRESS             (0X33)
#define GPIOD_BASE_ADDRRESS             (0X30)

#define GPIO_INPUT_REGISTER_PIN         (0X00)
#define GPIO_DIRCETION_REGISTER_DDR     (0X01)
#define GPIO_OUTPUT_REGISTER_PORT       (0X02)


/**************** External intrrupt*************/
#define SREG		*(volatile uint8 *)(0x5F)
#define GICR		*(volatile uint8 *)(0x5B)
#define MCUCR		*(volatile uint8 *)(0x55)
#define MCUCSR		*(volatile uint8 *)(0x54)

/*************** ADC ************************/
#define ADMUX					(*(volatile uint8*)(0x27 ))
#define ADCL					(*(volatile uint8*)(0x24 ))
#define ADC_input_16bit_Access	(*(volatile uint16*)(0x24))
#define ADCH					(*(volatile uint8*)(0x25 ))
#define ADCSRA					(*(volatile uint8*)(0x26 ))
#define SFIOR					(*(volatile uint8*)(0x50 ))

/**************** Timer ********************/
#define TCNT0	(*(volatile uint8*)(0x52))
#define TCCR0	(*(volatile uint8*)(0x53))
#define OCR0	(*(volatile uint8*)(0x5C))

#define TIMSK	(*(volatile uint8*)(0x59))

#define TCCR1A	(*(volatile uint8*)(0x4F))
#define TCCR1B	(*(volatile uint8*)(0x4E))
#define TCNT1H	(*(volatile uint8*)(0x4D))
#define TCNT1L	(*(volatile uint8*)(0x4C))
#define	OCR1AH	(*(volatile uint8*)(0x4B))
#define	OCR1AL	(*(volatile uint8*)(0x4A))
#define	OCR1BH	(*(volatile uint8*)(0x49))
#define	OCR1BL	(*(volatile uint8*)(0x48))
#define ICR1H	(*(volatile uint8*)(0x47))
#define ICR1L	(*(volatile uint8*)(0x46))

#define TCCR2	(*(volatile uint8*)(0x45))
#define TCNT2	(*(volatile uint8*)(0x44))
#define OCR2	(*(volatile uint8*)(0x43))

#define ICR1_16Bit_Access	(*(volatile uint16*)(0x46))
#define OCR1A_16bit_Access	(*(volatile uint16*)(0x4A))




/************** UART ***************/
#define UDR		(*((volatile uint8*)0x2C)) 
#define UCSRA	(*((volatile uint8*)0x2B))
#define UCSRB	(*((volatile uint8*)0x2A))
#define	UCSRC	(*((volatile uint8*)0x40))
#define	UBRRH	(*((volatile uint8*)0x40))
#define UBRRL   (*((volatile uint8*)0x29))


/********************* SPI ***********************/
typedef struct 
{
	char SPCR;
	char SPSR;
	char SPDR;
		   
}SPI_REGISTERS;

#define SPI		((volatile SPI_REGISTERS*)(0x2D))




/***************** I2C **************/
#define TWCR   (*((volatile uint8*)0x56))
#define TWDR   (*(volatile uint8*)(0x23))
#define TWAR   (*(volatile uint8*)(0x22))
#define TWSR   (*(volatile uint8*)(0x21))
#define TWBR   (*(volatile uint8*)(0x20))



/************* WDT ****************/
#define WDTCR   (*(volatile uint8*)(0x41))



/*******************************************************************************************************/

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

 
#endif /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: 
 *********************************************************************************************************************/


