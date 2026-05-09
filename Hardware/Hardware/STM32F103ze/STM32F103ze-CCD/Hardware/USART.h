#include "stdint.h"
#ifndef USART_H
#define USART_H

void USART1_INIT(void);//USART1
void USART1_Send(uint16_t Send_Data);
uint16_t USART1_Receive(void);
void USART2_INIT(void);//USART2
void USART2_Send(uint16_t Send_Data);
uint16_t USART2_Receive(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendString(char *String);
#endif
