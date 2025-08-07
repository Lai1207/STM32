#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.H"

int16_t Num;

int main(void)
{
	OLED_Init();
	Encoder_Init();
	
	OLED_ShowString(1,1,"Num:");		//顯示字串

	
	
	while(1)
	{	
		Num += Encoder_Get();
		OLED_ShowSignedNum(1,7,Num,5);
		
	}
}
