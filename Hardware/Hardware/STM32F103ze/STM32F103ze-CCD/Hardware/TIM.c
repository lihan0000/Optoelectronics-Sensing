#include "stm32f10x.h"
#include "stdint.h"

void TIM1_INIT(uint16_t ARR , uint16_t CCR)//
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM2;
	GPIO_InitStructureTIM2.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM2.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructureTIM2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructureTIM2);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 20 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	//TIM_SetAutoreload(TIMx,ARR);
	//while(TIM_GetFlagStatus(TIM1,TIM_FLAG_Update)==SET);
}
void TIM2_INIT(uint16_t ARR , uint16_t CCR)//M
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM2;
	GPIO_InitStructureTIM2.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM2.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructureTIM2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureTIM2);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40-1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	
	//TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)==SET);
}

void TIM3_INIT(uint16_t ARR , uint16_t CCR)//ICG
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM3;
	GPIO_InitStructureTIM3.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM3.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructureTIM3.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureTIM3);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 20 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);

  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET);
}

void TIM4_INIT(uint16_t ARR , uint16_t CCR)//SHI
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM4;
	GPIO_InitStructureTIM4.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM4.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructureTIM4.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureTIM4);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	
  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM4,TIM_FLAG_Update)==SET);
}

void TIM5_INIT(uint16_t ARR , uint16_t CCR)//SHI
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM5;
	GPIO_InitStructureTIM5.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM5.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructureTIM5.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureTIM5);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC1Init(TIM5, &TIM_OCInitStructure);
	
  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM5,TIM_FLAG_Update)==SET);
}
void TIM6_INIT(uint16_t ARR , uint16_t CCR)//SHI
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM6;
	GPIO_InitStructureTIM6.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM6.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructureTIM6.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureTIM6);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC2Init(TIM6, &TIM_OCInitStructure);
	
  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)==SET);
}
void TIM7_INIT(uint16_t ARR , uint16_t CCR)//SHI
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM7;
	GPIO_InitStructureTIM7.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM7.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructureTIM7.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructureTIM7);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
	TIM_OC2Init(TIM7, &TIM_OCInitStructure);
	
  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM7,TIM_FLAG_Update)==SET);
}
void TIM8_INIT(uint16_t ARR , uint16_t CCR)//SHI
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructureTIM8;
	GPIO_InitStructureTIM8.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructureTIM8.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructureTIM8.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructureTIM8);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = ARR - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 40 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR;		//CCR
	
  //TIM_ITConfig(TIM8,TIM_IT_Update,ENABLE);
		
	//TIM_OC2Init(TIM8, &TIM_OCInitStructure);
  //TIM_SetAutoreload(TIMx,ARR);
  //TIM_SetCompare(TIMx,CCR);
	//while(TIM_GetFlagStatus(TIM8,TIM_FLAG_Update)==SET);
}

void SYSTICK(void)
{
	SysTick->LOAD = 250;
	SysTick->VAL = 0x00;
	SysTick->CTRL = 0x00000005;
	while(!(SysTick->CTRL & 0x00010000));
}

void WIFI_PWM(void)
{
	/*USART1_INIT();
	TIM2_INIT(20,10);
	Delay_ms(20);
	Serial_SendString("AT+RST");
	Serial_SendString("\r\n");
	Delay_ms(20);
	Serial_SendString("AT+CWMODE=1");
	Serial_SendString("\r\n");
	Delay_ms(100);
	Serial_SendString("AT+CWJAP=");
	Delay_ms(20);
	USART1_Send(34);
	Serial_SendString("TP-LINK_AD8A");
	Delay_ms(20);
	USART1_Send(34);
	Serial_SendString(",");
	Delay_ms(20);
	USART1_Send(34);
	Serial_SendString("cx125127");
	Delay_ms(20);
	USART1_Send(34);
	Serial_SendString("\r\n");
	Delay_s(30);
	Serial_SendString("AT+ATKCLDSTA=");
	Delay_ms(20);
	USART1_Send(34);
	Delay_ms(20);
	Serial_SendString("41344852786356453281");
	Delay_ms(20);
	USART1_Send(34);
	Delay_ms(20);
	Serial_SendString(",");
	Delay_ms(20);
	USART1_Send(34);
	Delay_ms(20);
	Serial_SendString("12345678");
	Delay_ms(20);
	USART1_Send(34);
	Delay_ms(20);
	Serial_SendString("\r\n");
	Delay_s(2);
	
	while(USART1_Receive() != 0x00);
	TIM_Cmd(TIM2,ENABLE);
	while(USART1_Receive() != 0x00);
	TIM_SetCompare2(TIM2,1);
	TIM_SetAutoreload(TIM2,2);*/
}

