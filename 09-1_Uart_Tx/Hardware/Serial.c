#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);															//Enable Usart Clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;																				//Set baud rate
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//Set HardwareFlowControl to None , CTS, RTS, CTS_RTS
	USART_InitStructure.USART_Mode = USART_Mode_Tx;																		//Set Uart Mode to Rx, Tx, Rx | Tx  
	USART_InitStructure.USART_Parity = USART_Parity_No;																//Set Parity Even, Odd, No 
	USART_InitStructure.USART_StopBits = USART_StopBits_1;														//Set Stop Bit 
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;												//Set Data Lenght
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}
void Serial_SendByte(uint8_t Byte){
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *Array, uint16_t Lenght){
	uint16_t i;
	for(i = 0; i < Lenght; i++){
		Serial_SendByte(Array[i]);
	}
	
}

void Serial_SendString(char *String){
	uint8_t i;
	for(i = 0; String[i] != '\0' ; i++){
		Serial_SendByte(String[i]);
	}
}
uint32_t Serial_Pow(uint32_t x, uint32_t y){
	uint32_t Result = 1;
	while(y--){
		Result *= x;
	}
	return Result;
}
void Serial_SendNumber(uint32_t Number, uint8_t Length){
	uint8_t i;
	for(i = 0; i < Length; i ++){
		Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

int fputc(int ch, FILE *f){
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...){
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}