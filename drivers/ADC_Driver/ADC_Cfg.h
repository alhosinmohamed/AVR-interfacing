/*****************************************************/
/* Author      : alhosin                             */
/* date        : 22/09/2023                          */
/*****************************************************/

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/* Select ADC ref voltage =>
 * 	ADC_AVCC - ADC_AREF - ADC_2_56*/
#define ADC_REF_VOLT    ADC_AVCC

/* To enable ADC 8 bit mode choose STD_ON
 * Only 8 bit is supported now */
#define ADC_ENABLE_8BIT  STD_ON

/* To enable interrupt choose STD_ON
 * To disable interrupt choose STD_OFF*/
#define ADC_ENABLE_INTERRUPT  STD_ON

/* Choose ADC prescaller  :
 * 			ADC_PRESCALLER_2
			ADC_PRESCALLER_2
			ADC_PRESCALLER_4
			ADC_PRESCALLER_8
			ADC_PRESCALLER_16
			ADC_PRESCALLER_32
			ADC_PRESCALLER_64
			ADC_PRESCALLER_128
 * 			 */
#define ADC_FREQ_PRESCALLER  ADC_PRESCALLER_128

/* Choose ADC timeout */
#define ADC_TIMEOUT 20000


#endif /* EXTI_REG_H_ */
