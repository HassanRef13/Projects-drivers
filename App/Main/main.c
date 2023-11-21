/*
 * Calculator_main.c
 *
 * Created: 8/30/2023 10:52:40 AM
 *  Author: Hassan
 */ 
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>


int main(void)
{

	sint32 answer =0 , temp=0;
	extern sint32 arr[16];
	extern sint8 Counter;
	uint8 i=0 , j=0;
	
	uint8 Val=0;
	
	PORT_Init();
	
	LCD_Init();
	
	KEYPAD_init();
	
	while (1)
	{
		Val=KeyPAD_GetValue();
		if(Val !=0)
		{
			
			if (Val < 59	 &&		Val >47 )
			{
				
				temp = temp * 10 + (Val -48);
				LCD_WriteChar(Val);
				arr[Counter]= temp;
			}
			else if (Val == plus || Val == minus || Val == multiply || Val == devided)
			{
				LCD_WriteChar(Val);
				Counter++;
				arr[Counter]=Val;
				temp=0;
				Counter++;
			}
			else if (Val == 'c')
			{
				
				for (i=0 ; i<16 ; i++)
				{
					arr[i] =0;
				}
				Counter=0;
				i=0;
				j=0;
				temp=0;
				LCD_WriteClear();
				LCD_GoTo(0,0);
				answer=0;
			}
			else if (Val ==61)
			{
				

				for ( i =0 ; i < Counter +1 ; i++)
				{
					if (arr[i] == multiply)
					{
						arr[i-1] = arr[i-1] * arr [ i+1];

						for ( j = i ; j < Counter+1 ; j+=2)
						{
							arr[j] = arr[j+2];
							arr[j+1]=arr[j+3];
						}
						Counter-=2;
						i=0;
					}
					if (arr[i] == devided)
					{
						arr[i-1] = (arr[i-1] / arr [ i+1]);

						for ( j = i ; j < Counter+1 ; j+=2)
						{
							arr[j] = arr[j+2];
							arr[j+1]=arr[j+3];
						}
						Counter-=2;
						i=0;
					}
				}

				for ( i =0 ; i < Counter +1 ; i++)
				{
					if (arr[i] == plus)
					{
						arr[i-1] = arr[i-1] + arr [ i+1];

						for ( j = i ; j < Counter+1 ; j+=2)
						{
							arr[j] = arr[j+2];
							arr[j+1]=arr[j+3];
						}
						Counter-=2;
						i=0;
					}
					if (arr[i] == minus)
					{
						arr[i-1] = arr[i-1] - arr [ i+1];

						for ( j = i ; j < Counter+1 ; j+=2)
						{
							arr[j] = arr[j+2];
							arr[j+1]=arr[j+3];
						}
						Counter-=2;
						i=0;
					}
				}
				
				
				for (i = 0 ; i <Counter+1 ; i++)
				{
					answer= answer + arr[i];
					temp =answer;
				}
				
				LCD_WriteClear();
				LCD_GoTo(1,0);
				LCD_WriteChar('=');
				
				LCD_WriteInteger(answer);
				
			}
		}
		Val =0;
	}
}

 