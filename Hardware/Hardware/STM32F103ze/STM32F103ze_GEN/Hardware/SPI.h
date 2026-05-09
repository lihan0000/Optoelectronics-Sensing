#include "stm32f10x.h"
#include "stdint.h"

#ifndef SPI_H
#define SPI_H

void SPI3_INIT(void);
void SPI3_Send(uint16_t send);
uint16_t SPI3_Receive(void);
void SPI3_IT(void);
void SPI3_Close(void);
void SPI1_INIT(void);
void SPI1_Send(uint16_t send);
uint16_t SPI1_Receive(void);
void SPI1_IT(void);
void SPI1_Close(void);
void SPI2_INIT(void);
void SPI2_Send(uint16_t send);
uint16_t SPI2_Receive(void);
void SPI2_IT(void);
void SPI2_Close(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void SPI3_IRQHandler(void);

#endif
