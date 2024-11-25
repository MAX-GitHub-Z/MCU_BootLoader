/**
  ************************* Copyright **********************
  *
  *          (C) Copyright 2024,China.
  *                    All Rights Reserved
  *
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *
  * FileName     : stm32f10x_fmc.c
  * Version      : v1.0
  * Author       : MAX-GitHub-Z
  * Date         : 2024-11-23
  * Description  :
  * Function List:
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  **********************************************************
 */


#include "stm32f10x_mid.h"

#if defined (__CC_ARM)
#pragma diag_suppress 1296
#elif defined (__ICCARM)
#elif defined (__GNUC__)
#endif

/*********************************************************************/
/************************�ڲ���������*********************************/
/*********************************************************************/
void USART_Config(USART_TypeDef* USARTx,uint32_t Usart_Baudrate);
void gpio_init(GPIO_TypeDef* GPIOx,GPIOMode_TypeDef GPIO_MODE,uint16_t GPIO_Pin) ;
/*********************************************************************/
/************************����ʵ��*********************************/
/*********************************************************************/


/*************************************
  * @Name   : usart_init
  * @brief  :
  * @param  :  [����/��] 
  * @retval ��None
  * @author : MAX-GitHub-Z 
  * @Data   : 2024-11-25
  * <description> :
 ****************************************/
void usart_init()
{
	USART_Config(DEBUG_USARTx,DEBUG_USART_BAUDRATE);
	gpio_init(GPIOC,GPIO_Mode_Out_PP, GPIO_Pin_13);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

void DEBUG_USART_IRQHandler(void)
{
	uint16_t uTemp;
	if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE)!=RESET)
	{		
		uTemp = USART_ReceiveData(DEBUG_USARTx);
		USART_SendData(DEBUG_USARTx,uTemp);
		USART_ClearITPendingBit(DEBUG_USARTx,USART_IT_RXNE);//����жϱ�־λ
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
//    USART_SendData(DEBUG_USARTx,ucTemp);  
			
	}	 
//	if(USART_GetITStatus(DEBUG_USARTx,USART_IT_IDLE)!=RESET)
//	{		
//		
////		printf("%s\r\n",USART_Buffer);
//		i=0;
//		ucTemp=DEBUG_USARTx->SR;//���ڿ����жϵ��жϱ�־ֻ��ͨ���ȶ�SR�Ĵ������ٶ�DR�Ĵ��������
//    ucTemp=DEBUG_USARTx->DR;
////		 // USART_ClearITPendingBit(DEBUG_USARTx,USART_IT_IDLE);//����жϱ�־λ

//	}	 
		
}

//GPIO ��ʼ��
void gpio_init(GPIO_TypeDef* GPIOx,GPIOMode_TypeDef GPIO_MODE,uint16_t GPIO_Pin) 
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    //�򿪴�����������
    switch((uint32_t)GPIOx) {
    case (uint32_t)GPIOA:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
        break;
    case (uint32_t)GPIOB:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
        break;
    case (uint32_t)GPIOC:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
        break;
    case (uint32_t)GPIOD:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
        break;
    case (uint32_t)GPIOE:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
        break;
    default:
        //error
        break;

    }

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_MODE;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOx, &GPIO_InitStructure);

}


static void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* ����USARTΪ�ж�Դ */
    NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
    /* �������ȼ�*/
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    /* �����ȼ� */
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    /* ʹ���ж� */
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    /* ��ʼ������NVIC */
    NVIC_Init(&NVIC_InitStructure);
}
void USART_Config(USART_TypeDef* USARTx,uint32_t Usart_Baudrate)
{
    USART_InitTypeDef USART_InitStructure;

    //�򿪴���ʱ��
    switch((uint32_t)USARTx)
    {
    case (uint32_t)USART1:
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
        break;
    case (uint32_t)USART2:
        RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
        break;
    case (uint32_t)USART3:
        RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
        break;
    case (uint32_t)UART4:
        RCC_APB2PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
        break;
    case (uint32_t)UART5:
        RCC_APB2PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);
        break;
    default:
        //error
        break;

    }


    //��USART TX��GPIO����Ϊ���츴�����
    gpio_init(DEBUG_USART_TX_GPIO_PORT,GPIO_Mode_AF_PP,DEBUG_USART_TX_GPIO_PIN);

    // ��USART Rx��GPIO����Ϊ��������ģʽ
    gpio_init(DEBUG_USART_RX_GPIO_PORT,GPIO_Mode_IN_FLOATING,DEBUG_USART_RX_GPIO_PIN);

    // ���ô��ڵĹ�������
    // ���ò�����
    USART_InitStructure.USART_BaudRate = Usart_Baudrate;
    // ���� �������ֳ�
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    // ����ֹͣλ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    // ����У��λ
    USART_InitStructure.USART_Parity = USART_Parity_No ;
    // ����Ӳ��������
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    // ���ù���ģʽ���շ�һ��
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    // ��ɴ��ڵĳ�ʼ������
    USART_Init(USARTx, &USART_InitStructure);

    // �����ж����ȼ�����
    NVIC_Configuration();

    // ʹ�ܴ��ڽ����ж�
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
//	USART_ITConfig(DEBUG_USARTx,USART_IT_IDLE,ENABLE);

    // ʹ�ܴ���
    USART_Cmd(USARTx, ENABLE);

}


#define lora_len 200
void USART1_printf(char *format,...)
{
    char buffer[lora_len+1 ];//���ݳ���
    uint16_t i=0;
    uint16_t length;
    va_list ap;
    va_start(ap,format);
    vsprintf((char *)buffer,format,ap);
    va_end(ap);
    length=strlen((const char*)buffer);//LORA_USRAT
    for(i=0; i<length; i++) {
        while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
        USART_SendData(USART1,buffer[i]);
        //printf("%c",buffer[i]);
    }
}

/*����һ���ֽڵ�����*/
void USART_SendByte(USART_TypeDef* pSART1,uint8_t data)
{
    USART_SendData(pSART1,data);
    while(USART_GetFlagStatus(pSART1, USART_FLAG_TXE)==0);
}

/*���������ֽڵ�����*/
void USART_SendHalfgWord(USART_TypeDef* pSART1,uint16_t data)
{
    uint8_t temp_h,temp_l;
    temp_h=(data&0xff00)>>8;
    temp_l=data&0xff;
    USART_SendData(pSART1,temp_h);
    while(USART_GetFlagStatus(pSART1, USART_FLAG_TXE)==0);

    USART_SendData(pSART1,temp_l);
    while(USART_GetFlagStatus(pSART1, USART_FLAG_TXE)==0);
}
/*���Ͱ�λ���ݵ�����*/
void USART_Sendarray(USART_TypeDef* pSART1,uint8_t *array,uint8_t num)
{
    uint8_t i=0;
    for(i=0; i<num; i++) {
        USART_SendByte(pSART1,array[i]);
    }
    while(USART_GetFlagStatus(pSART1, USART_FLAG_TC)==0);//�ж�һ�������Ƿ������
}
/*�����ַ���*/
void USART_SendStr(USART_TypeDef* pSART1,uint8_t *str)
{   //
    uint8_t i=0;
    do {
        USART_SendByte(pSART1,*(str+i));
        i++;
    } while(*(str+i)!='\0');
    while(USART_GetFlagStatus(pSART1, USART_FLAG_TC)==0);//�ж�һ�������Ƿ������
}
//���¶���c�⺯��printf�����ڣ�
int fputc(int ch,FILE *f)
{
    USART_SendByte(DEBUG_USARTx,(uint8_t) ch);
    while(USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE)==0);
    return ch;
}
///�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
    /* �ȴ������������� */
    while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

    return (int)USART_ReceiveData(DEBUG_USARTx);
}




