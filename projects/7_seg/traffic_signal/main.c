#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include"STD_TYPES.h"
#include"Bit_math.h"


int main()
{
	DDRD=255;
	DDRC=255;
	set_Bit(DDRA,0);
	set_Bit(DDRA,1);
	set_Bit(DDRA,2);
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
        PORTD=seg[0],PORTC=seg[1],PORTA=0b00000100;
        _delay_ms(1000);
        PORTC=0b11111111;
    	for (u8 i=9;i>0;i--)
    	{
    		PORTD=seg[i];
    		_delay_ms(1000);
    	}
    	PORTA=0b00000010;
    	for (u8 i=3;i>0;i--)
    	{
    	    PORTD=seg[i];
    	    _delay_ms(1000);
    	}
        PORTD=seg[0],PORTC=seg[1],PORTA=0b00000001;
        _delay_ms(1000);
        PORTC=0b11111111;
    	for (u8 i=9;i>0;i--)
    	{
    		PORTD=seg[i];
    		_delay_ms(1000);
    	}
    }

}



