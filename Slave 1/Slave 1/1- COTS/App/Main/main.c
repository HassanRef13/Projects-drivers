/*
 * Calculator_main.c
 *
 * Created: 8/30/2023 10:52:40 AM
 *  Author: Hassan
 */ 
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "DC_Motor_Core.h"
#include "IRQH_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "SPI_Core.h"
#include "Ultrasonic_Core.h"
#include "ICU_Core.h"


int main(void)
{
	
	/*************** Slave 1 ***************/
	uint16 distance = 0 ;
	uint16 Rec = 0 ;
	PORT_Init();
	SPI_Init();
	LCD_Init();
	GPT_Init();	 
	IRQH_SetGlobalINT(INT_ENABLE);
	Ultrasonic_Init();
	Ultrasonic_Trigger();
	
	
    while (1) 
    {
		distance = Ultrasonic_Get_Distance();
		
		if(distance > 0)
		{
			Rec = SPI_TranSiever(distance);
			LCD_WriteInteger(distance);
			LCD_WriteString(" Cm");
			_delay_ms(50);
			LCD_WriteClear();
			

			Ultrasonic_Trigger();
			distance = 0;
		}
		
	}
	
}

 