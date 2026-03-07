#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	//推挽輸出高低電平都有驅動能力

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;   		//全部都初始化
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	
	while(1)
	{	
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);		//PB12設定低電壓
		Delay_ms(100);							
		GPIO_SetBits(GPIOB, GPIO_Pin_12);		//PB12設定高電壓
		Delay_ms(100);	
		
		
		
	}
}
