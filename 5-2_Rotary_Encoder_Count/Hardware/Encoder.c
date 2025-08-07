#include "stm32f10x.h"                  // Device header

int16_t Encoder_count;

void Encoder_Init(void){
	 /* 開啟時鐘 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);        // 開啟 GPIOB 的時鐘
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);         // 開啟 AFIO 的時鐘，外部中斷必須開啟 AFIO 的時鐘
    
    /* GPIO 初始化 */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                // 設定為上拉輸入模式
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;                   // 設定為 GPIOB 的第 14 腳
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            // 設定速度為 50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);                        // 將 GPIOB 14 腳初始化為上拉輸入

    /* AFIO 選擇中斷引腳 */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);  // 設定 GPIOB 第 14 腳為外部中斷引腳
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
    /* EXTI 初始化 */
    EXTI_InitTypeDef EXTI_InitStructure;                          // 定義 EXTI 初始化結構體
    EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;                   // 設定外部中斷為 14 號線
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;                     // 啟用該中斷線
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;           // 設定為中斷模式
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;       // 設定為下降沿觸發
    EXTI_Init(&EXTI_InitStructure);                                // 使用設定的結構體配置 EXTI 外設
    
    /* NVIC 中斷分組設定 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);               // 設定 NVIC 為分組 2
                                                                  // 這樣主優先級範圍為：0~3，響應優先級範圍為：0~3
                                                                  // 整個專案中只需調用一次
                                                                  // 若有多個中斷，可以將此設定放在 main 函式中，while 循環之前
                                                                  // 如果多次調用配置分組，後執行的配置會覆蓋先執行的配置
    
    /* NVIC 配置 */
    NVIC_InitTypeDef NVIC_InitStructure;                          // 定義 NVIC 初始化結構體
    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;         	  // 設定 NVIC 的 EXTI15_10 中斷
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               // 啟用 NVIC 中斷
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // 設定中斷的搶佔優先級為 1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;            // 設定中斷的響應優先級為 1
    NVIC_Init(&NVIC_InitStructure);          

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;              // 設定 NVIC 的 EXTI15_10 中斷
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               // 啟用 NVIC 中斷
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // 設定中斷的搶佔優先級為 1
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;            // 設定中斷的響應優先級為 1
    NVIC_Init(&NVIC_InitStructure);

}
int16_t Encoder_Get(void){
	int16_t Temp;
	Temp = Encoder_count;
	Encoder_count = 0;
	return Temp;
}

void EXTI0_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line0) == SET){
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0){
			Encoder_count --;
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
void EXTI1_IRQHandler(void){
	if (EXTI_GetITStatus(EXTI_Line1) == SET){
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0){
			Encoder_count ++;
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
