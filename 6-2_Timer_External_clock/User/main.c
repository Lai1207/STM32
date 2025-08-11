#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.H"

uint16_t Num;

int main(void)
{
	
	Timer_Init();
	OLED_Init();
	OLED_ShowString(1,1,"Num:");					//顯示字串
	OLED_ShowString(2,1,"CNT:");
	while(1){	
	
	OLED_ShowNum(1,5,Num,5);
	OLED_ShowNum(2,5,Timer_GetCounter(),5); 		//顯示cnt計數
		
	}
}
