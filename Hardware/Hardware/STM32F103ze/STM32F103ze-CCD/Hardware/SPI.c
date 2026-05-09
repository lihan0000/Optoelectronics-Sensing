#include "stm32f10x.h"
#include "stdint.h"

void SPI_INIT(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureNSS;
	GPIO_InitStructureNSS.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_InitStructureNSS.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructureNSS.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureNSS);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//CS低电平选中
	
	GPIO_InitTypeDef GPIO_InitStructureSPIIP;
	GPIO_InitStructureSPIIP.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_InitStructureSPIIP.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructureSPIIP.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureSPIIP);
	
	GPIO_InitTypeDef GPIO_InitStructureSPIAF;
	GPIO_InitStructureSPIAF.GPIO_Mode =GPIO_Mode_AF_PP;
	GPIO_InitStructureSPIAF.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_15;
	GPIO_InitStructureSPIAF.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureSPIAF);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);
	
	SPI_InitTypeDef SPI_InitStructureLCD;
	SPI_InitStructureLCD.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStructureLCD.SPI_CPHA=SPI_CPOL_Low;
	SPI_InitStructureLCD.SPI_CPOL=SPI_CPHA_1Edge;
	SPI_InitStructureLCD.SPI_CRCPolynomial=0;
	SPI_InitStructureLCD.SPI_DataSize=SPI_DataSize_8b;
	SPI_InitStructureLCD.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructureLCD.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStructureLCD.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructureLCD.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI2,&SPI_InitStructureLCD);
	
	SPI_Cmd(SPI2, ENABLE);
}

uint16_t SPI_Send(uint16_t SendDATA)
{
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)  != SET);
	SPI_I2S_SendData(SPI2, SendDATA);
	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_RXNE) != SET);
	return SPI_I2S_ReceiveData(SPI2);
}
