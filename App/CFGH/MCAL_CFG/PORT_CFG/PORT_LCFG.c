/*
 * Port_Lcfg_Study.c
 *
 * Created: 8/20/2023 11:30:37 AM
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
#include "PORT_LCFG.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const PIN_PARAMETERS PORT_Initialization[DEFINED_PINS] =
{
		/* LED Pin Output */
			// LED Red 
	{	PORTC_PIN0	,	PIN_OUTPUT	},
			// LED Green
	{	PORTC_PIN1	,	PIN_OUTPUT	},

			/* LED blue */
	/*{	PORTC_PIN2	,	PIN_OUTPUT	}, */
		
		//Push Button pin input 	
	/*{	PORTD_PIN2	,	PIN_INPUT	},
	{	PORTD_PIN3	,	PIN_INPUT	},
	{	PORTD_PIN4	,	PIN_INPUT	},
	{	PORTD_PIN5	,	PIN_INPUT	},
	{	PORTB_PIN4	,	PIN_INPUT	},*/

		
			/* Buzzer*/
	/*{	PORTC_PIN5  ,	PIN_OUTPUT	},*/
		
		/* 7Seg initialization */
		
	/*{	PORTC_PIN6  ,	PIN_OUTPUT	},
	{	PORTC_PIN7  ,	PIN_OUTPUT	},*/
		
// 		Port A initialization for LCD 
	{	PORTA_PIN1 ,	PIN_OUTPUT	},
	{	PORTA_PIN2 ,	PIN_OUTPUT	},
	{	PORTA_PIN3 ,	PIN_OUTPUT	},
	{	PORTA_PIN4 ,	PIN_OUTPUT	},
	{	PORTA_PIN5 ,	PIN_OUTPUT	},
	{	PORTA_PIN6 ,	PIN_OUTPUT	},
		
		
	// 		Port A initialization for 7seg
	/*{	PORTA_PIN0 ,	PIN_OUTPUT	},
	{	PORTA_PIN1 ,	PIN_OUTPUT	},
	{	PORTA_PIN2 ,	PIN_OUTPUT	},
	{	PORTA_PIN3 ,	PIN_OUTPUT	},
	{	PORTA_PIN4 ,	PIN_OUTPUT	},
	{	PORTA_PIN5 ,	PIN_OUTPUT	},
	{	PORTA_PIN6 ,	PIN_OUTPUT	},*/
	

			/*	KeyPad	*/
	{	PORTB_PIN4 ,	PIN_OUTPUT	},
	{	PORTB_PIN5 ,	PIN_OUTPUT	},
	{	PORTB_PIN6 ,	PIN_OUTPUT	},
	{	PORTB_PIN7 ,	PIN_OUTPUT	},
		
	{	PORTD_PIN2 ,	PIN_INPUT	},
	{	PORTD_PIN3 ,	PIN_INPUT	},
	{	PORTD_PIN4 ,	PIN_INPUT	},
	/*{	PORTD_PIN5 ,	PIN_INPUT	},*/
		
	/********** PWm pin *************/
		/**** Timer0 ***/
	/*{	PORTB_PIN3 , PIN_OUTPUT		},*/
		/*** Timer 2***/
	/*{	PORTD_PIN7 , PIN_OUTPUT		},*/
		
		
		/******* relay***********/
	/*{	PORTC_PIN4 , PIN_OUTPUT		},*/
		
		/******** Servo pin *******/
	{	PORTD_PIN5 , PIN_OUTPUT		},
	
	/********* L298N**********/
		/*** Motor 1 ***/
	/*{	PORTC_PIN4  ,	PIN_OUTPUT	},
	{	PORTC_PIN5  ,	PIN_OUTPUT	},
*/
		/**	 Motor 2 ***/
	/*{	PORTC_PIN6  ,	PIN_OUTPUT	},
	{	PORTC_PIN7  ,	PIN_OUTPUT	},*/
		
		
	/************* LM35 Temp sensor **********/
	/*{	PORTA_PIN7  ,	PIN_INPUT	},*/

		
	/***********ICU ULtrasonic*******/
			/*** echo *****/
	/*{	PORTD_PIN6  ,	PIN_INPUT	}*/
			/*** trigger ****/
	/*{	PORTC_PIN6  ,	PIN_OUTPUT	},*/
		

		/******* UART *********/

	/*{	PORTD_PIN0  ,	PIN_INPUT	},
	{	PORTD_PIN1  ,	PIN_OUTPUT	},
*/
		
		/******** SPI **********/
		/**** Master ***/
	/*{	PORTB_PIN4, PIN_OUTPUT		}, // CS
	{	PORTB_PIN5, PIN_OUTPUT		}, //MOSI
	{	PORTB_PIN6, PIN_INPUT		}, //MISO
	{	PORTB_PIN7, PIN_OUTPUT		}, //CLK*/
			/*** Slave ****/
	/*{	PORTB_PIN4, PIN_INPUT		}, // CS
	{	PORTB_PIN5, PIN_INPUT		}, //MOSI
	{	PORTB_PIN6, PIN_OUTPUT		}, //MISO
	{	PORTB_PIN7, PIN_INPUT		}, //CLK*/
		
		/* I2c */
	/*{	PORTC_PIN0, PIN_OUTPUT		}, 
	{	PORTC_PIN1, PIN_OUTPUT		}, */

		
		/* Stepper motor */
	/*{	PORTB_PIN0, PIN_OUTPUT		},
	{	PORTB_PIN1, PIN_OUTPUT		},
	{	PORTB_PIN2, PIN_OUTPUT		},
	{	PORTB_PIN3, PIN_OUTPUT		}*/
		
	
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

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
