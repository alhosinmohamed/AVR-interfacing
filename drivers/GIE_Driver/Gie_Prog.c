/*****************************************************/
/* Author      : alhosin                             */
/* date        : 21/09/2023                          */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Driver includes */
#include "GIE_Interface.h"
#include "GIE_Reg.h"
#include "GIE_Cfg.h"

void GIE_voidEnable(void)
{
	set_Bit(SREG , SREG_I);
}

void GIE_voidDisable(void)
{
	clear_Bit(SREG , SREG_I);
}



