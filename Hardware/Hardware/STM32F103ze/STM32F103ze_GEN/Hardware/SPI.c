#include "stm32f10x.h"
#include "stdint.h"

void SPI3_INIT(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure15;
	GPIO_InitStructure15.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure15.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure15.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure15);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
	
	GPIO_InitTypeDef GPIO_InitStructure3;
	GPIO_InitStructure3.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure3.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure3.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure3);
	
	GPIO_InitTypeDef GPIO_InitStructure4;
	GPIO_InitStructure4.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure4.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure4.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure4);
	
	GPIO_InitTypeDef GPIO_InitStructure5;
	GPIO_InitStructure5.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure5.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure5.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure5);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3,ENABLE);
	
	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_CPHA=SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPOL=SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CRCPolynomial=0;
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_16b;
	SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI3,&SPI_InitStructure);
	
  SPI_Cmd(SPI3, ENABLE);
	
}

void SPI3_Send(uint16_t send)
{
	while (SPI_I2S_GetFlagStatus(SPI3,SPI_I2S_FLAG_TXE) != SET);
	SPI_I2S_SendData(SPI3,send);
	SPI_I2S_ClearFlag(SPI3,SPI_I2S_FLAG_TXE);
}

uint16_t SPI3_Receive(void)
{
	while (SPI_I2S_GetFlagStatus(SPI3,SPI_I2S_FLAG_RXNE) != RESET);
	uint16_t data = SPI_I2S_ReceiveData(SPI3);
  SPI_I2S_ClearFlag(SPI3,SPI_I2S_FLAG_RXNE);
	return (data);
}

void SPI3_IT(void)
{
	
}

void SPI3_Close(void)
{ 
	while (SPI_I2S_GetFlagStatus(SPI3,SPI_I2S_FLAG_BSY) != SET);
	SPI_Cmd(SPI3,DISABLE);
	SPI_I2S_ClearFlag(SPI3,SPI_I2S_FLAG_BSY);
}

void SPI1_INIT(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure4;
	GPIO_InitStructure4.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure4.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure4.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure4);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	
	GPIO_InitTypeDef GPIO_InitStructure5;
	GPIO_InitStructure5.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure5.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure5.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure5);
	
	GPIO_InitTypeDef GPIO_InitStructure6;
	GPIO_InitStructure6.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure6.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure6.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure6);
	
	GPIO_InitTypeDef GPIO_InitStructure7;
	GPIO_InitStructure7.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure7.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure7.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure7);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_CPHA=SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPOL=SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CRCPolynomial=0;
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_16b;
	SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI1,&SPI_InitStructure);
	
  SPI_Cmd(SPI1, ENABLE);
	
}

void SPI1_Send(uint16_t send)
{
	while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != SET);
	SPI_I2S_SendData(SPI1,send);
	SPI_I2S_ClearFlag(SPI1,SPI_I2S_FLAG_TXE);
}

uint16_t SPI1_Receive(void)
{
	while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != RESET);
	uint16_t data = SPI_I2S_ReceiveData(SPI1);
  SPI_I2S_ClearFlag(SPI1,SPI_I2S_FLAG_RXNE);
	return (data);
}

void SPI1_IT(void)
{
	
}

void SPI1_Close(void)
{ 
	while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_BSY) != SET);
	SPI_Cmd(SPI1,DISABLE);
	SPI_I2S_ClearFlag(SPI1,SPI_I2S_FLAG_BSY);
}

void SPI2_INIT(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure12;
	GPIO_InitStructure12.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure12.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure12.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure12);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_12);
	
	GPIO_InitTypeDef GPIO_InitStructure13;
	GPIO_InitStructure13.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure13.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure13.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure13);
	
	GPIO_InitTypeDef GPIO_InitStructure14;
	GPIO_InitStructure14.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure14.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure14.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure14);
	
	GPIO_InitTypeDef GPIO_InitStructure15;
	GPIO_InitStructure15.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure15.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure15.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure15);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
	
	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_CPHA=SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPOL=SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_CRCPolynomial=0;
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_16b;
	SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI2,&SPI_InitStructure);
	
  SPI_Cmd(SPI2, ENABLE);
	
}

void SPI2_Send(uint16_t send)
{
	while (SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE) != SET);
	SPI_I2S_SendData(SPI2,send);
	SPI_I2S_ClearFlag(SPI2,SPI_I2S_FLAG_TXE);
}

uint16_t SPI2_Receive(void)
{
	while (SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE) != RESET);
	uint16_t data = SPI_I2S_ReceiveData(SPI2);
  SPI_I2S_ClearFlag(SPI2,SPI_I2S_FLAG_RXNE);
	return (data);
}

void SPI2_IT(void)
{
	
}

void SPI2_Close(void)
{ 
	while (SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_BSY) != SET);
	SPI_Cmd(SPI2,DISABLE);
	SPI_I2S_ClearFlag(SPI2,SPI_I2S_FLAG_BSY);
}

void SPI1_IRQHandler(void)
{
	
}

void SPI2_IRQHandler(void)
{
	
}

void SPI3_IRQHandler(void)
{
	
}

