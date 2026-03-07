#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"


int main(void)
{
	OLED_Init();
	
	Serial_Init();
	Serial_SendByte('a');
	
	uint8_t MyArray[] = {0x42, 0x43, 0x45, 0x46};
	char Mystring[] = "Hello word!!\r\n h";

	Serial_SendArray(MyArray, 4);
	Serial_SendString(Mystring);
	Serial_SendNumber(12345, 5);
	
	printf("Num=%d\r\n",666);
	printf("Num=%d\r\n",777);
	
	char String[100];
	sprintf(String,"Num=%d\r\n",777);
	Serial_SendString(String);
	Serial_Printf("Num=%d\r\n",777);
	
	while(1)
	{	

		
	}
}
 
