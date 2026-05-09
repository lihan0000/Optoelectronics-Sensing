#include "stm32f10x.h"
#include "stdint.h"
#include "SPI.h"
#include "LCD.h"
#include "TIM.h"
#include "DMA.h"
#include "ADC.h"
#include "Nvic.h"
#include "Delay.h"
#include "USART.h"

static uint16_t TIM2_ARR,TIM2_CCR,TIM3_ARR,TIM3_CCR,TIM4_ARR,TIM4_CCR;
static uint16_t CCD_DATA[4000];
static uint16_t ADC_DATA[4000];
static uint16_t USART_DATA;

void CCD(void)
{
	while(USART1_Receive() != 0xFF);
	int n = 0;
	while(n<4000)
	{
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

int main(void)
{
	USART1_INIT();//初始化并开启USART1
	
	//X = USART1_Receive();//等待接受曝光时间X
	
	TIM3_ARR=2;
	TIM3_CCR=1;
	TIM2_ARR=16000;
	TIM2_CCR=15979;
	TIM4_ARR=40;
	TIM4_CCR=30;
	
	TIM2_INIT(TIM2_ARR,TIM2_CCR);
	TIM3_INIT(TIM3_ARR,TIM3_CCR);//ICG TIM3引脚的周期为16000,高电平的时间为15979
	TIM4_INIT(TIM4_ARR,TIM4_CCR);//SH  TIM4引脚的周期为40*X,低电平的时间为(40)*X-10
	
	TIM_Cmd(TIM4,ENABLE);
	SYSTICK();
	TIM_Cmd(TIM2,ENABLE);
	TIM_Cmd(TIM3,ENABLE);

  DMA_INIT_ADC1((uint32_t)ADC_DATA,(uint32_t)(4000));//初始化DMA1的通道1
	ADC1_INIT();//初始化并开启ADC1的通道1
	DMA_Cmd(DMA1_Channel1,ENABLE);//开启DMA1的通道1	
	ADC_DMACmd(ADC1, ENABLE);//开启ADC的通道1的DMA功能
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//软件触发ADC的连续转化
		
  CCD();//跳转到CCD函数
}
