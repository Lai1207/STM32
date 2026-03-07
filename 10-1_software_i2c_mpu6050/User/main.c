#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Mpu6050.h"
#include "Myi2c.h"

uint8_t ID;
int16_t AX, AY, AZ, GX, GY, GZ;
int main(void)
{
	OLED_Init();
	
	Mpu6050_Init();
	ID = Mpu6050_GetID();
	OLED_ShowString(1, 1, "ID:");
	OLED_ShowHexNum(1,4,ID,2);
	
	//Mpu6050_WriteReg(0x6B, 0x00);
	//Mpu6050_WriteReg(0x19, 0xAA);
	
	//uint8_t ID = Mpu6050_ReadReg(0x19);
	
	
	//OLED_ShowHexNum(1, 1, ID, 2);
	

	
	while(1){
		Mpu6050_GatData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		OLED_ShowSignedNum(2, 1, AX, 5);
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);
		
	
		
	}
}
 
