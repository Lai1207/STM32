#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void Myi2c_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);
}

void Myi2c_w_scl(uint8_t BitValue){
	GPIO_WriteBit(GPIOB, GPIO_Pin_10,(BitAction)BitValue);
	Delay_us(10);
}
void Myi2c_w_sda(uint8_t BitValue){
	GPIO_WriteBit(GPIOB, GPIO_Pin_11,(BitAction)BitValue);
	Delay_us(10);
}
uint8_t Myi2c_r_sda(void){
	uint8_t BitValue;
	BitValue = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	Delay_us(10);
	return BitValue;
}

void MyI2C_Start(void){
	Myi2c_w_sda(1);
	Myi2c_w_scl(1);
	Myi2c_w_sda(0);
	Myi2c_w_scl(0);	
}
void MyI2C_Stop(void){
	Myi2c_w_sda(0);
	Myi2c_w_scl(1);
	Myi2c_w_sda(1);
}

void MyI2C_SendByte(uint8_t Byte){
	uint8_t i;
	for( i = 0 ; i < 8; i++){
		Myi2c_w_sda(Byte & (0x80 >> i));
		Myi2c_w_scl(1);
		Myi2c_w_scl(0);
	}

}
uint8_t MyI2C_ReceiveByte(void){
	uint8_t Byte = 0x00;
	uint8_t i;
	Myi2c_w_sda(1);	
	for( i = 0 ; i < 8; i++){
		
		Myi2c_w_scl(1);
		if(Myi2c_r_sda()== 1){
				Byte |= (0x80 >> i);
				
		}
		Myi2c_w_scl(0);
		
	}
	return Byte; 
}

void MyI2C_SendAck(uint8_t AckByte){
		Myi2c_w_sda(AckByte);
		Myi2c_w_scl(1);
		Myi2c_w_scl(0);
}
uint8_t MyI2C_ReceiveAck(void){
	
	uint8_t AckByte;
	Myi2c_w_sda(1);	
	Myi2c_w_scl(1);
	AckByte = Myi2c_r_sda(); 
	Myi2c_w_scl(0);
	
	return AckByte; 
}
