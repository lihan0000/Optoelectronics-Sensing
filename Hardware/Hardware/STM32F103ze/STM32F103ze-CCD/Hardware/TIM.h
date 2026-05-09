#include "stdint.h"

#ifndef TIM_H_T
#define TIM_H_T

void TIM1_INIT(uint16_t ARR , uint16_t CCR);//
void TIM2_INIT(uint16_t ARR , uint16_t CCR);//
void TIM3_INIT(uint16_t ARR , uint16_t CCR);//
void TIM4_INIT(uint16_t ARR , uint16_t CCR);//
void TIM5_INIT(uint16_t ARR , uint16_t CCR);//
void TIM6_INIT(uint16_t ARR , uint16_t CCR);//
void TIM7_INIT(uint16_t ARR , uint16_t CCR);//
void TIM8_INIT(uint16_t ARR , uint16_t CCR);//
void SYSTICK(void);
void WIFI_PWM(void);

#endif
