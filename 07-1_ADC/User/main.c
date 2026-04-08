#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t ADValue;
int main(void)
{
	OLED_Init();
	AD_Init();
	
	
	
	
	while(1)
	{	
		ADValue = AD_GetValue();
	}
}
 
