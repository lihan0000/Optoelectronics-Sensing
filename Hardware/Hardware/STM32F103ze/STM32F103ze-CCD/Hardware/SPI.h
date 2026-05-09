#include "stm32f10x.h"
#include "stdint.h"
#ifndef SPI_H
#define SPI_H

void SPI_INIT(void);
uint16_t SPI_Send(uint16_t SendDATA);

#endif
