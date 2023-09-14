#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include"STD_TYPES.h"
#include"Bit_math.h"
int main()
{
	DDRD=255;
	DDRC=255;
	u8 i=0,y=0;
	clear_Bit(DDRA,0);
	set_Bit(PORTA,0);

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
		u8 x=get_Bit(PINA,0);
		if(x==0)
		{
			i++;
		}
        if(i==10)
        {
        	i=0;
        	y++;
        }
        if(y==10)
        {
        	i=0;
        	y=0;
        }
        PORTD=seg[y];
        PORTC=seg[i];
		_delay_ms(400);

    }

}


