#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>

#include"Dio_Interface.h"

#include "Lcd_Interface.h"

void main()
{
	Lcd_Init();
    u8 arr1[]="hosin";
    while(1)
    {
    	for(u8 y=0;y<16;y+=2)
    	{
    	    Lcd_GoToXY(0,y);
    	    Lcd_VoidWriteString(arr1);
    	    _delay_ms(500);
    	    Lcd_VoidClear();
    	    Lcd_GoToXY(1,y+1);
    	    Lcd_VoidWriteString(arr1);
    	    _delay_ms(500);
    	    Lcd_VoidClear();
    	}
    }
}




