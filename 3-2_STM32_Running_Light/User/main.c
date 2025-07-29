#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽輸出高低電平都有驅動能力
	//GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_OD; //開漏輸出只有低電平驅動能力
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;   //全部都初始化
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	
	while(1)
	{	
		GPIO_Write(GPIOA,~0x0001); //0000 0000 0000 0001 pa0 ~ 全部為高電平 pa0為低電平
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0002); //0000 0000 0000 0010
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0004); //0000 0000 0000 0100
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0008); //0000 0000 0000 1000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0010); //0000 0000 0001 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0020); //0000 0000 0010 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0040); //0000 0000 0100 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0080); //0000 0000 1000 0000
		Delay_ms(100);
		
		
	}
}
