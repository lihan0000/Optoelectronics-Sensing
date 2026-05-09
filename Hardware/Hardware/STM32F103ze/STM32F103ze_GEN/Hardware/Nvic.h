#include "stm32f10x.h"
#include "stdint.h"
#ifndef Nvic_H
#define Nvic_H

void Nvic_INIT_USART1_2(void);
void Nvic_INIT_ADC1_2(void);
void ADC1_2_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);

#endif

