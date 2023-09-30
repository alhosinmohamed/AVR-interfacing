/*****************************************************/
/* Author      : alhosin                             */
/* date        : 22/09/2023                          */
/*****************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define STD_NOK 1
#define STD_OK 0

void Adc_voidInit(void) ;
u8 Adc_u8ReadValueSync(u8 Cpy_u8Channel , u8 *adc_read);
void Adc_voidReadValueAsynch(u8 Cpy_u8Channel , u8 *Cpy_u8digVlue , void (* Cpy_func)(void));

#endif /* EXTI_INTERFACE_H_ */
