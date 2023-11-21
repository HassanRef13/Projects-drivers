
 * Remote_Smart_Door.c
 *
 * Created: 10/3/2023 12:20:36 PM
 *  Author: Hassan
  


 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Hassan
 
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "IRQH_Core.h"
#include "DIO_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "UART_Core.h"
#include "Smart_Door.h"
#include "Servo_Core.h"
#include "PWM_Core.h"


int main (void)
{
	uint8 Rec_Status_main_l = 0 , i = 0;
	Smart_Door_init();
	UART_Init();

	uint8 Str1[]="Password:";

	
	IRQH_SetGlobalINT(INT_ENABLE);
	IRQH_Set_callback (USART_Rx_Complete_VECTOR_INDEX, UART_ReceiveData);

	LCD_WriteString(Str1);
	while (1)
	{
		Rec_Status_main_l = UART_ReceiveStatus();
		
		if (Rec_Status_main_l == 1)
		{	
			
			if (UART_RECIEVED_DATA[Smart_counter] !=0	&& Smart_counter <4)
			{
				Smart_Door_Inputs(UART_RECIEVED_DATA[Smart_counter]);
								
			}
			
			if ( Smart_counter ==4)
			{
				Smart_Door_Set ();
				Smart_counter=0;
				
			}
			

		}
	}
}
