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
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3
#define MCUCSR_ISC2 6
#define GICR_INTO 6
#define GICR_INT1 7
#define GICR_INT2 5
#define INT0 1
#define INT1 2
#define INT2 3
#define NULL '\0'
typedef struct {
	u8 intID ;
	u8 trigger ;
	void (*callback) (void);
}intirrupt_struct;

void EXIT_U8GIE_Statue(u8 U8GIE_Statue);
void EXIT_U8Int0Statue(u8 U8IntStatue);
void EXIT_U8Int1Statue(u8 U8IntStatue);
void EXIT_U8Int2Statue(u8 U8IntStatue);
void EXIT_voidIniInt0(u8 U8InitSate);
void EXIT_voidIniInt1(u8 U8InitSate);
void EXIT_voidIniInt2(u8 U8InitSate);

#endif
