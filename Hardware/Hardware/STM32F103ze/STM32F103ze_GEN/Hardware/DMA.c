#include "stm32f10x.h"
#include "stdint.h"

void DMA_INIT_ADC2(uint32_t Addr_ROM,uint32_t BufferSize)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC2->DR;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = Addr_ROM;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = BufferSize;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TE,DISABLE);
}

void DMA_INIT_ADC1(uint32_t Addr_ROM,uint32_t BufferSize)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = Addr_ROM;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = BufferSize;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TE,DISABLE);
}

void DMA_INIT_USART1(uint32_t Addr_ROM)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_DeInit(DMA1_Channel2);
	
	DMA_InitTypeDef DMA_InitStructure_USART1;
	DMA_InitStructure_USART1.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
	DMA_InitStructure_USART1.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure_USART1.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure_USART1.DMA_MemoryBaseAddr = Addr_ROM;
	DMA_InitStructure_USART1.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure_USART1.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_InitStructure_USART1.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure_USART1.DMA_BufferSize = 3695;
	DMA_InitStructure_USART1.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure_USART1.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure_USART1.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel2, &DMA_InitStructure_USART1);
	
	DMA_Cmd(DMA1_Channel2,ENABLE);	
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);

	DMA_ITConfig(DMA1_Channel2,DMA_IT_TE,DISABLE);
	DMA_ITConfig(DMA1_Channel2,DMA_IT_TC,DISABLE);
}

void DMA_INIT_USART2(uint32_t Addr_ROM)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure_USART2;
	DMA_InitStructure_USART2.DMA_PeripheralBaseAddr = (uint32_t)&USART2->DR;
	DMA_InitStructure_USART2.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure_USART2.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure_USART2.DMA_MemoryBaseAddr = Addr_ROM;
	DMA_InitStructure_USART2.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure_USART2.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure_USART2.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure_USART2.DMA_BufferSize = 1;
	DMA_InitStructure_USART2.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure_USART2.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure_USART2.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel3, &DMA_InitStructure_USART2);
	
	DMA_Cmd(DMA1_Channel3,ENABLE);
  USART_DMACmd(USART2,USART_DMAReq_Rx,ENABLE);
	
	DMA_ITConfig(DMA1_Channel2,DMA_IT_TE,DISABLE);
	DMA_ITConfig(DMA1_Channel2,DMA_IT_TC,DISABLE);
}


