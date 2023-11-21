/*
 * Calculator_main.c
 *
 * Created: 8/30/2023 10:52:40 AM
 *  Author: Hassan
 */ 
#include "PORT_Core.h"
#include "LCD_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "Multi_Agent.h"
#include "Timer_Core.h"

extern uint8 Flag;

int main(void)
{	
	/************ Slave 2 ***********/
	uint8 Rec=0 ;
	PORT_Init();
	SPI_Init();
	LCD_Init();


    while (1) 
    {		
		Rec = SPI_TranSiever(Flag);
		_delay_ms(100);
		
		LCD_WriteInteger(Flag);
		
		Button0 = BTN_GetValue (Button_0);
		if (Button0 == 0)
		{
			Flag = 10;				
		}
		
		Button1 = BTN_GetValue (Button_1);

		if (Button1 == 0)
		{
			Flag = 20;				
		}
		
		Button2 = BTN_GetValue (Button_2);

		if (Button2 == 0)
		{
			Flag = 30;
		}
		
		
 		if (	(Flag == 5 )	||	(Flag == 10)	)
 		{
 			SevSeg_Display(Seven_Segment_Values_g[0]);
 		}
 		else if (Flag == 20 )
 		{
 			SevSeg_Display(Seven_Segment_Values_g[1]);
 		}
		else if (Flag == 30 )
		{
			SevSeg_Display(Seven_Segment_Values_g[2]);
		} 

	}
		
   
	
}

 