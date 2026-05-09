#include "stm32f10x.h"
#include "stdint.h"
#include "SPI.h"
#include "Delay.h"

void LCD_REEST(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);//初始化关闭
	Delay_s(1);
	GPIO_SetBits(GPIOA,GPIO_Pin_11);  //初始化开启
	Delay_s(1);
}
void LCD_INITI(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xCF);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00); 
	SPI_Send(0xD9);
	SPI_Send(0X30); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xED);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x64); 
	SPI_Send(0x03); 
	SPI_Send(0X12); 
	SPI_Send(0X81); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xE8);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x85); 
	SPI_Send(0x10); 
	SPI_Send(0x7A); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xCB);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x39); 
	SPI_Send(0x2C); 
	SPI_Send(0x00); 
	SPI_Send(0x34); 
	SPI_Send(0x02); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xF7);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x20); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xEA);  
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00); 
	SPI_Send(0x00); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xC0); 
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x1B);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xC1);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x12);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xC5);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x08);
	SPI_Send(0x26);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xC7);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0XB7); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x36);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x08); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x3A);   
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x55); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xB1);   
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00);   
	SPI_Send(0x1A); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xB6);
  GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据	
	SPI_Send(0x0A); 
	SPI_Send(0xA2); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xF2);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x26);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x01); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0xE0);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x0F); 
	SPI_Send(0x1D); 
	SPI_Send(0x1A); 
	SPI_Send(0x0A); 
	SPI_Send(0x0D); 
	SPI_Send(0x07); 
	SPI_Send(0x49); 
	SPI_Send(0X66); 
	SPI_Send(0x3B); 
	SPI_Send(0x07); 
	SPI_Send(0x11); 
	SPI_Send(0x01); 
	SPI_Send(0x09); 
	SPI_Send(0x05); 
	SPI_Send(0x04); 		
  GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址	
	SPI_Send(0XE1);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00); 
	SPI_Send(0x18); 
	SPI_Send(0x1D); 
	SPI_Send(0x02); 
	SPI_Send(0x0F); 
	SPI_Send(0x04); 
	SPI_Send(0x36); 
	SPI_Send(0x13); 
	SPI_Send(0x4C); 
	SPI_Send(0x07); 
	SPI_Send(0x13); 
	SPI_Send(0x0F); 
	SPI_Send(0x2E); 
	SPI_Send(0x2F); 
	SPI_Send(0x05); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2B); 
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00);
	SPI_Send(0x00);
	SPI_Send(0x01);
	SPI_Send(0x3f);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2A); 
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0x00);
	SPI_Send(0x00);
	SPI_Send(0x00);
	SPI_Send(0xef);
  GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址	
	SPI_Send(0x11);
	Delay_ms(120);
	SPI_Send(0x29);
}
void LCD_Place(uint16_t X1,uint16_t X2,uint16_t Y1,uint16_t Y2)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2A);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(X1 >> 8);
	SPI_Send((X1)&0xFF);
	SPI_Send(X2 >> 8);
	SPI_Send((X2)&0xFF);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2B);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(Y1 >> 8);
	SPI_Send((Y1)&0xFF);
	SPI_Send(Y2 >> 8);
	SPI_Send((Y2)&0xFF);
}
void LCD_PIXEL(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2C);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
}
void LCD_Clear(void)
{
	int num = 0;
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2A);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0);
	SPI_Send(0);
	SPI_Send((240-1)>>8);
	SPI_Send((240-1)&0xFF);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2B);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
	SPI_Send(0);
	SPI_Send(0);
	SPI_Send((320-1)>>8);
	SPI_Send((320-1)&0xFF);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);//发送地址
	SPI_Send(0x2C);
	GPIO_SetBits(GPIOA,GPIO_Pin_12);  //发送数据
  for(num=0;num<(320*240);num++)
	{
		SPI_Send(0xFFFF);
		SPI_Send(0xFFFF);
	}
}
void QR_CODE(void)
{

}
