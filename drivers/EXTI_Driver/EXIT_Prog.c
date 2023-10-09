/*****************************************************/
/* Author      : alhosin                             */
/* date        : 15/09/2023                          */
/*****************************************************/
/* 1 - include libraries */
#include "STD_TYPES.h"
#include "Bit_Math.h" 

/* 2 - include module's files */
#include "EXIT_Interface.h"
#include "EXIT_Private.h"
#include "EXIT_Reg.h"


void (*CallBackInt0) (void);
void (*CallBackInt1) (void);
void (*CallBackInt2) (void);

void EXTI_voidInit(EXTI_struct config)
{
	set_Bit(SREG,7);
	switch(config.intID)
	{
	case INT0:
		set_Bit(GICR,GICR_INTO);
		switch(config.trigger)
		{
		    case LOW_LEVEL:
			    clear_Bit(MCUCR,MCUCR_ISC01);
			    clear_Bit(MCUCR,MCUCR_ISC00);
			    break;
		    case ANY_CHANGE:
			    clear_Bit(MCUCR,MCUCR_ISC01);
			    set_Bit(MCUCR,MCUCR_ISC00);
			    break;
		    case FALLING_EDGE:
			    set_Bit(MCUCR,MCUCR_ISC01);
		    	clear_Bit(MCUCR,MCUCR_ISC00);
		    	break;
		    case RISING_EDGE:
			    set_Bit(MCUCR,MCUCR_ISC01);
			    set_Bit(MCUCR,MCUCR_ISC00);
			    break;
		}
		CallBackInt0=config.callback;
		break;
	case INT1:
		set_Bit(GICR,GICR_INT1);
		switch(config.trigger)
		{
		    case LOW_LEVEL:
			    clear_Bit(MCUCR,MCUCR_ISC11);
			    clear_Bit(MCUCR,MCUCR_ISC10);
			    break;
		    case ANY_CHANGE:
			    clear_Bit(MCUCR,MCUCR_ISC11);
			    set_Bit(MCUCR,MCUCR_ISC10);
			    break;
		    case FALLING_EDGE:
			    set_Bit(MCUCR,MCUCR_ISC11);
		    	clear_Bit(MCUCR,MCUCR_ISC10);
		    	break;
		    case RISING_EDGE:
			    set_Bit(MCUCR,MCUCR_ISC10);
			    set_Bit(MCUCR,MCUCR_ISC11);
			    break;
		}
		CallBackInt1=config.callback;
		break;
	case INT2:
		set_Bit(GICR,GICR_INT2);
		switch(config.trigger)
		{
		    case FALLING_EDGE :
		    	clear_Bit(MCUCSR,MCUCSR_ISC2);
		    	break;
		    case RISING_EDGE :
		    	set_Bit(MCUCSR,MCUCSR_ISC2);
		    	break;
		}
		CallBackInt2=config.callback;
		break;
	}
}

void EXTI_VoidDisable(u8 U8_IntID)
{
	switch(U8_IntID)
	{
    case INT0:
    	clear_Bit(GICR,GICR_INTO);
	    break;
    case INT1:
    	clear_Bit(GICR,GICR_INT1);
	    break;
    case INT2:
    	clear_Bit(GICR,GICR_INT2);
    	break;

	}
}




void __vector_1(void) __attribute__((signal)) ;
void __vector_1 (void)
{
	if (CallBackInt0!=NULL)
	{
		CallBackInt0();
	}
}


void __vector_2(void) __attribute__((signal)) ;
void __vector_2 (void)
{
	if (CallBackInt1!=NULL)
	{
		CallBackInt1();
	}
}


void __vector_3(void) __attribute__((signal)) ;
void __vector_3 (void)
{
	if (CallBackInt2!=NULL)
	{
		CallBackInt2();
	}
}






