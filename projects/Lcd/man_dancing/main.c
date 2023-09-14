#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>

#include"Dio_Interface.h"

#include "Lcd_Interface.h"


void main()
{
	Lcd_Init();
    u8 arr1[]={0b00000100,
    		   0b00000101,
			   0b00011111,
			   0b00010100,
			   0b00000100,
			   0b00001010,
			   0b00010001,
			   0b00010001};
    u8 arr2[]={0b00000100,
    		   0b00010100,
			   0b00011111,
			   0b00000101,
			   0b00000100,
			   0b00001010,
			   0b00010001,
	 		   0b00010001};
    Lcd_voidAddNewPattern(0,arr1);
    Lcd_voidAddNewPattern(1,arr2);
    while(1)
    {


    		Lcd_voidShowNewPattern(0,0,7);
    		_delay_ms(200);
			Lcd_voidSendCommand(clear);
            Lcd_voidShowNewPattern(1,0,7);
	    	_delay_ms(200);
			Lcd_voidSendCommand(clear);
    }
};