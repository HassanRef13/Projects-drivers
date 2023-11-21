/*
 * Calculator_main.c
 *
 * Created: 8/30/2023 10:52:40 AM
 *  Author: Hassan
 */ 
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "DC_Motor_Core.h"
#include "SPI_Core.h"
#include "UART_Core.h"
#include "DIO_Core.h"
#include "IRQH_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


#define QUEUE_LENGTH 10
#define ITEM_SIZE	sizeof (uint8)

QueueHandle_t xQUEUE = NULL;
QueueHandle_t xQUEUE2 = NULL;

TaskHandle_t Task_1_Hnadle= NULL;
TaskHandle_t Task_2_Hnadle= NULL;
TaskHandle_t Task_3_Hnadle= NULL;
TaskHandle_t Task_4_Hnadle= NULL;
  
  
  
void Task_1 (void* p) 
{
	/************ Master *********/
	while (1)
	{
		PORT_Init();
		LCD_Init();
		DC_Motor_init();
		SPI_Init();

		xQUEUE	= xQueueCreate(QUEUE_LENGTH , ITEM_SIZE );
 		xQUEUE2	= xQueueCreate(QUEUE_LENGTH , ITEM_SIZE );
		vTaskSuspend( Task_1_Hnadle );
	}
}

void Task_2 (void* p)
{
	/******** Slave 1 ************/
	
	uint8 Distance_REC=0;
	
	while (1)
	{
		 /******** Slave 1 ************/
  		DIO_WriteChannel(PORTB_PIN0 , PIN_HIGH); // slave 2 off
 		DIO_WriteChannel(PORTB_PIN4 , PIN_LOW);// slave 1 send 
		 
 		Distance_REC = SPI_TranSiever (13);
		 Distance_REC/=2;
		 LCD_WriteString("Distance= ");
		 LCD_WriteInteger(Distance_REC);
		 LCD_WriteString(" Cm");
		 _delay_ms(50);
		 LCD_WriteClear();
 		xQueueSend(xQUEUE,( void *) &Distance_REC, ( TickType_t ) 10);		
		
		vTaskDelay( 250 );

	}
}

 void Task_3 (void* p)
 {
	 /*********** Slave 2 ***********/
 	uint8 Rec_state	=	0;
 	
 	while (1)
 	{
		  	DIO_WriteChannel(PORTB_PIN4 , PIN_HIGH);// slave 1 off
			 DIO_WriteChannel(PORTB_PIN0 , PIN_LOW);// slave 2 send
			 Rec_state = SPI_TranSiever(1);
			 Rec_state/=2;
			 switch (Rec_state)
			 {
				 case 10:
					LCD_WriteString("State: Parking");
					_delay_ms(50);
					LCD_WriteClear();
					break;
				 case 20:
					LCD_WriteString("State: Direct");
					_delay_ms(50);
					LCD_WriteClear();
					break;
				case 30:
					LCD_WriteString("State: Reverse");
					_delay_ms(50);
					LCD_WriteClear();
					break;
				default:
					break;
			 }
//  			LCD_WriteString("State: ");
//  			LCD_WriteClear();		  
 			xQueueSend(xQUEUE2,( void *) &Rec_state, ( TickType_t ) 10);
			

 		vTaskDelay( 200 );
 
 	}
 }

void Task_4 (void* p)
{
	uint8 Rec_Distance =0;
	uint8 Rec_State =0;
	
	while (1)
	{
		xQueueReceive (xQUEUE , &Rec_Distance  , 50);
 		xQueueReceive (xQUEUE2 , &Rec_State  , 50);
		 
 		if (Rec_State == 10)
 		{
 			DC_Motor1_Stop();
 			DC_Motor2_Stop();
 		}
		 if (Rec_State == 20)
		{
			if (Rec_Distance < 20)
			{
				LCD_WriteClear();
				LCD_WriteString("Force Stop");
				_delay_ms(50);
				LCD_WriteClear();
				
				DC_Motor1_Stop();
				DC_Motor2_Stop();

			}
			else
			{
				DC_Motor1(Clockwise, 100);
				DC_Motor2(Clockwise,100);
			}
			
		}
		if (Rec_State == 30)
		{
			if (Rec_Distance < 20)
			{
				LCD_WriteClear();
				LCD_WriteString("Force Stop");
				_delay_ms(50);
				LCD_WriteClear();
				
				DC_Motor1_Stop();
				DC_Motor2_Stop();

			}
			else
			{
				DC_Motor1(Anticlockwise, 100);
				DC_Motor2(Anticlockwise,100);
				
			}
		}
		vTaskDelay( 150 );

	}
}



int main(void)
{
	  xTaskCreate( Task_1,
				  "Init_Task",
				  100,
				  NULL,
				  9,
				  &Task_1_Hnadle
	  );

	 xTaskCreate(Task_2,
				 "Slave1",
				 200,
				 NULL,
				 6,
				 &Task_2_Hnadle
	 );

 	 xTaskCreate(Task_3,
 				"Slave2",
 				 200,
 				 NULL,
 				 7,
 				 &Task_3_Hnadle
 	 );
	xTaskCreate(Task_4,
				"Display",
				100,
				NULL,
				8,
				&Task_4_Hnadle
	);
	
	 // Start scheduler
	 vTaskStartScheduler();
	 
	 
    while (1) 
    {
		
		
		
	}
	
}

 