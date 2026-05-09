#include "stm32f10x.h"
#include "stdint.h"
#include "SPI.h"
#include "Delay.h"

#ifndef LCD_H
#define LCD_H

void LCD_REEST(void);
void LCD_INITI(void);
void LCD_Place(uint16_t X1,uint16_t X2,uint16_t Y1,uint16_t Y2);
void LCD_PIXEL(void);
void LCD_Clear(void);
void QR_CODE(void);
#endif
