#include"STD_TYPES.h"
#include"Bit_math.h"
#include<util/delay.h>

#include"Dio_Interface.h"
#include "EXIT_Interface.h"

void led1(void);
void led2(void);


int main()
{
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	Dio_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	Dio_voidSetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	Dio_voidSetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	Dio_voidSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	EXTI_struct EXT0={INT0,FALLING_EDGE,led1};
	EXTI_struct EXT1={INT1,FALLING_EDGE,led2};
	EXTI_voidInit(EXT0);
	EXTI_voidInit(EXT1);
	while(1);
}

void led1(void)
{
	static u8  flag=0;
	toggle_Bit(flag,0);
	Dio_voidSetPinValue(DIO_PORTC,DIO_PIN1,flag);
}
void led2(void)
{
	static u8  flag1=0;
	toggle_Bit(flag1,0);
	Dio_voidSetPinValue(DIO_PORTC,DIO_PIN2,flag1);
}


