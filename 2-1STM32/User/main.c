#include "stm32f10x.h"                  // Device header


int main(void)
{	 // 啟用 GPIOC 模組的時鐘
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	// 宣告 GPIO 初始化結構體
	GPIO_InitTypeDef GPIO_InitStructure;
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		//設定GPIO推挽輸出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				//指定為GPIOC 13PIN (PC13)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//設定輸出數度為50MHZ 切換速度
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);					//將上面設定好的參數應用到GPIOC PC13
	GPIO_SetBits(GPIOC,GPIO_Pin_13);						//輸出高電位
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);					//輸出低電位
	while(1)
	{
 
	}	
 
}
