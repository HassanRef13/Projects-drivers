/*
 * Smart_door_main.c
 *
 * Created: 9/27/2023 4:34:28 PM
 *  Author: Hassan
 */ 
/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ali
 */ 


#include "PORT_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "Servo_Core.h"
#include "DC_Motor_Core.h"
#include "IRQH_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "Ultrasonic_Core.h"
#include "BUZZER.h"
#include "Smart_Door.h"

int main(void)
{
	uint8 Input_digit;
	uint8 Str1[]="Password:";
   	Smart_Door_init();
	LCD_WriteString(Str1);
	
    while (1) 
    {
		Input_digit	=	KeyPAD_GetValue()	;
		if (Input_digit !=0		&&	Smart_counter <4)
		{		
			Smart_Door_Inputs(Input_digit);
			
		}
		if ( Smart_counter >=4)
		{
			Smart_Door_Set ();
		}
		if (Input_digit == 'c')
		{
			Smart_Door_Reset();
			LCD_WriteString(Str1);
		}
    }
}

