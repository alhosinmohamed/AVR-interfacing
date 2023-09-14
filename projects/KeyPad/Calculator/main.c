#include "STD_TYPES.h"
#include "Bit_Math.h"
#include<util/delay.h>
#include <string.h>

#include "Dio_Interface.h"
#include "Lcd_Interface.h"
#include "KeyPad_Interface.h"

void main()
{
    Lcd_Init();
	KeyPad_voidInit();
	u8 key,opr;
	u32 num1,num2,result;
    while(1)
    {
    	num1=0,num2=0,result=0,key=0;
    	Lcd_voidSendCommand(clear);
    	while(1)
    	{
    		key=KeyPad_u8GetPressedKey();
    		if(key==' ')
    			break;
    		Lcd_voidSendData(key);
    		num1*=10;
    		num1=num1+(key-'0');
    	}
    	opr=KeyPad_u8GetPressedKey();
    	Lcd_voidSendData(opr);
    	key=0;
    	while(1)
    	{
    		key=KeyPad_u8GetPressedKey();
    		if(key==' ')
    			break;
    		Lcd_voidSendData(key);
    		num2*=10;
    		num2=num2+(key-'0');
    	}
    	key=0;
    	Lcd_GoToXY(1,0);
        switch(opr)
    	{
    	case'+':
    		result=num1+num2;
    		Lcd_voidSendData('=');
    		Lcd_VoidWriteNumber(result);
    		key=KeyPad_u8GetPressedKey();
    	break;
    	case'-':
    		result=num1-num2;
    		Lcd_voidSendData('=');
    		Lcd_VoidWriteNumber(result);
    		key=KeyPad_u8GetPressedKey();
    	break;
    	case'/':
    		result=num1/num2;
    		Lcd_voidSendData('=');
    		Lcd_VoidWriteNumber(result);
    		key=KeyPad_u8GetPressedKey();
    	break;
    	case'*':
    		result=num1*num2;
    		Lcd_voidSendData('=');
    		Lcd_VoidWriteNumber(result);
    		key=KeyPad_u8GetPressedKey();
    	break;
    	case'%':
    		result=num1%num2;
    		Lcd_voidSendData('=');
    		Lcd_VoidWriteNumber(result);
    		key=KeyPad_u8GetPressedKey();
    	break;
    	default:
    		Lcd_voidSendCommand(clear);
    		Lcd_VoidWriteString("wrong operator");
    		key=KeyPad_u8GetPressedKey();
    	}
    }
}

