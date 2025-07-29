#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽輸出高低電平都有驅動能力
	//GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_OD; //開漏輸出只有低電平驅動能力
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	
	while(1)
	{	
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(500);
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);   //第三個參數BitAction BitVal 來控制狀態
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		Delay_ms(500);
		
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)0); //BitAction強轉型
		Delay_ms(500);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)1);
		Delay_ms(500);
		
	}
}
