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
	DDRA=255;
    u8 seg[10]=
    {
    	    0b01000000, // 0
    	    0b01111001, // 1
    	    0b00100100, // 2
    	    0b00110000, // 3
    	    0b00011001, // 4
    	    0b00010010, // 5
    	    0b00000010, // 6
    	    0b01111000, // 7
    	    0b00000000, // 8
    	    0b00010000  // 9
    };
	while(1)
	{
		if(PINC==0b11111110)
		{
			PORTA=0b00000001;
			PORTD=seg[0];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else if(PINC==0b11111101)
		{
			PORTA=0b00000001;
			PORTD=seg[1];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else if(PINC==0b11111011)
		{
			PORTA=0b00000001;
			PORTD=seg[2];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else if(PINC==0b11110111)
		{
			PORTA=0b00000001;
			PORTD=seg[3];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);

		}
		else if(PINC==0b11101111)
		{
			PORTA=0b00000001;
			PORTD=seg[4];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else if(PINC==0b11011111)
		{
			PORTA=0b00000001;
			PORTD=seg[5];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);

		}
		else if(PINC==0b10111111)
		{
			PORTA=0b00000001;
			PORTD=seg[6];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else if(PINC==0b01111111)
		{
			PORTA=0b00000001;
			PORTD=seg[7];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[1];
			_delay_ms(5);
		}
		else
		{
			PORTA=0b00000001;
			PORTD=seg[0];
			_delay_ms(5);
			PORTA=0b00000010;
			PORTD=seg[0];
			_delay_ms(5);
		}

	}
}

