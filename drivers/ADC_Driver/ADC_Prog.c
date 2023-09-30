/*****************************************************/
/* Author      : alhosin                             */
/* date        : 22/09/2023                          */
/*****************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"


#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"
#include "ADC_Reg.h"

void (*global_CallbackFunc)(void);
u8 * global_u8PtrDigVal;

void Adc_voidInit(void)
{
	/* Select max volt */
#if ADC_REF_VOLT == ADC_AVCC
	clear_Bit(ADMUX , ADMUX_REFS1);
	set_Bit(ADMUX , ADMUX_REFS0);
#elif ADC_REF_VOLT == ADC_AREF
	clear_Bit(ADMUX , ADMUX_REFS1);
	clear_Bit(ADMUX , ADMUX_REFS0);
#elif ADC_REF_VOLT == ADC_2_56
	set_Bit(ADMUX , ADMUX_REFS1);
	set_Bit(ADMUX , ADMUX_REFS0);
#else
	#error ("wrong configuration !!")
#endif

	/* To work with 8 bit mode */
#if ADC_ENABLE_8BIT == STD_ON
	set_Bit(ADMUX , ADMUX_ADLAR);
#else
	#error ("wrong configuration !!")
#endif

	/* Enable the ADC */
	set_Bit(ADCSRA , ADCSRA_ADEN);

	/* Select frequency prescaller */
	ADCSRA &= 0b11111000; // clear the firts 3 bits
	ADCSRA |= ADC_FREQ_PRESCALLER ; // write prescaller option

	/* Enable or disable interrupt */
#if ADC_ENABLE_INTERRUPT == STD_ON
	set_Bit(ADCSRA,ADCSRA_ADIE);
#elif ADC_ENABLE_INTERRUPT == STD_OFF
	clear_Bit(ADCSRA,ADCSRA_ADIE);
#else
	#error ("wrong configuration !!")
#endif
}


u8 Adc_u8ReadValueSync(u8 Cpy_u8Channel , u8 *adc_read)
{
	u32 local_u32Timeout = 0 ;
	u8  local_u8stdError = STD_NOK ;

	/* Select channel */
	ADMUX &= 0B11100000 ; // clear the firts 5 bits
	ADMUX |= Cpy_u8Channel ; // write channel number

	/* Start conversion */
	set_Bit(ADCSRA , ADCSRA_ADSC);

	/* Wait till conversion is done
	 * and check for timeout to get out if
	 * ADC is stuck */
	while((get_Bit(ADCSRA , ADCSRA_ADIF) == 0)
			&& (local_u32Timeout<ADC_TIMEOUT) ){
		local_u32Timeout++;
	}
	if (local_u32Timeout < ADC_TIMEOUT){
		local_u8stdError = STD_OK ; // ADC did read the value
		// return the digital value to the user in pointer
		*adc_read = ADCH ;
	}
	return local_u8stdError;
}


void Adc_voidReadValueAsynch(u8 Cpy_u8Channel , u8 *Cpy_u8digVlue , void (* Cpy_func)(void))
{
	/* Select channel */
	ADMUX &= 0B11100000 ;
	ADMUX |= Cpy_u8Channel ;

	/* Set ISR call back and digital value*/
	global_CallbackFunc = Cpy_func ;
	global_u8PtrDigVal =Cpy_u8digVlue;

	/* Start conversion */
	set_Bit(ADCSRA , ADCSRA_ADSC);
}

/* ISR  for ADC */
void __vector_16 (void) __attribute__((signal)) ;
void __vector_16 (void)
{
	if ((global_u8PtrDigVal != NULL )&&
		(global_CallbackFunc != NULL ))
	{
		*global_u8PtrDigVal = ADCH ;
		global_CallbackFunc();
	}
}

