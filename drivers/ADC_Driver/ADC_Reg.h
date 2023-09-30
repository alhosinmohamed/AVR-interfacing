/*****************************************************/
/* Author      : alhosin                             */
/* date        : 22/09/2023                          */
/*****************************************************/

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX    (*((volatile u8 *)0X27 ))
/* Bits */
#define ADMUX_REFS1  7
#define ADMUX_REFS0  6
#define ADMUX_ADLAR  5

#define ADCSRA   (*((volatile u8 *)0X26 ))
/* Bits */
#define  ADCSRA_ADEN    7
#define  ADCSRA_ADSC    6
#define  ADCSRA_ADATE   5
#define  ADCSRA_ADIF    4
#define  ADCSRA_ADIE    3
#define  ADCSRA_ADPS2   2
#define  ADCSRA_ADPS1   1
#define  ADCSRA_ADPS0   0

#define ADCH     (*((volatile u8 *)0X25 ))
#define ADCL     (*((volatile u8 *)0X24 ))


#endif /* EXTI_REG_H_ */
