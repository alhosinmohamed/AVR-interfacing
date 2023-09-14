/*****************************************************/
/* Author      : alhosin                             */
/* date        : 07/09/2023                          */
/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h" 

#include "Dio_Interface.h"

/* 2 - include module's files */
#include "Dio_Interface.h"
#include "KeyPad_Interface.h"
#include "KeyPad_Cfg.h"



const u8 r_Pins[4]={Row1_Pin,Row2_Pin,Row3_Pin,Row4_Pin};
const u8 c_Pins[4]={Column1_Pin,Column2_Pin,Column3_Pin,Column4_Pin};
const u8 KeyPad_SwitchVal[4][4]=
{
    {'7', '8','9','/'},
    {'4','5','6','*'},
	{'1','2','3','-'},
	{' ','0','=','+'}
};




void KeyPad_voidInit(void)
{
	Dio_voidSetPinDirection(KeyPad_Port,Row1_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Row2_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Row3_Pin,DIO_OUTPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Row4_Pin,DIO_OUTPUT);

	Dio_voidSetPinDirection(KeyPad_Port,Column1_Pin,DIO_INPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Column2_Pin,DIO_INPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Column3_Pin,DIO_INPUT);
	Dio_voidSetPinDirection(KeyPad_Port,Column4_Pin,DIO_INPUT);

	Dio_voidSetPortValue(KeyPad_Port,0xff);
}

u8 KeyPad_u8GetPressedKey(void)
{
	while(1)
	{
        u8 key = 0xff;
        for (u8 r = 0; r < 4; r++)
        {
            Dio_voidSetPinValue(KeyPad_Port, r_Pins[r], DIO_LOW);
            for (u8 c = 0; c < 4; c++)
            {
                if (Dio_u8GetPinValue(KeyPad_Port, c_Pins[c]) == DIO_LOW)
                {
                    key = KeyPad_SwitchVal[r][c];
                    while(Dio_u8GetPinValue(KeyPad_Port,c_Pins[c])==DIO_LOW);
                }
            }
            Dio_voidSetPinValue(KeyPad_Port, r_Pins[r], DIO_HIGH);
            if (key != 0xff) // If a key is pressed, return the key
            {
                return key;
            }
        }
	}
}
