#include "stm32f10x.h"
#include "stdint.h"
#include "TIM.h"
#include "ADC.h"
#include "DMA.h"
#include "SPI.h"
#include "Nvic.h"
#include "Delay.h"
#include "USART.h"

static uint16_t TIM1_ARR,TIM1_CCR,TIM2_ARR,TIM2_CCR,TIM3_ARR,TIM3_CCR,TIM4_ARR,TIM4_CCR;
static uint16_t TIM5_ARR,TIM5_CCR,TIM6_ARR,TIM6_CCR,TIM7_ARR,TIM7_CCR,TIM8_ARR,TIM8_CCR;
static uint16_t CCD_DATA[4000];
static uint16_t ADC_DATA[4000];
static uint16_t ADC_DATA1[4000];
static uint16_t ADC_DATA2[4000];
static uint16_t X = 0;
static uint16_t USART_DATA;
static uint16_t USART1_DATA;
static uint16_t USART2_DATA;

void CCD(void)
{
	while(USART1_Receive() != 0xFF);
	int n = 0;
	while(n<4000)
	{
		USART1_Send(1);
		CCD_DATA[n] = ADC_DATA[n];
		n = n+1;
	}
	int m = 0;	
	while(m<4000)
	{
		USART_DATA = (CCD_DATA[m]>>8)&0xFF;
		USART1_Send(USART_DATA);
		Delay_us(87);
		USART_DATA = CCD_DATA[m];
		USART1_Send(USART_DATA);
		Delay_us(87);
		m = m+1;
	}
	
	CCD();
}

void TIM1_UP_IRQHandler(void)
{
	TIM_Cmd(TIM1,DISABLE);
}

int main(void)
{
	USART1_INIT();//初始化并开启USART1
	
	X = USART1_Receive();//等待接受曝光时间X
	
	TIM1_ARR=20;
	TIM1_CCR=10;
	TIM2_ARR=2;
	TIM2_CCR=1;
	TIM3_ARR=16000;
	TIM3_CCR=15979;
	TIM8_ARR=40;
	TIM8_CCR=30;
	
  TIM1_INIT(TIM1_ARR,TIM1_CCR);
	TIM2_INIT(TIM2_ARR,TIM2_CCR);
	TIM3_INIT(TIM3_ARR,TIM3_CCR);//ICG TIM3引脚的周期为16000,高电平的时间为15979
	TIM8_INIT(TIM8_ARR,TIM8_CCR);//SH  TIM8引脚的周期为40*X,低电平的时间为(40)*X-10
	TIM_Cmd(TIM1,ENABLE);
	TIM_Cmd(TIM8,ENABLE);
	
	SYSTICK();
		
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);

  DMA_INIT_ADC1((uint32_t)ADC_DATA,(uint32_t)(4000));//初始化DMA1的通道1
	ADC1_INIT();//初始化ADC1的通道1
	DMA_Cmd(DMA1_Channel1,ENABLE);//开启DMA1的通道1	
	ADC_DMACmd(ADC1, ENABLE);//开启ADC的通道1的DMA功能
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//软件触发ADC的连续转化
		
  CCD();//跳转到CCD函数
}
