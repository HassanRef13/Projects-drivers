/*
 * Temp_Control_main.c
 *
 * Created: 10/26/2023 1:27:40 PM
 *  Author: Hassan
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
#include "ADC_Core.h"
#include "TempSensor_Core.h"


int main(void)
{
	uint8 str1[]="Temp =";
	uint8 Run[]="STATE:";
	uint8 Stable[]="Stable Temp";
	uint8 Heater_ON[]="Heater ON";
	uint8 Fan_ON[]="Fan ON";
	
	uint16 Temp=0;
	PORT_Init();
	LCD_Init();
	TempSensor_init();
	DC_Motor_init();
	
	while (1)
	{
		Temp= TempSensor_Read();
		
		// Keep the temp between 3 and 10 
		// if temp < 10 heater on
		// if temp > 20 cooler on
		//ADC_Vin_Value=0;
		LCD_GoTo(0,2);
		LCD_WriteString(str1);
		LCD_WriteInteger(Temp);
		LCD_WriteChar('C');
		
		
		if ( Temp <=	15)
		{
			// heater on
			DC_Motor2_Stop();
			DC_Motor1(Clockwise, 100);
			LED_SetValue(LED_GREEN, LED_HIGH);
			LCD_GoTo(1,0);
			LCD_WriteString(Run);
			LCD_WriteString(Heater_ON);
		}
		else if (Temp >= 20 )
		{
			// Fan On
			DC_Motor1_Stop();
			DC_Motor2(Clockwise,100);
			LED_SetValue(LED_GREEN, LED_HIGH);
			LCD_GoTo(1,0);
			LCD_WriteString(Run);
			LCD_WriteString(Fan_ON);
		}
		else
		{
			// Stable State
			DC_Motor1_Stop();
			DC_Motor2_Stop();
			LED_SetValue(LED_GREEN, LED_LOW);
			LED_SetValue(LED_RED, LED_HIGH);
			LCD_GoTo(1,0);
			LCD_WriteString(Stable);
			
		}

	}
	
}
