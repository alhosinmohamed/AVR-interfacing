/*****************************************************/
/* Author      : alhosin                             */
/* date        : 15/09/2023                          */
/*****************************************************/
#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H

#define LOW_LEVEL 1
#define ANY_CHANGE 2
#define FALLING_EDGE 3
#define RISING_EDGE 4
#define INT0 1
#define INT1 2
#define INT2 3
#define NULL '\0'
typedef struct {
	u8 intID ;
	u8 trigger ;
	void (*callback) (void);
}EXTI_struct;

void EXTI_voidInit(EXTI_struct config);
void EXTI_VoidDisable(u8 U8_IntID);

#endif
