#ifndef __MYI2C_H
#define __MYI2C_H
void Myi2c_Init(void);

void Myi2c_w_scl(uint8_t BitValue);
void Myi2c_w_sda(uint8_t BitValue);
uint8_t Myi2c_r_sda(void);
void MyI2C_Start(void);
void MyI2C_Stop(void);

void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_ReceiveByte(void);

void MyI2C_SendAck(uint8_t AckByte);
uint8_t MyI2C_ReceiveAck(void);
	

#endif
