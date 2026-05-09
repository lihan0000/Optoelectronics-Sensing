#include "stm32f10x.h"
#include "stdint.h"
#ifndef DMA_H
#define DMA_H

void DMA_INIT_ADC2(uint32_t Addr_ROM,uint32_t BufferSize); //ADC2_DMA
void DMA_INIT_ADC1(uint32_t Addr_ROM,uint32_t BufferSize); //ADC1_DMA
void DMA_INIT_USART1(uint32_t Addr_ROM); //USART1_DMA
void DMA_INIT_USART2(uint32_t Addr_ROM); //USART2_DMA

#endif

