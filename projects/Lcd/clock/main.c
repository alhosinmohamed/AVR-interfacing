#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>

#include"Dio_Interface.h"

#include "Lcd_Interface.h"


void main()
{
	Lcd_Init();
    while(1)
    {
    	Lcd_voidSendCommand(clear);
    	Lcd_VoidWriteString("Hours :Mins :Sec");
    	u8 h,m,s;
    	for(h=0;h<60;h++)
    	{
        	for(m=0;m<60;m++)
        	{
            	for(s=0;s<60;s++)
            	{
            		Lcd_GoToXY(1,0);
            		Lcd_VoidWriteNumber(h);
            		Lcd_GoToXY(1,7);
            		Lcd_VoidWriteNumber(m);
            		Lcd_GoToXY(1,13);
            		Lcd_VoidWriteNumber(s);
            		_delay_ms(1000);
            	}
            	Lcd_voidSendCommand(clear);
            	Lcd_VoidWriteString("Hours :Mins :Sec");
        	}
        	Lcd_voidSendCommand(clear);
        	Lcd_VoidWriteString("Hours :Mins :Sec");
    	}
    }
}