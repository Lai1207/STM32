#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"


int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1,1,'A');					//顯示字元
	OLED_ShowString(1,3,"HelloWorld!");		//顯示字串
	OLED_ShowNum(2,1,12345,5);				//顯示無符號數字(行,列,數值,數值大小)
	OLED_ShowSignedNum(2,7,-12345,5);		//顯示符號數字
	OLED_ShowHexNum(3,1,0xAA55,4);			//顯示16進制
	OLED_ShowBinNum(4,1,0xAA55,16);			//顯示2進制
	
	
	while(1)
	{	

		
	}
}
 
