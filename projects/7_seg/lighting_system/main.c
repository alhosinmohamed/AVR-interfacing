#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include"STD_TYPES.h"
#include"Bit_math.h"


int main()
{
	DDRD=255;
	DDRC=0;
	PORTC=0b11111111;
	u8 led[10]={
		0b00000000,//0
		0b00000001,//1
		0b00000010,//2
		0b00000100,//3
		0b00001000,//4
		0b00010000,//5
		0b00100000,//6
		0b01000000,//7
		0b10000000 //8
	};
	while(1)
	{
		if(PINC==0b11111110)
		{
			PORTD=0b11111111;
			_delay_ms(300);
			PORTD=0b00000000;
			_delay_ms(300);
		}
		else if(PINC==0b11111101)
		{
			for(u8 i=1;i<9;i++)
			{
				PORTD=led[i];
				_delay_ms(250);
			}
		}
		else if(PINC==0b11111011)
		{
			for(u8 i=8;i>0;i--)
			{
				PORTD=led[i];
				_delay_ms(250);
			}
		}
		else if(PINC==0b11110111)
		{
			for(u8 i=8,y=1;i>4&&y<5;i--,y++)
			{
				PORTD=led[i]|led[y];
				_delay_ms(300);
			}
		}
		else if(PINC==0b11101111)
		{
			for(u8 i=4,y=5;i>0&&y<9;i--,y++)
			{
				PORTD=led[i]|led[y];
				_delay_ms(300);
			}
		}
		else if(PINC==0b11011111)
		{
			for(u8 i=8,y=1;i>4&&y<5;i--,y++)
			{
				PORTD=led[i];
				_delay_ms(250);
				PORTD=led[y];
				_delay_ms(250);
			}
		}
		else if(PINC==0b10111111)
		{
			for(u8 i=0;i<8;i++)
			{
				set_Bit(PORTD,i);
				_delay_ms(250);
			}
			PORTD=led[0];
		}
		else if(PINC==0b01111111)
		{
			PORTD=0b11000011;
			_delay_ms(300);
			PORTD=0b00111100;
			_delay_ms(300);
		}
		else
		{
			PORTD=led[0];
		}

	}
}



