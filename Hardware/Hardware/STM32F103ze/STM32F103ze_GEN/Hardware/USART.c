#include "stm32f10x.h"
#include "stdint.h"

void USART1_INIT(void)//USART1
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureT;
	GPIO_InitStructureT.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureT.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStructureT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureT);
	
	GPIO_InitTypeDef GPIO_InitStructureR;
	GPIO_InitStructureR.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructureR.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructureR.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureR);
	
	
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate=115200;
	USART_InitStructure.USART_HardwareFlowControl=ENABLE;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
	USART_ITConfig(USART1,USART_IT_ERR,DISABLE);
}

void USART1_Send(uint16_t Send_Data)
{
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==SET);
	USART_SendData(USART1,Send_Data);
}


uint16_t USART1_Receive(void)
{
	while (USART_GetFlagStatus(USART1,USART_FLAG_RXNE)!=SET);
	uint16_t Receive_Data;
	Receive_Data=USART_ReceiveData(USART1);
	return Receive_Data;
}

void USART1H_IRQHandler(void)
{
	
}

void USART2_INIT(void)//USART2
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureT;
	GPIO_InitStructureT.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureT.GPIO_Pin = GPIO_Pin_2 ;
	GPIO_InitStructureT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureT);
	
	GPIO_InitTypeDef GPIO_InitStructureR;
	GPIO_InitStructureR.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructureR.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructureR.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureR);
	
	
	USART_InitTypeDef USART_InitStructure;
	
	USART_InitStructure.USART_BaudRate=7288;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_Odd;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_9b;
	USART_Init(USART2,&USART_InitStructure);
	

	USART_Cmd(USART2,ENABLE);
  USART_ITConfig(USART2,USART_IT_ERR,ENABLE);
}

void USART2_Send(uint16_t Send_Data)
{
	while (USART_GetFlagStatus(USART2,USART_FLAG_TXE)==SET);
	USART_SendData(USART2,Send_Data);
}

uint16_t USART2_Receive(void)
{
	while (USART_GetFlagStatus(USART2,USART_FLAG_RXNE)!=SET);
	uint16_t Receive_Data;
	Receive_Data=USART_ReceiveData(USART2);
	return Receive_Data;
}

void USART2H_IRQHandler(void)
{
	
}
